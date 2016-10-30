#include "tictactoeboard.h"
#include "corefunctions.h"
#include <iostream>

TicTacToeBoard::TicTacToeBoard()
{
  for (int i = 0; i < 9; i++)
  {
    TicTacToeBoard::board[i] = ' ';
  }
}

void TicTacToeBoard::PrintBoard()
{
  for (int i = 0; i < 9; i++)
  {
    std::cout << board[i] << std::endl;
  }
}

void TicTacToeBoard::PrettyPrintBoard()
{
  std::cout << std::endl;
  std::cout << std::endl;
  printf("%c | %c | %c", board[0], board[1], board[2]);
  std::cout << std::endl;
  printf("--  --  --");
  std::cout << std::endl;
  printf("%c | %c | %c", board[3], board[4], board[5]);
  std::cout << std::endl;
  printf("--  --  --");
  std::cout << std::endl;
  printf("%c | %c | %c", board[6], board[7], board[8]);
  std::cout << std::endl;
  std::cout << std::endl;
}

char* TicTacToeBoard::GetBoard()
{
  return board;
}

void TicTacToeBoard::MakeMove(int position, char symbol)
{
  board[position] = symbol;
}

bool TicTacToeBoard::GameIsOver()
{
  //horizontals
  for (int i = 0; i < 9; i = i+3)
  {
    if (( (board[i] == board[i + 1]) && (board[i + 1]== board[i + 2]) ) && board[i] != ' ')
    {
      return 1;
    }
  }

  //verticals
  for (int i = 0; i < 3; i++)
  {
    if (( (board[i] == board[i + 3]) && (board[i + 3] == board[i + 6]) ) && board[i] != ' ')
    {
      return 1;
    }
  }
  //diagonals
  if (( (board[0] == board[4]) && (board[4] == board[8]) ) && board[0] != ' ')
  {
    return 1;
  }

  if (( (board[2] == board[4]) && (board[4] == board[6]) ) && board[2] != ' ')
  {
    return 1;
  }
  return 0;
}


bool TicTacToeBoard::MoveIsValid(int move)
//0 is invalid, 1 is valid
{
  if (board[move] == ' ')
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

bool TicTacToeBoard::BoardIsFull()
{
  for (int i = 0; i < 9; i++)
  {
    if (board[i] == ' ')
    {
      return 0;
    }
  }
  return 1;
}
