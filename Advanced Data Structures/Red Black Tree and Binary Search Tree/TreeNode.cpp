/* 
I pledge that I have never given nor
received any help on this assignment
mfleschner & raparks
*/
#include "TreeNode.h"

//
// TreeNode(int data)
//
TreeNode::TreeNode(int data) : data_(data), leftChild_(nullptr), rightChild_(nullptr), parent_(nullptr), color_(0)
{
	// We could also use the initialization list here...
	/*
	data_ = data;
	leftChild_ = nullptr;
	rightChild_ = nullptr;
	parent_ = nullptr;
	color_ = 0;*/
}

//
// TreeNode(TreeNode & node)
//
TreeNode::TreeNode(TreeNode & node)
{
	data_ = node.data_;
	leftChild_ = node.getLeftChild();
	rightChild_ = node.getRightChild();
	parent_ = node.getParent();
	color_ = node.color_;
}

//
// ~TreeNode()
//
TreeNode::~TreeNode()
{
	// Recursive Delete
	if (leftChild_ != nullptr)
	{
		delete leftChild_;
	}
	
	if (rightChild_ != nullptr)
	{
		delete rightChild_;
	}
}

//
// int TreeNode::getData()
//
int TreeNode::getData()
{
	return data_;
}

//
// TreeNode * TreeNode::getLeftChild()
//
TreeNode * TreeNode::getLeftChild()
{
	return leftChild_;
}

//
// TreeNode * TreeNode::getRightChild()
//
TreeNode * TreeNode::getRightChild()
{
	return rightChild_;
}

//
// TreeNode * TreeNode::getParent()
//
TreeNode * TreeNode::getParent()
{
	return parent_;
}

bool TreeNode::getColor()
{
	return color_;
}

//
// void TreeNode::setLeftChild(TreeNode * child)
//
void TreeNode::setLeftChild(TreeNode * child)
{
	leftChild_ = child;
}

//
// void TreeNode::setRightChild(TreeNode * child)
//
void TreeNode::setRightChild(TreeNode * child)
{
	rightChild_ = child;
}

//
// void TreeNode::setParent(TreeNode * parent)
//
void TreeNode::setParent(TreeNode * parent)
{
	parent_ = parent;
}

void TreeNode::setColor(bool color)
{
	color_ = color;
}