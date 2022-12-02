// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// raparks

#include <iostream>
#include <string>
#include <cstring>
void reversedWord(char input[], int size); //function used to reverse word taking an array of characters and integer as size as parameters
int main()
{
	char word[100]; //word which is an array of characters of no more than 100 letters
	char answer(' '); // will be Y or N for continuing
	int complete(0); //integer to decide if a cycle is complete
	
	
	//Welcome the player to the program
	std::cout << "Welcome to Reece's Word Reversal Program!" << std::endl;
	std::cout << std::endl;
	
	
	do //do-while loop will run once no matter what
	{
	
		//Have the player enter a word which is an array of characters
		std::cout << "Please enter a word (100 Characters or less): ";
		std::cin >> word;
		std::cout << std::endl;
		
		//Go to reversed function using the entered word and the strlen(word) that will reverse the inputted array of charaters
		reversedWord(word, strlen(word));
		
		//tell the player the word spelled backwards
		std::cout << "Your word spelled backwards is: ";
		
		for(int i = 0; i < strlen(word); i++) //for integer starting at zero as is less than the strlen(word)
		{
			std::cout << word[i]; //display the word which will be reversed of what was entered due to reversedWord
		}
		std::cout << std::endl;
		std::cout << std::endl;
		
		//ask the player if he or she would like to continue
		std::cout << "Would you like to continue (Y|N)? ";
	
		//one completion
		complete = 1;
		
		while(complete == 1) //while there is a completion
		{
			//the player enters Y or N
			std::cin >> answer;
			std::cout << std::endl;
			
			if(answer == 'Y') //if the player answers Yes
			{
				// nothing happens this while loop ends and the do while continues
				complete = 0;
			}
			else if(answer == 'N') //if the player answers No
			{
				//Thank the player for running the program and terminate
				complete = 0;
				std::cout << "Thank you! Goodbye!" << std::endl;
			}
			else //Any other response
			{
				//Inform the player of an invalid response and have them enter again
				std::cout << "Invalid Input - Please enter 'Y' or 'N': ";
				
			}
		}
	
		
	}
	while(answer != 'N'); //while the player wishes to continue
	
	
	
	return 0;
}
void reversedWord(char input[],int size) //reversedWord recursive function
{
	
	
	char temporary(' '); //creating a temporary variable
	
	if(size <= strlen(input) - size) //if the parameter (size) is less than or equal to the string length of input minus the size
	{
		// nothing happens base case
	}
	else
	{
		
		//using recursion to reverse the string using a temporary variable character
		temporary = input[strlen(input) - size];  
		input[strlen(input) - size] = input[size - 1];
		input[size - 1] = temporary;
		
		//perform the reversedWord again but the size parameter goes down by one
		reversedWord(input, size - 1);
		
		//eventually the entered word will reach the base case and stop
		
	}
}