// Name: Steven Kolln
// Description: Supervisor class. Derived from piece and is a Supervisor object

#include "Supervisor.h"
#include "Piece.h"
#include <iostream>

using namespace std;

Supervisor::Supervisor(int Row, int Col, int Player):Piece(Row, Col, Player)
{}
//Returns true signifying this is not a piece but a Supervisor
bool Supervisor::isRealPiece() const
{
	return true;
}
//returns the row number the Supervisor is currently in
int Supervisor::getRow()
{
	return row;
}
//returns the collumn number the Supervisor is in
int Supervisor::getCol()
{
	return col;
}
//returns the player number of the player.
int Supervisor::getPlayer()
{
	return player;
}
bool Supervisor::move(int& fCol, int& fRow, int& tCol, int& tRow)
{
	cout << "My location is: " << fRow << " " << fCol << endl;
	if ((fCol==tCol+1&&fRow==tRow+1)||(fCol==tCol+2&&fRow==tRow+2)||(fCol==tCol+3&&fRow==tRow+3)||(fCol==tCol+4&&fRow==tRow+4)||(fCol==tCol+5&&fRow==tRow+5)||(fCol==tCol+6&&fRow==tRow+6)||(fCol==tCol+7&&fRow==tRow+7)||(fCol==tCol-1&&fRow==tRow-1)||(fCol==tCol-2&&fRow==tRow-2)||(fCol==tCol-3&&fRow==tRow-3)||(fCol==tCol-4&&fRow==tRow-4)||(fCol==tCol-5&&fRow==tRow-5)||(fCol==tCol-6&&fRow==tRow-6)||(fCol==tCol-7&&fRow==tRow-7))
	{
		return true;
	}
	else if ((fCol==tCol+1&&fRow==tRow-1)||(fCol==tCol+2&&fRow==tRow-2)||(fCol==tCol+3&&fRow==tRow-3)||(fCol==tCol+4&&fRow==tRow-4)||(fCol==tCol+5&&fRow==tRow-5)||(fCol==tCol+6&&fRow==tRow-6)||(fCol==tCol+7&&fRow==tRow-7)||(fCol==tCol-1&&fRow==tRow+1)||(fCol==tCol-2&&fRow==tRow+2)||(fCol==tCol-3&&fRow==tRow+3)||(fCol==tCol-4&&fRow==tRow+4)||(fCol==tCol-5&&fRow==tRow+5)||(fCol==tCol-6&&fRow==tRow+6)||(fCol==tCol-7&&fRow==tRow+7))
	{
		return true;
	}
	return false;
}
//Returns a string representation of a Supervisor.
//Yellow if 0 is the player number and green if the number is 1.
string Supervisor::object2string() const
{
	if (player==0)
	{
		return string("yS");
	}
	else
	{
		return string("gS");
	}
}