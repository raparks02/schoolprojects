// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// raparks

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void calculateLetterGrade(double score, char & letterGrade); //function for calculating letter grade
int main()
{
	double score(0); //number score
	char letterGrade(' '); //character letter grade
	std::string stringNumber(" "); //strings that will be converted to numbers
	std::string stringWord(" "); //string that is a whole line
	std::string fileName(" "); //file name person inputs that already exists with grades
	std::string fileNameTwo(" "); //second file that is created with grade and letter
	double number(0); //turning stringNumber into an actual number
	
	//scores from each category
	double assignmentScore(0);
	double participationScore(0);
	double midtermScore(0);
	double finalScore(0);
	
	
	//welcome person to calculator
	std::cout << "Welcome to Reece's Grade Calculator" << std::endl;
	std::cout << std::endl;
	
	//have person enter file 
	std::cout << "Please enter the file you wish to open: ";
	std::cin >> fileName;
	std::cout << std::endl;
	
	//input file stream
	std::ifstream inputFile;
	
	//open file
	inputFile.open(fileName);
	
	if(inputFile.is_open()) //if file is open
	{
		//used to convert strings from files
		std::stringstream converter;
		std::stringstream extraStream;
		
		//tell the person it is reading from file
		std::cout << "Reading from file " << fileName << "..." << std::endl;
		std::cout << std::endl;
		
		//calculate grades
		std::cout << "Calculating grades..." << std::endl;
		std::cout << std::endl;
		
		
		while(!inputFile.eof()) //while not at end of file
		{

			std::string category(" "); //string for weight or category
			double total(0); //total grade from category
			double count(0); //amount of grades from category
			
			std::getline(inputFile,category); //get line of input file and store as category string
			std::getline(inputFile,stringWord); //get line of input file and store as string Word
		
			extraStream.clear();
			extraStream.str(" ");
			extraStream << stringWord; //allows get line function to be done on entire line
			
			while(std::getline(extraStream, stringNumber, ',')) //each number will be a string from that entire line (',' delimiter)
			{
				converter.clear(); //converting to actual numbers
				converter.str(" ");
				converter << stringNumber; 
				converter >> number;
				
				//increase count by one
				count++;
				//total is the sum of last total and next number
				total = total + number;
			}
			if(category == "Assignments") //if weight is assignments
			{
				//assignment score is average and weighted at 50%
				assignmentScore = (total / count) * .5;
				
			}
			else if(category == "Participation") //if weight is participation
			{
				//participation score is average and weighted at 10%
				participationScore = (total / count) * .1;
				
			}
			else if(category == "Midterm") //if weight is midterm
			{
				//midterm score is average and wighted at 20%
				midtermScore = (total / count) * .2;
			}
			else if(category == "Final") //if weight is final
			{
				//final score is average and weighted at 20%
				finalScore = (total / count) * .2;
			}
			else
			{
				
			}
		}
		
		inputFile.close(); //close file
	
		//total score is scores added together
		score = assignmentScore + participationScore + midtermScore + finalScore;
		
		//variables created to truncate to one decimal place
		double cutOff(0); 
		int tempVariable(0);
		cutOff = 0.1;
		tempVariable = score / cutOff;
		
		//used to truncate score to one decimal place
		score = tempVariable * cutOff;
	
		//go to function calculateLetterGrade
		calculateLetterGrade(score, letterGrade);
	
		//Person chooses a file name to be created
		std::cout << "Save to (Filename): ";
		std::cin >> fileNameTwo;
		std::cout << std::endl;
	
		//output file stream
		std::ofstream outputFile(fileNameTwo);
		
		//output score and letterGrade to file
		outputFile << score << "\t" << letterGrade;
		
		//close file
		outputFile.close();
	
		//repeat where score and letter grade was written to
		std::cout << "Score & Letter Grade written to file: " << fileNameTwo << std::endl;
		std::cout << std::endl;			
			
	}
	else
	{
		//tell the person the file can not be opened 
		std::cout << "Unable to open file" << std::endl;
		std::cout << std::endl;
	}
	
	//thank the person for using program
	std::cout << "Thank you for using my program - good bye!" << std::endl;
	
	return 0;
}
void calculateLetterGrade(double score, char & letterGrade) //void function for finding letterGrade
{
	if(score >= 90) // if score is greater or equal to 90
	{
		letterGrade = 'A'; //grade is A
		
	}
	else if(score < 90 && score >= 80) //grade is less than 90 and greater than or equal to 80
	{
		letterGrade = 'B'; //grade is B
	
	}
	else if(score < 80 && score >= 70) //grade is less than 80 and greater than or equal to 70
	{
		letterGrade = 'C'; //grade is C
	
	}
	else if(score < 70 && score >= 60) //grade is less than 70 and greater than or equal to 60
	{
		letterGrade = 'D'; //grade is D
	
	}
	else //any other grade
	{
		letterGrade = 'F'; //grade is F
	}
	
	
	
}
