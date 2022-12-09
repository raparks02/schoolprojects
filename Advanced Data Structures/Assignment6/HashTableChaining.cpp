/* 
I pledge that I have never given nor
received any help on this assignment
mfleschner & raparks
*/
#include "HashTableChaining.h"
#include <iostream>

HashTableChaining::HashTableChaining(int size) //constructor
{
    entry_ = new DoublyLinkedList[size];
    size_ = size;
}

HashTableChaining::HashTableChaining(const HashTableChaining & arr) //copy constructor
{
    entry_ = arr.entry_;
}

HashTableChaining::~HashTableChaining() //destructor
{
    if(entry_ != nullptr)
    {
        delete [] entry_;
    }
    
    
}
int HashTableChaining::getSize() //method to get size
{
    return size_;
}
void HashTableChaining::insert(int key, int value) //method to insert 
{
  HashEntry entry(key,value);
  int index = key % size_;
  LinkedNode * node = new LinkedNode(entry,nullptr, nullptr);
  if(entry_[index].getHead() == nullptr)
  {
    DoublyLinkedList list;
    entry_[index] = list;
    entry_[index] = list;
    entry_[index].insertLinkedNode(node,entry);
    
  }
  else
  {
    entry_[index].insertLinkedNode(node,entry);
  }
  delete node;
   
   



  
 
  
   
}
int HashTableChaining::search(int key) //method to search for an entry
{
    for (int i = 0; i < size_; i++) //go through each index
    {
       if(entry_[i].find(key) != 0) //if the return from find function is not 0
       {
            return entry_[i].find(key); //return value
       }
    }
    return 0; //otherwise return 0
}
void HashTableChaining::remove(int key)
{
   
    for (int i = 0; i < size_; i++) //go through each index
    {
        if (entry_[i].searchKey(key) == key) //call search key function and see if its there
        {
            entry_[i].remove(key); //remove the key from DoublyLinkedList
            std::cout << "Key " << key << " removed." << std::endl;
            return;
        }
    }
    std::cout << "Key " << key << " is not present in the table!" << std::endl; //otherwise it can't be removed
    

   
}
void HashTableChaining::print() //method to print table
{
   
    int count(0);
    std::cout << "***********************************" << std::endl;
    for(int i = 0; i < size_; i++)
    {
       std::cout << "[" << i << "]: ";
       if(entry_[i].getHead() != nullptr) //if head is not null
       {
            entry_[i].printList(); //print the list
       }
       std::cout << std::endl;
    }
    std::cout << "***********************************" << std::endl;
    
}