/*
 *main file
 *
 * Name: Noah Adler
 * Date: August 18, 2019
 */
 
#include <iostream>
#include <string>
#include "MemoryBoard.h"

using namespace std;


int main()
{
	int coordX;
	int coordY;
	string choiceST;
	
	Board board1;

	cout << "Randomize board y or n";
	cin >> choiceST;
	cout << endl;
	if (choiceST == "y")
	{
		board1.boardRandom();
	}

	board1.boardPrintBlank();
	cout << endl;
  
	/*
	 * Player has 15 trys to match 2 numbers 
	 */
	for (int run = 0; run < 15; run++)
	{
		for (int run1 = 0; run1 < 2; run1++)
		{
			cout << "Enter a number pair: " << endl;
			cin >> coordX >> coordY;
			cout << endl;

			while (board1.errorCheck(coordX - 1, coordY - 1))
			{
				cout << "Enter a number pair: " << endl;
				cin >> coordX >> coordY;
				cout << endl;
			}

			board1.boardChose(coordX - 1, coordY - 1);
			board1.boardPrint();
			cout << endl;

			board1.boardMatchUp(coordX - 1, coordY - 1, run1 + 1);
			if (run1 == 1)
			{
				board1.boardPrint();
				cout << endl;
			}
			
		}
		if (board1.boardWinLose())
		{
			cout << "Congrats!" << endl;
			run = 15;
		}
	}
	if (!board1.boardWinLose())
	{
		cout << endl << "You lost" << endl;
	}

	system("pause");

}
