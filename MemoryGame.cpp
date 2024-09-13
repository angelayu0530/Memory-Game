// Angela Yu
//CSCI 135
// TONG YI
//PROJECT A

#include "MemoryGame.hpp"
#include <cstdlib>
#include <iostream>
#include <iomanip>


MemoryGame::MemoryGame() : MemoryGame(3, 8) {

}

MemoryGame :: MemoryGame(int numPairs, int numSlots){
 if(numPairs && numSlots <= 0 || numSlots < 2*numPairs){
    numPairs = 3;
    numSlots = 8;
 }
 else {
   this -> numPairs = numPairs;
    this -> numSlots = numSlots;
 }
 string *values = new string [numSlots];
 for (int i = 0; i< numPairs*2; i+=2){ //same thing as before but for general Numpairs/numslots 
    int random = rand()%1000;
    values[i] = to_string (random);
    values [i+1] = to_string (random);
 }
 for (int i = 2*numPairs;i < numSlots; i++){ 
    values[i] = "";
}
bool *Bshown = new bool[numSlots];
 for (int i = 0; i < numSlots; i ++){
    Bshown[i] = false;
 }
this -> values = values;
this -> bShown = Bshown;

}
MemoryGame::MemoryGame(string* words, int size, int numSlots) {
  if ((size <=0 || numSlots <= 0) || numSlots < 2*size){
    numSlots = 2*size;
  }
  numPairs = size; // sets number of pairs to the size of word array
  this -> numSlots = numSlots; 
  string *values = new string [numSlots];
     for (int j = 0; j<numPairs*2; j+=2){ // sets a word value to a pair of spaces
          values[j] = words[j/2]; // divides by 2 since numpairs is *2
          values[j+1] = words[j/2];
        
     }

for (int k = numPairs*2; k< numSlots; k++){
    values[k] ="";
}
bool *Bshown = new bool[numSlots];
 for (int i = 0; i < numSlots; i ++){
    Bshown[i] = false;
 }

this -> values = values;
this -> bShown =Bshown;
}
MemoryGame::~MemoryGame() { 
    values = nullptr;
    bShown = nullptr;
    delete [] values;
    delete [] bShown;
}
void MemoryGame::randomize() {
     int size = numSlots;
     int temp;
  while (size > 1){
  
    int random = rand () % size; 
    swap(values[random], values[size-1]);
    size-=1;  // decreases the size

   }
}
void printSeparatedLine(int size) {
 cout << "+"; //the first + //draw -----+ for (size) many times
for (int i = 0; i < size; i++)
 cout << "-----+";

 cout << endl;
 }



  void MemoryGame::display() const {
     cout << " ";
     for (int i = 0; i < numSlots; i++){

      cout << setw(3) << i << setw(3) << " ";
       //setw(3) before i means i occupies 3-character, //For example, if i has only two digits,  //then pad a space to its left.
   

      
     }
     cout << endl;
      printSeparatedLine(numSlots);
      for (int i = 0; i < numSlots; i++) {

      cout << "|";
      cout << setw(5);
      if (bShown[i]) {

        cout << values[i];
        

      }
      else {
         cout << " ";
      }
     } 
     cout << "|";
     cout << endl;

      printSeparatedLine(numSlots);

      }
   
  int MemoryGame:: input () const {
   int user;
   
    cout << "Enter an unflipped card in [0," << numSlots << "]" << endl; // asks for user input

    cin >> user;   // gets user input
    while (user >= numSlots || user < 0) {   // loop to check if it is negative or out of range

   cout << "input is not in [0," << numSlots << "]" << "Re-Enter: " << endl;

    cin >> user;
    }
    
    while (bShown[user] ==  true){
      cout << "The card is flipped already. Re-enter:";
      cin >> user;
    }
   
    
    return user;
   
  }
   void MemoryGame:: play (){
   randomize ();
   int pairs = 0; // keeps track of pairs

   int r =1; // keep tracks of rounds 

   int user; 
   int first;
   string compare; 

  
   while (pairs < numPairs){ 
     // allows the game to be played if the number of correct < # of pairs
  
      display ();

    
    

     cout << "round " << r << endl;  //print rounds

     user = input();     // input
    bShown[user] = true; // sets the input to true and displays it
      
     if(r % 2 != 0){     // see if it is first round, sets w to values[s]
       compare = values[user];
       first = user;
     } 
     else {
      string two = values[user];
       if (compare == two){  
        if (compare != ""){
          pairs = pairs +1;
         bShown[first] = true;
         bShown[user] = true;
         }
         
       }
       else{
         bShown[first] = false;
         bShown[user] = false;    // gets rid of it
       }

       
     }
      r= r+1;  // adds the rounds 
     
   }

   cout << "Congratulations! Found out all pairs " << r << " rounds" << endl;
  display ();
   
  }
 