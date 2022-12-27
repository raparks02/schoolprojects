/* 
I pledge that I have never given nor
received any help on this assignment
raparks & mfleschner
*/
#ifndef NODE_H
#define NODE_H

#include "HashEntry.h"
/**
 * @class Node
 *
 * Implementation of a Node
 */
class Node
{
public:
/// Constructor
Node(HashEntry data);
/// Destructor
virtual ~Node();
/// Getters/Setters - Accessor Methods
/**
 * Gets the Nodes Integer value.
 *
 * @return Integer
 */
virtual HashEntry getValue();
/**
 * Sets the value of the Node
 *
 * @param[in]          Integer data
 */
void setValue(HashEntry data);
private:
/// Private Attributes
/// Stores the Integer data value
HashEntry data_;
protected:
// We need to do this to prevent a Node from being
// created that has no value.
/// Constructor (Default)
Node() {}
};
#endif