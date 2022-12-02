// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// raparks & mfleschner
#include "bitarray.h"
#include <cstdlib>
          
BitArray::BitArray(int size)
{
	BYTES = size; //sets number of bytes equal to size
	LENGTH = BYTES * BIT_IN_BYTE; //# of bits
	data_ = new char[BYTES]; //creates a a char array of number of bytes 
	
}
BitArray::BitArray(const BitArray & array) //copy constructor to initialize dynamic memory
{
	
	
	LENGTH = array.LENGTH;
	BYTES = array.BYTES;
	
	std::cout << "Number of bits: " << LENGTH << std::endl;
	
	
	
	
	
}
BitArray::~BitArray() //destructor for getting rid of dynamically allocated memory
{
	if(data_ != NULL) 
	{
		delete [] data_;
	}
	else
	{
		
	}
}
bool BitArray::get(int position) const
{
	
	return ((data_[position/BIT_IN_BYTE] & (1 << (8 -(position % BIT_IN_BYTE) - 1))) != 0); //shift a one left 7 minus the position given and & it with the byte given
	
}
char BitArray::get8(int position) const
{
	return data_[position/BIT_IN_BYTE]; // return the full byte at the position
}


void BitArray::print()
{	
	std::cout << "|";
	
	for (int i=0; i < BYTES; i++)
	{
		std::bitset<BIT_IN_BYTE> bits = data_[i];
		std::cout << bits << "|";
	}
	
	std::cout << std::endl;	
}

void BitArray::clear()
{
	for(int i = 0; i < BYTES; i++) //sets the bytes to 0
	{
		data_[i] = 0;
	}
}
void BitArray::complement()
{
	char one(' ');
	one = 255;
	for(int i = 0; i < BYTES; i++)
	{
		data_[i] = data_[i]^one; //XOR with a bit array of all 1's to get the opposite
	}

}
bool BitArray::flip(int position)
{
	int index = position/BIT_IN_BYTE; //gets the byte you are working on
	position = 8 - (position % BIT_IN_BYTE) - 1; //gets the specific position within the byte
	data_[index] = ((data_[index]) ^ (1 << position)); //Xor with 1 shifted left position times to flip the bit
	
	return true;
	
}

void BitArray::initialize(char * word,int size)
{
	
	if(data_ != NULL) //deletes existing bit array
	{
		delete [] data_;
	}
	else
	{
		
	}
	BYTES = size;
	LENGTH = BYTES * BIT_IN_BYTE; //reinitializes the size
	data_ = new char[size];
	for(int i = 0; i < size; i++) //sets the byte equal to the respective byte in word 
	{
		data_[i] = word[i];
	}
	
	
}
bool BitArray::set(int position, int bit)
{
	int index = position/BIT_IN_BYTE; //gets the byte you are looking for 
	
	if (((data_[index] << (position % BIT_IN_BYTE)) >> 7) % 2 != bit) //if a shift all the way to the left position times followed by a shift all the way to the right leaving the given bit in the last postion, leaves the divisibility by 2 not equal to that of the given bit
	{
		flip(position); //flip
	}
	else
	{
		
	}
	return true;
}
void BitArray::set8(char c, int index)
{
	data_[index] = c; //setting the byte of the given index to the given char
}