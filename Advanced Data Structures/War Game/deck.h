// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// raparks
#ifndef DECK_H
#define DECK_H


#include "card.h"
class Deck
{
	public:
		//All methods will be inherited by the child classes StandardDeck and NonStandardDeck
		
		/// Default constructor.
		Deck();
		Deck(int size);
		
		/// Default destructor.
		~Deck();

		/**
	     * Returns True/False (1/0) whether or not the Deck is empty.
	     *
	     * @return          Boolean
	    */ 
		bool isEmpty();	

		/**
	     * Returns the number of cards remaining in the deck.
	     *
	     * @return          Integer		value
	    */ 
		int getNumCards();

		/**
	     * Displays the i'th card in the Deck.
	     *
		 * @param[in]      Index
	    */
		void displayCard(int i);

		/**
	     * Prints the contents of the Deck. This method should call the 
		 * print() method on each Card.
	    */
		void printDeck();	
		
		
		
		void shuffle(); //shuffles the deck
		
		virtual void initializeDeck() = 0; //initializes the deck
		
		Card dealCard(); //deals a card from a deck
			
		
		
		
		
	protected: 
		Card * deck_;	// Pointer to record the location of the array of Cards in memory.
		int numCards_;	// Stores the number of Cards currently in the deck.
		
};
#endif

