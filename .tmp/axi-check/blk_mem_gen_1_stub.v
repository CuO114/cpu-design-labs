module blk_mem_gen_1 (
    input  wire         clka,
    input  wire         wea,
    input  wire [  5:0] addra,
    input  wire [133:0] dina,
    output wire [133:0] douta
);
    assign douta = 134'h0;
endmodule
