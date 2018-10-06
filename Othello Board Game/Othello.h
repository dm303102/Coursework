//Doug Morgan
//6-01-05
//
//File: Othella class header file 
//Othello class is derived from the game class in game.h which implements
//the strategy game of Othello - two opponents "outflank" each other's pieces
//by positioning their pieces in such a way that one or more opponent pieces 
//in a row are between two of his/her pieces

#ifndef OTHELLO_H
#define OTHELLO_H

#include<list>
#include "game.h"
#include "Board.h"

using main_savitch_14::game;

class Othello : public game
{
 public:
  Othello();
  //Post: Intializes Oth_board and set the 4 centers pieces according to 
  //Othello rules

  Othello(const Othello& game);
 
  void display_status() const;
  //Calls display_board() member of Oth_board

  void restart();
  //Post: Re-initializes board to start setup

  Board get_board() const {return Oth_board;}
  
  game* clone() const;
  //Post: Return a pointer to a copy of the current game

  bool is_legal(const string& move) const;
  //Post: Returns true only if move is a legal move in Othello rules

  void make_move(const std::string& move);
  //Post: Checks if move is legal and if so, carries out move on Oth_board
  //"outflanking" any opponent pieces in a row

  int evaluate() const;
  //Post: returns a positive value if HUMAN player 1 is winning or, a negative
  //value is player 2 is winning or 0 if the game is tied

  bool is_game_over( ) const;
  //Post: returns true if there are no more available moves for either player
  //to make

  who winning( ) const;
  //Post: returns the player - HUMAN or COMPUTER - who currently has the 
  //greatest number of pieces on the board

  void compute_moves(std::queue<std::string>& moves) const;
  //Post: Computes all the possible legal moves for the current player and puts
  //them in moves

  std::string convert_move(int column, int row) const;
  //converts ints row and column to a string in the format of a move
  //exmaple: convert_move(1, 2) returns "a2"
 private:
  Board Oth_board; //Othello game board
  list<std::string> rows_obtained(const string& move, char opponent, 
				  char player) const;
  //Post: Evaluates the board and returns a list of rows lined with the 
  //current player move (e.g. "up_left", "up", "right")
};
#endif
