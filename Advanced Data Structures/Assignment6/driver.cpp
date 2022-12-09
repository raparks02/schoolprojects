/* 
I pledge that I have never given nor
received any help on this assignment
mfleschner & raparks
*/
#include <iostream>
#include <fstream>
#include "HashTableArray.h"
#include "HashTableCuckoo.h"
#include "HashTableChaining.h"
#include "HashTable.h"

//functions for each hashtable
void linearProbing();
void quadraticProbing();
void separateChaining();
void cuckooHashing();

int main()
{
    int hashChoice(0);
    std::cout << "Welcome to Blue IV's can of Who Hash!" << std::endl;
    std::cout << std::endl;
    while(hashChoice != 5) //while the player chooses not to quit
    {
        std::cout << "1) Linear Probing" << std::endl;
        std::cout << "2) Quadratic Probing" << std::endl;
        std::cout << "3) Separate Chaining" << std::endl;
        std::cout << "4) Cuckoo Hashing" << std::endl;
        std::cout << "5) Quit Program" << std::endl;
        std::cout << std::endl;

        //select a choice
        std::cout << "Please enter your choice: ";
        std::cin >> hashChoice;

        //pick a choice and go to one of the hashing options
        if(hashChoice == 1)
        {
            linearProbing();
        }
        else if(hashChoice == 2)
        {
            quadraticProbing();
        }
        else if(hashChoice == 3)
        {
            separateChaining();
        }
        else if(hashChoice == 4)
        {
            cuckooHashing();
        }
        else if(hashChoice == 5) //end program
        {
            std::cout << "Thank you for using Blue IV's program - Goodbye!" << std::endl;
        }
        else
        {
            //invalid selection
            std::cout << "Invalid selection! Please try again!" << std::endl;
        }
    }

    





    return 0;
}
void linearProbing() //function for linear probing
{
    int size(0);
    int choice(0);
    int count(0);

    std::cout << "Please enter the size of the Hash Table you wish to create: ";
    std::cin >> size;
    HashTableArray arr(size, LINEAR); //create hashtable array of entered size
    int key(0);
    int value(0);
    std::ifstream file;
    file.open("data.txt"); //open file
    while(!file.eof()) //while not at the end of file
    {
        count++; //increase count after each line
        if (count >= size) //if count is equal or greater than size you must rehash
        {
            std::cout << "<<<--- Insufficient Hash Table Size! Re-hash! --->>>" << std::endl;
            file.close();
            return;
        }
        file >> key;
        file >> value;
        arr.insert(key,value); //insert values in hashtable
    }

    file.close(); //close file
    arr.print(); //print table
    
    
    while(choice != 4) //while choice is not to go back to main menu
    {
        std::cout << std::endl;
        std::cout << "1) Search for Entry" << std::endl;
        std::cout << "2) Remove Entry" << std::endl;
        std::cout << "3) Print HashTable" << std::endl;
        std::cout << "4) Return to Main Menu" << std::endl;
        std::cout << std::endl;

        std::cout << "Please enter your choice: ";
        std::cin >> choice;
        std::cout << std::endl;

        if(choice == 1) //if choice is one, search for a key in the hashtable
        {
            std::cout << "Search (Please enter a Key): ";
            std::cin >> key;
            std::cout << std::endl;
            value = arr.search(key);
            if(value != 0) //if value isn't zero, its in the table
            {
                std::cout << "Key: " << key << "  " << "Value: " << value << std::endl;
        
            }
            else //key is not in the table
            {
                std::cout << "Invalid key! Key " << key << " not found in table!" << std::endl;
            }
        
           

        }
        else if(choice == 2) //if choice is 2, remove and entry from the hashtable
        {
           std::cout << "Remove (Please enter a Key): ";
           std::cin >> key;
           std::cout << std::endl;
           arr.remove(key);
           

        }
        else if(choice == 3) //if choice is 3 print the hashtable
        {
            arr.print();
            
        }
        else if(choice == 4)
        {

        }
        else
        {
            std::cout << "Invalid Selection! Please try again!" << std::endl;
            
        }
    }

}
void quadraticProbing() //function for quadratic probing, same process as linear
{
    int size(0);
    int choice(0);
    int count(0);
    

    std::cout << "Please enter the size of the Hash Table you wish to create: ";
    std::cin >> size;
    HashTableArray arr(size, QUADRATIC);

    int key(0);
    int value(0);
    std::ifstream file;
    file.open("data.txt");
    while(!file.eof())
    {
        count++;
        if (count >= size)
        {
            std::cout << "<<<--- Insufficient Hash Table Size! Re-hash! --->>>" << std::endl;
            file.close();
            return;
        }
        file >> key;
        file >> value;
        arr.insert(key,value);
    }
    file.close();
    arr.print();
    while(choice != 4)
    {
    
        std::cout << std::endl;
        std::cout << "1) Search for Entry" << std::endl;
        std::cout << "2) Remove Entry" << std::endl;
        std::cout << "3) Print HashTable" << std::endl;
        std::cout << "4) Return to Main Menu" << std::endl;
        std::cout << std::endl;

        std::cout << "Please enter your choice: ";
        std::cin >> choice;
        std::cout << std::endl;
        
        if(choice == 1)
        {
            std::cout << "Search (Please enter a Key): ";

            std::cin >> key;
            std::cout << std::endl;
            value = arr.search(key);
            if(value != 0)
            {
                std::cout << "Key: " << key << "  " << "Value: " << value << std::endl;
        
            }
            else
            {
                std::cout << "Invalid key! Key " << key << " not found in table!" << std::endl;
            }

        }
        else if(choice == 2)
        {
            std::cout << "Remove (Please enter a Key): ";
            std::cin >> key;
            std::cout << std::endl;
            arr.remove(key);
    
            

        }
        else if(choice == 3)
        {
            arr.print();
        
        }
        else if(choice == 4)
        {

        }
        else
        {
            std::cout << "Invalid Selection! Please try again!" << std::endl;
        
        }
    }
}
void separateChaining() //function for separate chaining, same process as linear and quadratic
{
    int size(0);
    int choice(0);
    

    std::cout << "Please enter the size of the Hash Table you wish to create: ";
    std::cin >> size;
    HashTableChaining arr(size);

    int key(0);
    int value(0);
    std::ifstream file;
    file.open("data.txt");
    while(!file.eof())
    {
        file >> key;
        file >> value;
        arr.insert(key,value);
        
    }
    
    file.close();
    arr.print();
    while(choice != 4)
    {
    
        std::cout << std::endl;
        std::cout << "1) Search for Entry" << std::endl;
        std::cout << "2) Remove Entry" << std::endl;
        std::cout << "3) Print HashTable" << std::endl;
        std::cout << "4) Return to Main Menu" << std::endl;
        std::cout << std::endl;

        std::cout << "Please enter your choice: ";
        std::cin >> choice;
        std::cout << std::endl;
        
        if(choice == 1)
        {
            std::cout << "Search (Please enter a Key): ";

            std::cin >> key;
            std::cout << std::endl;
            value = arr.search(key);
            if(value != 0)
            {
                std::cout << "Key: " << key << "  " << "Value: " << value << std::endl;
        
            }
            else
            {
                std::cout << "Invalid key! Key " << key << " not found in table!" << std::endl;
            }

        }
        else if(choice == 2)
        {
            std::cout << "Remove (Please enter a Key): ";
            std::cin >> key;
            std::cout << std::endl;
            arr.remove(key);
            

        }
        else if(choice == 3)
        {
            arr.print();
        
        }
        else if(choice == 4)
        {

        }
        else
        {
            std::cout << "Invalid Selection! Please try again!" << std::endl;
        
        }
    }
}
void cuckooHashing() //function for cuckooHashing, same process as linear, quadratic, and separate chaining
{
    int size(0);
    int choice(0);
    int count(0);

    std::cout << "Please enter the size of the Hash Table you wish to create: ";
    std::cin >> size;
    HashTableCuckoo arr(size);

    int key(0);
    int value(0);
    std::ifstream file;
    file.open("data.txt");
    while(!file.eof())
    {
        count++;
        if (count >= size)
        {
            std::cout << "<<<--- Insufficient Hash Table Size! Re-hash! --->>>" << std::endl;
            file.close();
            return;
        }
        file >> key;
        file >> value;
        arr.insert(key,value);
        if(arr.getCycle() == true)
        {
            file.close();
            return;
        }
    }

    file.close();
    arr.print();
    while(choice != 4)
    {
    
        std::cout << std::endl;
        std::cout << "1) Search for Entry" << std::endl;
        std::cout << "2) Remove Entry" << std::endl;
        std::cout << "3) Print HashTable" << std::endl;
        std::cout << "4) Return to Main Menu" << std::endl;
        std::cout << std::endl;

        std::cout << "Please enter your choice: ";
        std::cin >> choice;
        std::cout << std::endl;
        
        if(choice == 1)
        {
            std::cout << "Search (Please enter a Key): ";

            std::cin >> key;
            std::cout << std::endl;
            value = arr.search(key);
            if(value != 0)
            {
                std::cout << "Key: " << key << "  " << "Value: " << value << std::endl;
        
            }
            else
            {
                std::cout << "Invalid key! Key " << key << " not found in table!" << std::endl;
            }

        }
        else if(choice == 2)
        {
            std::cout << "Remove (Please enter a Key): ";
            std::cin >> key;
            std::cout << std::endl;
            arr.remove(key);
            

        }
        else if(choice == 3)
        {
            arr.print();
        
        }
        else if(choice == 4)
        {

        }
        else
        {
            std::cout << "Invalid Selection! Please try again!" << std::endl;
        
        }
    }
}

