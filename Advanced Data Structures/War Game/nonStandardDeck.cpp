// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// raparks
#include "nonStandardDeck.h"
#include "card.h"
#include <iostream>
#include <fstream>

NonStandardDeck::NonStandardDeck()
{

	//default constructor
	
}

bool NonStandardDeck::addCard(Card c)
{
	deck_[numCards_] = c; //set the new card c to the next position in deck
	numCards_++; //increase number of cards
	return true; //always able to add a card as any decksize is possible
}

bool NonStandardDeck::mergeDecks(NonStandardDeck & newdeck, bool needShuffle)
{
	//same as Standard Deck but can merge for any deck size
	for(int i = 0; i < newdeck.getNumCards(); i++)
	{
		deck_[numCards_+i]= newdeck.deck_[i];
	}
		
	numCards_ += newdeck.getNumCards();
	newdeck.numCards_ = 0;
		
	if(needShuffle)
	{
		shuffle();
	}
	else
	{
		//empty
	}
	return true;
		
	
	
	
}

void NonStandardDeck::initializeDeck()
{
	delete [] deck_; //delete deck as another array is going to be created
	
	//variable initialization
	int size(0);
	int suitVal(0);
	int faceVal(0);
	int count(0);
	
	//open a text file 
	std::ifstream inputFile("deck.txt");
	if (inputFile.is_open()) // if open
	{
		//take in first value as decksize and create array of cards at that size
		inputFile >> size; 
		deck_ = new Card[size];
		numCards_=size;
		
		while(!inputFile.eof()) //while not at end of file
		{
			//take in next to values as the suit and face
			inputFile >> suitVal; 
			inputFile >> faceVal;
			
			
			//create a card with that suit and face and add to the deck
			Card card(suitVal,faceVal);
			deck_[count] = card;
			count++; //move on to next position in deck
			
			
			
		}
	}
	inputFile.close(); //close file
}