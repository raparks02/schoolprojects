import java.io.*;
import java.util.*;
public class Room
{
	/**
	A Class to create and label all adjacent rooms
	@author Reece Parks and my partner Matt Fleschner
	*/
	
	String roomDesc;
	public int adj1, adj2, adj3, roomName;
	
	/** Constructor for Room Class
		@param x Read in from File to generate Rooms
	*/
	public Room(Scanner x) throws IOException
	{
		roomName = x.nextInt();
		adj1 = x.nextInt();
		adj2 = x.nextInt();
		adj3 = x.nextInt();
		roomDesc = x.nextLine();
		roomDesc = x.nextLine();
	}
	
	/** @return the RoomName*/
	public int getRoom(){return roomName;}
	/** @return the first adjacent room*/
	public int getAdj1(){return adj1;}
	/** @return the second adjacent room*/
	public int getAdj2(){return adj2;}
	/** @return the third adjacent room*/
	public int getAdj3(){return adj3;}
	/** @return the Room description*/
	public String getRoomDesc(){return roomDesc;}
}