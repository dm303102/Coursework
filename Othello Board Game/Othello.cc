//Doug Morgan
//6-02-05
//
//File: Othello Implementation file
//Othello class is derived from the game class in game.h which implements
//the strategy game of Othello - two opponents "outflank" each other's pieces
//by positioning their pieces in such a way that one or more opponent pieces
//in a row are between two of his/her pieces

#include "Othello.h"
#include <cctype>
#include<iostream>
#include <sstream>

using namespace std;

//Post: Intializes Oth_board and set the 4 centers pieces according to
//Othello rules
Othello::Othello()
{
  Board new_board;
  Oth_board = new_board;

  Oth_board.set_pos(3, 3, PLAYER1);

  Oth_board.set_pos(3, 4, PLAYER2);

  Oth_board.set_pos(4, 3, PLAYER2);

  Oth_board.set_pos(4, 4, PLAYER1);
}

//Copy Constructor
Othello::Othello(const Othello& game)
{
  Oth_board = game.get_board();
}

//Post:: displays current game information and the Othello
//game board
void Othello::display_status() const
{
  cout<<"\n     Player1(Human) = " <<BLUE <<PLAYER1 <<endl <<RESET;
  cout<<"     Player2(Computer) = " <<GREEN <<PLAYER2 <<endl <<RESET;
  
  if(winning() == HUMAN)
    cout<<"     Player 1 is winning\n";
  else if(winning() == COMPUTER)
    cout<<"     Computer is winning\n";
  else
    cout<<"     Game tied\n";
  Oth_board.display_board();
}

//Post: Re-initializes board to start setup
void Othello::restart()
{
  Othello new_board;
  Oth_board = new_board.get_board();
  game::restart();
}

//Post: Return a pointer to a copy of the current game
game* Othello::clone() const
{
  return new Othello(*this);
}

//Post: Returns true only if move is a legal move in Othello rules
bool Othello::is_legal(const string& move) const
{
  char opponent, player;
  list<std::string> rows;

  if(next_mover() == HUMAN)
    {
      opponent = PLAYER2;
      player = PLAYER1;
    }
  else
    {
      opponent = PLAYER1;
      player = PLAYER2;
    }

  //Empty is there are no legal moves
  rows = rows_obtained(move, opponent, player);

  if(rows.empty())
    return false;
  return true;
}

//Post: Evaluates the board and returns a list of rows lined with the
//current player move (e.g. "up_left", "up", "right")
list<std::string> Othello::rows_obtained(const string& move, char opponent,
			     char player) const
{
  list<std::string> rows;
  int i = 0;
  int column;
  int row;
  char column_c;

  //CHECK INPUT FORMAT WITH SPACES ALLOWED
  while(isspace(move[i]))
    i++;

  if(isalpha((move[i])))
    {
      column_c = tolower(char(move[i]));  //grab column letter
      column = (int(column_c) - int('a')); //convert column letter to number
      i++;
    }

  else
    return rows;

  if(isdigit(move[i]))
    row = int(move[i] - '0') - 1;  //grab row number
  else
    return rows;

  //CHECK IF ROW AND COLUMN IS IN BOUNDS OF THE BOARD
  if((column >= COLUMNS) || (row >= ROWS))
    return rows;

  //CHECK IF POSITION IS OPEN
  if(Oth_board.get_pos(row, column) != ' ')
    return rows;

  char up_right = Oth_board.get_pos(row-1, column+1);
  char low_right = Oth_board.get_pos(row+1, column+1);
  char right = Oth_board.get_pos(row, column+1);
  char up = Oth_board.get_pos(row-1, column);
  char down = Oth_board.get_pos(row+1, column);
  char up_left = Oth_board.get_pos(row-1, column-1);
  char left = Oth_board.get_pos(row, column-1);
  char low_left = Oth_board.get_pos(row+1, column-1);

  int column_check = column;
  int row_check = row;

  //CHECK EACH POSITION AROUND THE MOVE LOCATION AND EVALUATE
  //IT TO BE A LEGAL MOVE OR NOT
  if(up_right == opponent && row != 0 && column != (COLUMNS - 1))
    {
      while((column_check < COLUMNS) && (row_check >= 0) && (up_right  == opponent))
	{
	  column_check++;
	  row_check--;

	  if((column_check < COLUMNS) && (row_check >= 0))
	    up_right = Oth_board.get_pos(row_check, column_check);
	}
      if(up_right == player)
	rows.push_front("up_right");
    }

  column_check = column;
  row_check = row;

  if(low_right == opponent && row != (ROWS - 1) && column != (COLUMNS - 1))
    {
      while((column_check < COLUMNS) && (row_check < ROWS) && (low_right  == opponent))
	{
	  column_check++;
	  row_check++;

	  if((column_check < COLUMNS) && (row_check < ROWS))
	    low_right = Oth_board.get_pos(row_check, column_check);
	}
      if(low_right == player)
	rows.push_front("low_right");;
    }

  column_check = column;
  row_check = row;

  if(right == opponent && column != (COLUMNS - 1))
    {
      while((column_check < COLUMNS) && (right == opponent))
	{
	  column_check++;

	  if(column_check < COLUMNS)
	    right = Oth_board.get_pos(row_check, column_check);
	}
      if(right == player)
	rows.push_front("right");
    }

  column_check = column;
  row_check = row;

  if(up == opponent && row != 0)
    {
      while((row_check >= 0) && (up == opponent))
	{
	  row_check--;
	  if(row_check >= 0)
	    up = Oth_board.get_pos(row_check, column_check);
	}
      if(up == player)
	rows.push_front("up");
    }

  column_check = column;
  row_check = row;

  if(down == opponent && row != (ROWS - 1))
    {
      while((row_check < ROWS) && (down == opponent))
	{
	  row_check++;

	  if(row != (ROWS - 1))
	    down = Oth_board.get_pos(row_check, column_check);
	}
      if(down == player)
	rows.push_front("down");
    }

  column_check = column;
  row_check = row;

  if(up_left == opponent && row != 0 && column != 0)
    {
      while((column_check >= 0) && (row_check >= 0) && (up_left == opponent))
	{
	  column_check--;
	  row_check--;

	  if((column_check >= 0) && (row_check >= 0))
	    up_left = Oth_board.get_pos(row_check, column_check);
	}
      if(up_left == player)
	rows.push_front("up_left");
    }

  column_check = column;
  row_check = row;

  if(left == opponent && column != 0)
    {
      while((column_check >= 0) && (left == opponent))
	{
	  column_check--;

	  if(column_check >= 0)
	    left = Oth_board.get_pos(row_check, column_check);
	}
      if(left == player)
	rows.push_front("left");
    }

  column_check = column;
  row_check = row;

  if(low_left == opponent && row != (ROWS - 1) && column != 0)
    {
      while((column_check >= 0) && (row_check < ROWS) && (low_left == opponent))
	{
	  column_check--;
	  row_check++;

	  if((column_check >= 0) && (row_check < ROWS))
	    low_left = Oth_board.get_pos(row_check, column_check);
	}
      if(low_left == player)
	rows.push_front("low_left");
    }
  return rows;
}

