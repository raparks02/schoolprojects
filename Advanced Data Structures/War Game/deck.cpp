// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// raparks
#include <iostream>
#include "deck.h"
#include "card.h"
Deck::Deck() //default constructor with no parameters
{
	
	deck_=new Card[52]; //creating a deck of size 52(standarddeck)
	numCards_=0;
}
Deck::Deck(int size)
{
	deck_= new Card[size]; //creating a deck of int size(nonstandarddeck)
	numCards_ = 0;
	
}

Deck::~Deck()
{
	
	delete [] deck_;
}
bool Deck::isEmpty()
{
	if (numCards_ == 0) //return 1 if there are no cards, 0 otherwise
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Deck::getNumCards() //returns current numCards
{
	return numCards_; 
}

void Deck::displayCard(int i) //prints/displays a certain card from the deck
{
	std::cout << deck_[i].print() << std::endl; 
}

void Deck::printDeck() //prints entire deck
{
	for(int i = 0; i < numCards_; i++) //for loop to print the entire deck
	{
		std::cout << deck_[i].print() << std::endl;
	}
}
void Deck::shuffle() //shuffles deck
{
	srand((unsigned) time(0)); //seeding number generator
	
	for(int s = 0; s < 3; s++) //for loop that runs 3 times that runs through the shuffle each time
	{
		for (int i = 0; i < numCards_; i++) //for loop starting at 0 until one less then numCards to run through deck
		{
			int j(0);
			j = (rand() % (numCards_-1)) + 1; //create a random integer j
			
			//Create a temporary card to swap the i position with the new j position
			Card temp;
			temp = deck_[j];
			deck_[j] = deck_[i];
			deck_[i] = temp;
			 
		} 
	}
	
}
Card Deck::dealCard() //deals out a card from the deck
{
	numCards_--; //substract one from numCards
	return deck_[numCards_]; //return a card 
}


