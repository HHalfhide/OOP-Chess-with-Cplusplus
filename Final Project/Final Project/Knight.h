#include"Piece.h"


#ifndef KNIGHT
#define KNIGHT
class knight : public piece
{
private:
	int player{};
	// Keeps track of the  total amount of knights for each player
	static int p1_knights;
	static int p2_knights;

public:
	knight (int p);
	~knight();
	int get_player();
	std::string check_type();
	std::vector<int> allowed_moves(board game_board, int pos);
};
#endif