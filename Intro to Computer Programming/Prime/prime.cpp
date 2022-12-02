// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// raparks

#include <iostream>

bool isPrime(int enteredNumber); //function to test if enteredNumber is prime
void printPrimeNumbers(int enteredNumber); //function to print prime numbers
int howManyPrime(int enteredNumber, int & total); //function to show total prime numbers from 0 to entered number

int main()
{
	char continueGame(' '); //character for continuing game
	char seeNumbers(' '); //character for seeing prime numbers
	int enteredNumber(0); //intital integer input
	bool prime(false); //prime or not
	int complete(0); //complete a playthrough
	int total(0); //total prime numbers
	
	//welcome player
	std::cout << "Welcome to Reece's Prime Calculator!" << std::endl;
	std::cout << std::endl;
	do //always runs one time
	{
		
		complete = 0; //makes sure complete playthrough has not occured
		
		//enter number
		std::cout << "Please enter a number: ";
		std::cin >> enteredNumber;
		std::cout << std::endl;
		
		//make prime equal to the return of isPrime function
		prime = isPrime(enteredNumber);
		
		if(prime) //if number is prime
		{
			//states that number is prime
			std::cout << enteredNumber << " is a prime number!" << std::endl;
			std::cout << std::endl;
			
		}
		else
		{
			//nothing happens
		}
		if(enteredNumber == 0 || enteredNumber == 1) //if enteredNumber is 0 or 1
		{
			//0 and 1 are the smallest possible enteredNumbers
			std::cout << "No prime numbers were found!" << std::endl;
			std::cout << std::endl;
			complete = 1;
		}
		else if(enteredNumber == 2) //if enteredNumber is 2
		{
			//2 is the smallest prime number
			std::cout << enteredNumber << " is the smallest prime number!" << std::endl;
			std::cout << std::endl;
			complete = 1;
		}
		else
		{
			total = 0; //reset total to 0
			
			//go to howManyPrime function
			howManyPrime(enteredNumber, total);
			
			//print out total prime numbers from 0 to enteredNumber
			std::cout << "\t" << "There are " << total << " prime numbers between 0 and " << enteredNumber << std::endl;
			std::cout << std::endl;
			
			//ask the player if they want to see the numbers
			std::cout << "Would you like to see the numbers - (Y)es or (N)o? ";
			std::cin >> seeNumbers;
			std::cout << std::endl;
		
			
			if(seeNumbers == 'Y' || seeNumbers == 'y') //if player chooses yes
			{
				//go to function printPrimeNumbers
				printPrimeNumbers(enteredNumber);
				complete = 1;
				
				
				
			}
			else if(seeNumbers == 'N' || seeNumbers == 'n') //if player chooese no
			{
				//nothing happens 
				complete = 1;
			}
			else
			{
				//nothing happens as invalid input
			}
		}
			
		while(complete == 1 ) //while a playthrough is complete
		{
			//ask the player if he or she would like to continue
			std::cout << "Would you like to continue - (Y)es or (N)o? ";
			std::cin >> continueGame;
			std::cout << std::endl;
			
			if(continueGame == 'Y' || continueGame == 'y') //if player chooses yes
			{
				// nothing happens returns to do while loop
				complete = 0;
			}
			else if(continueGame == 'N' || continueGame == 'n') //if player chooses no
			{
				//thanks the player for running the program and terminates
				complete = 0; 
				std::cout << "Thank you for running my program - goodbye!" << std::endl;
			}
			else
			{
					//nothing happens as invalid input
					complete = 0;
			}
		}
		
	
		
		
	}while(continueGame == 'Y' || continueGame == 'y'); //while the player chooses to continue
	
	return 0;
}


bool isPrime(int enteredNumber)
{
	int x(0); //integer for factors of enteredNumber
	
	
	if (enteredNumber == 0 || enteredNumber == 1) //if the number is 0 or 1
	{
		return false;//not prime
	}
	else
	{
		for(x = 2; x <= enteredNumber / 2; ++x) //for loop for finding if enteredNumber has factors
		{
			if(enteredNumber % x == 0) //if there is no remainder between enteredNumber and possible factor
			{
				return false; //not prime
			}
			else
			{
				// nothing happens
			}
		}
	}
	return true; //is prime
}

void printPrimeNumbers(int enteredNumber)
{

	int count(0); //numbers from 0 to enteredNumber
	bool primeCount(false); //deciding if count is prime or not
	
	
	
	
	std::cout << '\t' << "The number(s) are: ";
	while(count < enteredNumber) //while count is less than enteredNumber
	{
		primeCount = isPrime(count); //primeCount is made equal to the isPrime return for count
		if(primeCount) //if count is prime
		{
			//display count
			std::cout << count << " ";
			
		}
		else
		{
			//nothing happens
		}
		//increase count by one with post-decrement
		count++;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	
}
int howManyPrime(int enteredNumber, int & total)
{
	int count(0); //numbers from 0 to enteredNumber
	bool primeCount(false); //deciding if count is prime or not
	
	while(count < enteredNumber) //while count is less than enteredNumber
	{
		primeCount = isPrime(count); //primeCount is made equal to the isPrime return for count
		if(primeCount) //if count is prime
		{
			total++; //increase total numbers by one
			
		}
		else
		{
			//nothing happens
		}
		//increase count by one with post-decrement
		count++; 
	}
		
	return total; 
}