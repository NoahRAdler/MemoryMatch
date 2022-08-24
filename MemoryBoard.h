/*
 * header file for program
 *
 * Name: Noah Adler
 * Date: August 18, 2019
 */
#pragma once
#include <string>

using namespace std;

class Board 
{
	/*
	 * varriables, arrays, methods
	 * 
	 * return: assigns values and outputs them aswell.
	 */
	private:
		const static int ARRAYSIZE = 4;
		string boardNumPlace[ARRAYSIZE][ARRAYSIZE];
		string blankBoardGrid[ARRAYSIZE][ARRAYSIZE];
		string boardGrid[ARRAYSIZE][ARRAYSIZE];
		int increment;
		int holdX;
		int holdY;
		
	public:
		Board();
		void boardPrint() const;
		void boardPrintBlank() const;
		void boardClear();
		void boardChose(int, int);
		void boardRandom();
		void boardMatchUp(int, int, int);
		bool boardWinLose();
		bool errorCheck(int, int);
		int getArraySize();

};