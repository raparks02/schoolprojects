/* 
I pledge that I have never given nor
received any help on this assignment
raparks & mfleschner
*/
#include "Node.h"
#include "LinkedNode.h"
#include "LinkedList.h"
#include "DoublyLinkedList.h"
#include <iostream>
#include <fstream>

int main()
{
    //Phase 1: creating and changing the value of a Node
    std::cout << "Phase 1: " << std::endl;
    Node a(4);
    std::cout << "Value of node is " << a.getValue() << std::endl;
    std::cout << "Changing value of node to 2" << std::endl;
    a.setValue(2);
    std::cout << "Value of node is " << a.getValue() << std::endl;
    std::cout << std::endl;

    //Phase 2 and 3: Creating a LinkedList and inserting into it
    std::cout << "Phase 2 and 3: " << std::endl;
    std::ifstream phaseTwoFile;
    std::cout << "Creating a Linked List" << std::endl;
    LinkedList b;
    int temp(0);
    if(b.isEmpty())
    {
        std::cout << "Linked List is empty!" << std::endl;
    }
    else
    {
        std::cout << "Linked List is not empty!" << std::endl;
    }
    std::cout << "Inserting into Linked List" << std::endl;
    phaseTwoFile.open("data.txt");
    while(phaseTwoFile.is_open())
    {
        phaseTwoFile >> temp;
        //std::cout << "Inserting " << temp << "..." << std::endl;
        b.insert(temp);
        if(phaseTwoFile.eof())
        {
            phaseTwoFile.close();
        }
    }
    std::cout << "Printing the List" << std::endl;
    b.printList();
    if(b.isEmpty())
    {
        std::cout << "Linked List is empty!" << std::endl;
    }
    else
    {
        std::cout << "Linked List is not empty!" << std::endl;
    }
    std::cout << "The length of the Linked List is " << b.getLength() << std::endl;
    std::cout << std::endl;

   //Phase 4; Creating a DoublLinkedList and trying all insert methods on it
    std::cout << "Phase 4: " << std::endl;
    std::ifstream phaseFourFile;
    std::cout << "Creating a Linked List" << std::endl;
    DoublyLinkedList c;
    int temp1(0);
    std::cout << "Inserting into Linked List after the tail" << std::endl;
    phaseFourFile.open("data.txt");
    while(phaseFourFile.is_open())
    {
        phaseFourFile >> temp1;
        //std::cout << "Inserting " << temp1 << "..." << std::endl;
        c.insertAfterLinkedNode(c.getTail(),temp1);
        if (phaseFourFile.eof())
        {
            phaseFourFile.close();
        }

    }
    std::cout << "Printing the list" << std::endl;
    c.printList();
    std::cout << "The length of the Linked List is " << c.getLength() << std::endl;

    
    DoublyLinkedList d;
    std::cout << "Inserting into Linked List before the head" << std::endl;
    phaseFourFile.open("data.txt");
    while(phaseFourFile.is_open())
    {
        phaseFourFile >> temp1;
        //std::cout << "Inserting " << temp1 << "..." << std::endl;
        d.insertBeforeLinkedNode(d.getHead(),temp1);
        if (phaseFourFile.eof())
        {
            phaseFourFile.close();
        }

    }
    std::cout << "Printing the list" << std::endl;
    d.printList();
    std::cout << "The length of the Linked List is " << d.getLength() << std::endl;
    std::cout << std::endl;

    DoublyLinkedList e;
    std::cout << "Inserting into Linked List" << std::endl;
    phaseFourFile.open("data.txt");
    while(phaseFourFile.is_open())
    {
        phaseFourFile >> temp1;
       // std::cout << "Inserting " << temp1 << "..." << std::endl;
        e.insertLinkedNode(e.getTail(),temp1);
        if (phaseFourFile.eof())
        {
            phaseFourFile.close();
        }

    }
    std::cout << "Printing the list" << std::endl;
    e.printList();
    std::cout << "The length of the Linked List is " << e.getLength() << std::endl;
    std::cout << std::endl;

   
    //Phase 5: finding number of hops
    std::cout << "Phase 5: " << std::endl;
    int hops(0);
	int ival(0);
	int val(0);
	DoublyLinkedList list;
	std::ifstream olistfile;
	std::string olistfilename;

	std::cout << "Enter the name of the file to make a DoublyLinkedList: ";
	std::cin >> olistfilename;

	olistfile.open(olistfilename);
	while (!olistfile.eof()) //inserts into DoublyLinkedList from file
	{
		olistfile >> val;
		list.insertLinkedNode(list.getTail(),val);
	}
	olistfile.close();

	std::ifstream inputvalues;
	std::string inputvaluefilename;
	std::cout << "Name of file with values to insert: ";
	std::cin >> inputvaluefilename;
	inputvalues.open(inputvaluefilename); 
	while (!inputvalues.eof())
	{
		int headcount(0);
		int tailcount(0);
		inputvalues >> ival; //take in an insert value

		LinkedNode * temphead = list.getHead();
		LinkedNode * temptail = list.getTail();
		while (ival >= temphead->getValue())  //while insert value is greater than or equal to the value of tempHead
		{
			headcount++; //increase headcount
			temphead = temphead->getNextLinkedNode(); //temphead becomes nextLinkedNode of temptail
			if (temphead == nullptr) //if temphead is nullptr,break
			{
				break;
			}
		}
		while (ival <= temptail->getValue()) //while insertval is less thant or eqaul to the value of temptail
		{
			tailcount++; //increase tailcount
			temptail = temptail->getPrevLinkedNode(); //temptail becomes prevLinkedNode of temptail
			if (temptail == nullptr) //if temptail is nullptr, break
			{
				break;
			}
		}
		if (headcount >= tailcount) //if headcount is greater or equal to tailcount
		{
			list.insertAfterLinkedNode(temptail,ival); //insert into list after the temptail
			hops +=tailcount; //increase hops 
		}
		else if (tailcount > headcount) //otherwise
		{
			list.insertBeforeLinkedNode(temphead,ival); //insert before temphead 
			hops += headcount; //increase hops
		}
	}
	inputvalues.close();
    //outputting list to another file
	std::ofstream outputfile;
	std::string outputfilename;
	std::cout << "File to output to: ";
	std::cin >> outputfilename;
	outputfile.open(outputfilename);
    
	LinkedNode * placeholder = list.getHead();
	while (placeholder != nullptr)
	{
		outputfile << placeholder->getValue() << " ";
		placeholder = placeholder -> getNextLinkedNode();
	}
	outputfile.close();

    //outputting hops to a file
	std::cout << "File to output hops to: ";
	std::cin >> outputfilename;

	outputfile.open(outputfilename, std::ios_base::app); 
	outputfile << "\nTotal number of hops for " << olistfilename << ": " << hops;
	outputfile.close();

    return 0;
}