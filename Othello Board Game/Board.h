//Doug Morgan
//5-16-05
//
//File: Board.h - Header file for the Board class which represents a 
//ROWSxCOLUMNS game board with data in the form of a 2 dimensional array of
//characters

const int ROWS = 8;  
const int COLUMNS = 8;
const char PLAYER1 = char(214);
const char PLAYER2 = char(216);
 
#ifndef BOARD_H
#define BOARD_H

#include "colors.h"
#include<string>

class Board
{
 public:
  Board();
  //Post: Initializes all array element to the ' ' character

  Board(const Board& b1);
  //Post: all elements of board are equal to
  //those of object b1

  void operator =(const Board& b1);

  void set_pos(int row, int column, const char c);
  //Pre: row and colunm are less than ROWS and COLUMNS respectively
  //Post: Sets board[row][column] to charatcer c

  char get_pos(int row, int column) const;
  //Pre: row and colunm are less than ROWS and COLUMNS respectively
  //Post: Returns character at board[row][column]

  void display_board() const;
  //Post: Cout a 2-dimensional game board 
 private:
  char board[ROWS][COLUMNS];
};
#endif
