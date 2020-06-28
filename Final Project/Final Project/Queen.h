#include"Piece.h"

#ifndef QUEEN
#define QUEEN
class queen : public piece
{
private:
	int player{};
	// Keeps track of the  total amount of queens for each player
	static int p1_queens;
	static int p2_queens;
public:
	queen (int p);
	~queen();
	int get_player();
	std::string check_type();
	std::vector<int> allowed_moves(board game_board, int pos);
};
#endif