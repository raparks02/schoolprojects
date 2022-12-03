//Worked with Matt Fleschner
import java.util.*;
import java.io.*;


class SortMain
{
	
    /**
  	A class to run and test the speed of various sorting methods
  	@author Reece Parks and my partner Matt Fleschner	*/
	
	
  public static void main(String[] args) {
    int numInts;
    long start=0;
    long end;
    long length=0;
    boolean keepGoing = true;
    
    //creating a list of the amount of integers entered
	Scanner cin = new Scanner(System.in);
    System.out.print("How many integers would you like to sort? ");
    numInts = cin.nextInt();
    Integer [] list=new Integer[numInts];
    Integer [] list2=new Integer[numInts];

    //makes the list of integers be of random integers
	for (int i = 0; i<list.length; i++)
      {
        list[i] = (int)(Math.random()*(numInts+1));
      }
	  //prints the list if less than 100 integers
	if (list.length <= 100)
    {
      for (int i = 0; i < list.length; i++)
      {
        System.out.print(list[i] + " ");
      }
    }

	
    for (int sortNum = 0; sortNum <= 4; sortNum++)
      {
		  //makes a deep copy of the list
        for (int i = 0; i < list.length; i++)
          {
            list2[i] = list[i];
          }
        start = System.currentTimeMillis(); //start time
        if (sortNum == 0) //runs through one sort method at a time in the loop
        {
          System.out.println("***Bubble Sort***");
          Sorts.bubble(list);    
        }
        else if (sortNum == 1)
        {
          System.out.println("***Insertion Sort***");
          Sorts.insertion(list);
        }
        else if (sortNum == 2)
        {
          System.out.println("***Selection Sort***");
          Sorts.selection(list);
        }
        else if (sortNum == 3)
        {
          System.out.println("***Quick Sort***");
          Sorts.quick(list);
        }
        else if (sortNum == 4)
        {
          System.out.println("***Shell Sort***");
          Sorts.shell(list);
        }
        end = System.currentTimeMillis(); //end time
        for (int i = 0; i < list.length; i++) //make the deep copy back to original
          {
            list[i] = list2[i];
          }
        length = end - start; //get the time of sort
        System.out.println("Sort Time: " + length);
      }



    
    
  }
}