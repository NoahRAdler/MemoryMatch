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
	int tries = 15;
	bool valid = false;
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
	 * Player has 15 tries to match 2 numbers 
	 */
	for (int run = 0; run < tries; run++)
	{
		for (int run1 = 0; run1 < 2; run1++)
		{
			/*
			 * Input error check
			 */
			valid = false;
			do
			{
				cout << "Enter a number pair: " << flush << endl;
				cin >> coordX >> coordY;
				cout << endl;
				if(cin.good()) 
				{ 
					valid = true;
				}
				else
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Input error, enter again, ensure to use a number" << endl;
				}
			} while (!valid);
			
			/*
			 * board error check
			 */
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
			run = tries;
		}
	}
	if (!board1.boardWinLose())
	{
		cout << endl << "You lost" << endl;
	}

	system("pause");

}
