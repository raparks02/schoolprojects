/* 
I pledge that I have never given nor
received any help on this assignment
raparks & mfleschner
*/
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include "LinkedList.h"
#include <iostream>

class DoublyLinkedList : public LinkedList //inherits from LinkedList
{
public:
   //constructor
    DoublyLinkedList(); 
    //virtual destructor
    virtual ~DoublyLinkedList();
    //virtual method to print list
    virtual void printList();
    //methods to insert linkedNodes
    void insertLinkedNode(LinkedNode * node, int data);
    void insertAfterLinkedNode(LinkedNode * node, int data);
    void insertBeforeLinkedNode(LinkedNode * node, int data);
private:

protected:
   
};
#endif