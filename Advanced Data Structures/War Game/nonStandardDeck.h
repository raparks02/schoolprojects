// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// raparks
#ifndef NONSTANDARD_DECK_H
#define NONSTANDARD_DECK_H

#include "card.h"
#include "deck.h"


/**
 * @class NonStandardDeck
 *
 * The NonStandardDeck class represents a deck of any amount of cards.
 * 
 */
class NonStandardDeck : public Deck //class inherits from parent class deck
	
{
	public: 
		//All methods listed are specific or altered for nonStandardDeck class, the rest are inherited from the parent Deck class
		
		// Default constructor.
		NonStandardDeck();

		
		
		
		//Add card changed to be able to add a card no matter what
		bool addCard(Card c);
		
		//when merging decks, the decks can be of any size
		bool mergeDecks(NonStandardDeck &, bool needShuffle);
		
		//the deck is read in from a file 
		void initializeDeck();
		
		
			
		
		
		
		
		
		
};

#endif