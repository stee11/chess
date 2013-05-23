// Name: Steven Kolln
// Description: Header file for Developer class


#if ! defined (Developer_H)
#define Developer_H

#include <string>
#include "Piece.h"


class Developer: public Piece
{
	private:
		bool moved;
	public:
		Developer(int=0, int=0, int =1);
		bool isRealPiece() const;
		string object2string() const;
		bool move(int&, int&, int&, int&);
		int getRow();
		int getCol();
		int getPlayer();
		bool getMoved();
};




#endif