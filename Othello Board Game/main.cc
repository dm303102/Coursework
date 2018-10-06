#include<string>
#include<iostream>
#include "Othello.h"

using namespace std;
using main_savitch_14::game;

int
main()
{
  game::who winner;  
  Othello instance;

  winner = instance.play();

  if(winner == game::HUMAN)
    cout<<"Player 1 wins!!!\n";
  else if(winner == game::COMPUTER)
    cout<<"Computer wins!!!\n";
  else
    cout<<"Game tie.\n";
  
  return 0;
}
