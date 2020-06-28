#include<iostream>
#include<vector>
#include"Board.h"

#ifndef PIECES
#define PIECES
class piece 
{
public:
	virtual ~piece() {};
	virtual int get_player() = 0;
	virtual std::string check_type() = 0;
	virtual std::vector<int> allowed_moves(board game_board, int pos) = 0;
};

#endif
