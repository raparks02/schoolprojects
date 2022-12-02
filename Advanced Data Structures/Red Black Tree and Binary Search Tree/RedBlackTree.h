/* 
I pledge that I have never given nor
received any help on this assignment
mfleschner & raparks
*/
#ifndef REDBLACKTREENODE_H
#define REDBLACKTREENODE_H

#include "BinarySearchTree.h"
#include <iostream>
#include <string>

class RedBlackTree : public BinarySearchTree //
{

    public:
        RedBlackTree(); //default constructor
        virtual ~RedBlackTree(); //destructor
        virtual void insert(int data); //method to insert into red black tree
        void printBlackNodes(TreeNode * root); //method to print black nodes using preorder traversal
        void printRedNodes(TreeNode * root); //method to print red nodes using postorder traversal
        int getHeight(TreeNode * root); //method to get the height of the red black tree


    private:
        void rotateLeft(TreeNode *& root, TreeNode *& newNode); //method to rotate left on the newNode
        void rotateRight(TreeNode *& root, TreeNode *& newNode); //method to rotate right on the newNode
    protected:
        void balanceColor(TreeNode *& root, TreeNode *& newNode); //method to maintain color balance 
        

};





#endif