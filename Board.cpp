//Seth Perts
//CPSC 444
//Project Connect 4
//Class where the data is stored for the board and gameplay is handled.
#ifndef BOARD_CPP
#define BOARD_CPP

#include "Board.h"


Board::Board()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			Box b;
			b.setControlledBy("-");
			this->board[i][j] = b;
		}
	}
}


void Board::printBoard()
{
	cout << "\nCurrent Board\n";
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			cout << board[i][j].getControlledBy() << " ";
		}
		cout << endl;
	}
	cout << endl;
}


bool Board::isLegalMove(int column)
{
	if (board[0][column].getControlledBy() == "-")
	{
		return true;
	}
	else
	{
		return false;
	}
}


int Board::makeMove(string controlledBy, int column)
{
	for (int i = 0; i < 6; i++)
	{
		if (i == 5)
		{
			if (board[i][column].getControlledBy() == "-")
			{
				board[i][column].setControlledBy(controlledBy);
			}
			return i;
			break;
		}
		if (board[i + 1][column].getControlledBy() != "-")
		{
			board[i][column].setControlledBy(controlledBy);
			return i;
			break;
		}
	}
}


string Board::gameOver()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (board[i][j].getControlledBy() == "P")
			{
				if ((i - 3) >= 0)
				{
					if ((board[i - 1][j].getControlledBy() == "P") && (board[i - 2][j].getControlledBy() == "P") && (board[i - 3][j].getControlledBy() == "P"))
					{
						return "P";
					}
				}
				if ((i + 3) <= 5)
				{
					if ((board[i + 1][j].getControlledBy() == "P") && (board[i + 2][j].getControlledBy() == "P") && (board[i + 3][j].getControlledBy() == "P"))
					{
						return "P";
					}
				}
				if ((j - 3) >= 0)
				{
					if ((board[i][j - 1].getControlledBy() == "P") && (board[i][j - 2].getControlledBy() == "P") && (board[i][j - 3].getControlledBy() == "P"))
					{
						return "P";
					}
				}
				if ((j + 3) <= 6)
				{
					if ((board[i][j + 1].getControlledBy() == "P") && (board[i][j + 2].getControlledBy() == "P") && (board[i][j + 3].getControlledBy() == "P"))
					{
						return "P";
					}
				}
				if (((i - 3) >= 0) && ((j - 3) >= 0))
				{
					if ((board[i - 1][j - 1].getControlledBy() == "P") && (board[i - 2][j - 2].getControlledBy() == "P") && (board[i - 3][j - 3].getControlledBy() == "P"))
					{
						return "P";
					}
				}
				if (((i - 3) >= 0) && ((j + 3) <= 6))
				{
					if ((board[i - 1][j + 1].getControlledBy() == "P") && (board[i - 2][j + 2].getControlledBy() == "P") && (board[i - 3][j + 3].getControlledBy() == "P"))
					{
						return "P";
					}
				}
				if (((i + 3) <= 5) && ((j + 3) <= 6))
				{
					if ((board[i + 1][j + 1].getControlledBy() == "P") && (board[i + 2][j + 2].getControlledBy() == "P") && (board[i + 3][j + 3].getControlledBy() == "P"))
					{
						return "P";
					}
				}
				if (((i + 3) <= 5) && ((j - 3) >= 0))
				{
					if ((board[i + 1][j - 1].getControlledBy() == "P") && (board[i + 2][j - 2].getControlledBy() == "P") && (board[i + 3][j - 3].getControlledBy() == "P"))
					{
						return "P";
					}
				}
			}
			else if (board[i][j].getControlledBy() == "A")
			{
				if ((i - 3) >= 0)
				{
					if ((board[i - 1][j].getControlledBy() == "A") && (board[i - 2][j].getControlledBy() == "A") && (board[i - 3][j].getControlledBy() == "A"))
					{
						return "A";
					}
				}
				if ((i + 3) <= 5)
				{
					if ((board[i + 1][j].getControlledBy() == "A") && (board[i + 2][j].getControlledBy() == "A") && (board[i + 3][j].getControlledBy() == "A"))
					{
						return "A";
					}
				}
				if ((j - 3) >= 0)
				{
					if ((board[i][j - 1].getControlledBy() == "A") && (board[i][j - 2].getControlledBy() == "A") && (board[i][j - 3].getControlledBy() == "A"))
					{
						return "A";
					}
				}
				if ((j + 3) <= 6)
				{
					if ((board[i][j + 1].getControlledBy() == "A") && (board[i][j + 2].getControlledBy() == "A") && (board[i][j + 3].getControlledBy() == "A"))
					{
						return "A";
					}
				}
				if (((i - 3) >= 0) && ((j - 3) >= 0))
				{
					if ((board[i - 1][j - 1].getControlledBy() == "A") && (board[i - 2][j - 2].getControlledBy() == "A") && (board[i - 3][j - 3].getControlledBy() == "A"))
					{
						return "A";
					}
				}
				if (((i - 3) >= 0) && ((j + 3) <= 6))
				{
					if ((board[i - 1][j + 1].getControlledBy() == "A") && (board[i - 2][j + 2].getControlledBy() == "A") && (board[i - 3][j + 3].getControlledBy() == "A"))
					{
						return "A";
					}
				}
				if (((i + 3) <= 5) && ((j + 3) <= 6))
				{
					if ((board[i + 1][j + 1].getControlledBy() == "A") && (board[i + 2][j + 2].getControlledBy() == "A") && (board[i + 3][j + 3].getControlledBy() == "A"))
					{
						return "A";
					}
				}
				if (((i + 3) <= 5) && ((j - 3) >= 0))
				{
					if ((board[i + 1][j - 1].getControlledBy() == "A") && (board[i + 2][j - 2].getControlledBy() == "A") && (board[i + 3][j - 3].getControlledBy() == "A"))
					{
						return "A";
					}
				}
			}
		}
	}
	return "-";
}


void Board::resetBoard()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			Box b;
			b.setControlledBy("-");
			this->board[i][j] = b;
		}
	}
}
#endif // BOARD_CPP