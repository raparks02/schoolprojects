/* 
I pledge that I have never given nor
received any help on this assignment
raparks & mfleschner
*/
#ifndef LINKEDNODE_H
#define LINKEDNODE_H
#include "Node.h"
#include "HashEntry.h"
class LinkedNode : public Node //inherits from node
{
public:
    //constructor
    LinkedNode(HashEntry data, LinkedNode * nextLinkedNode, LinkedNode * prevLinkedNode); 
    //destructor
    ~LinkedNode();
    //method to get the nextLinkedNode
    LinkedNode * getNextLinkedNode(); 
    //method to set the nextLinkedNode
    void setNextLinkedNode(LinkedNode * nextLinkedNode); 
    //method with bool return to see if there is a nextLinkedNode
    bool hasNextLinkedNode();
    //method to get the prevLinkedNode
    LinkedNode * getPrevLinkedNode();
    //method to set the prevLinkedNode
    void setPrevLinkedNode(LinkedNode * prevLinkedNode);
    //method with bool return to see if there is a prevLinkedNode
    bool hasPrevLinkedNode();
private:
    LinkedNode * nextLinkedNode_;
    LinkedNode * prevLinkedNode_;
protected:
    LinkedNode() {}
};
#endif