// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.


@SCREEN
D=A	

@iteration
M=D

@8192 
D=A

@SCREEN
D=D+A

@max
M=D


(BEGIN)
@KBD //see if key is being pressed
D=M
@CLEAR
D;JEQ //if no key is pressed, clear
@FILL
0;JMP //if it is, go to fill

(FILL)	
@iteration //fill one pixel
A=M
M=-1	
@INC //go to increment
0;JMP

(CLEAR)
@iteration //clear a pixel back to white
A=M
M=0
@INC //go to increment

(INC)
@iteration //increase current iteration
D=M+1
M=D

@max 
D=D-M
@BEGIN
D;JNE //reset if greater than the max, if not don't reset


@SCREEN //go back to start
D=A
@iteration
M=D
@BEGIN
0;JMP 