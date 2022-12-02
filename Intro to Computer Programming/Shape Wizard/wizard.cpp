// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// raparks

#include <iostream>

int main()
{
	int firstValue(0);
	int secondValue(0);
	double area(0);
	
	std::cout << "CS 142 Wizard!" << std::endl;
	std::cout << std::endl;
	
	std::cout << "****Rectangle Area****" << std::endl;
	std::cout << "Please enter the length: ";
	std::cin >> firstValue;
	std::cout << "Please enter the width: ";
	std::cin >> secondValue;
	area = firstValue * secondValue;
	std::cout << "The area of the rectangle is: " << area << std::endl;
	std::cout << std::endl;
	
	std::cout << "****Square Area****" << std::endl;
	std::cout << "Please enter the side: ";
	std::cin >> firstValue;
	area = firstValue * firstValue;
	std::cout << "The area of the square is: " << area << std::endl;
	std::cout << std::endl;
	
	std::cout << "****Rhombus Area****" << std::endl;
	std::cout << "Please enter the diagonal: ";
	std::cin >> firstValue;
	std::cout << "Please enter the diagonal: ";
	std::cin >> secondValue;
	area = firstValue * secondValue;
	std::cout << "The area of the rhombus is: " << area/2.0 << std::endl;
	std::cout << std::endl;
	
	std::cout << "****Triangle Area****" << std::endl;
	std::cout << "Please enter the base: ";
	std::cin >> firstValue;
	std::cout << "Please enter the height: ";
	std::cin >> secondValue;
	area = firstValue * secondValue;
	std::cout << "The area of the triangle is: " << area/2.0 << std::endl;
	std::cout << std::endl;
	
	std::cout << "Thank you! Goodbye!" << std::endl;
	
	return 0;
}