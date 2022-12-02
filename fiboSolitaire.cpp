// Name: Aveline Villaganas
// Class (CECS 282-04)
// Project Name (Prog 1 - Solitaire Fibonacci)
// Due Date (2/15/2022)
//
// I certify that this program is my own original work. I did not copy any part of this program from any other source. 
// I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <string>
#include "Card.h"
#include "Deck.h"
using namespace std; 

/** Takes in number from main, checks if it is a Fibonacci number. Returns true if yes, returns false if it isn't
 *  IN: Int
 *  OUT: Boolean  
 */ 
bool isFibo(int num){
  int fibNums[17] = {1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584};
  for(int i = 0; i < 17; i++){
    if(num == fibNums[i]){
      //cout << "reached" << endl;
      return true;
    }
  }
  return false; 
}

int main(){

  int userChoice = -1;
  Deck playDeck;
  cout << "Welcome to Fibonacci Solitaire!" << endl; 
  bool passFib = false;
  bool fib = false; 
  int gamesNum = 1; // Keep track of games played

  while(userChoice != 5){ // looping while not exit out 
    if(passFib == true){
      break;
    }
    // menu
    cout << "1) New Deck" << endl << "2) Display Deck" << endl << "3) Shuffle Deck" << endl << "4) Play Solitaire" << endl << "5) Exit" << endl;
    cin >> userChoice;

    if(userChoice == 1){ // New Deck 
      playDeck.refreshDeck(); // ? 
      cout << ". . . Refreshed Deck." << endl;
    }else if(userChoice == 2){ // Display Deck 
      playDeck.display();
    }else if(userChoice == 3){ // Shuffle Deck 
      playDeck.shuffle();
      cout << ". . . Shuffled." << endl;
    }else if(userChoice == 4){ // Play Solitaire 
      bool wonFib = false; 
      
      //while(wonFib != true){ // loop for testing to save my hands
        cout << "Playing Fibonacci Solitaire !" << endl; 
        cout << endl;
        int sum = 0;
        // Keep track of piles made 
        int pileNum = 0; 
        //string fibPile = ""; 
        while(playDeck.isEmpty() == false){
          passFib = false; 
          Card temp = playDeck.deal();
          //cout << "card val -- " << temp.getValue() << endl;
          sum = sum + temp.getValue();
          //fibPile = fibPile + temp.get
          //cout << "current sum: " << sum << endl; 
          temp.display();
          cout << ", ";
          if(isFibo(sum) == true){
            //cout << "reached ... " << endl; 
            passFib = true;
            cout << "Fibo:" << sum << endl; 
            sum = 0; // reset sum 
            pileNum++;
          }
        }
        //cout << "---- Is it a fib? : " << isFibo(sum) << endl;
        if(passFib == true){ // Win
          cout << "Winner in " << pileNum << " piles!" << endl;
          cout << endl;
          cout << "Games played:" << gamesNum << endl;
          break;
        }else{ // Lose 
          cout << "Last hand value:" << sum << endl;
          cout << "Loser in " << pileNum << " piles!" << endl;
          cout << endl;
          gamesNum++;
          //playDeck.refreshDeck();
          //playDeck.shuffle();
          //playDeck.display();
        }
      //}
    }else if(userChoice == 5){ // Exit 
      cout << "Thank you for playing." << endl;
      break; 
    }

    
  }
  return 0; 
}