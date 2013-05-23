// Name: Steven Kolln
// Description: Header file for Piece class

#if ! defined (PIECE_H)
#define PIECE_H

#include <string>

using namespace std;


const int PRESIDENT = 1;
const int CEO = 2;
const int MANAGER = 3;
const int SUPERVISOR = 4;
const int TEAMLEADER = 5;
const int DEVELOPER = 6;


class Piece 
{
    
protected:
    int row;
    int col;
    int player;
    
public:
    Piece (int=0, int=0, int =0);
	//returns true if the piece is an actual piece used in the game and false if it is of the base class piece
	bool isRealPiece() const;
	virtual string object2string() const;
	//virtual method move; used in all other pieces to change other pieces move methods appropriatly. 
	//Returns true if the user has a valid move for the dependent piece.
	virtual bool move(int&, int&, int&, int&);
	//getter and setter methods for class
	virtual int getRow();
	virtual int getCol();
	virtual int getPlayer();
	void setRow(int i);
	void setCol(int i);
	void setPlayer(int i);
 
    
};

#endif  // PIECE_H
