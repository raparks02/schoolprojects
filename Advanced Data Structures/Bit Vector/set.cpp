// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// raparks & mfleschner
#include "set.h"


Set::Set(int size) : data_(BitArray(size))
{
	
}

Set::~Set()
{
	//empty destructor bc no dynamic memory 
}
void Set::initialize(char * word, int size)
{
	data_.initialize(word,size); //calls initialize bit array function
	//data_.print();
	
	
}
int Set::getCardinality() const
{
	int count = 0;
	for(int i = 0; i < data_.length(); i++)
	{
		if(data_.get(i) == 1) //checks to see if bit equals one
		{
			count++;
		}
		
	}
	return count;
	
}
BitArray & Set::getData()
{
	return data_; //returns the bitarray for the set, makes it accessible 
}
bool Set::setUnion(Set & B)
{
	char c;
	if(data_.bytes() >= B.getData().bytes()) //makes sure the set you union into is not smaller
	{
		for (int i = 0; i < B.getData().bytes(); i++) 
		{
			c = (data_.get8(i*8)) | (B.getData().get8(i*8)); //or the two sets at the given byte to union
			data_.set8(c,i); //moves that byte to the original set
				
		}
		int start = B.getData().bytes();
		int total = data_.bytes();
		for(int i = start; i < total; i++) 
		{
			data_.set8(0,i);
		}
		data_.print();
		return true;
	}
	else
	{
		return false;
	}
	
}
bool Set::setIntersection(Set & B)
{
	char c(' ');
	if(data_.bytes() >= B.getData().bytes())
	{
		for (int i = 0; i < B.getData().bytes(); i++)
		{
			c = (data_.get8(i*8)) & (B.getData().get8(i*8));//and the two sets at the given byte to intersect
			data_.set8(c,i);
				
		}
		int start = B.getData().bytes();
		int total = data_.bytes();
		for(int i = start; i < total; i++)
		{
			data_.set8(0,i); //clears the remaining bits if bigger
		}
		data_.print();
		return true;
	}
	else
	{
		return false;
	}
	
}


	