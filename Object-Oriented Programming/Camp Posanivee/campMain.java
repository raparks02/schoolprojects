//Worked with Matt Fleschner
import java.util.*;
import java.io.*;

class campMain {
  /** 
  A class that uses binary search trees to maintain campers enrolled at Camp Posanivee 
@author Reece Parks and my partner Matt Fleschner */
  
  public static void main(String[] args) throws IOException{
    String input;
    char command; 
    String name;
    int age;
    int totalCampers=0;
    double avgAge=0;
    double sumAge=0;
    char diet;
    camper person;
    camper key;
    int numVegans = 0;

    BST tree = new BST();
    
    System.out.println("Welcome to Camp Posanivee!!");

    Scanner file = new Scanner(new FileReader("camp.txt"));
    Scanner cin = new Scanner(System.in);

    do
      {
        //read in the letter for the command
        command = file.next().charAt(0);
        //System.out.println(command);
    
        if (command == 'A')
        {
          System.out.println("\nCommand: A");
          if(totalCampers == 0)
          {
            System.out.println("There are no campers enrolled.");
          }
          else
          {
            avgAge = sumAge/totalCampers;
            System.out.println("Average Age = " + avgAge + ".");
          }
        }
        else if (command == 'E')
        {
          //enroll a camper
          name = file.next();
          age = file.nextInt();
          diet = file.next().charAt(0);
          if (diet == 'V') { numVegans++; }
          System.out.println("\nCommand E: " + name + " " + age + " " + diet);
          tree.insert(new camper(name, age, diet));
          totalCampers++;
          sumAge += age;
          System.out.println("New camper added.");
        }
        else if (command == 'W') //withdraw a camper
        {
          person = new camper(file);
          if (person.getDiet() == 'V')
          {
            numVegans--;
          }
          tree.delete(person);
          totalCampers--;
          sumAge -= person.getAge();
          System.out.println("\nCommand W: " + person.getName());
          System.out.println("Camper withdrawn.");
        }
        else if (command == 'D')  //display a camper's name, age, and diet
        {
          person = new camper(file);
          //System.out.println(person);
          System.out.println("\nCommand D " + person.getName());
          key = (camper)tree.lookup(person);
          if (key == null)
          {
            System.out.println("Camper Not Found");
          }
          else
          {
            System.out.println("\tName: " + key.getName() + "\n\tAge: " + key.getAge() + "\n\tDiet: " + key.getDiet());
          }
        }
        else if (command == 'H')  //print help menu for list of commands
        {
          //print list of commands
          System.out.println("Command List");
          System.out.println("H - List of commands");
          System.out.println("E - Enroll a new camper");
          System.out.println("W - Withdraw a camper");
          System.out.println("D - Display the age and diet of a camper");
          System.out.println("A - Print the average age of the campers");
          System.out.println("L - List all campers in alphabetical order");
          System.out.println("V - Print the number of vegan campers");
          System.out.println("P - List all camper names in preorder");
          System.out.println("Q - Quit");
          
          
        }
        else if (command == 'L') //LIst in Alphabetical Order
        {
          System.out.println("\nCommand: L");
          System.out.println("Alphabetical List of Campers");
          tree.reset();
          while(tree.hasNext())
            {
            System.out.println(((camper)tree.getNext()).getName());
            }
        }
        else if (command == 'V')  //Print the number of Vegan campers
        {
          System.out.println("\nCommand: V");
          System.out.println("Number of Vegan campers: "+ numVegans);
        }
        else if (command == 'P')  //Print in Preorder Traversal
        {
          System.out.println("\nCommand: P");
          System.out.println("Preorder Traversal: ");
          tree.reset(BST.PRE);
          while(tree.hasNext())
            {
              System.out.println(((camper)tree.getNext()).getName());
            }
        }
        else 
        {
          //
        }
      }while (command != 'Q'); //end when commmand is Q
    System.out.println("\nCommand: Q");
    System.out.println("End of program.");
    System.out.println("Bring plenty of calomine!");
  }

}

