// Name: Steven Kolln
// Description: Header file for Supervisor class


#if ! defined (Supervisor_H)
#define Supervisor_H

#include <string>
#include "Piece.h"


class Supervisor: public Piece
{
	private:
	public:
		Supervisor(int=0, int=0, int =1);
		bool isRealPiece() const;
		string object2string() const;
		bool move(int&, int&, int&, int&);
		int getRow();
		int getCol();
		int getPlayer();
};




#endif