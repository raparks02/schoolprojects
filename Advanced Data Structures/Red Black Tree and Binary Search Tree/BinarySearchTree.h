/* 
I pledge that I have never given nor
received any help on this assignment
mfleschner & raparks
*/
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "TreeNode.h"
#include <iostream>

/**
 * @class BinarySearchTree
 *
 * A Class that simulates a Binary Search Tree.
 */
class BinarySearchTree
{
	public:
		/// Constructor
		BinarySearchTree();
		
		/**
		* Copy constructor
		*
		* We need this since we have dynamically allocated
		* memory on this Class.
		*
		* @param[in]     tree        Source BinarySearchTree
		*/
		//BinarySearchTree(BinarySearchTree & tree);
		
		/// Destructor
		~BinarySearchTree();
		
		/**
	     * Returns a pointer to the root node of the BST.
		 *
	     * @return          TreeNode*
	    */ 
		TreeNode * getRoot();
		
		/**
	     * Inserts a data element into the BST.
	     *
		 * @param[in]	   int	data
	    */ 
		void insert(int data);

		void setRoot(TreeNode * root);
		void inorder(TreeNode * root);
		void preorder(TreeNode * root);
		void postorder(TreeNode * root);
	protected:
		TreeNode * insertNode(TreeNode * root, TreeNode * newNode);
	private:
		/**
	     * Helper method to insert a TreeNode into the BST.
	     *
		 * @param[in]	   TreeNode*	root	
		 * @param[in]	   TreeNode*	newNode
		 *
	     * @return          TreeNode*
	    */ 
		//TreeNode * insertNode(TreeNode * root, TreeNode * newNode);
		
		TreeNode * root_; // Pointer to the root node of the BST
		
};

#endif