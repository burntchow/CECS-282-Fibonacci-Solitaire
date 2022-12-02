// Name: Aveline Villaganas
// Class (CECS 282-04)
// Project Name (Prog 1 - Solitaire Fibonacci)
// Due Date (2/15/2022)
//
// I certify that this program is my own original work. I did not copy any part of this program from any other source. 
// I further certify that I typed each and every line of code in this program.

#ifndef Card_hpp
#define Card_hpp
#include <string>
using namespace std;

class Card{
  private:
    char rank;
    char suit; 
  public: 
    Card();
    Card(char r, char s);
    void setCard(char r, char s);
    int getValue();
    void display();
};

#endif