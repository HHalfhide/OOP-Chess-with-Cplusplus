#include"Piece.h"
class pawn;
class rook;
class queen;
class king;
class knight;
class bishop;

#ifndef ROOK
#define ROOK
class rook : public piece
{
private:
	int player{};
	// Keeps track of the  total amount of rooks for each player
	static int p1_rooks;
	static int p2_rooks;

public:
	rook(int p);
	~rook();
	int get_player();
	std::string check_type();
	std::vector<int> allowed_moves(board game_board, int pos);
};
#endif