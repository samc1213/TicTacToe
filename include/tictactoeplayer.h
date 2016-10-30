#include <string>
#include "tictactoeboard.h"

#ifndef TICTACTOEPLAYER_H
#define TICTACTOEPLAYER_H

class TicTacToePlayer
{
    char player_symbol;
    char* player_name;
  public:
    TicTacToePlayer(char player_symbol);
    char GetSymbol();
    char* GetName();
    void SetName(char* name);
    virtual int MakeMove(TicTacToeBoard* board) = 0;
};

#endif
