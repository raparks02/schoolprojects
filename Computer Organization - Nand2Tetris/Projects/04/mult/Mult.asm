// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)
//
// This program only needs to handle arguments that satisfy
// R0 >= 0, R1 >= 0, and R0*R1 < 32768.

// Put your code here.

@R2 //R2 starts at 0
M=0

@R0 //if R0 > 0 jump to loop
D=M
@LOOP
D;JGT

@END //if it isn't go to END 
0;JMP

(LOOP) //Add R1 to R2 & subtract from R0
@R2 //get R2
D=M 

@R1 //Add R1 to R2
D=D+M

@R2 //set that to R2
M=D


@R0 //subtract 1 from R0
D=M-1
M=D

@LOOP //if R0 is still greater than 0, continue loop
D;JGT

(END)
@END
0;JMP