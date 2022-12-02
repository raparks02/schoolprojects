// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// raparks
#include <iostream>
#include "card.h"
#include "standardDeck.h"
#include "deck.h"
#include "nonStandardDeck.h"
void playStandardDeck();

int main()
{
	
	std::cout << "NonStandardDeck Game of War!" << std::endl;
	NonStandardDeck * nonstanddeck = new NonStandardDeck(); 
	Deck * deck = nonstanddeck;
	
	deck->initializeDeck(); //initialize the nonstandard deck and read in from text file
	
	deck->shuffle(); //shuffle the deck
	
	//creating nonstandard decks
	NonStandardDeck * playerone = new NonStandardDeck();
	NonStandardDeck * playertwo = new NonStandardDeck();
	NonStandardDeck * battleground = new NonStandardDeck();
	
	//creating 3 decks
	Deck * p1 = playerone;
	Deck * p2 = playertwo;
	Deck * battledeck = battleground;
	
	//initializing variables
	Card temp;
	Card battlecard;
	int turns(0);
	int gameNumber(0);
	int p1score(0);
	int p2score(0);
	int p1Wins(0);
	int p2Wins(0);
	
	
	while (gameNumber < 50) //runs for 50 games
	{
		turns = 0; //reset turns to 0
		
		int deckCards = deck -> getNumCards(); //get numCards in deck
		for (int i=0; i < deckCards; i++) //to give players even cards
		{
			temp = deck->dealCard(); //deal a card from deck
			if(i % 2 == 0) //evens 
			{
				//add to player one's deck
				playerone->addCard(temp);
			}
			else //odds
			{
				//add to player two's deck
				playertwo->addCard(temp);
			}
		}
		
		
		
		while (p1->isEmpty() == 0 && p2->isEmpty() == 0) //while both players have cards
		{
			if (turns % 2 == 0 && battledeck->isEmpty() == 0) //if it is player one's turn and battledeck is not empty
			{
				//deal a card from both decks
				temp = p1->dealCard();
				battlecard = battledeck->dealCard();
				if(temp.getFace() == battlecard.getFace()) //if faces match
				{
					
					//add both card to battleground
					battleground->addCard(battlecard);
					battleground->addCard(temp);
					
					//give player one the battleground cards
					playerone->mergeDecks(*battleground,true);
					
					//std::cout << "Player one gets the cards----------" << std::endl;
					//std::cout << "Battledeck---------" <<std::endl;
					//battledeck->printDeck();
					//std::cout << battledeck->getNumCards() << std::endl;
					//std::cout << "Player one deck----------" << std::endl;
					//p1->printDeck();
					//std::cout << p1->getNumCards() << std::endl;
				
					
			
					turns++; //increase turns so player one goes again
				}
				else //no match
				{
					//add both cards to battleground
					battleground->addCard(battlecard);
					battleground->addCard(temp);
					
					
					//std::cout << "Player one does not match----------" << std::endl;
					//std::cout << "Battledeck----------" <<std::endl;
					//battledeck->printDeck();
					//std::cout << battledeck->getNumCards() << std::endl;
					//std::cout << "Player one deck------------" << std::endl;
					//p1->printDeck();
					//std::cout << p1->getNumCards() << std::endl;
				}
				turns++; //increase turns 
			}
			else if (turns % 2 == 1 && battledeck->isEmpty() == 0) //player two turn and battledeck is not empty
			{
				//deal a card from player two and battledeck
				temp = p2->dealCard();
				battlecard = battledeck->dealCard();
				if (temp.getFace() == battlecard.getFace()) //if faces match
				{
					//add both cards to battleground
					battleground->addCard(battlecard);
					battleground->addCard(temp);
					
					//put all cards in player two deck
					playertwo->mergeDecks(*battleground,true);
					
					//std::cout << "Player two gets the cards------------" << std::endl;
					//std::cout << "Battledeck-----------" <<std::endl;
					//battledeck->printDeck();
					//std::cout << battledeck->getNumCards() << std::endl;
					//std::cout << "Player two deck-----------" << std::endl;
					//p2->printDeck();
					//std::cout << p2->getNumCards() << std::endl;
					
					turns++; //increase turns so player two goes again
				}
				else //no match
				{
					//add both cards back to battleground 
					battleground->addCard(battlecard);
					battleground->addCard(temp);
					
					
					//std::cout << "Player two does not match----------" << std::endl;
					//std::cout << "Battledeck---------" <<std::endl;
					//battledeck->printDeck();
					//std::cout << battledeck->getNumCards() << std::endl;
					//std::cout << "Player two deck---------" << std::endl;
					//p2->printDeck();
					//std::cout << p2->getNumCards() << std::endl;
				}
				turns++; //increase turns
			}
			else if (battledeck->isEmpty() == 1 && turns % 2 == 0) //battle deck is empty and player one turn
			{
				//deal a card from player to battleground
				temp = p1->dealCard();
				battleground->addCard(temp);
				
				
				//std::cout << "Player one battle deck is empty----------" << std::endl;
				//std::cout << "Battledeck--------" <<std::endl;
				//battledeck->printDeck();
				//std::cout << battledeck->getNumCards() << std::endl;
				//std::cout << "Player one deck--------" << std::endl;
				//p1->printDeck();
				//std::cout << p1->getNumCards() << std::endl;
				
				turns++; //increase turns
			}
			else if (battledeck->isEmpty() == 1 && turns % 2 == 1) //battledeck is empty and player two's turn 
			{
				//deal a card from player and add to battleground
				temp = p2->dealCard();
				battleground->addCard(temp);
				
				
				//std::cout << "Player two battle deck is empty-----------" << std::endl;
				//std::cout << "Battledeck-------" <<std::endl;
				//battledeck->printDeck();
				//std::cout << battledeck->getNumCards() << std::endl;
				//std::cout << "Player two deck-------" << std::endl;
				//p2->printDeck();
				//std::cout << p2->getNumCards() << std::endl;
				
				turns++; //increase turns
				
			}
			else
			{
				break; //empty
			}
			
		}
		if (p1->isEmpty() == 1) //if player 1 is empty
		{
			//std::cout << "P2 win" << std::endl;
			
			//add player two's score to current numCards to get new score
			p2score = p2score + p2->getNumCards();
			p2Wins++; //increase wins
			nonstanddeck->mergeDecks(*playertwo,false); //merge back into initial deck
		}
		else if(p2->isEmpty() == 1) // if player 2 is empty
		{
			//std::cout << "P1 win" << std::endl;
			
			//add player one's score to current numCards to get new score
			p1score = p1score + p1->getNumCards();
			p1Wins++; //increase wins
			nonstanddeck->mergeDecks(*playerone,false); //merge back into initial deck
			
		}
		else
		{
			//empty
		}
		
		
		nonstanddeck->mergeDecks(*battleground,true); //merge battleground into  initial deck
		
		gameNumber++;	//go on to next game
		
	}
	

		
	if (p1Wins > p2Wins) //if player one wins
	{
		std::cout << "Player 1 was the champion with " << p1Wins << " victories versus Player 2!" << std::endl;	
	}	
	else if(p2Wins > p1Wins) //if player two wins
	{
		std::cout << "Player 2 was the champion with " << p2Wins << " victories versus Player 1!" << std::endl;
	}
	else //if a tie
	{
		std::cout << "There is a tie between Player 1 and Player 2 with " << p1Wins << " each!" << std::endl;
	}
	if(p1Wins == 0) //if player one never wins
	{
		std::cout << "Player 1 Average Score: " << p1Wins << std::endl;
		std::cout << "Player 2 Average Score: " << p2score/p2Wins << std::endl;
	}
	else if(p2Wins == 0) //if player two never wins
	{
		std::cout << "Player 1 Average Score: " << p1score/p1Wins << std::endl;
		std::cout << "Player 2 Average Score: " << p2Wins << std::endl;
	}
	else //if they both sometimes win
	{
		std::cout << "Player 1 Average Score: " << p1score/p1Wins << std::endl;
		std::cout << "Player 2 Average Score: " << p2score/p2Wins << std::endl;
	}
	
	
	
	//deleting nonstandard decks
	delete playerone;
	delete playertwo;
	delete battleground;
	delete nonstanddeck;
	
	playStandardDeck(); //play again on a standarddeck
	
	
	
	
	
	return 0;
	
	
}
void playStandardDeck()
{
	std::cout << "StandardDeck Game of War!" << std::endl;
	StandardDeck * standdeck = new StandardDeck(); 
	Deck * deck = standdeck;
	
	deck->initializeDeck(); //initialize the standard deck and read in from text file
	
	deck->shuffle(); //shuffle the deck
	
	//creating standard decks
	StandardDeck * playerone = new StandardDeck();
	StandardDeck * playertwo = new StandardDeck();
	StandardDeck * battleground = new StandardDeck();
	
	//creating 3 decks
	Deck * p1 = playerone;
	Deck * p2 = playertwo;
	Deck * battledeck = battleground;
	
	//initializing variables
	Card temp;
	Card battlecard;
	int turns(0);
	int gameNumber(0);
	int p1score(0);
	int p2score(0);
	int p1Wins(0);
	int p2Wins(0);
	
	
	while (gameNumber < 50) //runs for 50 games
	{
		turns = 0; //reset turns to 0
		
		int deckCards = deck -> getNumCards(); //get numCards in deck
		for (int i=0; i < deckCards; i++) //to give players even cards
		{
			temp = deck->dealCard(); //deal a card from deck
			if(i % 2 == 0) //evens 
			{
				//add to player one's deck
				playerone->addCard(temp);
			}
			else //odds
			{
				//add to player two's deck
				playertwo->addCard(temp);
			}
		}
		
		
		
		while (p1->isEmpty() == 0 && p2->isEmpty() == 0) //while both players have cards
		{
			if (turns % 2 == 0 && battledeck->isEmpty() == 0) //if it is player one's turn and battledeck is not empty
			{
				//deal a card from both decks
				temp = p1->dealCard();
				battlecard = battledeck->dealCard();
				if(temp.getFace() == battlecard.getFace()) //if faces match
				{
					
					//add both card to battleground
					battleground->addCard(battlecard);
					battleground->addCard(temp);
					
					//give player one the battleground cards
					playerone->mergeDecks(*battleground,true);
					
					//std::cout << "Player one gets the cards----------" << std::endl;
					//std::cout << "Battledeck---------" <<std::endl;
					//battledeck->printDeck();
					//std::cout << battledeck->getNumCards() << std::endl;
					//std::cout << "Player one deck----------" << std::endl;
					//p1->printDeck();
					//std::cout << p1->getNumCards() << std::endl;
				
					
			
					turns++; //increase turns so player one goes again
				}
				else //no match
				{
					//add both cards to battleground
					battleground->addCard(battlecard);
					battleground->addCard(temp);
					
					
					//std::cout << "Player one does not match----------" << std::endl;
					//std::cout << "Battledeck----------" <<std::endl;
					//battledeck->printDeck();
					//std::cout << battledeck->getNumCards() << std::endl;
					//std::cout << "Player one deck------------" << std::endl;
					//p1->printDeck();
					//std::cout << p1->getNumCards() << std::endl;
				}
				turns++; //increase turns 
			}
			else if (turns % 2 == 1 && battledeck->isEmpty() == 0) //player two turn and battledeck is not empty
			{
				//deal a card from player two and battledeck
				temp = p2->dealCard();
				battlecard = battledeck->dealCard();
				if (temp.getFace() == battlecard.getFace()) //if faces match
				{
					//add both cards to battleground
					battleground->addCard(battlecard);
					battleground->addCard(temp);
					
					//put all cards in player two deck
					playertwo->mergeDecks(*battleground,true);
					
					//std::cout << "Player two gets the cards------------" << std::endl;
					//std::cout << "Battledeck-----------" <<std::endl;
					//battledeck->printDeck();
					//std::cout << battledeck->getNumCards() << std::endl;
					//std::cout << "Player two deck-----------" << std::endl;
					//p2->printDeck();
					//std::cout << p2->getNumCards() << std::endl;
					
					turns++; //increase turns so player two goes again
				}
				else //no match
				{
					//add both cards back to battleground 
					battleground->addCard(battlecard);
					battleground->addCard(temp);
					
					
					//std::cout << "Player two does not match----------" << std::endl;
					//std::cout << "Battledeck---------" <<std::endl;
					//battledeck->printDeck();
					//std::cout << battledeck->getNumCards() << std::endl;
					//std::cout << "Player two deck---------" << std::endl;
					//p2->printDeck();
					//std::cout << p2->getNumCards() << std::endl;
				}
				turns++; //increase turns
			}
			else if (battledeck->isEmpty() == 1 && turns % 2 == 0) //battle deck is empty and player one turn
			{
				//deal a card from player to battleground
				temp = p1->dealCard();
				battleground->addCard(temp);
				
				
				//std::cout << "Player one battle deck is empty----------" << std::endl;
				//std::cout << "Battledeck--------" <<std::endl;
				//battledeck->printDeck();
				//std::cout << battledeck->getNumCards() << std::endl;
				//std::cout << "Player one deck--------" << std::endl;
				//p1->printDeck();
				//std::cout << p1->getNumCards() << std::endl;
				
				turns++; //increase turns
			}
			else if (battledeck->isEmpty() == 1 && turns % 2 == 1) //battledeck is empty and player two's turn 
			{
				//deal a card from player and add to battleground
				temp = p2->dealCard();
				battleground->addCard(temp);
				
				
				//std::cout << "Player two battle deck is empty-----------" << std::endl;
				//std::cout << "Battledeck-------" <<std::endl;
				//battledeck->printDeck();
				//std::cout << battledeck->getNumCards() << std::endl;
				//std::cout << "Player two deck-------" << std::endl;
				//p2->printDeck();
				//std::cout << p2->getNumCards() << std::endl;
				
				turns++; //increase turns
				
			}
			else
			{
				break; //empty
			}
			
		}
		if (p1->isEmpty() == 1) //if player 1 is empty
		{
			//std::cout << "P2 win" << std::endl;
			
			//add player two's score to current numCards to get new score
			p2score = p2score + p2->getNumCards();
			p2Wins++; //increase wins
			standdeck->mergeDecks(*playertwo,false); //merge back into initial deck
		}
		else if(p2->isEmpty() == 1) // if player 2 is empty
		{
			//std::cout << "P1 win" << std::endl;
			
			//add player one's score to current numCards to get new score
			p1score = p1score + p1->getNumCards();
			p1Wins++; //increase wins
			standdeck->mergeDecks(*playerone,false); //merge back into initial deck
			
		}
		else
		{
			//empty
		}
		
		
		standdeck->mergeDecks(*battleground,true); //merge battleground into  initial deck
		
		gameNumber++;	//go on to next game
		
	}
	

		
	if (p1Wins > p2Wins) //if player one wins
	{
		std::cout << "Player 1 was the champion with " << p1Wins << " victories versus Player 2!" << std::endl;	
	}	
	else if(p2Wins > p1Wins) //if player two wins
	{
		std::cout << "Player 2 was the champion with " << p2Wins << " victories versus Player 1!" << std::endl;
	}
	else //if a tie
	{
		std::cout << "There is a tie between Player 1 and Player 2 with " << p1Wins << " each!" << std::endl;
	}
	if(p1Wins == 0) //if player one never wins
	{
		std::cout << "Player 1 Average Score: " << p1Wins << std::endl;
		std::cout << "Player 2 Average Score: " << p2score/p2Wins << std::endl;
	}
	else if(p2Wins == 0) //if player two never wins
	{
		std::cout << "Player 1 Average Score: " << p1score/p1Wins << std::endl;
		std::cout << "Player 2 Average Score: " << p2Wins << std::endl;
	}
	else //if they both sometimes win
	{
		std::cout << "Player 1 Average Score: " << p1score/p1Wins << std::endl;
		std::cout << "Player 2 Average Score: " << p2score/p2Wins << std::endl;
	}
	
	
	
	//deleting standard decks
	delete playerone;
	delete playertwo;
	delete battleground;
	delete standdeck;
}
