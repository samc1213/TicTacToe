#include <string>
#include <stdexcept>
#include "tictactoeplayer.h"
#include "tictactoeboard.h"


TicTacToePlayer::TicTacToePlayer(char player_symbol)
{
  if (player_symbol == 'X' || player_symbol == 'O')
  {
    TicTacToePlayer::player_symbol = player_symbol;
  }
  else
  {
    throw std::invalid_argument("player_symbol must be X or O");
  }
}

char TicTacToePlayer::GetSymbol()
{
  return TicTacToePlayer::player_symbol;
}

void TicTacToePlayer::SetName(char* name)
{
  TicTacToePlayer::player_name = name;
}

char* TicTacToePlayer::GetName()
{
  return TicTacToePlayer::player_name;
}
