// Name: Aveline Villaganas
// Class (CECS 282-04)
// Project Name (Prog 1 - Solitaire Fibonacci)
// Due Date (2/15/2022)
//
// I certify that this program is my own original work. I did not copy any part of this program from any other source. 
// I further certify that I typed each and every line of code in this program.

#include "Deck.h"
#include "Card.h"
#include <iostream>
#include <string>
using namespace std;

/** Constructor that create 52 cards. 
 *  Starting from Ace of Spaces followed by the rest of the spades in order 
 *  followed by the Hearts, Diamonds, and Clubs
 */
Deck::Deck(){
  int top = 0; 

  int currCard = 0; // track on deck of cards 

  char allSuits[4] = {'S','H','D','C'};
  char allRanks[13] = {'A','2','3','4','5','6','7','8','9','%','J','Q','K'};
  // % for rank 10 - not a char 
  
  for(int i = 0; i < 4; i++){
    char currSuit = allSuits[i];
    for(int j = 0; j < 13; j++){
      char currRank = allRanks[j];
      deckOf[currCard] = Card(currRank, currSuit);
      currCard++;
    }
  }
}

/** Resets the deck so that it looks like a new deck - refer to constructor order 
 *  IN: None 
 *  OUT: None 
 */
void Deck::refreshDeck(){
  int currCard = 0; // track on deck of cards 
  top = 0; // reset to top of deck 
  char theSuits[4] = {'S','H','D','C'};
  char theRanks[13] = {'A','2','3','4','5','6','7','8','9','%','J','Q','K'};
  for(int i = 0; i < 4; i++){
    char currSuit = theSuits[i];
    for(int j = 0; j < 13; j++){
      char currRank = theRanks[j];
      deckOf[currCard].setCard(currRank, currSuit); 
      currCard++;
    }
  }
}

/** Deals a card from the top of the deck 
 *  IN: None
 *  OUT: Card 
 */
Card Deck::deal(){
  return this->deckOf[this->top++]; 
}

/** Shuffles the cards in the deck 
 *  IN: None 
 *  OUT: None 
 */
void Deck::shuffle(){  
  for(int i = 0; i < 5824; i++){

    int range = 51 - (this->top);
    int x = rand() % range; 
    int y = rand() % range;

    //cout << "x: " << x << " ";
    //cout << "y: " << y << "\n"; 
    Card temp = this->deckOf[x];
    this->deckOf[x] = this->deckOf[y];
    this->deckOf[y] = temp; 
  }
}

/** Checks if the deck is empty: True if empty; False if not empty 
 *  IN: None
 *  OUT: Boolean 
 */
bool Deck::isEmpty(){
  if(this->top == 52){
    return true;
  }
  return false; 
}

/** Shows, prints, all the cards in the deck. Format: 13 columns by 4 rows 
 *  IN: None
 *  OUT: None 
 */
void Deck::display(){
  int card = 0; 
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 13; j++){
      //cout << this->deckOf[card] << " ";

      deckOf[card].display(); 
      cout << " "; 
      //cout << "here";
      card++;
      //cout << card;
    }
    cout << endl;
  }
}
