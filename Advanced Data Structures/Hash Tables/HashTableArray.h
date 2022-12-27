/* 
I pledge that I have never given nor
received any help on this assignment
mfleschner & raparks
*/
#ifndef HASHTABLEARRAY_H
#define HASHTABLEARRAY_H

#include "HashTable.h"
#include "HashEntry.h"

enum Method{LINEAR, QUADRATIC};

class HashTableArray : public HashTable
{
public:
/// Constructor
HashTableArray(int size, Method method);
HashTableArray(const HashTableArray & arr);
/// Destructor
~HashTableArray();
//get and set methods
int getSize();
void setSize(int size);
//method to insert into hashtable
void insert(int key, int value);
//method to search through hashtbale
int search(int key);
//method to remove entry from hashtable
void remove(int key);
//print hashtable method
void print();

private:
HashEntry * entry_;
int size_;
Method method_;

};
#endif