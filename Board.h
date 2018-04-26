//Seth Perts
//CPSC 444
//Project Connect 4
//Class where the data is stored for the board and gameplay is handled.
#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Box.h"

class Board {

public:
	Board();
	void printBoard();
	bool isLegalMove(int column);
	int makeMove(string controlledBy, int column);
	string gameOver();
	void resetBoard();
	Box board[6][7];
private:
	
};

#endif // BOARD_H

