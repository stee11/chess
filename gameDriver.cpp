// Name: Steven Kolln
// Description: Driver program for final exam chess game. 
// Creates a board with pieces to play with


#include "GameBoard.h"

#include <iostream>
#include <fstream>

using namespace std;

// You may edit this driver as long as the basic functionality and class / method names remain the same.
// I will be using this driver to test ALL submitted programs.

int main (void)
{
	ifstream initBoardStr;
	string initBoardFile;
    GameBoard newBoard;
	
	int option, gameEndOpt;
	int fromRow, toRow;
	int fromCol, toCol;
    
	bool gameEnd = false;
    
    while (!gameEnd) 
	{
		cout << "The current board is:" << endl; 
		cout << newBoard.object2string();
		cout << "What do you want to do?" << endl;
		cout << "(1) Make a move" << endl;
		cout << "(2) End the game" << endl;
		cin >> option;
		switch (option)
		{
			case 1: // Make a move
				gameEnd = false;
				cout << "Enter coordinates of piece to move: ";
				cin >> fromRow >> fromCol;
				cout << "Enter coordinates to move piece to: ";
				cin >> toRow >> toCol;

				if (newBoard.doMove (fromRow, fromCol, toRow, toCol))
					cout << "Move Succeeded\n";
				else
					cout << "*** Invalid Move ***\n";
				break;
			case 2: //End the game
				{			
				gameEnd = true;
				bool tryEndAgain = true;
				while (tryEndAgain)
				{
					tryEndAgain = false;
					
					cout << "How did the game end?" << endl;
					cout << "(1) Green Won" << endl;
					cout << "(2) Yellow Won" << endl;
					cout << "(3) Green Resigned" << endl;
					cout << "(4) Yellow Resigned" << endl;
					cout << "(5) It's a Draw" << endl;
					cout << "(6) OOPS! Continue Game" << endl;
					cin >> gameEndOpt;
                    
					switch (gameEndOpt) {
						case 1: // Green Won
							cout << "Green gains " << WIN << " points" << endl;
							break;
						case 2: // Yellow Won
							cout << "Yellow gains " << WIN << " points" << endl;
							break;
						case 3: // Green Resigns
							cout << "Yellow gains " << RES_WIN << " points" << endl;
							cout << "Green forfeits " << RES_LOSE << " points" << endl;
							break;
						case 4: // Yellow Resigns
							cout << "Green gains " << RES_WIN << " points" << endl;
							cout << "Yellow forfeits " << RES_LOSE << " points" << endl;
							break;
						case 5: // Draw
							cout << "Green gains " << DRAW << " points" << endl;
							cout << "Yellow gains " << DRAW << " points" << endl;
							break;
						case 6:   // Don't end game
							cout << "Continuing Game" << endl;
							gameEnd = false;
							break;
						default:
							cout << "Invalid game end option" << endl;
							tryEndAgain = true;
							break;
					} // end switch (gameEndOpt)
				} // while (tryEndAgain)
				break;
				}
			default:
				gameEnd = false;
				cout << "Invalid option" << endl;
				break;
		} // end switch (option)
	} // while (!gameEnd) 
} // end main
