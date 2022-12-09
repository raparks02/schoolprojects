/* 
I pledge that I have never given nor
received any help on this assignment
mfleschner & raparks
*/

#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList() : LinkedList() //Create a linked List Object that also falls for doublylinked list
{

}

DoublyLinkedList::~DoublyLinkedList() //not needed as there is no dynamic memory in the class
{

}

void DoublyLinkedList::insertLinkedNode(LinkedNode * node, HashEntry data) //calls the linked list insert as node is not needed
{
   node = new LinkedNode(data,nullptr,nullptr);
   LinkedNode * head = getHead();
   LinkedNode * tail = getTail();

   if(head == nullptr)
   {
        head = node;
        tail = node;
        setHead(head);
        setTail(tail);
   }
   else if(getLength() == 1)
   {
        tail = node;
        setTail(tail);
        head->setNextLinkedNode(tail);
        tail->setPrevLinkedNode(head);
   }
   else if(getLength() > 1)
   {
        tail->setNextLinkedNode(node);
        node->setPrevLinkedNode(tail);
        tail = node;
        setTail(tail);
   }
   
    
   
}


void DoublyLinkedList::insertBeforeLinkedNode(LinkedNode * node, HashEntry data) //same as after just flipped
{
    LinkedNode * newNode = new LinkedNode(data,nullptr,nullptr);
    if (getHead() == nullptr)
    {
        //std::cout << "test" << std::endl;
        //newNode->setValue(element);
        
        if (getHead() == nullptr && getTail() == nullptr)
        {
            setHead(newNode);
        }
        else if (getHead() != nullptr && getTail()== nullptr)
        {
            setTail(newNode);
            getHead()->setNextLinkedNode(getTail());
            getTail()->setPrevLinkedNode(getHead());
        }
    }
    else
    {
        newNode -> setPrevLinkedNode(node -> getPrevLinkedNode()); 
        if (node->getPrevLinkedNode() == nullptr)
        {
            node->setPrevLinkedNode(newNode);
            newNode -> setNextLinkedNode(node);
            setHead(newNode);
        }
        else
        {
            node->getPrevLinkedNode()->setNextLinkedNode(newNode);
            node->setPrevLinkedNode(newNode); 
            newNode ->setNextLinkedNode(node);
        }
    }
    
}

void DoublyLinkedList::printList()
{
    LinkedNode * current = getHead(); //grabs the first node
	std::cout<< current->getValue().getKey(); //gets the value of the first node and prints it
	while (current->hasNextLinkedNode()) //while there is a next node
	{
		current = current->getNextLinkedNode(); //move to the next node
		std::cout<< " <--> " << current->getValue().getKey(); //prints the next node's value
	}
	//std::cout << std::endl; //new line at end of file
}



int DoublyLinkedList::find(int key)
{
    LinkedNode * current = getHead();
    while (current != nullptr)
    {
        if (current->getValue().getKey() == key)
        {
            return current->getValue().getValue();
        }
        current = current->getNextLinkedNode();
    }
    return 0;
}

void DoublyLinkedList::remove(int key)
{
    if (nullptr == LinkedList::getHead() -> getNextLinkedNode() && key == LinkedList::getHead() -> getValue().getKey())
    {
        setHead(nullptr);
    }
    else if(key == LinkedList::getHead() -> getValue().getKey())
    {
        LinkedNode * currentHead = LinkedList::getHead();
        LinkedNode * nextNode = currentHead -> getNextLinkedNode();
        setHead(nextNode);
        nextNode -> setPrevLinkedNode(nullptr);
        currentHead -> setNextLinkedNode(nullptr);
        delete currentHead;
    }
    else if (key == LinkedList::getTail() -> getValue().getKey())
    {
        LinkedNode * currentTail = LinkedList::getTail();
        LinkedNode * prevNode = currentTail -> getPrevLinkedNode();
        setTail(prevNode);
        prevNode -> setNextLinkedNode(nullptr);
        currentTail -> setPrevLinkedNode(nullptr);
        delete currentTail;
    }
    else
    {
        LinkedNode * currentNode = LinkedList::getHead();
        bool isFound(false);
        while (currentNode-> hasNextLinkedNode())
        {
            currentNode = currentNode -> getNextLinkedNode();

            if (currentNode -> getValue().getKey() == key)
            {
                isFound = true;
                break;
            }
        }

        if (isFound)
        {
            currentNode -> getPrevLinkedNode() -> setNextLinkedNode(currentNode -> getNextLinkedNode());
            currentNode -> getNextLinkedNode() -> setPrevLinkedNode(currentNode -> getPrevLinkedNode());
            currentNode -> setNextLinkedNode(nullptr);
            currentNode -> setPrevLinkedNode(nullptr);
            delete currentNode;
        }
        else
        {
            std::cout << "Key " << key << " not found!" << std::endl;
        }
    }
}
int DoublyLinkedList::searchKey(int key)
{
    LinkedNode * head = getHead();
    if(head == nullptr)
    {
    
        return 0;
    }
    LinkedNode * current = head;
    while (current != nullptr)
    {
        if (current->getValue().getKey() == key)
        {
            return key;
        }
        current = current->getNextLinkedNode();
    }
    return 0;
}

