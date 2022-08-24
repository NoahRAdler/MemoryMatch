/* 
 *implementation file
 *
 * Name: Noah Adler
 * Date: August 18, 2019
 */
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "MemoryBoard.h"

using namespace std;

/*
 * constructor
 *
 * Return: makes all boards set up and establishes the increment
 */
Board::Board()
{
	increment = 1;

	for (int row = 0; row < ARRAYSIZE; row++)
	{
		for (int col = 0; col < ARRAYSIZE; col++)
		{
			boardGrid[row][col] = "<*>";
		}
	}

	for (int row = 0; row < ARRAYSIZE; row++)
	{
		for (int col = 0; col < 2; col++)
		{
			boardNumPlace[row][col] = "<" + to_string(increment) + ">";
		}
		increment++;
		for (int col = 2; col < 4; col++)
		{
			boardNumPlace[row][col] = "<" + to_string(increment) + ">";
		}
		increment++;
	}

	for (int row = 0; row < ARRAYSIZE; row++)
	{
		for (int col = 0; col < ARRAYSIZE; col++)
		{
			blankBoardGrid[row][col] = "<*>";
		}
	}
}
/*
 * print method
 *
 * Return: Prints out all values in blank for when values reset or for other uses
 */
void Board::boardPrintBlank() const
{
	for (int row = 0; row < ARRAYSIZE; row++)
	{

		for (int col = 0; col < ARRAYSIZE; col++)
		{
			cout << blankBoardGrid[row][col] << " ";
		}
		cout << endl;
	}
}

/*
 * Print statement
 *
 * Return: Prints out the current object's board, keeps track of card places and the selected
 */
void Board::boardPrint() const
{
	for (int row = 0; row < ARRAYSIZE; row++)
	{

		for (int col = 0; col < ARRAYSIZE; col++)
		{
			cout << boardGrid[row][col] << " ";
		}
		cout << endl;
	}

}

/*
 * This method translates known values array to the template array 
 *
 * Parameter: x  row of the array
 * Parameter: y  column of the array
 * Return: one value to the other
 */
void Board::boardChose(int x, int y)
{

	boardGrid[x][y] = boardNumPlace[x][y];

}

/*
 * this checks for errors and already face up cards
 *
 * Parameter: x row of array
 * Parameter: y column array
 * Return: true for continue false for otherwise
 */
bool Board::errorCheck(int x, int y)
{
	if (((x > - 1) && (x <= ARRAYSIZE - 1)) && ((y > - 1) && (y <= ARRAYSIZE - 1)))
	{
		if (boardGrid[x][y] == "<*>")
		{
			return false;
		}
		else
		{
			cout << "Card is already face up" << endl;

			return true;
		}

	}
	else
	{
		cout << "Invalid row and/or column" << endl << endl << endl;

		return true;
	}

}

/*
 * this method makes the template board cleared and all cards face down
 *
 * Return: resets all values to default for loop
 */
void Board::boardClear()
{
	for (int row = 0; row < ARRAYSIZE; row++)
	{
		for (int col = 0; col < ARRAYSIZE; col++)
		{
			boardGrid[row][col] = "<*>";
		}
	}

}

/*
 * For working with the array size
 *
 * Return: Array size
 */
int Board::getArraySize()
{
	return ARRAYSIZE;
}

/*
 * Randomizer method
 *
 * Return: will randomize the current board
 */
void Board::boardRandom()
{
	string holder;
	int x;
	int y;

	srand(time(NULL));

	for (int row = 0; row < ARRAYSIZE; row++)
	{
		for (int col = 0; col < ARRAYSIZE; col++)
		{
			x = rand() % ARRAYSIZE;

			y = rand() % ARRAYSIZE;

			holder = boardNumPlace[row][col];
			boardNumPlace[row][col] = boardNumPlace[x][y];

			boardNumPlace[x][y] = holder;
		}
	}

}

/*
 * This decides if the cards are all up for the win lose
 *
 * Return: gives a boolean for a win and lose if statement
 */
bool Board::boardWinLose()
{
	int checker = 0;

	for (int row = 0; row < ARRAYSIZE; row++)
	{
		for (int col = 0; col < ARRAYSIZE; col++)
		{
			if (boardGrid[row][col] != "<*>")
			{
				checker++;
				if (checker == 16)
				{
					return  true;
				}
			}
		}
	}
	return false;

}

/*
 * Allowes the main aspect of the game which is matching up cards
 *
 * Parameter: x coord for storing first then matching
 * Parameter: y coord for storing first then matching
 * Parameter: i is the count on the current pair loop which works as a control
 * Return: takes both values for both sets, stores them, compares them, if correct keeping each up, otherwise both are down.
 */
void Board::boardMatchUp(int x, int y, int i)
{

	if (i == 1)
	{
		holdX = x;
		holdY = y;
	}
	else if (i == 2)
	{
		if (boardNumPlace[holdX][holdY] == boardNumPlace[x][y])
		{
			cout << "Match" << endl;
		}
		else
		{
			cout << "Nope" << endl;

			boardGrid[x][y] = "<*>";
			boardGrid[holdX][holdY] = "<*>";

		}
	}

}