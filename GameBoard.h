// Name: Steven Kolln
// Description: Game Board class header file


#if !defined (GAMEBOARD_H)
#define GAMEBOARD_H

#include <iostream>
#include <iostream>
#include <fstream>

#include "Piece.h"
#include "President.h"
#include "Manager.h"
#include "Developer.h"
#include "Ceo.h"
#include "Supervisor.h"
#include "TeamLeader.h"

using namespace std;

const int MROWS = 8;
const int MCOLS = 8;
const int WIN = 10; 
const int RES_LOSE = -2; 
const int RES_WIN = 7; 
const int DRAW = 5; 


class GameBoard 
{
	
private:
	// DO: Add attributes here
    // The 2-d array is called board
	Piece *board[MROWS][MCOLS];
	//initializes the board through a text file
	//pre condition: the text file exists in directory all ready.
	void initBoard ();
	int noKill;
	
public:
	//constructor
	//pre condition is required text field with correct name already exists in program and directory.
    GameBoard ();
	//Rturns a boolean for whether or not the move is valid or not. If true, the move will register, if false, the flow of control 
	//will go back to the main menu
	bool doMove(int&, int&, int&, int&);
    string object2string () const;
    // DO: Add methods here
	~GameBoard();

};

#endif  // GAMEBOARD_H
