#include <string>
#include "tictactoeboard.h"
#include "tictactoeplayer.h"

#ifndef SAMPLAYER_H
#define SAMPLAYER_H

class SamPlayer : public TicTacToePlayer
{
  public:
    SamPlayer(char player_symbol);
    int MakeMove(TicTacToeBoard* board);
};

#endif
