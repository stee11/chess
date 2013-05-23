// Name: Steven Kolln
// Description: TeamLeader class. Derived from piece and is a TeamLeader object

#include "TeamLeader.h"
#include "Piece.h"

using namespace std;

TeamLeader::TeamLeader(int Row, int Col, int Player):Piece(Row, Col, Player)
{}
//Returns true signifying this is not a piece but a TeamLeader
bool TeamLeader::isRealPiece() const
{
	return true;
}
//returns the row number the TeamLeader is currently in
int TeamLeader::getRow()
{
	return row;
}
//returns the collumn number the TeamLeader is in
int TeamLeader::getCol()
{
	return col;
}
//returns the player number of the player.
int TeamLeader::getPlayer()
{
	return player;
}
bool TeamLeader::move(int& fCol, int& fRow, int& tCol, int& tRow)
{
	if ((fCol==tCol+2&&fRow==tRow+1) || (fCol==tCol+2&&fRow==tRow-1) || (fCol==tCol-2&&fRow==tRow+1) || (fCol==tCol-2&&fRow==tRow-1) || (fCol==tCol+1&&fRow==tRow+2) || (fCol==tCol+1&&fRow==tRow-2) || (fCol==tCol-1&&fRow==tRow+2) || (fCol==tCol-1&&fRow==tRow-2))
		return true;
	return false;
}
//Returns a string representation of a TeamLeader.
//Yellow if 0 is the player number and green if the number is 1.
string TeamLeader::object2string() const
{
	if (player==0)
	{
		return string("yT");
	}
	else
	{
		return string("gT");
	}
}