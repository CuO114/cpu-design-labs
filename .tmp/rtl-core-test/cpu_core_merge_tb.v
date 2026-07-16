`timescale 1ns / 1ps

module cpu_core_merge_tb;
    reg clk = 1'b0;
    reg rst = 1'b1;

    wire        ifetch_req;
    wire [31:0] ifetch_addr;
    reg         ifetch_valid = 1'b0;
    reg  [31:0] ifetch_inst = 32'h00000013;
    wire [ 3:0] daccess_ren;
    wire [31:0] daccess_addr;
    reg         daccess_rvalid = 1'b0;
    reg  [31:0] daccess_rdata = 32'h0;
    wire [ 3:0] daccess_wen;
    wire [31:0] daccess_wdata;
    reg         daccess_wresp = 1'b0;

    reg [31:0] imem [0:127];
    reg [31:0] dmem [0:127];
    integer i;
    integer failures = 0;
    localparam [31:0] HALT_PC = 32'd172;

    always #5 clk = ~clk;

    cpu_core dut (
        .cpu_rst        (rst),
        .cpu_clk        (clk),
        .ifetch_req     (ifetch_req),
        .ifetch_addr    (ifetch_addr),
        .ifetch_valid   (ifetch_valid),
        .ifetch_inst    (ifetch_inst),
        .daccess_ren    (daccess_ren),
        .daccess_addr   (daccess_addr),
        .daccess_rvalid (daccess_rvalid),
        .daccess_rdata  (daccess_rdata),
        .daccess_wen    (daccess_wen),
        .daccess_wdata  (daccess_wdata),
        .daccess_wresp  (daccess_wresp)
    );

    function [31:0] enc_r;
        input [6:0] funct7;
        input [4:0] rs2;
        input [4:0] rs1;
        input [2:0] funct3;
        input [4:0] rd;
        begin
            enc_r = {funct7, rs2, rs1, funct3, rd, 7'b0110011};
        end
    endfunction

    function [31:0] enc_i;
        input [11:0] imm;
        input [4:0] rs1;
        input [2:0] funct3;
        input [4:0] rd;
        input [6:0] opcode;
        begin
            enc_i = {imm, rs1, funct3, rd, opcode};
        end
    endfunction

    function [31:0] enc_s;
        input [11:0] imm;
        input [4:0] rs2;
        input [4:0] rs1;
        input [2:0] funct3;
        begin
            enc_s = {imm[11:5], rs2, rs1, funct3, imm[4:0], 7'b0100011};
        end
    endfunction

    function [31:0] enc_b;
        input [12:0] imm;
        input [4:0] rs2;
        input [4:0] rs1;
        input [2:0] funct3;
        begin
            enc_b = {imm[12], imm[10:5], rs2, rs1, funct3,
                     imm[4:1], imm[11], 7'b1100011};
        end
    endfunction

    function [31:0] enc_j;
        input [20:0] imm;
        input [4:0] rd;
        begin
            enc_j = {imm[20], imm[10:1], imm[11], imm[19:12], rd, 7'b1101111};
        end
    endfunction

    task check_reg;
        input [4:0] reg_index;
        input [31:0] expected;
        begin
            if (dut.U_RF.regs[reg_index] !== expected) begin
                $display("FAIL x%0d: actual=%h expected=%h",
                         reg_index, dut.U_RF.regs[reg_index], expected);
                failures = failures + 1;
            end
        end
    endtask

    always @(posedge clk) begin
        if (rst) begin
            ifetch_valid <= 1'b0;
        end else begin
            ifetch_valid <= ifetch_req;
            if (ifetch_req)
                ifetch_inst <= imem[ifetch_addr[8:2]];
        end
    end

    always @(posedge clk) begin
        if (rst) begin
            daccess_rvalid <= 1'b0;
            daccess_wresp <= 1'b0;
            daccess_rdata <= 32'h0;
        end else begin
            daccess_rvalid <= |daccess_ren;
            daccess_wresp <= |daccess_wen;
            if (|daccess_ren)
                daccess_rdata <= dmem[daccess_addr[8:2]];
            if (daccess_wen[0]) dmem[daccess_addr[8:2]][ 7: 0] <= daccess_wdata[ 7: 0];
            if (daccess_wen[1]) dmem[daccess_addr[8:2]][15: 8] <= daccess_wdata[15: 8];
            if (daccess_wen[2]) dmem[daccess_addr[8:2]][23:16] <= daccess_wdata[23:16];
            if (daccess_wen[3]) dmem[daccess_addr[8:2]][31:24] <= daccess_wdata[31:24];
        end
    end

    initial begin
        for (i = 0; i < 128; i = i + 1) begin
            imem[i] = 32'h00000013;
            dmem[i] = 32'h0;
        end

        imem[ 0] = enc_i(-20, 5'd0, 3'b000, 5'd1, 7'b0010011);
        imem[ 1] = enc_i(3, 5'd0, 3'b000, 5'd2, 7'b0010011);
        imem[ 2] = enc_i(15, 5'd1, 3'b111, 5'd3, 7'b0010011);
        imem[ 3] = enc_r(7'b0000000, 5'd3, 5'd2, 3'b110, 5'd4);
        imem[ 4] = enc_r(7'b0000000, 5'd2, 5'd1, 3'b010, 5'd5);
        imem[ 5] = enc_r(7'b0000000, 5'd2, 5'd1, 3'b011, 5'd6);
        imem[ 6] = enc_r(7'b0000001, 5'd2, 5'd1, 3'b000, 5'd7);
        imem[ 7] = enc_r(7'b0000001, 5'd2, 5'd1, 3'b001, 5'd8);
        imem[ 8] = enc_r(7'b0000001, 5'd2, 5'd1, 3'b011, 5'd9);
        imem[ 9] = enc_r(7'b0000001, 5'd2, 5'd1, 3'b100, 5'd10);
        imem[10] = enc_r(7'b0000001, 5'd2, 5'd1, 3'b110, 5'd11);
        imem[11] = enc_r(7'b0000001, 5'd2, 5'd1, 3'b101, 5'd12);
        imem[12] = enc_r(7'b0000001, 5'd2, 5'd1, 3'b111, 5'd13);
        imem[13] = enc_i(-10, 5'd1, 3'b010, 5'd14, 7'b0010011);
        imem[14] = enc_i(-1, 5'd2, 3'b011, 5'd15, 7'b0010011);
        imem[15] = enc_i(0, 5'd0, 3'b000, 5'd16, 7'b0010011);
        imem[16] = enc_i(0, 5'd0, 3'b000, 5'd17, 7'b0010011);
        imem[17] = enc_i(0, 5'd0, 3'b000, 5'd19, 7'b0010011);
        imem[18] = enc_i(0, 5'd0, 3'b000, 5'd20, 7'b0010011);
        imem[19] = enc_i(0, 5'd0, 3'b000, 5'd21, 7'b0010011);
        imem[20] = enc_i(0, 5'd0, 3'b000, 5'd22, 7'b0010011);
        imem[21] = enc_b(8, 5'd2, 5'd1, 3'b100);
        imem[22] = enc_i(99, 5'd0, 3'b000, 5'd16, 7'b0010011);
        imem[23] = enc_b(8, 5'd1, 5'd2, 3'b101);
        imem[24] = enc_i(99, 5'd0, 3'b000, 5'd17, 7'b0010011);
        imem[25] = enc_b(8, 5'd1, 5'd2, 3'b110);
        imem[26] = enc_i(99, 5'd0, 3'b000, 5'd19, 7'b0010011);
        imem[27] = enc_b(8, 5'd2, 5'd1, 3'b111);
        imem[28] = enc_i(99, 5'd0, 3'b000, 5'd20, 7'b0010011);
        imem[29] = enc_b(8, 5'd14, 5'd5, 3'b000);
        imem[30] = enc_i(99, 5'd0, 3'b000, 5'd21, 7'b0010011);
        imem[31] = enc_b(8, 5'd5, 5'd6, 3'b001);
        imem[32] = enc_i(99, 5'd0, 3'b000, 5'd22, 7'b0010011);
        imem[33] = enc_i(256, 5'd0, 3'b000, 5'd23, 7'b0010011);
        imem[34] = enc_i(-1, 5'd0, 3'b000, 5'd24, 7'b0010011);
        imem[35] = enc_s(0, 5'd24, 5'd23, 3'b010);
        imem[36] = enc_i(1, 5'd23, 3'b000, 5'd25, 7'b0000011);
        imem[37] = enc_i(2, 5'd23, 3'b100, 5'd26, 7'b0000011);
        imem[38] = enc_i(291, 5'd0, 3'b000, 5'd27, 7'b0010011);
        imem[39] = enc_s(2, 5'd27, 5'd23, 3'b001);
        imem[40] = enc_i(2, 5'd23, 3'b101, 5'd28, 7'b0000011);
        imem[41] = enc_i(127, 5'd0, 3'b000, 5'd29, 7'b0010011);
        imem[42] = enc_s(1, 5'd29, 5'd23, 3'b000);
        imem[43] = enc_j(0, 5'd0);

        repeat (3) @(posedge clk);
        rst = 1'b0;

        wait (dut.pc == HALT_PC);
        repeat (3) @(posedge clk);

        check_reg(5'd1, 32'hffff_ffec);
        check_reg(5'd3, 32'h0000_000c);
        check_reg(5'd4, 32'h0000_000f);
        check_reg(5'd5, 32'h0000_0001);
        check_reg(5'd6, 32'h0000_0000);
        check_reg(5'd7, 32'hffff_ffc4);
        check_reg(5'd8, 32'hffff_ffff);
        check_reg(5'd9, 32'h0000_0002);
        check_reg(5'd10, 32'hffff_fffa);
        check_reg(5'd11, 32'hffff_fffe);
        check_reg(5'd12, 32'h5555_554e);
        check_reg(5'd13, 32'h0000_0002);
        check_reg(5'd14, 32'h0000_0001);
        check_reg(5'd15, 32'h0000_0001);
        check_reg(5'd16, 32'h0000_0000);
        check_reg(5'd17, 32'h0000_0000);
        check_reg(5'd19, 32'h0000_0000);
        check_reg(5'd20, 32'h0000_0000);
        check_reg(5'd21, 32'h0000_0000);
        check_reg(5'd22, 32'h0000_0000);
        check_reg(5'd25, 32'hffff_ffff);
        check_reg(5'd26, 32'h0000_00ff);
        check_reg(5'd28, 32'h0000_0123);
        if (dmem[64] !== 32'h0123_7fff) begin
            $display("FAIL memory: actual=%h expected=01237fff", dmem[64]);
            failures = failures + 1;
        end

        if (failures == 0)
            $display("CPU_CORE_MERGE_TEST_PASS");
        else
            $display("CPU_CORE_MERGE_TEST_FAIL count=%0d", failures);
        $finish;
    end

    initial begin
        #20000;
        $display("CPU_CORE_MERGE_TEST_TIMEOUT pc=%h", dut.pc);
        $finish;
    end
endmodule
