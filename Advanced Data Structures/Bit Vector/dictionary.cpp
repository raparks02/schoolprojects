// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// raparks & mfleschner
#include "dictionary.h"



Dictionary::Dictionary() //Making a lookupTable of size (num of possibilities)
{
	lookupTable_ = new int[DICTIONARY_SIZE];
}
Dictionary::Dictionary(const Dictionary & dict) //copy constructor to allocate dynamic memory 
{
	lookupTable_ = dict.lookupTable_;
}
Dictionary::~Dictionary() //destructor to delete instance of dynamic memory
{
	if (lookupTable_ != NULL)
	{
		delete [] lookupTable_;
	}
}
void Dictionary::initialize(char * word, int size)
{
	data_.initialize(word,size); //calls BitArray initialize
	data_.print();  //prints the initialize word/char in binary
	initializeLookupTable(); //creates a lookuptable to reference 
	
}
int Dictionary::rank_range(int start,int end,int bit)
{
	int count = 0;
	for(int i = start; i < end; i++) //cycle through all bits from start to end but don't include end
	{
		if(data_.get(i) == bit) //if bit at the current location is equal to the bit in parameter(1 or 0)
		{
			count++; //increase count 
		}
	}
	return count;
}
int Dictionary::select_range(int start,int end, int k, int bit)
{
	int count = 0;
	for(int i = start; i < end; i++) //cycle through all bits from start to end but don't include end
	{
		if(data_.get(i) == bit) //if bit at current location is equal to the bit in parameter
		{
			count++; //increase count
		} 
		if(count == k) //keep cycling through until your count is equal to the parameter k
		{
			return i; //return that position
		}
	}
	return end;
	
}
int Dictionary::rank(int end, int bit)
{
	/*
	//Phase 4 rank
	int count = 0;
	for(int i = 0; i < end; i++)
	{
		if(data_.get(i) == bit)
		{
			count++;
		}
		
	}
	return count;
	*/
	
	int rank(0);
	for(int i = 0; i < end/8; i++) //cycle through the bytes 
	{
		if(bit == 1)
		{
			rank = rank + lookupTable_[data_.get8(i*8)]; //add the number of 1s at the given byte from the lookup table
		}
		else
		{
			rank = rank + abs(lookupTable_[data_.get8(i*8)]- 8); //same thing but you want 0s instead
		}
	}
	if(end % 8 != 0) //goes through the last byte if there is not 8 bits until the end displayed in the parameter 
	{
		for(int i = (end/8)*8; i < end; i++) //go through the remaining bits unti the end
		{
			if(data_.get(i) == bit) //if the bit at i is equal bit you need
			{
				rank++; //increase rank
			}
		}
	}
	return rank;
	
	
}
int Dictionary::select(int k, int bit)
{
	
	/*
	//Phase 4 select
	int count = 0;
	for(int i = 0; i < data_.length()-1; i++)
	{
		if(data_.get(i) == bit)
		{
			count++;
		
		}
		if(count == k)
		{
			return i;
		}
		
	}
	return data_.length()-1;
*/
	
	int count(0);
	for(int i = 0; i < data_.bytes();i++) //cycle through the bytes
	{
		if(bit == 1)
		{
			count = count + lookupTable_[data_.get8(i*8)]; //counts the number of ones from the matching byte in the lookuptable
		}
		else
		{
			count = count + abs(lookupTable_[data_.get8(i*8)]-8); //same thing but for 0s
		}
		if(count >= k) //if the lookuptable gets you above or equal to the position you want, you go through the individual bits to find exactly where the position is 
		{
			int subtract(0);
			if(i > 0) 
			{
				
				if(bit==1)
				{
					subtract = lookupTable_[data_.get8((i-1)*8)];
				}
				else
				{
					subtract = abs(lookupTable_[data_.get8((i-1)*8)] - 8);
				}
			}
			int start = i*8; //calculate new start position to get number of ones for partial byte
			int end = (start+8)- 1; //calculate new end
			
			int position = select_range(start,end,k-subtract,bit); //call select range of the partial or full byte
			
			return position;
			
		}
	}
	return count;
	
	
}
void Dictionary::initializeLookupTable()
{
	
	
	int count(0);
		for (int i = 0; i < DICTIONARY_SIZE; i++)
		{
			
			Set set(1); //creates set of size one
			char c(i); //creates a char of the respective number in decimal
			char * cval = &c; //copies the memory location of that char to a pointer
			set.initialize(cval,1); //initialize that set with the given char
		
			int count = set.getCardinality(); //get cardinality of that byte
			lookupTable_[i] = count; // sets the position in the lookup table to the number of ones.
		}
	
	
	
}
void Dictionary::printLookupTable(std::ostream & output)
{
	for (int i = 0; i < DICTIONARY_SIZE; i++) //for loop to go from 0 to 255
	{
		output << "Decimal Representation of a BYTE: " << i << ", Number of 1's: " << lookupTable_[i] << std::endl;
	}
	
}

