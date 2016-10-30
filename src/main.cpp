#include<iostream>
#include <string>
#include "tictactoeboard.h"
#include "tictactoeplayer.h"
#include "tictactoemanager.h"
#include "samplayer.h"

int main(int argc, char *argv[]){
  TicTacToeBoard* b = new TicTacToeBoard();

  TicTacToePlayer* player1 = new SamPlayer('X');
  TicTacToePlayer* player2 = new SamPlayer('O');

  TicTacToeManager* game_manager = new TicTacToeManager(b, player1, player2);

  game_manager -> PlayGame();

  return 0;
}
