// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// raparks

#include <iostream>

int main()
{
	// Seeding the Random Number Generator
	srand((unsigned) time(0));
	
	double selectionNumber(0); //double for choosing which selection
	char playAgain(' '); //character for selecting Yes or No on play again question
	int tries(0); //integer for amount of tries for person or computer to guess
	int complete(0); //integer created to show completion and move on to play again while loop
	
	//Welcoming the player
	std::cout << "Welcome to the CS 142 Guess-o-Matic!" << std::endl;
	std::cout << std::endl;
	
	do //do while loop (runs one time no matter what)
	{
		//Displaying the two selections
		std::cout << "1. Human vs. CPU" << std::endl;
		std::cout << "2. CPU vs. Human" << std::endl;
		std::cout << std::endl;
	
		//Inputting a selection
		std::cout << "Selection: ";
		std::cin >> selectionNumber;
		std::cout << std::endl;
	
		if(selectionNumber == 1) //If selection 1 was chosen
		{
			//showing that number is between 1 and 100
			std::cout << "Ok...I have a random number between 1 and 100..." << std::endl;
			std::cout << std::endl;
		
			int randNumber(0); //integer for random number
			
			// Generating a random number between 1 and 100.
			randNumber = (rand() % 100) + 1;
			
			//resetting tries to 0
			tries = 0;
			
			double guess(0);  //double guessing computer's number
			
			while(guess != randNumber) //while entered guess is not the random number(loop)
			{
				//enter guess
				std::cout << "Please enter your guess: ";
				std::cin >> guess;
				std::cout << std::endl;
			
				//tries increases by one each time with post-increment
				tries++;
			
				if(guess > randNumber) //if guess is greater than random number
				{
					//inform that player is too high
					std::cout << "\t" << "You are too high!" << std::endl;
					std::cout << std::endl;
				}
				else if(guess < randNumber) //if guess is less than random number
				{
					//inform that player is too low
					std::cout << "\t" << "You are too low!" << std::endl;
					std::cout << std::endl;
				}
				else //guess is equal to random number and end of while loop
				{
					
					//inform that player is correct
					std::cout << "\t" << "CORRECT!!!" << std::endl;
					std::cout << std::endl;
				
					//show amount of guesses
					std::cout << "It took you " << tries << " total guesses!" << std::endl;	
					std::cout << std::endl;
					
					//moves to play again while loop
					complete = 1;
				}
			}
		
		} 
		else if(selectionNumber == 2) //if selection 2 was chosen
		{
			//resetting tries to 0
			tries = 0;
			
			char humanResponse(' '); //character for selecting High, Low, or Correct
			
			
			//Having the player think of a random number
			std::cout << "Please pick a random number between 1 and 100 for the CPU to guess." << std::endl;
			std::cout << std::endl;
			
			//Introducing both a maximum and minimum integer that random number could be
			int max(100);
			int min(1);
			
			while(humanResponse != 'C' && humanResponse != 'c') //while random number is not correct
			{
				
				//introducing computer's guess as an integer that is the average of the max and min
				int cpuGuess(0);
				//formula for average
				cpuGuess = (max + min) / 2;
				
				//CPU's initial guess(always 50)
				std::cout << "\t" << "CPU Guess: " << cpuGuess << std::endl;
				std::cout << std::endl;
				
				//player inputs if too high, correct, or too low
				std::cout << "Please respond - (H)igh, (L)ow, or (C)orrect: ";
				std::cin >> humanResponse;
				if(humanResponse == 'H' || humanResponse == 'h') //if computer's guess is too high
				{
					//average(cpuGuess) becomes the new max but subtract one to counter decimals
					max = cpuGuess - 1;
					
					//tries increases by one each time with post-increment
					tries++;
				}
				else if(humanResponse == 'L' || humanResponse == 'l') //if computer's guess is too low
				{
					//average(cpuGuess) becomes new min but add one to counter decimals
					min = cpuGuess + 1;
					
					//tries increases by one with post-increment
					tries++;
				}
				else if(humanResponse == 'C' || humanResponse == 'c') //If computer's guess is correct
				{
					//CPU guesses correctly
					std::cout << "\t" << "The CPU guessed your number!" << std::endl;
					std::cout << std::endl;
				
					//Display tries + the initial one
					std::cout << "It took the CPU " << tries + 1 << " total guesses!" << std::endl;
					std::cout << std::endl;
					
					//moves to play again while loop
					complete = 1;
				
				}
				else
				{
					//Invalid input entered
					std::cout << "\t" << "Invalid Input!" << std::endl;
					std::cout << std::endl;
				}
				
			}
		
			
		
		}
		else
		{
			//invalid selection entered
			std::cout << "Invalid Selection!" << std::endl;
			std::cout << std::endl;
			
			//moves to play again while loop
			complete = 1;
		}
		
		while(complete == 1) //after the completion of one of the selections
		{
			//ask the player to play again and allow them to input a yes or no through a character
			std::cout << "Play again? (Y)es or (N)o: ";
			std::cin >> playAgain;
			std::cout << std::endl;
		
			if(playAgain == 'N' || playAgain == 'n') //if the player chooses no
			{
				//thank the player for playing
				std::cout << "Thank you for playing CS 142 Guess-o-Matic - Goodbye!" << std::endl;
				complete = 0;
			}
			else if(playAgain == 'Y' || playAgain == 'y') //if the player chooses yes
			{
		
				//nothing is printed and goes back to yes while loop(mode selection)
				complete = 0;
			}	
			else
			{
				//invalid selection entered
				std::cout << "Invalid Selection!" << std::endl;
				std::cout << std::endl;
				
			}
		}
		
		
			
	}while(playAgain == 'Y' || playAgain == 'y');	//while the player chooses yes
		
	
	
	return 0;
}