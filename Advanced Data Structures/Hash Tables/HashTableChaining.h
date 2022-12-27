/* 
I pledge that I have never given nor
received any help on this assignment
raparks & mfleschner
*/
#ifndef HASHTABLECHAINING_H
#define HASHTABLECHAINING_H

#include "HashTable.h"
#include "HashEntry.h"
#include "DoublyLinkedList.h"


class HashTableChaining : public HashTable
{
    public: 
        //constructor
        HashTableChaining(int size);
        //copy constructor
        HashTableChaining(const HashTableChaining & arr);
        //destructor
        ~HashTableChaining();
        //get method for size
        int getSize();

        //methods to insert, search, remove, and print
        void insert(int key, int value);
        int search(int key);
        void remove(int key);
        void print();
        
    private:
        int size_;
        DoublyLinkedList * entry_;
        

};

#endif