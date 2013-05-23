// Name: Steven Kolln
// Description: Developer class. Derived from piece and is a Developer object

#include "Developer.h"
#include "Piece.h"

using namespace std;

Developer::Developer(int Row, int Col, int Player):Piece(Row, Col, Player)
{
	moved=false;
}
//Returns true signifying this is not a piece but a Developer
bool Developer::isRealPiece() const
{
	return true;
}
bool Developer::getMoved()
{
	return moved;
}
//returns the row number the Developer is currently in
int Developer::getRow()
{
	return row;
}
//returns the collumn number the Developer is in
int Developer::getCol()
{
	return col;
}
//returns the player number of the player.
int Developer::getPlayer()
{
	return player;
}
bool Developer::move(int& fCol, int& fRow, int& tCol, int& tRow)
{
	if (getPlayer()==1)
	{
		if (!getMoved())
		{
			if ((tRow==fRow&&tCol==fCol-1)||(tRow==fRow&&tCol==fCol-2) || (tRow==fRow+1&&tCol==fCol-1) || (tRow==fRow-1&&tCol==fCol-1))
			{
				moved=true;
				return true;
			}
		}
		else
		{
			if ((tRow==fRow&&tCol==fCol-1) ||(tRow==fRow+1&&tCol==fCol-1) || (tRow==fRow-1&&tCol==fCol-1))
				return true;
		}
	}
	else
	{
		if (!getMoved())
		{
			if ((tRow==fRow&&tCol==fCol+1)||(tRow==fRow&&tCol==fCol+2) || (tRow==fRow+1&&tCol==fCol+1) || (tRow==fRow-1&&tCol==fCol+1))
			{
				moved=true;
				return true;
			}
		}
		else
		{
			if ((tRow==fRow&&tCol==fCol+1) ||(tRow==fRow+1&&tCol==fCol+1) || (tRow==fRow-1&&tCol==fCol+1))
				return true;
		}
	}
	return false;
}
//Returns a string representation of a Developer.
//Yellow if 0 is the player number and green if the number is 1.
string Developer::object2string() const
{
	if (player==0)
	{
		return string("yD");
	}
	else
	{
		return string("gD");
	}
}