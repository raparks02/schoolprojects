import java.io.*;
import java.util.*;

public class MyDate implements DateInterface
{
	/**
	A class to calculate and print the date
	@author Reece Parks and partner Matt Fleschner
	*/
	
	int day;
	int dow;
	int month;
	int year;

	/** Empty Constructor for MyDate */
	public MyDate()
	{
		
	}
	

	/** @return the day */
	public int getDay() { return day; }
	/** @return the month */
	public int getMonth() { return month; }
	/** @return year */
	public int getYear() { return year; }
	/** @return the day of the week */
	public int getDow() { return dow; }
	
	/** 
	@param m Corresponding number of the month
	@param d The day of the month
	@param y The integer for the year
	@param dow Corresponding number for the day of the week
	Function to set the current day
	*/
	public void set(int m, int d, int y, int dow)
	{
		month = m;
		dow = dow;
		day = d;
		year = y;
	}
	
	/** 
	@return a printable astring that represents the date 
	*/
	public String toString()
	{
		String months = " ";
		String dows= " ";
		if (month==1) { months = "January"; }
		else if (month==2) { months = "February"; }
		else if (month==3) { months = "March"; }
		else if (month==4) { months = "April"; }
		else if (month==5) { months = "May"; }
		else if (month==6) { months = "June"; }
		else if (month==7) { months = "July"; }
		else if (month==8) { months = "August"; }
		else if (month==9) { months = "September"; }
		else if (month==10) { months = "October"; }
		else if (month==11) { months = "November"; }
		else if (month==12) { months= "December"; }
		
		if (dow == 0) {dows = "Sunday"; }
		else if (dow == 1) {dows = "Monday"; }
		else if (dow == 2) {dows = "Tuesday"; }
		else if (dow == 3) {dows = "Wednesday"; }
		else if (dow == 4) {dows = "Thursday"; }
		else if (dow == 5) {dows = "Friday"; }
		else if (dow == 6) {dows = "Saturday"; }
		
		return dows + " " + months + " " + day + ", " + year;
	}
		
	/**
	@return a boolean stating whether the given year is a leap year
	*/	
	
	public boolean isLeapYear()
	{
		if((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	/**
	Funtion to increment the day of the month for February
	*/
	public void february()
	{
		if(isLeapYear())
		{
			if (day == 30)
			{
				day = 1;
				month++;
			}
		}
		else if(!isLeapYear())
		{
			if (day == 29)
			{
				day = 1;
				month++;
			}
		}
	
	
	}
	
	/**
	Function to increment the day 
	*/
	
	public void tomorrow()
	{
		day++;
		dow++;
		if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if(day == 32)
			{
				day = 1;
				month++;
				
			}
		}
		else if(month == 2)
		{
			february();
		}
		else if(month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day == 31)
			{
				day = 1;
				month++;
			}
		}
		if (dow == 7)
		{
			dow = 0;
		}
		if (month == 13)
		{
			month = 1;
			year++;
		}
	}
	
	public void today()
	{
		
	}
	
	public void yesterday()
	{
		
	}
}
	