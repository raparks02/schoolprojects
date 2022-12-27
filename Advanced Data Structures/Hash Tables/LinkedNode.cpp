/* 
I pledge that I have never given nor
received any help on this assignment
mfleschner & raparks
*/
#include "LinkedNode.h"
LinkedNode::LinkedNode(HashEntry data, LinkedNode * nextLinkedNode, LinkedNode * prevLinkedNode) : Node(data) //constructor
{
    nextLinkedNode_ = nextLinkedNode;
    prevLinkedNode_ = prevLinkedNode;
}
LinkedNode::~LinkedNode() 
{
    if(nextLinkedNode_ != nullptr) //if the nextLinkedNode is not a nullptr, delete it
    {
        delete nextLinkedNode_;
    }
}
//get and set methods for nextLinkedNode and prevLinkedNode
LinkedNode * LinkedNode::getNextLinkedNode()
{
    return nextLinkedNode_;
}
LinkedNode * LinkedNode::getPrevLinkedNode()
{
    return prevLinkedNode_;
}
void LinkedNode::setNextLinkedNode(LinkedNode * nextLinkedNode)
{
    nextLinkedNode_ = nextLinkedNode;
}
void LinkedNode::setPrevLinkedNode(LinkedNode * prevLinkedNode)
{
    prevLinkedNode_ = prevLinkedNode;
}
bool LinkedNode::hasNextLinkedNode()
{
    if(nextLinkedNode_ == nullptr) //if the nextLinkedNode is null, return false, true otherwise
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool LinkedNode::hasPrevLinkedNode()
{
    if(prevLinkedNode_ == nullptr) //if the prevLinkedNode is null return false
    {
        return false;
    }
    else
    {
        return true;
    }
}