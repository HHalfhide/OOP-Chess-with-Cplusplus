#include"Piece.h"


#ifndef BISHOP
#define BISHOP
class bishop : public piece
{
private:
	int player{};
	// Keeps track of the  total amount of bishops for each player
	static int p1_bishops;
	static int p2_bishops;

public:
	bishop(int p);
	~bishop();
	int get_player();
	std::string check_type();
	std::vector<int> allowed_moves(board game_board, int pos);
};

#endif
