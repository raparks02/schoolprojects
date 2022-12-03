import java.util.*;
import java.io.*;

class partyMain
{

  /**
	A class read and queue people from a file in order to properly seat them at a table
	@author Reece Parks and my partner Matt Fleschner	*/

  
	public static void main(String [] args) throws IOException
	{
		String filename;
		boolean open = true;
		int count;
		double wait = 0;
		double average;
		char letter;
		double total = 0;
		Party lead;
		
		System.out.println("*** Welcome to the La Food Restaurant Simulator ***\n");

    //get name of file
		Scanner cin = new Scanner(System.in);
		System.out.print("Enter data file name: ");
		filename = cin.next();
   	 	System.out.println();
		
		Scanner file = new Scanner(new FileReader(filename));
		
		Queue list = new QueueLL();
	
		
		do
		{
			//read the first letter
     		letter = file.next().charAt(0);

     	   //if file reads an A
			if(letter == 'A')
			{
				lead = new Party(file);
				System.out.println("Please wait at the bar, ");
				list.enqueue(lead);
				System.out.print(lead); //print out the details of the new party and add to queue
				System.out.println(" (time=" + lead.getTime() + ")");
        		wait = wait - lead.getTime();
			}
        //if file reads in T, a table is avaliable
			else if(letter == 'T')
			{
				int t = file.nextInt();
				lead = (Party) list.getFront(); 
				System.out.println("Table for" + lead.getName() + "!" + " (time=" + t + ")");
				wait += t;
				total++;

				list.dequeue();
			}
        //if file reads in Q
			else if(letter == 'Q')
			{
				System.out.println("** Simulation Terminated **");
				open=false;
        //end of simulation
			}
			else
			{
				// nothing happens
			}
			
			
		}while(open);
		lead = (Party) list.getFront();
		average = ((float)wait + lead.getTime())/ (float) total; //get average
		System.out.println("\nThe average wating time was: " + average );
		System.out.println("The following parties were never seated: " );
		for(int i = 0; i <= list.size();i++)
		{
			lead = (Party) list.getFront();
      		System.out.println(lead); //getting table that is still not seated
      		list.dequeue();
		}
		System.out.println("\nHave a nice meal!");
	}
}