#include "samplayer.h"
#include "tictactoeplayer.h"
#include <iostream>

SamPlayer::SamPlayer(char player_symbol)
  : TicTacToePlayer(player_symbol)
{
  char* name = new char[4];
  strcpy(name, "Sam");
  TicTacToePlayer::SetName(name);
}

int SamPlayer::MakeMove(TicTacToeBoard* board)
{
  for (int i = 0; i < 9; i++)
  {
    if (board -> MoveIsValid(i))
    {
      return i;
    }
  }
  return 0;
}
