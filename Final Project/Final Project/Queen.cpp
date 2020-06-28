#include"Queen.h"
#include"Moves.h"

int queen::p1_queens{};
int queen::p2_queens{};

queen::queen(int p)
{
	player = p;
	if (p == 1) {
		p1_queens++;
		std::cout << "Player 1's queen has been created. Player 1 queens: " << p1_queens << " queens" << std::endl;
	}
	else {
		p2_queens++;
		std::cout << "Player 2's queen has been created. Player 2 queens: " << p2_queens << " queens" << std::endl;
	}
}

queen::~queen()
{
	if (player == 1) {
		p1_queens--;
		std::cout << "Player 1's queen has been taken! Queens remaining = " << p1_queens << std::endl;
	}
	else {
		p2_queens--;
		std::cout << "Player 2's queen has been taken! Queens remaining = " << p2_queens << std::endl;
	}
}


int queen::get_player() 
{
	return player;
}

std::string queen::check_type()
{
	return "queen";
}

std::vector<int> queen::allowed_moves(board game_board, int pos)
{
	int player = game_board.squares[pos]->get_player();
	std::vector<int> allowed;
	move_vert(allowed, game_board, pos, player, 'u');
	move_vert(allowed, game_board, pos, player, 'd');
	move_horiz(allowed, game_board, pos, player, 'l');
	move_horiz(allowed, game_board, pos, player, 'r');
	move_diag(allowed, game_board, pos, player, 'u', 'l');
	move_diag(allowed, game_board, pos, player, 'u', 'r');
	move_diag(allowed, game_board, pos, player, 'd', 'r');
	move_diag(allowed, game_board, pos, player, 'd', 'l');
	return allowed;
}



