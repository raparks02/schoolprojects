/* 
I pledge that I have never given nor
received any help on this assignment
raparks & mfleschner
*/
#include "Node.h"
Node::Node(int data) : data_(data) //default constructor
{

}
Node::~Node() //destructor
{

}
int Node::getValue() //method to get the current value of the node
{
    return data_;
}
void Node::setValue(int data) //method to set the value of the node
{
    data_ = data;
}
