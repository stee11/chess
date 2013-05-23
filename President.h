// Name: Steven Kolln
// Description: Header file for President class


#if ! defined (PRESIDENT_H)
#define PRESIDENT_H

#include <string>
#include "Piece.h"


class President: public Piece
{
	private:
	public:
		President(int=0, int=0, int =1);
		bool isRealPiece() const;
		string object2string() const;
		bool move(int&, int&, int&, int&);
		int getRow();
		int getCol();
		int getPlayer();
};




#endif