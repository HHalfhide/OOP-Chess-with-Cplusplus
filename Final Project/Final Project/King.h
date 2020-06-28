#include"Piece.h"

#ifndef KING
#define KING
class king : public piece
{
private:
	int player{};

public:
	king(int p);
	~king() {}
	int get_player();
	std::string check_type();
	std::vector<int> allowed_moves(board game_board, int pos);
};
#endif