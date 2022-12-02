/* 
I pledge that I have never given nor
received any help on this assignment
raparks & mfleschner
*/
#include "LinkedList.h"
LinkedList::LinkedList() //constructor
{
    head_ = nullptr;
    tail_ = nullptr;
}
LinkedList::~LinkedList() //destructor
{
    if(head_ != nullptr) //if head is not a nullptr, delete head
    {
        delete head_;
    }
}
bool LinkedList::isEmpty() 
{
    if(head_ == nullptr && tail_ == nullptr)  //if both the head and tail are nullptrs, return true
    {
        return true;
    }
    else
    {
        return false;
    }
} 
int LinkedList::getLength()
{
    int count(0);
    LinkedNode * current = head_; //make a current LinkedNode set to the head
    while(current != nullptr) //while it is not a nullptr
    {
        count++; //increase by one
        current = current->getNextLinkedNode(); //make the nextLinkedNode the new current
    }
    return count; //return count

}
void LinkedList::insert(int element)
{
    LinkedNode * newNode = new LinkedNode(element,nullptr,nullptr); //create a newNode
    if(head_ == nullptr && tail_ == nullptr) //if head and tail are both nullptrs
    {
        head_ = newNode; //head becomes the newNode
    }
    else if(head_ != nullptr && tail_ == nullptr) //if the tail is a nullptr but the head is not
    {
        tail_ = newNode; //tail becomes the newNode
        head_->setNextLinkedNode(tail_); //set the head's next node to the tail
         
    }
    else
    {
        tail_->setNextLinkedNode(newNode); //set the tail's next node to the newNode
        tail_ = newNode; //tail becomes the newNode
        
    }
} 
void LinkedList::printList()
{
    LinkedNode * current = head_; //make a current linkedNode set to the head
    std::cout << current->getValue(); //print its value
    while(current->hasNextLinkedNode()) //while it has a nextLinkedNode
    {
        current = current->getNextLinkedNode(); //current becomes its nextLinkedNode
        std::cout << " --> " << current->getValue(); //print the current LinkedNode value
    }
    std::cout << std::endl;
}
//accessor methods
void LinkedList::setHead(LinkedNode * head)
{
    head_ = head;
}
void LinkedList::setTail(LinkedNode * tail)
{
    tail_ = tail;
}
    
LinkedNode * LinkedList::getHead()
{
    return head_;
}
LinkedNode * LinkedList::getTail()
{
    return tail_;
}