/* 
I pledge that I have never given nor
received any help on this assignment
mfleschner & raparks
*/
#ifndef DOUBLTLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "LinkedList.h"
#include "HashEntry.h"
#include <iostream>


class DoublyLinkedList : public LinkedList
{
    public:
        DoublyLinkedList();
        virtual ~DoublyLinkedList();
        virtual void printList(); 
        void insertLinkedNode(LinkedNode * node, HashEntry data); 
        void insertAfterLinkedNode(LinkedNode * node, HashEntry data); 
        void insertBeforeLinkedNode(LinkedNode * node, HashEntry data);
        void remove(int key);
        int find(int key);
        int searchKey(int key);
};

#endif