#include "tictactoeboard.h"
#include "tictactoeplayer.h"

#ifndef TICTACTOEMANAGER_H
#define TICTACTOEMANAGER_H


class TicTacToeManager
{
  private:
    TicTacToeBoard* game_board;
    TicTacToePlayer* player1;
    TicTacToePlayer* player2;
    char player_symbols[2];
    char* player_names[2];
    TicTacToePlayer* players[2];
    void ValidateGameArgs();
    void EndGame(TicTacToePlayer* winner);
    int TakeTurn(bool player_index);
    void GamePrint(bool player_index);
  public:
    TicTacToeManager(TicTacToeBoard* board, TicTacToePlayer* player1,
      TicTacToePlayer* player2);
    void PlayGame();
};

#endif
