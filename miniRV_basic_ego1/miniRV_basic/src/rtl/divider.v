`timescale 1ns / 1ps

module divider #(
    parameter WIDTH = 32
)(
    input  wire       clk,
    input  wire       rst,
    input  wire [WIDTH-1:0] x,
    input  wire [WIDTH-1:0] y,
    input  wire       start,
    output reg  [WIDTH-1:0] z,
    output reg  [WIDTH-1:0] r,
    output reg        busy     
);

    reg [WIDTH-1:0] dividend;
    reg [WIDTH-1:0] divisor;
    reg [WIDTH-1:0] quotient;
    reg [WIDTH:0]   remainder;
    integer         count;

    wire [WIDTH:0] remainder_shift = {remainder[WIDTH-1:0], dividend[WIDTH-1]};
    wire             subtract_divisor = remainder_shift >= {1'b0, divisor};
    wire [WIDTH:0]   remainder_next = subtract_divisor
                                      ? remainder_shift - {1'b0, divisor}
                                      : remainder_shift;
    wire [WIDTH-1:0] quotient_next = {quotient[WIDTH-2:0], subtract_divisor};

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            z         <= {WIDTH{1'b0}};
            r         <= {WIDTH{1'b0}};
            busy      <= 1'b0;
            dividend  <= {WIDTH{1'b0}};
            divisor   <= {WIDTH{1'b0}};
            quotient  <= {WIDTH{1'b0}};
            remainder <= {(WIDTH+1){1'b0}};
            count     <= 0;
        end else if (start && !busy) begin
            if (y == {WIDTH{1'b0}}) begin
                z    <= {WIDTH{1'b1}};
                r    <= x;
                busy <= 1'b0;
            end else begin
                dividend  <= x;
                divisor   <= y;
                quotient  <= {WIDTH{1'b0}};
                remainder <= {(WIDTH+1){1'b0}};
                count     <= 0;
                busy      <= 1'b1;
            end
        end else if (busy) begin
            dividend <= {dividend[WIDTH-2:0], 1'b0};
            quotient <= quotient_next;
            remainder <= remainder_next;

            if (count == WIDTH-1) begin
                z    <= quotient_next;
                r    <= remainder_next[WIDTH-1:0];
                busy <= 1'b0;
            end else begin
                count <= count + 1;
            end
        end
    end
	
endmodule
