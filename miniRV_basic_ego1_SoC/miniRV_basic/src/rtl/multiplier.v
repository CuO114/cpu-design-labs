`timescale 1ns / 1ps

module multiplier #(
    parameter WIDTH = 32
)(
    input  wire        clk,
	input  wire        rst,
	input  wire [WIDTH-1:0] x,
	input  wire [WIDTH-1:0] y,
	input  wire        start,
	output reg  [2*WIDTH-1:0] z,
	output reg         busy
);

	localparam O_WID = 2*WIDTH;

    reg [O_WID-1:0] accumulator;
    reg [O_WID-1:0] multiplicand;
    reg [WIDTH-1:0] multiplier_mag;
    reg             negative;
    integer         count;

    wire [WIDTH-1:0] x_mag = x[WIDTH-1] ? (~x + 1'b1) : x;
    wire [WIDTH-1:0] y_mag = y[WIDTH-1] ? (~y + 1'b1) : y;
    wire [O_WID-1:0] add_result = accumulator
                                + (multiplier_mag[0] ? multiplicand : {O_WID{1'b0}});

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            z              <= {O_WID{1'b0}};
            busy           <= 1'b0;
            accumulator    <= {O_WID{1'b0}};
            multiplicand   <= {O_WID{1'b0}};
            multiplier_mag <= {WIDTH{1'b0}};
            negative       <= 1'b0;
            count          <= 0;
        end else if (start && !busy) begin
            accumulator    <= {O_WID{1'b0}};
            multiplicand   <= {{WIDTH{1'b0}}, x_mag};
            multiplier_mag <= y_mag;
            negative       <= x[WIDTH-1] ^ y[WIDTH-1];
            count          <= 0;
            busy           <= 1'b1;
        end else if (busy) begin
            if (count == WIDTH-1) begin
                z    <= negative ? (~add_result + 1'b1) : add_result;
                busy <= 1'b0;
            end else begin
                accumulator    <= add_result;
                multiplicand   <= multiplicand << 1;
                multiplier_mag <= multiplier_mag >> 1;
                count          <= count + 1;
            end
        end
    end
    
endmodule
