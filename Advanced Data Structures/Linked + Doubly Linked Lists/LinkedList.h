/* 
I pledge that I have never given nor
received any help on this assignment
raparks & mfleschner
*/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "LinkedNode.h"
#include "Node.h"
#include <iostream>

class LinkedList
{
public:
   //constructor
    LinkedList();
    //destructor
    ~LinkedList();
    //method to see if LinkedList is empty
    bool isEmpty(); 
    //method to get length of LinkedList
    int getLength(); 
    //method to insert into the LinkedList
    void insert(int element); 
    //method to print the LinkedList
    void printList();

   //accessor methods for the head and the tail
    void setHead(LinkedNode * head);
    void setTail(LinkedNode * tail);
    LinkedNode * getHead();
    LinkedNode * getTail();
private:
    LinkedNode * head_;
    LinkedNode * tail_;
protected:
   
};
#endif