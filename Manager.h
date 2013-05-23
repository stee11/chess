// Name: Steven Kolln
// Description: Header file for Manager class


#if ! defined (MANAGER_H)
#define MANAGER_H

#include <string>
#include "Piece.h"


class Manager: public Piece
{
	private:
	public:
		Manager(int=0, int=0, int =1);
		bool isRealPiece() const;
		string object2string() const;
		bool move(int&, int&, int&, int&);
		int getRow();
		int getCol();
		int getPlayer();
};




#endif