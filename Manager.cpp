// Name: Steven Kolln
// Description: Manager class. Derived from piece and is a Manager object
#include <iostream>
#include "Manager.h"
#include "Piece.h"

using namespace std;

Manager::Manager(int Row, int Col, int Player):Piece(Row, Col, Player)
{}
//Returns true signifying this is not a piece but a Manager
bool Manager::isRealPiece() const
{
	return true;
}
//returns the row number the Manager is currently in
int Manager::getRow()
{
	return row;
}
//returns the collumn number the Manager is in
int Manager::getCol()
{
	return col;
}
//returns the player number of the player.
int Manager::getPlayer()
{
	return player;
}
bool Manager::move(int& fCol, int& fRow, int& tCol, int& tRow)
{
		if ((fCol==tCol))
		{
			if ((fRow==tRow+1)||(fRow==tRow+2)||(fRow==tRow+3)||(fRow==tRow+4)||(fRow==tRow+5)||(fRow==tRow+6)||(fRow==tRow+7)||(fRow==tRow-1)||(fRow==tRow-2)||(fRow==tRow-3)||(fRow==tRow-4)||(fRow==tRow-5)||(fRow==tRow-6)||(fRow==tRow-7))
				return true;
		}
		else if ((fRow==tRow))
		{
			if ((fCol==tCol+1)||(fCol==tCol+2)||(fCol==tCol+3)||(fCol==tCol+4)||(fCol==tCol+5)||(fCol==tCol+6)||(fCol==tCol+7)||(fCol==tCol-1)||(fCol==tCol-2)||(fCol==tCol-3)||(fCol==tCol-4)||(fCol==tCol-5)||(fCol==tCol-6)||(fCol==tCol-7))
				return true;
		}
	return false;
}
//Returns a string representation of a Manager.
//Yellow if 0 is the player number and green if the number is 1.
string Manager::object2string() const
{
	if (player==0)
	{
		return string("yM");
	}
	else
	{
		return string("gM");
	}
}