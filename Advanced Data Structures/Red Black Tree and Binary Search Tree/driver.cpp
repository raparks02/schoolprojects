/* 
I pledge that I have never given nor
received any help on this assignment
mfleschner & raparks
*/

#include <fstream>
#include <iostream>
#include "BinarySearchTree.h"
#include "TreeNode.h"
#include "RedBlackTree.h"

int main()
{
    std::cout << "Phase 1:" << std::endl;
    std::ifstream file;
    int temp(0);
    file.open("data.txt");

    if (file.is_open())
    {
        while (!file.eof())
        {
            file >> temp;
            std::cout << temp << " ";
        }
    }
    file.close();

    //Phase 2
    std::cout << std::endl;
    std::cout << "Phase 2: " << std::endl;
    BinarySearchTree BST;
    std::ifstream file2;
    file2.open("data.txt");
    
    if (file2.is_open())
    {
        while (!file2.eof())
        {
            
            file2 >> temp;
            std::cout << temp << " ";
            BST.insert(temp);
        }
    }
     file2.close();
    std::cout << std::endl;
    std::cout << "Root: " << BST.getRoot()->getData() << std::endl; 

   
    std::cout << "Phase 3, 4, 5: " << std::endl;
    std::ifstream file3;
    file3.open("data.txt");
    RedBlackTree RBT;
    if (file3.is_open())
    {
        while (!file3.eof())
        {

            file3 >> temp;
            RBT.insert(temp);

        }

       
    }
    file3.close();

    std::cout << "Black Nodes: ";
    RBT.printBlackNodes(RBT.getRoot());
    std::cout << std::endl;
    std::cout << "Red Nodes: ";
    RBT.printRedNodes(RBT.getRoot());
    std::cout << std::endl;


    std::cout << "Root: " << RBT.getRoot() -> getData() << std::endl;
    if(RBT.getRoot()->getColor() == 1)
    {
        std::cout << "Root Color: BLACK" << std::endl;
    }
    else if(RBT.getRoot()->getColor() == 0)
    {
        std::cout << "Root Color: RED" << std::endl;
    }
    std::cout << "Height: " << RBT.getHeight(RBT.getRoot()) << std::endl;
    

    return 0;
    
}