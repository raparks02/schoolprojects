/* 
I pledge that I have never given nor
received any help on this assignment
raparks & mfleschner
*/
#include "DoublyLinkedList.h"
DoublyLinkedList::DoublyLinkedList() : LinkedList() //constructor
{

}
DoublyLinkedList::~DoublyLinkedList() //destructor
{

}
void DoublyLinkedList::insertLinkedNode(LinkedNode * node, int data)
{
    LinkedNode * newNode = new LinkedNode(data,nullptr,nullptr); //create a newNode
    if(getHead() == nullptr && getTail() == nullptr) //if head and tail are nullptrs
    {
       setHead(newNode); //head becomes the new node
    }
    else if(getHead() != nullptr && getTail() == nullptr) //if head isn't a nullptr but the tail is 
    {
        setTail(newNode); //tail becomes the newNode
        getHead()->setNextLinkedNode(getTail()); //head's next node is the tail
        getTail()->setPrevLinkedNode(getHead()); //tail's previous node is the head

        
    }
    else
    {
        newNode->setPrevLinkedNode(getTail()); //newNode's previous node is the tail
        getTail()->setNextLinkedNode(newNode); //tail's next node is the newNode
        setTail(newNode); //newNode is the new tail
        
    }
}
void DoublyLinkedList::insertAfterLinkedNode(LinkedNode * node, int data)
{
    LinkedNode * newNode = new LinkedNode(data,nullptr,nullptr); //create a newNode
    if(getHead() == nullptr && getTail() == nullptr) //if head is nullptr and tail is nullptr
    {
        setHead(newNode); //set head to the newNode
    }
    else if(getHead() != nullptr && getTail() == nullptr) //if head is not nullptr but tail is 
    {
        setTail(newNode); //set the tail to the newNode
        getHead()->setNextLinkedNode(getTail()); //head's next linked node is tail
        getTail()->setPrevLinkedNode(getHead()); //tail's prev linked node is head
    }
    else
    {
        newNode->setNextLinkedNode(node->getNextLinkedNode()); //set the newNode's next node to the node it will go after next node
        if(node->getNextLinkedNode() == nullptr) //if the node's next node is nullptr
        {
            node->setNextLinkedNode(newNode); //set the node's nextNode to the newNode
            newNode->setPrevLinkedNode(node); //set the newNode's previous node to the node
            setTail(newNode); //set the tail to be the newNode
        }
        else
        {
            node->getNextLinkedNode()->setPrevLinkedNode(newNode); //get the node's next node and set that node's previous linkedNode to the newNode
            node->setNextLinkedNode(newNode); //set the node's next node to the newNode
            newNode->setPrevLinkedNode(node); //set the newNode's previous node to the node

        }
    }
}
void DoublyLinkedList::insertBeforeLinkedNode(LinkedNode * node, int data)
{
    LinkedNode * newNode = new LinkedNode(data,nullptr,nullptr); //create a newNode
    if(getHead() == nullptr && getTail() == nullptr) //if head and tail are both null
    {
        setTail(newNode); //set tail to the newNode
    }
    else if(getHead() == nullptr && getTail() != nullptr) //if tail isn't null but head is
    {
        setHead(newNode); //set head to newNode
        getHead()->setNextLinkedNode(getTail()); //head's nextLinkedNode is the tail
        getTail()->setPrevLinkedNode(getHead()); //tail's prevLinkedNode is the head
    }
    else
    {
        newNode->setPrevLinkedNode(node->getPrevLinkedNode()); //get the node's prevLinkedNode and set the newNode's prevLinkedNode to that
        if(node->getPrevLinkedNode() == nullptr) //if node's prevLinkedNode is null
        {
            node->setPrevLinkedNode(newNode); //set node's prevLinkedNode to the newNode
            newNode->setNextLinkedNode(node); //set newNode's nextLinkedNode to the node
            setHead(newNode); //set the head to the new node
        }
        else
        {
            node->getPrevLinkedNode()->setNextLinkedNode(newNode); //get the prevLinkedNode of the node and set that node's nextLinkedNode to the newnode
            node->setPrevLinkedNode(newNode); //set the node's prevLinkedNode to the newNode
            newNode->setNextLinkedNode(node); //set the newNodes nextLinkedNode to the node
        }
    }
}
void DoublyLinkedList::printList()
{
    LinkedNode * current = getHead(); //current becomes the head
    std::cout << current->getValue(); //print the value of the current linkedNode
    while(current->hasNextLinkedNode()) //while the current has a nextLinkedNode
    {
        current = current->getNextLinkedNode(); //make the new current it's nextLinkedNode
        std::cout << " <--> " << current->getValue(); //print the value of the current
    }
    std::cout << std::endl;
}