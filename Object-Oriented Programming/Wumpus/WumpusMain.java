//Program by Reece worked with Matt Fleschner
import java.io.*;
import java.util.*;
class WumpusMain 
{
	/**
	A class to move throughout the map and shoot the corresponding enemies
	@author Reece Parks and my partner Matt Fleschner
	*/
	
	public static void main(String[] args) throws IOException
	{
		int numRooms, adj1, adj2, adj3, numSpiderRooms, numPitRooms;
		int currentRoom, badrooms;
		int numArrows; 
		char selection;
		int roomSel;
		String roomDesc;
		boolean alive = true;
		
		
		currentRoom = 0;
		numArrows = 3;
		
		Scanner cin = new Scanner(System.in);
		Scanner wumpus = new Scanner(new FileReader("Wumpus.txt"));
		
		numRooms = wumpus.nextInt();
		numSpiderRooms = wumpus.nextInt();
		numPitRooms = wumpus.nextInt();
		
		badrooms = numSpiderRooms + numPitRooms + 3;
		int [] assignedRooms = new int[badrooms];
		assignedRooms = assignRooms(badrooms, numRooms);
		
		boolean [] spiderRooms = new boolean[numRooms];
		boolean [] pitRooms = new boolean[numRooms];
		boolean [] batRooms = new boolean[numRooms];
		boolean [] arrowRooms = new boolean[numRooms];
		boolean [] wumpusRoom = new boolean[numRooms];
		
		//for loops to make rooms the randomly assigned rooms into each different type
		for (int i = 0; i < numSpiderRooms; i++)
		{
			int temp = assignedRooms[i];
			spiderRooms[temp - 1] = true;
		}
		for (int i = numSpiderRooms; i <(numSpiderRooms + numPitRooms); i++)
		{
			int temp = assignedRooms[i];
			pitRooms[temp-1] = true;
		}
		for (int i = (numSpiderRooms + numPitRooms); i < (numSpiderRooms + numPitRooms +1); i++)
		{
			int temp = assignedRooms[i];
			batRooms[temp-1] = true;
		}
		for (int i = (numSpiderRooms + numPitRooms+1); i < (numSpiderRooms + numPitRooms + 2); i++)
		{
			int temp = assignedRooms[i];
			arrowRooms[temp-1] = true;
		}
		for (int i = (numSpiderRooms + numPitRooms+2); i < (numSpiderRooms + numPitRooms + 3); i++)
		{
			int temp = assignedRooms[i];
			wumpusRoom[temp-1] = true;
		}
		
		
		Room [] rooms = new Room[numRooms];
		
		for (int i = 0; i < numRooms; i++)
		{
			rooms[i] = new Room(wumpus);
		}
		
		System.out.println("**Welcome to the Zombie Apocalypse!**");
		System.out.println("Destroy the hive to stop the outbreak!");
		
		while (alive)
		{
			adj1 = rooms[currentRoom].getAdj1();
			adj2 = rooms[currentRoom].getAdj2();
			adj3 = rooms[currentRoom].getAdj3();
			roomDesc = rooms[currentRoom].getRoomDesc();
		
			System.out.println("\nYou are in room " + (currentRoom+1) + ".");
			System.out.println("You have " + numArrows + " explosive shots left.");
			System.out.println(roomDesc);
			System.out.println("There are tunnels to rooms " + adj1 + ", " + adj2 + ", " + adj3 + ".");
			
			//If statements to let player know about nearby rooms.
			if (spiderRooms[adj1-1] || spiderRooms[adj2-1] || spiderRooms[adj3-1])
			{
				System.out.println("You can hear the faint groan of zombies nearby.");
			}
			if (pitRooms[adj1-1] || pitRooms[adj2-1] || pitRooms[adj3-1])
			{
				System.out.println("You can hear crackles of lava coming from ahead.");
			}
			if (arrowRooms[adj1-1] || arrowRooms[adj2-1] || arrowRooms[adj3-1])
			{
				System.out.println("There is an ammo crate ahead. Maybe more explosives?");
			}
			if (wumpusRoom[adj1-1] || wumpusRoom[adj2-1] || wumpusRoom[adj3-1])
			{
				System.out.println("A screeching noise indicates the hive is nearby.");
			}
			if (batRooms[adj1-1] || batRooms[adj2-1] || batRooms[adj3-1])
			{
				System.out.println("Loud sparks up ahead. Maybe a teleporter?");
			}
		
			do
			{
				System.out.println("(M)ove or (S)hoot?");
				selection = cin.next().charAt(0);
		
				if(selection == 'M' || selection == 'm')
				{
					//Do while for if player chooses to move
					do
					{
						System.out.println("Which Room?");
						roomSel = cin.nextInt();
						if(roomSel == adj1 || roomSel == adj2 || roomSel == adj3)
						{
							currentRoom = roomSel-1;
						}
						else
						{
							System.out.println("Invalid Room Selection!");
						}
					
					} while(roomSel != adj1 && roomSel != adj2 && roomSel != adj3);
					if (spiderRooms[currentRoom])
					{
						System.out.println("The zombies attack and eat you!");
						System.out.println("You are dead!");
						alive = false;
					}
					if (pitRooms[currentRoom])
					{
						System.out.println("You burn alive in lava!");
						System.out.println("You are dead!");
						alive = false;
					}
					if (wumpusRoom[currentRoom])
					{
						System.out.println("The screech from the zombies in the hive is too loud to handle!");
						System.out.println("You are dead!");
						alive = false;
					}
					if (arrowRooms[currentRoom])
					{
						numArrows = 3;
						System.out.println("You found an ammo crate!");
						System.out.println("You replenish your explosive shots. They are set back to 3.");
					}
					if (batRooms[currentRoom])
					{
						int temp = (int)((Math.random()*(numRooms-1)+1));
						if (temp == currentRoom)
						{
							temp = (int)((Math.random()*(numRooms-1)+1));
						}
						currentRoom = temp-1;
						System.out.println("You step on to a teleporter!");
						System.out.println("You are moved to room " + (currentRoom+1) + ". ");
					}
					
				}
				else if(selection == 'S' || selection == 's')
				{
					if(numArrows > 0)
					{
						//Do while if player chooses to shoot and has ammo
						do
						{
							System.out.println("Which room?");
							roomSel = cin.nextInt();
							if(roomSel == adj1 || roomSel == adj2 || roomSel == adj3)
							{
								if (spiderRooms[roomSel-1])
								{
									System.out.println("You missed the mark and shot a zombie. Keep exploring!");
									numArrows--;
								}
								else if (pitRooms[roomSel-1])
								{
									System.out.println("You missed the mark and shot through a pool of lava. Keep exploring.");
									numArrows--;
								}
								else if (wumpusRoom[roomSel-1])
								{
									System.out.println("You destroyed the hive with an explosive round! **YOU WIN**");
									alive = false;
								}
								else
								{
									System.out.println("You shot and hit nothing. Do not waste your shots!");
									numArrows--;
									
								}
							}
							else if(roomSel != adj1 && roomSel != adj2 && roomSel != adj3)
							{
								System.out.println("You cannot shoot there, dimwit.");
							}
							else
							{
								System.out.println("Invalid Input!");
							}
					
						} while(roomSel != adj1 && roomSel != adj2 && roomSel != adj3);
					}
					else
					{
						System.out.println("You have no explosive shots remaining!");
					}
				}
				else
				{
					System.out.println("Invalid Selection!");
				}
			}while(selection != 'M' && selection != 'm' && selection != 'S' && selection != 's');
		}
		System.out.println("\nThank you for playing!");
		
		
	}
	
	/**
	@param badrooms number of numbers to generate
	@param numRooms number of total rooms in the game
	@return an integer array with the required unique random numbers
	A function to generate unique array of numbers*/
	
	public static int[] assignRooms(int badrooms, int numRooms)
	{
		boolean same;
		int [] randoms = new int[badrooms];
		
		do
		{
			same = false;
			for (int i = 0; i < badrooms; i++)
			{
				randoms[i] = (int)((Math.random()* (numRooms-1)+2));
			}
			
			for (int i = 0; i < badrooms; i++)
			{
				for (int j = i+1; j < badrooms; j++)
				{
					if (randoms[i] == randoms[j])
					{
						same = true;
					}	
				}
			}
		} while(same);
		for (int i = 0; i < randoms.length; i++)
		{
			if (randoms[i] == 0)
			{
				randoms[i] = 1;
			}
		}
		return randoms;
	}
}