// Name: Aveline Villaganas
// Class (CECS 282-04)
// Project Name (Prog 1 - Solitaire Fibonacci)
// Due Date (2/15/2022)
//
// I certify that this program is my own original work. I did not copy any part of this program from any other source. 
// I further certify that I typed each and every line of code in this program.

#include "Card.h"
#include "Deck.h"
#include <iostream>
using namespace std; 

/** DEFAULT Constructor 
 *  Necessary for using array of cards 
 */
Card::Card(){ 
  // Nothing
}

/** OVERLOADED Constructor 
 *  Creates a card with set rank and suit 
 *  IN: Rank (r), Suit (s) 
 */
Card::Card(char r, char s){
  rank = r;
  suit = s;
}

/** Set an existing card to new values 
 *  IN: Rank (r), Suit (s)
 *  OUT: None 
 */
void Card::setCard(char r, char s){
  rank = r;
  suit = s; // Use set card for refresh, Patrice is cool :D
}

/** Returns the point value of the card
 *  EX - Ace=1, Jack=10, Queen=10, King=10 
 *  IN: None 
 *  OUT: Integer 
 */
int Card::getValue(){
  if(this->rank == 'J' || this->rank == 'Q' || this->rank == 'K' || this->rank == '%'){
    return 10;
  }else if(this->rank == 'A'){
     return 1;
  }else{
    //return int(this->rank);
    //cout << "\n";
    //cout << "CARD RANK:" << this->rank << endl;
    return (int)(this->rank) - 48; // ascii 0 starts at 48 
  }
  return -1;
}

/** Display, print, card values RankSuit 
 *  EX - Ace of Spades=AS
 *  IN: None
 *  OUT: None 
 */
void Card::display(){
  if(this->rank == '%'){
    cout << 10 << this->suit; 
  }else{
    cout << this->rank << this->suit;
  }
}