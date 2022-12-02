// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// raparks & mfleschner
#include <iostream>
#include "bitarray.h"
#include "set.h"
#include "dictionary.h"
#include <fstream>



int main()
{
	
	BitArray bit2(4);
	BitArray bit(bit2);
	bit.initialize("test",4);
	bit.print();
	
	std::cout << "\n0th bit set: " << bit.get(0) << std::endl;
	std::cout << "10th bit set: " << bit.get(10)<< std::endl;
	
	std::cout << "\nSetting 0th bit to 1..." << std::endl;
	bit.set(0,1);
	bit.print();
	
	std::cout << "\nSetting 10th bit to 0..." << std::endl;
	bit.set(10,0);
	bit.print();
	
	bit.complement();
	std::cout << "\nComplement: " << std::endl;
	bit.print();
	
	bit.clear();
	std::cout << "\nClear: " << std::endl;
	bit.print();
	
	std::cout << "Phase 3: " << std::endl;
	Set a(3);
	Set b(3);
	//BitArray bit2(5);
	//BitArray bit(bit2);
	a.initialize("dog",3);
	b.initialize("cat",3);
	
	std::cout << "cardinality: " << a.getCardinality() << std::endl;
	
	std::cout << "Union: " << std::endl;
	a.setUnion(b);
	std::cout << "Intersection: " << std::endl;
	a.setIntersection(b);
	
	
	std::cout << "Phase 4 and 5:" << std::endl;
	
	Dictionary d;
	d.initialize("test", 4);
	std::cout << "Rank: " << d.rank(31,1) << std::endl;
	std::cout << "Rank Range (15-31): " << d.rank_range(15,31,1) << std::endl;
	std::cout << "Select: " << d.select(5,1) << std::endl;
	std::cout << "Select Range(0,15,2,1): " << d.select_range(0,15,2,1) << std::endl;
	
	
	std::cout << "Printing Lookup Table...." << std::endl;
	std::ofstream  outStream; 
	outStream.open("LookupTable.txt");
	d.printLookupTable(outStream);
	outStream.close();
	
	
	
	
	
	
	
	return 0; 
}