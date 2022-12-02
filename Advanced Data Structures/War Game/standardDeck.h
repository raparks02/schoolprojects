// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// raparks
#ifndef STANDARD_DECK_H
#define STANDARD_DECK_H

#include "card.h"
#include "deck.h"
#define DECK_SIZE 52

/**
 * @class StandardDeck
 *
 * The StandardDeck class represents a standard deck of 52 cards.
 * 
 */
class StandardDeck : public Deck //StandardDeck inherits from parent class Deck
{
	public:
		//All methods listed are specific or altered for StandardDeck class, the rest are inherited from the parent Deck class
		
		// Default constructor.
		StandardDeck();
		
		
		//Add card only adds card if there are less than 52 cards unlike nonStandardDeck
		bool addCard(Card c);
		
		//merge decks wont merge if decksize is larger than 52
		bool mergeDecks(StandardDeck &, bool needShuffle);
		
		//initializes deck for a standard 52 card deck
		void initializeDeck();
		
};

#endif