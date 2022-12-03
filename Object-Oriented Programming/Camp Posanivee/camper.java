import java.io.*;
import java.util.*;
public class camper implements Comparable{
 /** 
	 A class to create and access individual campers
@author Reece Parks and my Partner Matt Fleschner 
 */
  String name;
  int age;
  char diet;
  String empty;

  /** 
	  @param file text file of commands
function to create a camper object
 */
  public camper(Scanner file)
  {
    if (file.hasNext())
    {
      name = file.next();
      if (file.hasNextInt())
      {
        age = file.nextInt();
        if (file.hasNext())
        {
          diet = file.next().charAt(0);
          //empty = file.nextLine();
        }
      }
    }
    else {
      //empty = file.nextLine();
    }
  }
  /** 
@param n name 
@param a age
@param d diet
Function to create a camper object
 */
  public camper (String n, int a, char d)
  {
    name = n;
    age = a;
    diet = d;
  }
/** A function to return name */
  public String getName() { return name; }
  /** A function to return age */
  public int getAge() { return age; }
  /** A function to return diet */
  public char getDiet() { return diet; }
/** A function to make the class comparable */
  public int compareTo(Object x)
  {
    camper temp = (camper) x;
    return name.compareTo(temp.name);
    
  }
      public String toString()
    {
        return name + " " + age + " " + diet;
    }
  
}