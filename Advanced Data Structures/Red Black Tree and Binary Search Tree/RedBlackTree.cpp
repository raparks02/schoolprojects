/* 
I pledge that I have never given nor
received any help on this assignment
mfleschner & raparks
*/
#include "RedBlackTree.h"

RedBlackTree::RedBlackTree() : BinarySearchTree()
{
    //default constructor
}

RedBlackTree::~RedBlackTree()
{
    //destructor
}

void RedBlackTree::insert(int data)
{
   
    TreeNode * newNode = new TreeNode(data); //create newNode pointer of data
    if (newNode -> getColor() == 0) //if color is red
    {
        setRoot(BinarySearchTree::insertNode(getRoot(), newNode)); //insert using binary search tree insertNode 
        TreeNode * root = getRoot(); //set treenode pointer to root
        balanceColor(root,newNode); //call balance color
    }
    
  
}

void RedBlackTree::rotateLeft(TreeNode *& root, TreeNode *& newNode)
{
    TreeNode * newNodeRightChild = newNode->getRightChild();
    TreeNode * temp;
    newNode->setRightChild(newNodeRightChild->getLeftChild()); //set newNode's right child to newNodeRightChild's left child
    if(newNode->getRightChild() != nullptr) //if newNode's right child isn't null
    {
        newNode->getRightChild()->setParent(newNode); //sets the right child's parent to the newNode
    }
    newNodeRightChild->setParent(newNode->getParent()); //sets the parent on the pointer to match the tree
    temp = newNode->getParent();
    if(newNode->getParent() == nullptr) //if the newNode is the root of the whole tree since it has no parent
    {
        root = newNodeRightChild; //sets the root equal to the newNode
        setRoot(root);
    }
    else if (newNode == temp->getLeftChild()) //if newNode is the left child
    {
        temp->setLeftChild(newNodeRightChild);  //set the original right child to the left child
    }
    else
    {
        temp->setRightChild(newNodeRightChild); //if it is right child, sets the orig left child to the right child
    }
   //newNode -> setParent(temp);
    newNodeRightChild->setLeftChild(newNode); //sets the left child to the newNode
    newNode->setParent(newNodeRightChild); //make the original right child the new parent of newNode to finish the rotation
}

void RedBlackTree::rotateRight(TreeNode *& root, TreeNode *& newNode) //same thing as left rotate but other way
{
    TreeNode * newNodeLeftChild = newNode->getLeftChild();
    TreeNode * temp;
    newNode->setLeftChild(newNodeLeftChild->getRightChild());

    if(newNode->getLeftChild() != nullptr)
    {
        newNode->getLeftChild()->setParent(newNode);
    }
    newNodeLeftChild->setParent(newNode->getParent());
    temp = newNode -> getParent();
    if(newNode->getParent() == nullptr)
    {
        root = newNodeLeftChild;
        setRoot(root);
    }
    else if (newNode == temp->getLeftChild())
    {
        temp->setLeftChild(newNodeLeftChild);
    }
    else
    {
        temp->setRightChild(newNodeLeftChild);
    } 
   // newNode -> setParent(temp);
   newNodeLeftChild->setRightChild(newNode);
   newNode->setParent(newNodeLeftChild); 
}

