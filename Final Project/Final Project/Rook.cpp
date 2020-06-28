#include"Rook.h"
#include"Moves.h"



int rook::p1_rooks{};
int rook::p2_rooks{};

rook::rook(int p)
{
	player = p;
	if (p == 1) {
		p1_rooks++;
		std::cout << "Player 1's rook has been created. Player 1 rooks: " << p1_rooks<< std::endl;
	}
	else {
		p2_rooks++;
		std::cout << "Player 2's rook has been created. Player 2 rooks: " << p2_rooks  << std::endl;
	}
}

rook::~rook()
{
	if (player == 1) {
		p1_rooks--;
		std::cout << "Player 1's rook has been taken! Rooks remaining = " << p1_rooks << std::endl;
	}
	else {
		p2_rooks--;
		std::cout << "Player 2's rook has been taken! Rooks remaining = " << p2_rooks << std::endl;
	}
}


int rook::get_player() 
{
	return player;
}

std::string rook::check_type()
{
	return "rook";
}

std::vector<int> rook::allowed_moves(board game_board, int pos) 
{
	int player = game_board.squares[pos]->get_player();
	std::vector<int> allowed;
	move_vert(allowed, game_board, pos, player, 'u');
	move_vert(allowed, game_board, pos, player, 'd');
	move_horiz(allowed, game_board, pos, player, 'l');
	move_horiz(allowed, game_board, pos, player, 'r');
	return allowed; 
}