/* 
I pledge that I have never given nor
received any help on this assignment
mfleschner & raparks
*/
#include "HashTableArray.h"
#include <iostream>
HashTableArray::HashTableArray(int size, Method method) //constructor
{
    entry_ = new HashEntry[size];
    size_ = size;
    method_ = method;
}
HashTableArray::HashTableArray(const HashTableArray & arr) //copy constructor
{
    
    entry_ = arr.entry_;

}
HashTableArray::~HashTableArray() //destructor
{
   if(entry_ != nullptr)
    {
        delete [] entry_;
    }
}
void HashTableArray::insert(int key, int value) //insert an entry
{
    HashEntry temp(key, value); 
    int hashIndex(0);

    if(method_ == LINEAR) //for linear probing
    {
       hashIndex = key % size_; //get the hashIndex
       if(entry_[hashIndex].getStatus() == EMPTY || entry_[hashIndex].getStatus() == REMOVED) //if its an open spot
       {
            entry_[hashIndex] = temp; //make an insertion and set status to occupied
            entry_[hashIndex].setStatus(OCCUPIED);

       }
       else
       {
            for(int i = hashIndex; i < size_; i++) //go through each position starting at the hashIndex
            {
                if(entry_[i].getStatus() == EMPTY || entry_[i].getStatus() == REMOVED) //if theres an open spot
                {
                    entry_[i] = temp; //insert 
                    entry_[i].setStatus(OCCUPIED);
                    break;

                }
                
                if(i + 1 == size_) //if its approaching size
                {
                    i = 0; //loop back around
                }
                
            }
       }
    }
    else if(method_ == QUADRATIC) //for quadratic probing
    {
       hashIndex = key % size_;
       if(entry_[hashIndex].getStatus() == EMPTY || entry_[hashIndex].getStatus() == REMOVED) //if there's an open bucket
       {
            entry_[hashIndex] = temp; //insert and set status to occupied
            entry_[hashIndex].setStatus(OCCUPIED);
       }
       else
       {
        for(int i = 1; i < size_; i++) //start at 1 and continue on
        {
            int newHashIndex = (hashIndex + i * i) % size_; // find the new hashIndex 
            if(entry_[newHashIndex].getStatus() == EMPTY || entry_[newHashIndex].getStatus() == REMOVED) //if its an open bucket
            {
                entry_[newHashIndex] = temp; //insert and set to occupied
                entry_[newHashIndex].setStatus(OCCUPIED);
                break;
            }
            
        }
       }
    }
}
int HashTableArray::search(int key) //search for an entry
{
    
   for(int i = 0; i < size_; i++) //go through each index
   {
    if(entry_[i].getKey() == key && entry_[i].getStatus() == OCCUPIED) //if the key is there and the entry is occupied
    {
        return entry_[i].getValue(); //return the value

    }
   }
   return 0; //return 0 otherwise
   
}
void HashTableArray::remove(int key) //remove an entry
{
    
    for(int i = 0; i < size_; i++) //go through each index
    {
        if(entry_[i].getKey() == key && entry_[i].getStatus() == OCCUPIED) //if the key is there and the entry is occupied
        {
            entry_[i].setStatus(REMOVED); //set it to be removed
            std::cout << "Key " << key << " removed." << std::endl;
            return;
        }
    }
    std::cout << "Key " << key << " not found! " << std::endl; //otherwise key is not found
}
void HashTableArray::print()
{
    std::cout << "***********************************" << std::endl;
    for(int i = 0; i < size_; i++) //go through all buckets
    {
        if(entry_[i].getStatus() == OCCUPIED) //if status is occupied at an index
        {
            std::cout << "[" << i << "]: " << entry_[i].getKey() << std::endl; //print out the key
        }
        else
        {
            std::cout << "[" << i << "]: " << std::endl;
        }
    }
    std::cout << "***********************************" << std::endl;



}
int HashTableArray::getSize() //function to get size
{
    return size_;
}