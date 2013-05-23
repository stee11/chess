// Name: Steven Kolln
// Description: Ceo class. Derived from piece and is a Ceo object

#include "Ceo.h"
#include "Piece.h"

using namespace std;

Ceo::Ceo(int Row, int Col, int Player):Piece(Row, Col, Player)
{}
//Returns true signifying this is not a piece but a Ceo
bool Ceo::isRealPiece() const
{
	return true;
}
//returns the row number the Ceo is currently in
int Ceo::getRow()
{
	return row;
}
//returns the collumn number the Ceo is in
int Ceo::getCol()
{
	return col;
}
//returns the player number of the player.
int Ceo::getPlayer()
{
	return player;
}
bool Ceo::move(int& fCol, int& fRow, int& tCol, int& tRow)
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
	else if ((fCol==tCol+1&&fRow==tRow-1)||(fCol==tCol+2&&fRow==tRow-2)||(fCol==tCol+3&&fRow==tRow-3)||(fCol==tCol+4&&fRow==tRow-4)||(fCol==tCol+5&&fRow==tRow-5)||(fCol==tCol+6&&fRow==tRow-6)||(fCol==tCol+7&&fRow==tRow-7)||(fCol==tCol-1&&fRow==tRow+1)||(fCol==tCol-2&&fRow==tRow+2)||(fCol==tCol-3&&fRow==tRow+3)||(fCol==tCol-4&&fRow==tRow+4)||(fCol==tCol-5&&fRow==tRow+5)||(fCol==tCol-6&&fRow==tRow+6)||(fCol==tCol-7&&fRow==tRow+7))
	{
		return true;
	}
	else
	{
		if ((fCol==tCol+1&&fRow==tRow+1)||(fCol==tCol+2&&fRow==tRow+2)||(fCol==tCol+3&&fRow==tRow+3)||(fCol==tCol+4&&fRow==tRow+4)||(fCol==tCol+5&&fRow==tRow+5)||(fCol==tCol+6&&fRow==tRow+6)||(fCol==tCol+7&&fRow==tRow+7)||(fCol==tCol-1&&fRow==tRow-1)||(fCol==tCol-2&&fRow==tRow-2)||(fCol==tCol-3&&fRow==tRow-3)||(fCol==tCol-4&&fRow==tRow-4)||(fCol==tCol-5&&fRow==tRow-5)||(fCol==tCol-6&&fRow==tRow-6)||(fCol==tCol-7&&fRow==tRow-7))
			return true;
	}
	return false;
}
//Returns a string representation of a Ceo.
//Yellow if 0 is the player number and green if the number is 1.
string Ceo::object2string() const
{
	if (player==0)
	{
		return string("yC");
	}
	else
	{
		return string("gC");
	}
}