//Post: Checks if move is legal and if so, carries out move on Oth_board
//"outflanking" any opponent pieces in a row
void Othello::make_move(const std::string& move)
{
  list<std::string> rows;
  int i = 0;
  int column_check, row_check;
  char piece;
  char opponent, player;

  //assert(is_legal(move));

  //CHECK INPUT FORMAT WITH SPACES ALLOWED
  while(i < move.length() && isspace(move[i]))
    i++;

  char column_c = tolower(char(move[i]));  //grab column letter
  int column = (int(column_c) - int('a')); //convert column letter to number
  i++;

  int row_num = (move[i] - '0') - 1;  //grab row number

  if(next_mover() == HUMAN)
    {
      opponent = PLAYER2;
      player = PLAYER1;
    }
  else
    {
      opponent = PLAYER1;
      player = PLAYER2;
      cout<<"\nComputer moves at " <<move <<endl;
    }

  //CONTAINS ALL LEGAL MOVES
  rows = rows_obtained(move, opponent, player);

  while(!rows.empty())
    {
      string row = rows.front();
      rows.pop_front();

      column_check = column;
      row_check = row_num;

      //MAKE EACH MOVE IN rows
      if(row == "up_right")
	{
	  row_check--;
	  column_check++;
	  piece = Oth_board.get_pos(row_check, column_check);

	  while(piece == opponent)
	    {
	      Oth_board.set_pos(row_check, column_check, player);
	      row_check--;
	      column_check++;
	      piece = Oth_board.get_pos(row_check, column_check);
	    }
	}
      else if(row == "right")
        {
          column_check++;
          piece = Oth_board.get_pos(row_check, column_check);

          while(piece == opponent)
            {
              Oth_board.set_pos(row_check, column_check, player);
              column_check++;
              piece = Oth_board.get_pos(row_check, column_check);
            }
        }
      else if(row == "low_right")
        {
	  row_check++;
          column_check++;
          piece = Oth_board.get_pos(row_check, column_check);

          while(piece == opponent)
            {
              Oth_board.set_pos(row_check, column_check, player);
	      row_check++;
              column_check++;
              piece = Oth_board.get_pos(row_check, column_check);
            }
        }
      else if(row == "up")
        {
          row_check--;
          piece = Oth_board.get_pos(row_check, column_check);

          while(piece == opponent)
            {
              Oth_board.set_pos(row_check, column_check, player);
              row_check--;
	      piece = Oth_board.get_pos(row_check, column_check);
            }
        }
      else if(row == "down")
        {
          row_check++;
          piece = Oth_board.get_pos(row_check, column_check);

          while(piece == opponent)
            {
              Oth_board.set_pos(row_check, column_check, player);
              row_check++;
              piece = Oth_board.get_pos(row_check, column_check);
            }
        }
      else if(row == "up_left")
        {
          row_check--;
          column_check--;
          piece = Oth_board.get_pos(row_check, column_check);

          while(piece == opponent)
            {
              Oth_board.set_pos(row_check, column_check, player);
              row_check--;
              column_check--;
              piece = Oth_board.get_pos(row_check, column_check);
            }
        }
      else if(row == "low_left")
        {
          row_check++;
          column_check--;
          piece = Oth_board.get_pos(row_check, column_check);

          while(piece == opponent)
            {
              Oth_board.set_pos(row_check, column_check, player);
              row_check++;
              column_check--;
              piece = Oth_board.get_pos(row_check, column_check);
            }
        }
      else if(row == "left")
        {
          column_check--;
          piece = Oth_board.get_pos(row_check, column_check);

          while(piece == opponent)
            {
              Oth_board.set_pos(row_check, column_check, player);
              column_check--;
              piece = Oth_board.get_pos(row_check, column_check);
            }
        }
    }

  Oth_board.set_pos(row_num, column, player);

  game::make_move(move);

  //Skips next player if they have no more moves
  int s_i = 0;
  int s_j = 0;
  bool player1 = false;  //true if there are any more moves for player 1
  bool player2 = false;  //true if there are any more moves for player 2

  for(s_i = 0; s_i < ROWS; s_i++)
    {
      for(s_j = 0; s_j < COLUMNS; s_j++)
        {
          string move;
	  move = convert_move(s_j, s_i);  //convert ints to move string
          if(is_legal(move))
            {
              if(next_mover() == HUMAN)
                player1 = true;
              else
                player2 = true;
            }
        }
    }

  if((next_mover() == HUMAN) && player1 == false)
    {
      game::make_move(" ");
      cout<<"Player 1 skipped(no moves currently available)\n";
    }
  else if((next_mover() == COMPUTER) && player2 == false)
    game::make_move(" ");
}
    
