// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// raparks

#include <iostream> 
#include <string>

int main()
{
	// Use of two strings (name and color) and a double for the mathematical questions
	std::string name("");
	std::string color("");
	double mathAnswer(0);
	
	// Welcoming the player
	std::cout << "Welcome to Reece's Monty C++ Text-based Adventure!" << std::endl;
	std::cout << std::endl;
	
	// Asking for the player's name
	std::cout << "WHAT is your name? ";
	// Allowing name to be inputted
	std::cin >> name;
	std::cout << std::endl;
	
	// Tab over and welcoming the player
	std::cout << "\t" << "Welcome Sir " << name << "!" << std::endl;
	std::cout << std::endl;
	
	// Displaying mathematical query
	std::cout << "WHAT is the result of 2 + 3? ";
	// Allowing input of answer (double)
	std::cin >> mathAnswer;
	std::cout << std::endl;
	
	if(mathAnswer == 5) // If inputted answer is correct (5)
	{
		// Tab over and display correct to the player
		std::cout << "\t" << "CORRECT Sir " << name << "!" << std::endl;
		std::cout << std::endl;
		
		// Displaying mathematical query
		std::cout << "WHAT is the result of 2 + 5 * 3 / (9 + 3)? ";
		// Allowing input of asnwer (double)
		std::cin >> mathAnswer;
		std::cout << std::endl;
		
		if(mathAnswer == 3.25) // If inputted answer is correct (3.25)
		{
			// Tab over and display correct to the player
			std::cout << "\t" << "CORRECT Sir " << name << "!" << std::endl;
			std::cout << std::endl;
			
			// Displaying question asking for favorite color
			std::cout << "WHAT is your favorite color? ";
			// Allowing input of response (string)
			std::cin >> color;
			std::cout << std::endl;
			
			if(color == "Blue" || color == "blue") // If response is correct (Blue or blue)
			{
				// Tab over and display correct to the player
				std::cout << "\t" << "CORRECT Sir " << name << "!" << std::endl;
				std::cout << std::endl;
				
				// Display question asking for velocity
				std::cout << "WHAT is the airspeed velocity of an unladen swallow? ";
				// Allow input of answer (double)
				std::cin >> mathAnswer;
				std::cout << std::endl;
				
				if((int)mathAnswer % 2 == 1) // Allow mathAnswer variable to be an integer. Then only let integers with remainders of 1 after being divided by 2 be correct (odd numbers).
				{
					// Tab over and display correct to the player
					std::cout << "\t" << "I, I don't know that!" << std::endl;
					std::cout << std::endl;
					
					// Display CPU Wizard being casted
					std::cout << "The CPU Wizard is cast into the Gorge of Eternal Peril!" << std::endl;
					std::cout << std::endl;
					
					// Congratulate player
					std::cout << "Congratulations Sir " << name << " " << "you won!!" << std::endl;
					std::cout << std::endl;
					
				}
				else // Entered number is not odd
				{
					// Display incorrect/taunt player
					std::cout << "\t" << "That is definitely INCORRECT! WRONG!" << std::endl;
					std::cout << std::endl;
					// Display player loses
					std::cout << "You have been cast into the Gorge of Eternal Peril!" << std::endl;
					std::cout << std::endl;
				}
			}
			else //Entered string is not blue or Blue
			{
				// Display incorrect/taunt player
				std::cout << "\t" << "HA! HA! What a weak attempt! WRONG!" << std::endl;
				std::cout << std::endl;
				
				// Display player loses
				std::cout << "You have been cast into the Gorge of Eternal!" << std::endl;
				std::cout << std::endl;
			}
		}	
		else //Entered double is not 3.25
		{
			// Display incorrect/taunt player
			std::cout << "\t" << "NO, NO, NO! WRONG!" << std::endl;
			std::cout << std::endl;
			
			// Display player loses
			std::cout << "You have been cast into the Gorge of Eternal!" << std::endl;
			std::cout << std::endl;
		}
	}
	else // Entered double is not 5
	{
		// Display incorrect/taunt player
		std::cout << "\t" << "WRONG!" << std::endl;
		std::cout << std::endl;
		
		// Display player loses
		std::cout << "You have been cast into the Gorge of Eternal!" << std::endl;
		std::cout << std::endl;
	}
	
	// Display thanks for playing
	std::cout << "Thank you for playing my Monty C++ Sir " << name << ". " << "Intermission..." << std::endl;
	
	return 0;
}