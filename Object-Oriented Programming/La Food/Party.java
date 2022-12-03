import java.util.*;
import java.io.*;

public class Party
  {
    
  /**
	A class to create and access individual Parties
	@author Reece Parks and my partner Matt Fleschner
	*/
	
    
   public int time;
   public int numPeople;
   public String name;


    /**
     @param file to create a party by reading from file
      A funtion to create a party
    */
  public Party (Scanner file)
   {
  
    time = file.nextInt();
    numPeople = file.nextInt();
    name = file.nextLine();
   }


  /** A function to return the time */
	public int getTime() {return time;}
    /** A function to return the number of people */
	public int getNumPeople() {return numPeople;}
    /** A function to return the name of the party */
	public String getName() {return name;}

    /** A function to print the details of the party */
    public String toString()
    {
      return "  party" + name + " of " + numPeople + " people. ";
    }
  }