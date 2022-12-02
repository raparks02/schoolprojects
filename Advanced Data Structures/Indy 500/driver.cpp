// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// raparks

#include <iostream>
#include <fstream>
#include "Car.h"

void simulateRace(Car racers[]);

int main()
{

	std::cout << "***Welcome to the 2022 Indianapolis 500!***" << std::endl;
	//input file stream
	std::ifstream inputFile;
	
	//variable declaration
	int count(0);
	int speed(0);
	int control(0);
	int lapNumber(0);
	std::string name(" ");
	Car racers[33];
	
	//open file
	inputFile.open("indy500.txt");
	
	if(inputFile.is_open()) //if file is open
	{
		
		while(!inputFile.eof()) //while not at the end of file
		{
			//take in the name, speed, and control from text file
			inputFile >> name;
			inputFile >> speed;
			inputFile >> control;
			
			//using file to set values for the car and then move on to the next
			racers[count].setName(name);
			racers[count].setSpeed(speed);
			racers[count].setControl(control);
			racers[count].setLapNum(0);
			count++; //increase to move on to next racer
			
		}
		inputFile.close(); //close file
	}
	simulateRace(racers); //go to simulateRace to get winner 
	
	std::cout << "Driver Name: Lap Number" << std::endl;
	std::cout << "********************" << std::endl;
	
	for(int i=0; i<33; i++) //for loop for listing drivers and their lap numbers
	{
		name = racers[i].getName();
		lapNumber = racers[i].getLapNum();
		std::cout << name << ": " << lapNumber << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Thank you for using my race simulation program - goodbye!" << std::endl;
	
	return 0;
}
void simulateRace(Car racers[])
{
	//variable declaration
	bool complete(false);
	int speed(0);
	int control(0);
	int lapNumber(0);
	std::string name(" ");
	std::string winner(" ");
	
	//seeding the random number
	srand((unsigned) time(0));
	int randNumber(0);
	
	
	while(complete == false) //while the race is not complete
	{
		for(int i=0; i<33; i++) //forloop for going through the racers/cars
		{
			control = racers[i].getControl();
			speed = racers[i].getSpeed();
			lapNumber = racers[i].getLapNum();
			
			if(control > 5) //if control is greater than 5
			{
				randNumber = (rand() % 10) + 1; //set to random number
				racers[i].setLapNum(lapNumber+(control/randNumber) + speed); //current lap number gets added to speed along with control/random number
					
			}
			else
			{
				racers[i].setLapNum(lapNumber + speed); //current lap number gets added to speed
			}
			lapNumber = racers[i].getLapNum(); //get lapNumber again
			if(lapNumber >= 200) //if the race is over
			{
				winner = racers[i].getName(); //get name of winner
				racers[i].setLapNum(200); //can't be over lap 200
				complete = true;
				break; //quit the for loop since someone has beaten the race
			}
			else if(lapNumber % 100 == 0) //if lap is divisble by 100, print statement
			{
				std::cout << "***--> Racing..." << std::endl;
			}
			else
			{
				//nothing
			}
		}
	}
	std::cout << std::endl;
	std::cout << "\t ***" << winner << " has won the 2022 Indianapolis 500! ***" << std::endl;
	//void function so nothing returns and go back to main
	
	
	
}