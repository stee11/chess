// Name: Steven Kolln
// Description: President class. Derived from piece and is a president object

#include "President.h"
#include "Piece.h"

using namespace std;

President::President(int Row, int Col, int Player):Piece(Row, Col, Player)
{}
//Returns true signifying this is not a piece but a president
bool President::isRealPiece() const
{
	return true;
}
//returns the row number the president is currently in
int President::getRow()
{
	return row;
}
//returns the collumn number the president is in
int President::getCol()
{
	return col;
}
//returns the player number of the player.
int President::getPlayer()
{
	return player;
}
bool President::move(int& fCol, int& fRow, int& tCol, int& tRow)
{
	if ((tRow==fRow+1&&tCol==fCol)||(tRow==fRow-1&&tCol==fCol)||(tRow==fRow&&tCol+1==fCol)||(tRow==fRow&&tCol-1==fCol)||(tRow==fRow-1&&tCol==fCol-1) || (tRow==fRow-1&&tCol==fCol+1)||(tRow==fRow+1&&tCol==fCol-1) || (tRow==fRow+1&&tCol==fCol+1))
		return true;
	return false;
}
//Returns a string representation of a president.
//Yellow if 0 is the player number and green if the number is 1.
string President::object2string() const
{
	if (player==0)
	{
		return string("yP");
	}
	else
	{
		return string("gP");
	}
}