#include"Piece.h"

#ifndef PAWN
#define PAWN
class pawn : public piece
{
private:
	int player{};
	// Keeps track of the  total amount of pawns for each player
	static int p1_pawns;
	static int p2_pawns;
public:
	pawn(int p);
	~pawn();
	int get_player();
	std::string check_type();
	std::vector<int> allowed_moves(board game_board,int pos);
};
#endif