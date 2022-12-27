/* 
I pledge that I have never given nor
received any help on this assignment
raparks & mfleschner
*/
#ifndef HASHTABLECUCKOO_H
#define HASHTABLECUCKOO_H

#include "HashTable.h"
#include "HashEntry.h"
#include "HashTableArray.h"

class HashTableCuckoo : public HashTable
{
    public: 
        //constructor
        HashTableCuckoo(int size);
        //copy constructor
        HashTableCuckoo(const HashTableCuckoo & arr);
        //destructor
        ~HashTableCuckoo();
        //get methods
        int getSize();
        bool getCycle();
        //insert,search,remove, and print methods
        void insert(int key, int value);
        int search(int key);
        void remove(int key);
        void print();

        
        
    private:
        int hash(int option, int key);
        int size_;
        HashEntry * entry_;
        HashEntry * entry_2;
        bool cycle_;
        
        

};

#endif