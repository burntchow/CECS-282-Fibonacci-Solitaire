// Name: Aveline Villaganas
// Class (CECS 282-04)
// Project Name (Prog 1 - Solitaire Fibonacci)
// Due Date (2/15/2022)
//
// I certify that this program is my own original work. I did not copy any part of this program from any other source. 
// I further certify that I typed each and every line of code in this program.

#ifndef Deck_cpp
#define Deck_cpp 
#include <string>
#include "Card.h"
using namespace std;

class Deck{
  private:
    Card deckOf[52];
    int top = 0;
  public:
    Deck();
    void refreshDeck();
    Card deal();
    void shuffle();
    bool isEmpty();
    void display();
};

#endif 