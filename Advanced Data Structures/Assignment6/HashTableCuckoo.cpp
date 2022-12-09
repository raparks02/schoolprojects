/* 
I pledge that I have never given nor
received any help on this assignment
raparks & mfleschner
*/


#include "HashTableCuckoo.h"

HashTableCuckoo::HashTableCuckoo(int size) //constructor
{
    size_ = size;
    entry_ = new HashEntry[size_];
    entry_2 = new HashEntry[size_];
    cycle_ = false;
}

HashTableCuckoo::HashTableCuckoo(const HashTableCuckoo & arr) //constructor
{
    entry_ = arr.entry_;
    entry_2 = arr.entry_;
}

HashTableCuckoo::~HashTableCuckoo() //destructor
{
    if(entry_ != nullptr)
    {
        delete [] entry_;
    }
    if(entry_2 != nullptr)
    {
        delete [] entry_2;
    }
}
int HashTableCuckoo::getSize() //method for getSize
{
    return size_;
}
void HashTableCuckoo::insert(int key, int value) //method to insert an entry
{
    /*HashEntry temp(key,value);
    temp.setStatus(OCCUPIED);
    int table = 1;
    int hashindex = hash(1, key);
    int temp2hashindex;

    if (entry_[hashindex].getStatus() == OCCUPIED) //if status is occupied
    {
        HashEntry temp2 = entry_[hashindex]; //try to place in table 2
        temp2hashindex = hash(2, temp2.getKey()); 
        if (entry_2[temp2hashindex].getStatus() == OCCUPIED) //if table 2 is occupied
        {
            if(entry_[temp2hashindex].getStatus() == OCCUPIED) //try to see if spot is taken back at table 1
            {
                std::cout << "Cycle Present - Rehash!" << std::endl;
                std::cout << "Key Unpositioned: " << key << std::endl;
                return;
            }
            else
            {
                entry_[temp2hashindex] = temp2;
            }
        }
        else //put entry in table 2
        {
            entry_2[temp2hashindex] = temp2;
            entry_[hashindex] = temp;
            table = 2;
        }
    }

    if (table == 1) //put entry in table 1
    {
        entry_[hashindex] = temp;
    }
    */

   HashEntry temp(key,value);
   int importKey = key;
   int hashIndex = key % size_;
   int tempHashIndex = hashIndex;
   int tempKey(0);
   int tempValue(0);
   int temp2key(0);
   int count(0);

    while(count <= size_)
    {
        if(entry_[tempHashIndex].getStatus() == OCCUPIED)
        {
            tempKey = entry_[tempHashIndex].getKey();
            tempValue = entry_[tempHashIndex].getValue();
            HashEntry temp2(tempKey,tempValue);
            entry_[tempHashIndex] = temp;
            entry_[tempHashIndex].setStatus(OCCUPIED);
            tempHashIndex = (tempKey/size_) % size_;
        
            if(entry_2[tempHashIndex].getStatus() == OCCUPIED)
            {
                tempKey = entry_2[tempHashIndex].getKey();
                tempValue = entry_2[tempHashIndex].getValue();
                HashEntry temp(tempKey,tempValue);
                entry_2[tempHashIndex] = temp2;
                entry_2[tempHashIndex].setStatus(OCCUPIED);
                tempHashIndex = tempKey % size_;
                temp2key = entry_[tempHashIndex].getKey();
            }
            else
            {
                entry_2[tempHashIndex] = temp2;
                entry_2[tempHashIndex].setStatus(OCCUPIED);
                return;
        }
        }
        else
        {
            entry_[tempHashIndex] = temp;
            entry_[tempHashIndex].setStatus(OCCUPIED);
            return;
        }
        count++;
    }
    if(count > size_)
    {
        std::cout << "Cycle Present - Rehash!" << std::endl;
        std::cout << "Key Unpositioned: " << key << std::endl;
        cycle_ = true;
  }

}
int HashTableCuckoo::search(int key)
{
    for (int i = 0; i < size_; i++) //search through both tables, if you find the key and its occupied, return value
    {
        if (entry_[i].getKey() == key && entry_[i].getStatus() == OCCUPIED)
        {
            return entry_[i].getValue();
        }
        if (entry_2[i].getKey() == key && entry_2[i].getStatus() == OCCUPIED)
        {
            return entry_2[i].getValue();
        }
    }
    return 0;
}
void HashTableCuckoo::remove(int key) 
{
    for (int i = 0; i < size_; i++) //search through both tables, if you find the key and its occupied, return value
    {
        if (entry_[i].getKey() == key && entry_[i].getStatus() == OCCUPIED)
        {
            entry_[i].setStatus(REMOVED);
            std::cout << "Key " << key << " removed." << std::endl;
            return;
        }
        else if (entry_2[i].getKey() == key && entry_2[i].getStatus() == OCCUPIED)
        {
            entry_2[i].setStatus(REMOVED);
            std::cout << "Key " << key << " removed." << std::endl;
            return;
        }
    }
    std::cout << "Key " << key << " is not present in the tables!" << std::endl;

}
void HashTableCuckoo::print()
{
    std::cout << "***********************************" << std::endl;
    for(int i = 0; i < size_; i++) //go through each index and print the entries for each table
    {
        if(entry_[i].getStatus() == OCCUPIED)
        {
            std::cout << "[" << i << "]: " << entry_[i].getKey() << std::endl;
        }
        else
        {
            std::cout << "[" << i << "]: " << std::endl;
        }
    }
    std::cout << "***********************************" << std::endl;

    std::cout << "***********************************" << std::endl;
    for(int i = 0; i < size_; i++)
    {
        if(entry_2[i].getStatus() == OCCUPIED)
        {
            std::cout << "[" << i << "]: " << entry_2[i].getKey() << std::endl;
        }
        else
        {
            std::cout << "[" << i << "]: " << std::endl;
        }
    }
    std::cout << "***********************************" << std::endl;
}
int HashTableCuckoo::hash(int option, int key) //helper function 
{
    switch (option)
    {
        case 1: return key % size_; //hash index for first table
        case 2: return (key/size_) % size_; //hash index for second table
    }
    return key % size_;
}
bool HashTableCuckoo::getCycle()
{
    return cycle_;
}