//Doug Morgan
//5-16-05
//
//File: Board.cc - Implementation file for the Board class which 
//Represents a ROWSxCOLUMNS game board with data in the form of a 2 
//dimensional array of characters

#include "Board.h"
#include<iostream>
#include<cassert>

using namespace std;

//Initializes all array element to the ' ' character
Board::Board()
{
  int i = 0;
  int j = 0;

  for(i = 0; i < ROWS; i++)
    {
      for(j = 0; j < COLUMNS; j++)
	board[i][j] = ' ';
    }
}

//Copy Constructor
Board::Board(const Board& b1)
{
  int i = 0;
  int j = 0;

  for(i = 0; i < ROWS; i++) 
    {
      for(j = 0; j < COLUMNS; j++)
	board[i][j] = b1.get_pos(i,j);
    }
}

//Overloaded = operator
void Board::operator =(const Board& b1)
{
  if(&b1 == this)
    return;

  int i = 0;
  int j = 0;

  for(i = 0; i < ROWS; i++)
    {
      for(j = 0; j < COLUMNS; j++)
        board[i][j] = b1.get_pos(i,j);
    }
}

//Sets board[row][column] to charatcer c
void Board::set_pos(int row, int column, const char c)
{
  assert(row < ROWS);
  assert(column < COLUMNS);

  board[row][column] = c;
}

//Returns character at board[row][column]
char Board::get_pos(int row, int column) const
{
  assert(row <= ROWS);
  assert(column <= COLUMNS);

  return  board[row][column];
}

//Cout a 2-dimensional game board (example at bottom of function)
void Board::display_board() const
{
  //PRINT HEADING
  cout<<"    " <<YELLOW <<"A  B  C  D  E  F  G  H\n";
  cout<<RESET <<"   /----------------------\\" <<endl;

  //PRINT ALL ELEMENTS OF COLOR DEPENDENT UPON SYMBOL
  for(int i = 0; i < ROWS; i++)
    {
      cout<<" " <<YELLOW <<(i+1) <<RESET <<"|";
      for(int j = 0; j < COLUMNS; j++)
	{
	  cout<<"[";

	  if(board[i][j] == PLAYER1)
	    cout<<BLUE;  //Player1 color
	  else if(board[i][j] == PLAYER2)
	    cout<<GREEN;  //Player2 color

	  cout<<board[i][j] <<RESET <<"]";
	}
      cout<<"|\n";
    }
  cout<<"   \\----------------------/" <<endl;
}
//Example print without color
//     A  B  C  D  E  F  G  H 
//   /------------------------\ 
// 1 |[O][X][O][ ][O][ ][ ][O]|
// 2 |[ ][O][O][ ][O][ ][ ][ ]|
// 3 |[O][O][O][O][X][ ][O][ ]|
// 4 |[O][ ][O][ ][ ][ ][ ][ ]|
// 5 |[ ][O][X][ ][O][ ][O][ ]|
// 6 |[O][O][O][ ][X][ ][ ][ ]|
//   \------------------------/
