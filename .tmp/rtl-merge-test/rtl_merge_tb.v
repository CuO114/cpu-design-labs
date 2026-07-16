`timescale 1ns / 1ps

`include "defines.vh"

module rtl_merge_tb;
    reg         clk = 1'b0;
    reg         rst = 1'b1;
    reg  [ 4:0] op = `ALU_ADD;
    reg  [31:0] a = 32'h0;
    reg  [31:0] b = 32'h0;
    wire [31:0] c;
    wire        br;
    wire        busy;

    reg  [ 6:0] opcode = 7'h0;
    reg  [ 2:0] funct3 = 3'h0;
    reg  [ 6:0] funct7 = 7'h0;
    wire [ 1:0] npc_op;
    wire [ 2:0] sext_op;
    wire        alua_sel;
    wire        alub_sel;
    wire [ 4:0] alu_op;
    wire        is_mul;
    wire        is_div;
    wire [ 2:0] ram_r_op;
    wire [ 3:0] ram_w_op;
    wire        rf_we;
    wire [ 1:0] rf_wsel;

    integer failures = 0;

    always #5 clk = ~clk;

    ALU dut_alu (
        .rst  (rst),
        .clk  (clk),
        .op   (op),
        .a    (a),
        .b    (b),
        .c    (c),
        .br   (br),
        .busy (busy)
    );

    Controller dut_controller (
        .opcode   (opcode),
        .funct3   (funct3),
        .funct7   (funct7),
        .npc_op   (npc_op),
        .sext_op  (sext_op),
        .alua_sel (alua_sel),
        .alub_sel (alub_sel),
        .alu_op   (alu_op),
        .is_mul   (is_mul),
        .is_div   (is_div),
        .ram_r_op (ram_r_op),
        .ram_w_op (ram_w_op),
        .rf_we    (rf_we),
        .rf_wsel  (rf_wsel)
    );

    task check_value;
        input [255:0] name;
        input [31:0] actual;
        input [31:0] expected;
        begin
            if (actual !== expected) begin
                $display("FAIL %0s: actual=%h expected=%h", name, actual, expected);
                failures = failures + 1;
            end
        end
    endtask

    task check_comb;
        input [255:0] name;
        input [4:0] test_op;
        input [31:0] test_a;
        input [31:0] test_b;
        input [31:0] expected_c;
        input expected_br;
        begin
            op = test_op;
            a = test_a;
            b = test_b;
            #1;
            check_value(name, c, expected_c);
            if (br !== expected_br) begin
                $display("FAIL %0s branch: actual=%b expected=%b", name, br, expected_br);
                failures = failures + 1;
            end
        end
    endtask

    task check_mul_div;
        input [255:0] name;
        input [4:0] test_op;
        input [31:0] test_a;
        input [31:0] test_b;
        input [31:0] expected;
        integer cycles;
        begin
            @(negedge clk);
            op = test_op;
            a = test_a;
            b = test_b;
            @(posedge clk);
            @(negedge clk);
            op = `ALU_ADD;
            a = 32'h0;
            b = 32'h0;
            cycles = 0;
            while (busy && cycles < 80) begin
                @(negedge clk);
                cycles = cycles + 1;
            end
            #1;
            check_value(name, c, expected);
            if (cycles >= 80) begin
                $display("FAIL %0s: operation timed out", name);
                failures = failures + 1;
            end
            @(posedge clk);
        end
    endtask

    task check_decode;
        input [255:0] name;
        input [6:0] test_opcode;
        input [2:0] test_funct3;
        input [6:0] test_funct7;
        input [4:0] expected_alu;
        input [1:0] expected_npc;
        input expected_rf_we;
        input expected_mul;
        input expected_div;
        begin
            opcode = test_opcode;
            funct3 = test_funct3;
            funct7 = test_funct7;
            #1;
            if ((alu_op !== expected_alu) || (npc_op !== expected_npc)
                || (rf_we !== expected_rf_we) || (is_mul !== expected_mul)
                || (is_div !== expected_div)) begin
                $display("FAIL %0s decode: alu=%h npc=%h rf_we=%b mul=%b div=%b",
                         name, alu_op, npc_op, rf_we, is_mul, is_div);
                failures = failures + 1;
            end
        end
    endtask

    initial begin
        repeat (2) @(posedge clk);
        rst = 1'b0;

        check_decode("ADD regression", 7'b0110011, 3'b000, 7'b0000000,
                     `ALU_ADD, `NPC_PC4, 1'b1, 1'b0, 1'b0);
        check_decode("AND", 7'b0110011, 3'b111, 7'b0000000,
                     `ALU_AND, `NPC_PC4, 1'b1, 1'b0, 1'b0);
        check_decode("SLTIU", 7'b0010011, 3'b011, 7'b1111111,
                     `ALU_SLTU, `NPC_PC4, 1'b1, 1'b0, 1'b0);
        check_decode("BLT", 7'b1100011, 3'b100, 7'b0000000,
                     `ALU_LT, `NPC_BRA, 1'b0, 1'b0, 1'b0);
        check_decode("BGEU", 7'b1100011, 3'b111, 7'b0000000,
                     `ALU_GEU, `NPC_BRA, 1'b0, 1'b0, 1'b0);
        check_decode("MULHU", 7'b0110011, 3'b011, 7'b0000001,
                     `ALU_MULHU, `NPC_PC4, 1'b1, 1'b1, 1'b0);
        check_decode("REM", 7'b0110011, 3'b110, 7'b0000001,
                     `ALU_REM, `NPC_PC4, 1'b1, 1'b0, 1'b1);

        check_comb("AND result", `ALU_AND, 32'hf0f0_aa55, 32'h0ff0_0f0f,
                   32'h00f0_0a05, 1'b0);
        check_comb("OR result", `ALU_OR, 32'hf000_00f0, 32'h0f00_0f00,
                   32'hff00_0ff0, 1'b0);
        check_comb("SLT signed", `ALU_SLT, 32'hffff_ffff, 32'h0000_0001,
                   32'h0000_0001, 1'b0);
        check_comb("SLTU unsigned", `ALU_SLTU, 32'hffff_ffff, 32'h0000_0001,
                   32'h0000_0000, 1'b0);
        check_comb("BLT signed", `ALU_LT, 32'h8000_0000, 32'h0000_0000,
                   32'h0000_0000, 1'b1);
        check_comb("BGEU unsigned", `ALU_GEU, 32'hffff_ffff, 32'h0000_0001,
                   32'h0000_0000, 1'b1);

        check_mul_div("MUL negative", `ALU_MUL, 32'hffff_fffa, 32'h0000_0007,
                      32'hffff_ffd6);
        check_mul_div("MULH negative", `ALU_MULH, 32'hffff_fffa, 32'h0000_0007,
                      32'hffff_ffff);
        check_mul_div("MULHU", `ALU_MULHU, 32'hffff_ffff, 32'h0000_0002,
                      32'h0000_0001);
        check_mul_div("DIV signed", `ALU_DIV, 32'hffff_ffec, 32'h0000_0003,
                      32'hffff_fffa);
        check_mul_div("REM signed", `ALU_REM, 32'hffff_ffec, 32'h0000_0003,
                      32'hffff_fffe);
        check_mul_div("DIVU", `ALU_DIVU, 32'hffff_ffff, 32'h0000_0002,
                      32'h7fff_ffff);
        check_mul_div("REMU", `ALU_REMU, 32'hffff_ffff, 32'h0000_0002,
                      32'h0000_0001);
        check_mul_div("DIV by zero", `ALU_DIV, 32'h8000_0001, 32'h0000_0000,
                      32'hffff_ffff);
        check_mul_div("REM by zero", `ALU_REM, 32'h8000_0001, 32'h0000_0000,
                      32'h8000_0001);
        check_mul_div("DIV overflow", `ALU_DIV, 32'h8000_0000, 32'hffff_ffff,
                      32'h8000_0000);
        check_mul_div("REM overflow", `ALU_REM, 32'h8000_0000, 32'hffff_ffff,
                      32'h0000_0000);

        if (failures == 0)
            $display("RTL_MERGE_TEST_PASS");
        else
            $display("RTL_MERGE_TEST_FAIL count=%0d", failures);
        $finish;
    end
endmodule
