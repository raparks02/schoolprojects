// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// raparks
#include "card.h"

std::string Card::SUIT[] = {"No Suit", "Spades", "Hearts", "Diamonds", "Clubs"};

std::string Card::FACE[] = {"Joker", "Ace", "Two", "Three", "Four", "Five", "Six",  
                       "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};


//constructor
Card::Card()
{
	suitVal_ = 0;
	faceVal_ = 0;
}
//constructor with attributes
Card::Card(int suit, int face)
{
	suitVal_ = suit;
	faceVal_ = face;
}
//creation of destructor
Card::~Card() 
{
	
}
//accessor methods/functions
std::string Card::getSuit()
{
	return SUIT[suitVal_];
}
std::string Card::getFace()
{
	return FACE[faceVal_];
}
std::string Card::print()
{
	return FACE[faceVal_] + " of " + SUIT[suitVal_];
}
void Card::initialize(int suit, int face)
{
	suitVal_= suit;
	faceVal_ = face;
}

