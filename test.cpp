#include <iostream>
 #include <string>
#include "MemoryGame.hpp"
using namespace std;

int main() {
  string words[] = {"Hello", "Hi", "Yo", "Ni Hao"};
 int size = sizeof(words) / sizeof(words[0]);
 MemoryGame game(words, size, 7);
 game.play();

   

 
}