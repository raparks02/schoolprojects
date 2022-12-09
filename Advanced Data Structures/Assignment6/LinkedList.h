/* 
I pledge that I have never given nor
received any help on this assignment
mfleschner & raparks
*/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "LinkedNode.h"
#include "HashEntry.h"
#include "Node.h"

class LinkedList
{
	public: 
		LinkedList();
		~LinkedList();
		bool isEmpty(); 
		int getLength(); 
		void insert(HashEntry element); 
		void printList(); 
		
		void setHead(LinkedNode * head);
		void setTail(LinkedNode * tail);
		
		LinkedNode* getHead();
		LinkedNode* getTail();
 
	private: 
		LinkedNode * head_; 
		LinkedNode * tail_;
};
#endif