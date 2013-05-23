// Name: Steven Kolln
// Description: Piece class. Is a basic definition for what a piece should
// look like with move virtual function


#include "Piece.h"

Piece::Piece (int inRow, int inCol, int inColor)
{
    row=inRow;
    col=inCol;
    player = inColor;
}

bool Piece::isRealPiece() const
{
    return false;
}

string Piece::object2string () const
{
    return string (" s ");
}
/*~Piece::Piece()
{
	delete row;
	delete col;
	delete player;
}*/

bool Piece::move(int& r, int& c, int& newr, int& newc)
{
	return true;
}
void Piece::setRow(int i)
{
	row=i;
}
void Piece::setCol(int i)
{
	col=i;
}
void Piece::setPlayer(int i)
{
	player=i;
}

//returns the row number the CEO is currently in
int Piece::getRow()
{
	return row;
}
//returns the collumn number the CEO is in
int Piece::getCol()
{
	return col;
}
//returns the player number of the player.
int Piece::getPlayer()
{
	return player;
}