//Post: returns a positive value if HUMAN player 1 is winning or, a negative
//value is player 2 is winning or 0 if the game is tied
int Othello::evaluate() const
{
  int i = 0;
  int j = 0;
  int eval = 0;

  for(i = 0; i < ROWS; i++)
    {
      for(j = 0; j < COLUMNS; j++)
        {
	  if(Oth_board.get_pos(i, j) == PLAYER1)
	    eval++;
	  else if(Oth_board.get_pos(i, j) == PLAYER2)
	    eval--;
	}
    }
  return eval;
}

bool Othello::is_game_over( ) const
{
  int i = 0;
  int j = 0;
  bool player1 = false;  //true if there are any more moves for player 1
  bool player2 = false;  //true if there are any more moves for player 2

  for(i = 0; i < ROWS; i++)
    {
      for(j = 0; j < COLUMNS; j++)
        {
	  string move;
	  move = convert_move(j, i);  //convert ints to move string
	  if(is_legal(move))
	    {
	      if(next_mover() == HUMAN)
		player1 = true;
	      else
		player2 = true;
	    }
	}
    }

  /*
  if(player1 == false || player2 == false)
    {
      for(i = 0; i < ROWS; i++)
	{
	  for(j = 0; j < COLUMNS; j++)
	    {
	      string move;
	      move = convert_move(j, i);  //convert ints to move string
	      if(is_legal(move))
		{
		  if(next_mover() == HUMAN)
		    player1 = true;
		  else
		    player2 = true;
		}
	    }
	}
    }
  */
  if(next_mover() == HUMAN)
    return (player1 == false);
  else
    return(player2 == false);
} 

//Post: returns the player - HUMAN or COMPUTER - who currently has the greatest
//number of pieces on the board
game::who Othello::winning( ) const
{
  int value = evaluate();

  if(value > 0)
    return HUMAN;
  else if(value < 0)
    return COMPUTER;
  else
    return NEUTRAL;
}

//Post: Computes all the possible legal moves for the current player and puts
//them in moves
void Othello::compute_moves(std::queue<std::string>& moves) const
{
  int i = 0;
  int j = 0;
  string move;

  for(i = 0; i < ROWS; i++)
    {
      for(j = 0; j < COLUMNS; j++)
        {
	  move = convert_move(j, i);
	  if(is_legal(move))
	    moves.push(move);
	}
    }
}

std::string Othello::convert_move(int column, int row) const
{
  string move;
  char s_row, s_column;

  s_row = char(row + 1) + '0';  //construct row string
  s_column = char(column + int('a'));  //convert column number to letter
  move += s_column;
  move += s_row;

  return move;
}

