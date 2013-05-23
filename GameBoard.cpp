// Name: Steven Kolln
// Description: Game Board class. Holds the array of pieces
// and the doMove method for starting a move 

#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip> 
#include <cstring>
#include "GameBoard.h"


using namespace std;

GameBoard::GameBoard ()
{
	//private method to instantiate board
    initBoard();
	//number of turns without a piece being killed
	noKill=0;
}
//Destructor for Gameboard. Deletes all dynamic pieces
GameBoard::~GameBoard()
{

	for (int i=0;i<MROWS;i++)
	{
		for (int a=0;a<MCOLS; a++)
		{
			delete board[i][a];
		}
	}
}

void GameBoard::initBoard ()
{
	ifstream inStr;
	//Sets the board all to NULL
	for (int i=0;i<MROWS;i++)
	{
		for (int a=0;a<MCOLS;a++)
		{
			board[i][a]=NULL;
		}
	}
	//cout << endl << "last";
	bool worked = true;
	string inFileName;
	int inputRow, inputCol, inputPiece, inputColor;
	//Piece pointer used to create piece objects
	Piece *myPiece;
	do 
	{
		inFileName="newBoard.txt";
		//opens the board text file
		inStr.open (inFileName.c_str());
		if (inStr.fail())
		{
			cerr << "Error opening file. Try again." << endl;
			inStr.clear();
			inStr.ignore(80, '\n');
			worked = false;
		}
		else 
			worked = true;
		
	} while (!worked);
	
	while (!inStr.eof())
	{
		inStr >> inputRow >> inputCol >> inputPiece >> inputColor; //reads each int a line at a time
		//Depeneding on the number determines which object is created. That object is then assigned to that array location.
		switch (inputPiece)
		{ 
			case 1:
				myPiece=new President(inputRow, inputCol, inputColor);
				//cout << "Pres is location " << inputRow << " " << inputCol << endl;
				board[myPiece->getRow()][myPiece->getCol()]=myPiece;
			//	cout << board[myPiece->getRow()][myPiece->getCol()];
				break;
			case 2:
				myPiece=new Ceo (inputRow, inputCol, inputColor);
				board[myPiece->getRow()][myPiece->getCol()]=myPiece;
				break;
			case 3:
				myPiece=new Manager(inputRow, inputCol, inputColor);
				board[myPiece->getRow()][myPiece->getCol()]=myPiece;
				break;
			case 4:
				myPiece=new Supervisor(inputRow, inputCol, inputColor);
				board[myPiece->getRow()][myPiece->getCol()]=myPiece;
				break;
			case 5:
				myPiece=new TeamLeader(inputRow, inputCol, inputColor);
				board[myPiece->getRow()][myPiece->getCol()]=myPiece;
				break;
			case 6:
				myPiece=new Developer(inputRow, inputCol, inputColor);
				board[myPiece->getRow()][myPiece->getCol()]=myPiece;
				break;
			default:
				cout << "Error in the switch statement initializing the board" << endl;
				break;
		}
	}
	
	inStr.close();
	//cout << "Location 1 4 is " << board[1][4] << endl;
	
	/*int row = 0, col = 0, pieceType = -1, player=0;
	
	while (!initStr.eof())
	{
        // Each line in the input file represents a piece
        // The first 2 values are for the row and column of the piece's 
        //       position
        // The third value is the type of piece (President, CEO, etc.)
        // The fourth value is the type of player - Green or Yellow
        
		initStr >> row >> col >> pieceType >> player;
        /*
		// This skeleton version assumes data entered are valid and so does no 
        //         input error checking
		
		switch (pieceType) {
			case PRESIDENT: // To handle President piece
                       // dynamically create and allocate a President object at 
                       // the location (row, col) on the board.
                board [row][col] = ???;
				break;
			
                //repeat for all types
            default: 
				board [row][col] = NULL;
				break;
		} // end switch (pieceType)
	} // end while (!eof)
    
    // DO: Add code as needed*/
    
} // end initBoard()

