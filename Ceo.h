// Name: Steven Kolln
// Description: Header file for Ceo class


#if ! defined (Ceo_H)
#define Ceo_H

#include <string>
#include "Piece.h"

using namespace std;

class Ceo: public Piece
{
	private:
	public:
		Ceo(int=0, int=0, int =1);
		bool isRealPiece() const;
		string object2string() const;
		bool move(int&, int&, int&, int&);
		int getRow();
		int getCol();
		int getPlayer();
};




#endif