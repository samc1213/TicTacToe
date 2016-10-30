#ifndef TICTACTOEBOARD_H
#define TICTACTOEBOARD_H


class TicTacToeBoard
{
    char board[9];
  public:
    TicTacToeBoard();
    void PrintBoard();
    void PrettyPrintBoard();
    bool TryDoTurn(int location);
    char* GetBoard();
    void MakeMove(int position, char symbol);
    bool GameIsOver();
    bool MoveIsValid(int move);
    bool BoardIsFull();
};

#endif
