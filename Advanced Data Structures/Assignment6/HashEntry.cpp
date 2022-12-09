/* 
I pledge that I have never given nor
received any help on this assignment
mfleschner & raparks
*/
#include "HashEntry.h"
HashEntry::HashEntry(int key, int value) //default constructor
{
   key_= key;
   value_ = value; 
   status_ = EMPTY;
}
HashEntry::HashEntry() //constructor
{
    key_ = 0;
    value_ =  0;
    status_ = EMPTY;
}
HashEntry::~HashEntry() //deconstructor
{
    
}
int HashEntry::getKey() //method to get key
{
    return key_;
}
void HashEntry::setKey(int key) //method to set key
{
    key_ = key;
}
int HashEntry::getValue() //method to get value
{
    return value_;
}
void HashEntry::setValue(int value) //method to set value
{
    value_ = value;
}
Status HashEntry::getStatus() //method to get status
{
    return status_;
}
void HashEntry::setStatus(Status status) //method to set status
{
    status_ = status;
}