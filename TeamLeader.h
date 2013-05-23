// Name: Steven Kolln
// Description: Header file for TeamLeader class


#if ! defined (TeamLeader_H)
#define TeamLeader_H

#include <string>
#include "Piece.h"


class TeamLeader: public Piece
{
	private:
	public:
		TeamLeader(int=0, int=0, int =1);
		bool isRealPiece() const;
		string object2string() const;
		bool move(int&, int&, int&, int&);
		int getRow();
		int getCol();
		int getPlayer();
};




#endif