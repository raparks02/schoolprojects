// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// raparks
#include "standardDeck.h"
#include "card.h"
#include <iostream>
#include <algorithm>
#include <random>

//default constructor
StandardDeck::StandardDeck()
{
	
}

bool StandardDeck::mergeDecks(StandardDeck & newdeck, bool needShuffle)
{
	if (numCards_ < DECK_SIZE) //if num cards is less than decksize(52)
	{
		int mergeNum(0); //create a merge number
		mergeNum = DECK_SIZE - numCards_;  //number if cards you have to add to the deck
		if(mergeNum > newdeck.getNumCards()) //if mergeNum is greater
		{
			mergeNum = newdeck.getNumCards(); 
		}
		for(int i = 0; i < mergeNum; i++) //from 0 to less then mergeNum
		{
			deck_[numCards_+i]= newdeck.deck_[i]; //moving the cards from one deck to the other
		}
		
		numCards_ += mergeNum; //increasing num cards
		newdeck.numCards_ = 0;  //setting the newdeck cards to 0
		
		if(needShuffle) //if you choose to shuffle
		{
			shuffle(); //call shuffle function
		}
		else
		{
			//empty
		}
		return true;
		
	}
	return false;
	
}
bool StandardDeck::addCard(Card c)
{
	if(numCards_ >= 52)
	{
		return false; //can't add card if not a standard deck
	}
	else if (c.getFace() == "Joker" || c.getSuit() == "No Suit") 
	{
		return false; //can't add card if a joker
	}
	else
	{
		deck_[numCards_] = c; //set the new card c to the next position in deck
		numCards_++; //increase number of cards
		return true;
	}
}

void StandardDeck::initializeDeck()
{
	for (int i = 1; i < 5; i++) //go through all suits
	{
		for (int j = 1; j < 14; j++) //go through all faces
		{
			//create a temp card with the i and j suit and face
			Card temp(i,j);
			deck_[numCards_] = temp; //set that equal to the array of cards
			numCards_++; //increase numCards_ to next card
		}
	}
}