void RedBlackTree::balanceColor(TreeNode *& root, TreeNode *& newNode)
{   
   
    TreeNode * newNodeParent = nullptr;
    TreeNode * newNodeGrandparent = nullptr;
    TreeNode * newNodeUncle = nullptr;
    bool tempColor(0);
    

    if (newNode -> getParent() != nullptr) //if newNode has a parent
    {

        while ((newNode != root) && (newNode -> getColor() == 0) && (newNode -> getParent() -> getColor() == 0)) //while newNode is not thr root, its color is red, and its parent is red
        {
            newNodeParent = newNode -> getParent();
            newNodeGrandparent = newNodeParent -> getParent();

            if (newNodeGrandparent -> getLeftChild() == newNodeParent) //if newNodeParent is the left child of its parent
            { 
                newNodeUncle = newNodeGrandparent -> getRightChild(); //uncle is the right child

        
                if (newNodeUncle != nullptr && newNodeUncle -> getColor() == 0) //if uncle is red, just recolor 
                {
                    newNodeGrandparent -> setColor(0);
                    newNodeParent -> setColor(1);
                    newNodeUncle -> setColor(1);
                    newNode = newNodeGrandparent;
                }
                else //uncle is null or not red
                {
                    
                    if (newNode == newNodeParent->getRightChild()) //if newNode is the right child of its parent
                    {
                        rotateLeft(root, newNodeParent); //rotate left on newNode's parent
                        newNode = newNodeParent;
                        newNodeParent = newNode -> getParent();
                    }

                    else //if newNode is left child of its parent
                    {
                        rotateRight(root,newNodeGrandparent); //rotate right on the newNode's grandparent
                        tempColor = newNodeParent -> getColor(); //swap colors
                        newNodeParent -> setColor(newNodeGrandparent -> getColor());
                        newNodeGrandparent->setColor(tempColor);
                        newNode = newNodeParent;
                    }
                    
                }
            }
            else //if newNodeParent is right child of its parent
            {
                newNodeUncle = newNodeGrandparent -> getLeftChild(); //uncle is the left child

                if ((newNodeUncle != nullptr) && (newNodeUncle -> getColor() == 0)) // if uncle is not null and is red
                {
                    newNodeGrandparent -> setColor(0); //just recolor
                    newNodeParent -> setColor(1);
                    newNodeUncle -> setColor(1);
                    newNode = newNodeGrandparent;
                }

                else //if uncle is null or not red
                {
                    if (newNodeParent -> getLeftChild() == newNode) //if newNode is left child of parent
                    {
                        rotateRight(root, newNodeParent);  //rotate right on the parent
                        newNode = newNodeParent;
                        newNodeParent = newNode -> getParent();
                    }
                    else //if newNode is right child of the parent
                    { 
                        rotateLeft(root, newNodeGrandparent); //rotate left on the grandparent
                        tempColor = newNodeParent -> getColor(); //swap colors to maintain balance
                        newNodeParent -> setColor(newNodeGrandparent -> getColor());
                        newNodeGrandparent -> setColor(tempColor);
                        newNode = newNodeParent;
                    }
                    
                }
            }
        }
    }
    root -> setColor(1);  //set the root to black
    
    /*
    TreeNode * newNodeParent = nullptr;
    TreeNode * newNodeGrandparent = nullptr;
    TreeNode * newNodeUncle = nullptr;
    bool tempColor(0);
    

    
    if((newNode != root) && (newNode -> getColor() == 0) && (newNode -> getParent() -> getColor() == 0))
     {
        if (newNode -> getParent() != nullptr)
        {   
            newNodeParent = newNode -> getParent();
            newNodeGrandparent = newNodeParent -> getParent();
            //When newNode is left child of its parent
            if (newNodeGrandparent -> getLeftChild() == newNodeParent)
            {
                newNodeUncle = newNodeGrandparent -> getRightChild();

                //When the uncle is red, you only need to recolor
                if (newNodeUncle != nullptr && newNodeUncle -> getColor() == 0)
                {
                    newNodeGrandparent -> setColor(0);
                    newNodeParent -> setColor(1);
                    newNodeUncle -> setColor(1);
                    balanceColor(root,newNodeGrandparent);
                }
                else
                {
                    //if newNode is the right child of its parent, must rotate
                    if (newNode == newNodeParent->getRightChild())
                    {
                        rotateLeft(root, newNodeParent);
                        balanceColor(root,newNodeParent);
                    }

                    else
                    {
                        //newNode is left child, must rotate right
                        rotateRight(root,newNodeGrandparent);
                        //swap the colors
                        tempColor = newNodeParent -> getColor();
                        newNodeParent -> setColor(newNodeGrandparent -> getColor());
                        //newNode -> setColor(tempColor);
                        newNodeGrandparent->setColor(tempColor);
                        balanceColor(root,newNodeParent);
                    }
                    
                }
            }

            //NewNode Parent is right child of Grandparent
            else
            {
                newNodeUncle = newNodeGrandparent -> getLeftChild();
                //Uncle is red as well, only recolor
                if ((newNodeUncle != nullptr) && (newNodeUncle -> getColor() == 0))
                {
                    newNodeGrandparent -> setColor(0);
                    newNodeParent -> setColor(1);
                    newNodeUncle -> setColor(1);
                    balanceColor(root,newNodeGrandparent);
                }

                else
                {
                    //if newnode is left child
                    if (newNodeParent -> getLeftChild() == newNode)
                    {
                        rotateRight(root, newNodeParent);
                        balanceColor(root,newNodeParent);
                    }
                    else
                    {
                        rotateLeft(root, newNodeGrandparent);
                        tempColor = newNodeParent -> getColor();
                        newNodeParent -> setColor(newNodeGrandparent -> getColor());
                        newNodeGrandparent -> setColor(tempColor);
                        balanceColor(root,newNodeParent);
                    }
                    //newNode is right child
                    
                }
            }
        }
    }
    root -> setColor(1); 
    */
}

void RedBlackTree::printRedNodes(TreeNode * root)
{
    if (root == nullptr) //base case when nothing is left in the tree
    {
        return;
    }
    else
    {
        printRedNodes(root->getLeftChild()); //recursively print left nodes until you are at the bottomm left
        if (root-> getColor() == 0) //if the node is red
        {
            std::cout << root -> getData() << " ";
        }
        printRedNodes(root -> getRightChild()); //recursively print right nodes after you print the left node at that level
    }
}

void RedBlackTree::printBlackNodes(TreeNode * root) //printing black nodes just like red but in preorder
{
    if (root == nullptr)
    {
        return;
    }
    else
    {
        if (root->getColor() == 1)
        {
            std::cout << root->getData() << " ";
        }
        printBlackNodes(root->getLeftChild());
        printBlackNodes(root->getRightChild());
    }
}
int RedBlackTree::getHeight(TreeNode * root)
{
    if(root == nullptr) //return 0 if root is null as height would be 0
    {
        return 0;

    }
    else
    {
        int leftHeight = getHeight(root->getLeftChild()); //recursively call getHeight on the left child 
        int rightHeight = getHeight(root->getRightChild());//recursively call getHeight on the right child 
        if(leftHeight >= rightHeight) //if the left height is greater or equal 
        {
            return leftHeight + 1; //return left height + 1
        }
        else
        {
            return rightHeight + 1; //return right height + 1
        }
    }
}