bool GameBoard::doMove(int& fRow, int& fCol, int& tRow, int& tCol)
{
	//If the user goes out of bounds, do not do it
	if (fRow<0||fRow>MROWS-1||fCol<0||fCol>MCOLS-1||tRow<0||tRow>MROWS-1||tCol<0||tCol>MCOLS-1)
	{
		cout << "Move invalid: Please selection a row and collumn located on the board." << endl;
		return false;
	}
	//If the space the user chooses is empty, don't do it.
	if (board[fRow][fCol]==NULL)
	{
		cout << "There is no piece to move on this square. Go again." << endl;
		return false;
	}
	//valid move
	if (board[fRow][fCol]->move(fRow, fCol, tRow, tCol))
	{
		Piece *myPiece;
		int team=board[fRow][fCol]->getPlayer();
		//If the space the user wants to move to is null
		if (board[tRow][tCol]==NULL)
		{
			//make a new pointer with object dependent on what string the object has and set it equal to the new board location
			char switchNum=board[fRow][fCol]->object2string().c_str()[1];
			switch (switchNum)
			{
				case 'P':
				myPiece=new President(tRow, tCol, team);
				//cout << "Pres is location " << inputRow << " " << inputCol << endl;
				board[myPiece->getRow()][myPiece->getCol()]=myPiece;
				//	cout << board[myPiece->getRow()][myPiece->getCol()];
				break;
			case 'C':
				myPiece=new Ceo (tRow, tCol, team);
				board[myPiece->getRow()][myPiece->getCol()]=myPiece;
				break;
			case 'M':
				myPiece=new Manager(tRow, tCol, team);
				board[myPiece->getRow()][myPiece->getCol()]=myPiece;
				break;
			case 'S':
				myPiece=new Supervisor(tRow, tCol, team);
				board[myPiece->getRow()][myPiece->getCol()]=myPiece;
				break;
			case 'T':
				myPiece=new TeamLeader(tRow, tCol, team);
				board[myPiece->getRow()][myPiece->getCol()]=myPiece;
				break;
			case 'D':
				myPiece=new Developer(tRow, tCol, team);
				board[myPiece->getRow()][myPiece->getCol()]=myPiece;
				break;
			default:
				cout << "Error in the switch statement initializing the board" << endl;
				break;
			}
		/*	//Piece *p;
			p->setRow(tRow);
			p->setCol(tCol);
			p->setPlayer(team);
			//p=board[fRow][fCol];
			board[tRow][tCol]=p;*/
			delete board[fRow][fCol]; //delete the old object pointer
			board [fRow][fCol]=NULL; //set the old space equal to null
			noKill++;
			// a draw
			if (noKill==50)
			{
				cout << "This game is a draw! No significant moves made in 50 turns!" << endl;
			}
			
		}
		// If you already have an allied piece on the square, you can not go there
		else if (team==board[tRow][tCol]->getPlayer())
		{
			cout << "Invalid move. Your piece is on that square." << endl;
			return false;
		}
		//if there is any enemy on that square
		else if (team!=board[tRow][tCol]->getPlayer())
		{
			//make a new object
			char switchNum=board[fRow][fCol]->object2string().c_str()[1];
			//delete the enemy object
			delete board[tRow][tCol];
			board[tRow][tCol]=NULL;
			switch (switchNum)
			{
				case 'P':
				myPiece=new President(tRow, tCol, team);
				//cout << "Pres is location " << inputRow << " " << inputCol << endl;
				board[myPiece->getRow()][myPiece->getCol()]=myPiece;
				//	cout << board[myPiece->getRow()][myPiece->getCol()];
				break;
			case 'C':
				myPiece=new Ceo (tRow, tCol, team);
				board[myPiece->getRow()][myPiece->getCol()]=myPiece;
				break;
			case 'M':
				myPiece=new Manager(tRow, tCol, team);
				board[myPiece->getRow()][myPiece->getCol()]=myPiece;
				break;
			case 'S':
				myPiece=new Supervisor(tRow, tCol, team);
				board[myPiece->getRow()][myPiece->getCol()]=myPiece;
				break;
			case 'T':
				myPiece=new TeamLeader(tRow, tCol, team);
				board[myPiece->getRow()][myPiece->getCol()]=myPiece;
				break;
			case 'D':
				myPiece=new Developer(tRow, tCol, team);
				board[myPiece->getRow()][myPiece->getCol()]=myPiece;
				break;
			default:
				cout << "Error in the switch statement initializing the board" << endl;
				break;
			}
			//board[tRow][tCol]=myPiece; //add your piece
			board[fRow][fCol]=NULL; // set your old location to null
			noKill=0;
			cout << "KILLED" << endl;
		}
		
	}
}

string GameBoard::object2string () const
{
    ostringstream os;
	
	cout << setw(5) << " ";
    for (int j = 0; j < MROWS; j++)
		os << setw(5) << j;
    os << endl << endl;
    for (int i = 0; i < MCOLS; i++) {
		os << setw(5) << i;
		for (int j = 0; j < MROWS; j++)
		{
			if (board[i][j]==NULL)
			{}
			else
			os << setw(5) << board[i][j]->object2string();
		}
		os << endl;
	}
    os << endl;
    return os.str();
}






