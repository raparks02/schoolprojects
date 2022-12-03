//Program by Reece Parks, Partner: Matt Fleschner
//Program to have the player guess a computer's number

import java.io.*;
import java.util.*;

class guessinggame
{
	static void guess() //void function created for the guessing of the number along with insults
	{
		int number;
		int guess = 0;
		int insultNumber;
		
		//creating string array of insults
		String [] insults = {"You suck!\n", "That's not right!\n", "You'll eventually get it!\n", "Try harder!\n", "Give up!\n" };
	
	System.out.println("I have a number between 1 and 100. Can you guess it?");
	number = (int)(1 + 100*Math.random()); //creating a random number for the player to guess
	
	
	Scanner cin = new Scanner(System.in);
	
	while(guess != number)
	{
		//using random number generator to pick one of five insults from the array
		insultNumber = (int)(1 + 5*Math.random());
		insultNumber--; //subtract 1 as arrays start at 0
		
		//enter a guess
		System.out.print("\nEnter a guess: ");
		guess= cin.nextInt();
		
		//if else statement for if guess is right, too high or too low 
		if(guess == number)
		{
			//print out win
      System.out.println("You Win!!\n");
		
		}
		else if(guess > number)
		{
			//print out too high and insult
      System.out.print("Too High, ");
			System.out.print(insults[insultNumber]);
		}
		else
		{
			//print out too low and insult
      System.out.print("Too Low, ");
			System.out.print(insults[insultNumber]);
		}
	
	}
		
	
	
	}
	public static void main(String [] args) //main function to welcome and ask to play again
	{
		char playAgain = 'Y';

		Scanner cin=new Scanner(System.in);
		System.out.println("***Welcome to the GUESSING GAME!!***\n");
		
		while(playAgain == 'Y' || playAgain == 'y') //while the player want to play again
		{
			guess(); //go to guess function

			System.out.print("Would you like to play again? (Y)es or (N)o? ");
		
    	playAgain = cin.next().charAt(0);
			System.out.println(" ");
			
		}
		while(playAgain != 'Y' && playAgain != 'N' && playAgain != 'y' && playAgain != 'n') //while the player does not enter a correct character
		{
			System.out.println("Invalid input, enter 'Y', 'N', 'y', or 'n'. \n ");

			System.out.print("Would you like to play again? (Y)es or (N)o? ");
			playAgain = cin.next().charAt(0);
			System.out.println(" ");
		
		}
		
	
		System.out.println("Thank you for playing!");
	}

}
