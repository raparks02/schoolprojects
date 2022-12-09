/* 
I pledge that I have never given nor
received any help on this assignment
mfleschner & raparks
*/

#include "LinkedList.h"

LinkedList::LinkedList() //creates a list of nothing
{
	head_ = nullptr;
	tail_ = nullptr;
}

LinkedList::~LinkedList() //delete the head, which in turn cycles through the list deleting everything else as it becomes the new head also
{
	if (head_ != nullptr)
	{
		delete head_;
	}
	else if(tail_ != nullptr)
	{
		delete tail_;
	}
	
}

LinkedNode * LinkedList::getHead() //returns the node at the head of the list
{
	return head_;
}

LinkedNode * LinkedList::getTail() //returns the node at the end of the list
{
	return tail_;
}

void LinkedList::setHead(LinkedNode * head) //sets the first node of the list
{
	head_ = head;
}

void LinkedList::setTail(LinkedNode * tail) //sets the last node of the list
{
	tail_ = tail;
}

bool LinkedList::isEmpty()
{
	return ((head_ == nullptr) && (tail_ == nullptr)); //returns whether or not there is not either a head or tail
}

int LinkedList::getLength() //cycles through the list counting the number of nodes it gets to
{
	int count(0);
	LinkedNode * current = getHead();
	while (current != nullptr)
	{
		count++;
		current= current->getNextLinkedNode();
	}
	return count;
}

void LinkedList::insert(HashEntry element)
{
	LinkedNode * newNode = new LinkedNode(element, nullptr, nullptr); //creates a new node that will be inserted
	
	if (head_ == nullptr && tail_ == nullptr) //if empty list
	{
		head_ = newNode;
	}
	else if (head_ != nullptr && tail_ == nullptr) //if only one node
	{
		tail_ = newNode;
		head_->setNextLinkedNode(tail_);
		tail_->setPrevLinkedNode(head_);
	}
	else
	{
		newNode->setPrevLinkedNode(tail_);
		tail_->setNextLinkedNode(newNode);
		tail_ = newNode;
	}	
}

void LinkedList::printList()
{
	LinkedNode * current = head_; //grabs the first value
	std::cout << current->getValue().getKey();
	while (current->hasNextLinkedNode()) //cycles through all the nodes
	{
		current = current->getNextLinkedNode();
		std::cout<< " --> " << current->getValue().getKey();
		
	}
	std::cout << std::endl;
}