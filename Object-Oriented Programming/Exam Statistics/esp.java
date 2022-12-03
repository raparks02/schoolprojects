// Program by Reece Parks, Partner is Matt Fleschner
import java.io.*;
import java.util.*;

class esp
{

	static int[] getGrades(String fileName, int[] grades) //function created to get the letter grades using the scores from the file entered
	throws IOException
	{
		int count = 0;
		int [] letterGrades = new int[5]; //array of 5 for A,B,C,D,F grades
		Scanner file = new Scanner(new FileReader(fileName));	
		
		//run once to skip first line as that is count of grades
		file.nextInt();
		
		while(file.hasNextInt()) //while file has a next line to read
		{
			grades[count] = file.nextInt(); 
			
			if(grades[count] >= 90)  //if grade read is an A
			{
				letterGrades[0]++; //increase As by one
			}
			else if(grades[count] >= 80) //if grade read is a B
			{
				letterGrades[1]++; //increase Bs by one
			}
			else if(grades[count] >= 70) //if grade read is a C
			{
				letterGrades[2]++; //increase Cs by one
			}
			else if(grades[count] >= 60) //If grade read is a D
			{
				letterGrades[3]++; //increase Ds by one
			}
			else //If grade read is a F
			{
				letterGrades[4]++; //increase Fs by one
			}
			count++; //increase count to continue loop
		
		}
		return letterGrades; //return the array of letterGrades
		
	}
	static int getMinScore(int[] grades) //function created to get the mimimum score by taking in the array of grades
	{
		int smallest = grades[0]; //smallest is made equal to first position
		for(int i=0; i < grades.length; i++) //for loop with if statement to find minimum score
		{
			if(grades[i] < smallest) 
			{
				smallest = grades[i];
			}
		
		}
		return smallest; //return minimum
	
	}
	static int getMaxScore(int[] grades) //function created to get the maximum score by taking in the array of grades
	{
		int biggest = grades[0]; //biggest is made equal to first position
		for(int i=0; i < grades.length; i++) //for loop with if statment to find maximum score
		{
			if(grades[i] > biggest)
			{
				biggest = grades[i];
			}
		
		}
		return biggest; //return maximum
	}
	
	static double getAvgScore(int[] grades) //function created to find the average score by taking in the array of grades 
	{
		double avg;
		double sum = 0;
		for(int i=0; i < grades.length; i++) //for each position the grade gets added to the old sum to get a new sum
		{
			sum += grades[i];
		}
		avg = sum/grades.length; //divide sum by length for average
		
		return avg; //return average
	}
	static double getMedian(int[] grades) //function created to find the median score by taking in the array of grades
	{
		double median = 0;
		int temp;
		for(int i=0; i < grades.length; i++) //use two for loops with a temporary variable to sort the grades
		{
			for(int j= i+1; j < grades.length; j++)
			{
				if(grades[i] > grades[j])
				{
					temp = grades[i];
					grades[i] = grades[j];
					grades[j] = temp;
				}
			}
			
		}
		if(grades.length % 2 == 1) //if the amount of grades is odd(has a center grade)
		{
			median = grades[(grades.length + 1) / 2 - 1];
		}
		else //if the amount of grades is even
		{
			median = (grades[grades.length / 2 - 1] + grades[grades.length / 2]) / 2;
		}
		return median; //return median
	}
	static int getFileLength(String fileName)  //function used to get the length of the file using the entered file
	throws IOException
	{
		int count = 0;
		Scanner file = new Scanner(new FileReader(fileName)); 
		count = file.nextInt(); //reading the first line of file to know the count of scores
		return count; //returning back integer count
	}

		
	public static void main(String [] args) //main function to welcome the player and have them enter a file
	throws IOException
	{
		String fileName; //initializing variables
		int total;
			
		//welcome player
		System.out.println("***Welcome to the Exam Statistics Progam!!***\n");
			
		Scanner cin=new Scanner(System.in); //have them enter the name of the file
		System.out.print("Please enter the name of your data file: ");
		fileName = cin.next();
		
		//creating arrays for the letterGrades and grades(scores) while calling the getFileLength function
		int[] letterGrades = new int[getFileLength(fileName)];
		int[] grades = new int[getFileLength(fileName)];
			
		letterGrades = getGrades(fileName, grades); //letterGrades array is equal to the return of getGrades function
		total = letterGrades[0] + letterGrades[1] + letterGrades[2] + letterGrades[3] + letterGrades[4]; //total grades
		
		//print out each type of score and call its corresponding function to get score
		System.out.print("\nMinimum Score: " + getMinScore(grades));
		System.out.print("\nMaximum Score: " + getMaxScore(grades));
		System.out.print("\nAverage Score: " + getAvgScore(grades));
		System.out.print("\nMedian Score: " + getMedian(grades));
		
		//print out number of scores by letter grade
		System.out.println("\n\nNumber of Scores by Letter Grade: ");
		System.out.println("\tA: " + letterGrades[0]);
		System.out.println("\tB: " + letterGrades[1]);
		System.out.println("\tC: " + letterGrades[2]);
		System.out.println("\tD: " + letterGrades[3]);
		System.out.println("\tF: " + letterGrades[4]);
		
		//print out total scores
		System.out.println("There are " + total + " scores.");
	}
	
	

}