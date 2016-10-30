#include "tictactoemanager.h"
#include "tictactoeboard.h"
#include "tictactoeplayer.h"
#include <iostream>
#include <stdexcept>
#include <chrono>
#include <thread>

TicTacToeManager::TicTacToeManager(TicTacToeBoard* board, TicTacToePlayer* player1,
  TicTacToePlayer* player2)
{
  game_board = board;
  players[0] = player1;
  players[1] = player2;

  player_names[0] = player1 -> GetName();
  player_names[1] = player2 -> GetName();

  player_symbols[0] = player1 -> GetSymbol();
  player_symbols[1] = player2 -> GetSymbol();
}

void TicTacToeManager::PlayGame()
{
  std::cout << "Game Starting..." << std::endl;
  std::cout << player_names[0] << "(" << player_symbols[0] << ")" <<
    " vs. " << player_names[1] << "(" << player_symbols[1] << ")" << std::endl;

  game_board -> PrettyPrintBoard();
  std::this_thread::sleep_for(std::chrono::milliseconds(2000));

  ValidateGameArgs();

  std::cout << player_names[0] << " will go first." << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(500));

  bool current_player_index = 0;
  int turn_result = TakeTurn(current_player_index);
  bool is_tie = 0;

  GamePrint(current_player_index);

  while (turn_result == -1)
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    current_player_index = !current_player_index;
    turn_result = TakeTurn(current_player_index);

    if (turn_result == -1)
    {
      if (game_board -> BoardIsFull())
      {
        is_tie = 1;
        break;
      }
      
      GamePrint(current_player_index);
    }
  }
  if (is_tie)
  {
    std::cout << "Tie. :( Sad." << std::endl;
  }
  else
  {
    EndGame(players[current_player_index]);
  }
}

void TicTacToeManager::ValidateGameArgs()
{
  if ((player_symbols[0] == player_symbols[1]) ||
    (player_symbols[0] != 'O' && player_symbols[0] != 'X') ||
    (player_symbols[1] != 'O' && player_symbols[1] != 'X'))
  {
    throw std::invalid_argument("The game players must not have the same symbol and must be either X or O");
  }
}

void TicTacToeManager::EndGame(TicTacToePlayer* winner)
{
  std::cout << "GAME OVER!! " << winner -> GetName() << "(" << winner -> GetSymbol() << ") WINS!!" << std::endl;
  game_board -> PrettyPrintBoard();
  std::cout << "      |      " << std::endl;
  std::cout << "     / \\     " << std::endl;
  std::cout << "    / _ \\    " << std::endl;
  std::cout << "   |.o '.|   " << std::endl;
  std::cout << "   |'._.'|   " << std::endl;
  std::cout << "   |     |   " << std::endl;
  std::cout << " ,'|  |  |`. " << std::endl;
  std::cout << "/  |  |  |  \\" << std::endl;
  std::cout << "|,-'--|--'-.|" << std::endl;
}

int TicTacToeManager::TakeTurn(bool player_index)
// return 0: player 1 wins
// return 1: player 2 wins
// return -1: game continues
{
  int move = players[player_index] -> MakeMove(game_board);
  if (!game_board -> MoveIsValid(move))
  {
    return !player_index;
  }
  game_board -> MakeMove(move, player_symbols[player_index]);

  if (game_board -> GameIsOver())
  {
    return player_index;
  }

  return -1;
}

void TicTacToeManager::GamePrint(bool player_index)
{
  std::cout << "---------------------------" << std::endl;
  std::cout << player_names[player_index] << "(" << player_symbols[player_index] << ")";
  game_board -> PrettyPrintBoard();
  std::cout << "---------------------------" << std::endl;
}
