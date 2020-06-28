#include"Bishop.h"
#include"Moves.h"



int bishop::p1_bishops{};
int bishop::p2_bishops{};

bishop::bishop(int p)
{
	player = p;
	if (p == 1) {
		p1_bishops++;
		std::cout << "Player 1's bishop has been created. Player 1 bishops: " << p1_bishops << std::endl;
	}
	else {
		p2_bishops++;
		std::cout << "Player 2's bishop has been created. Player 2 bishops: " << p2_bishops << std::endl;
	}

}

bishop::~bishop()
{
	if (player == 1) {
		p1_bishops--;
		std::cout << "Player 1's bishop has been taken! Bishops remaining = " << p1_bishops << std::endl;
	}
	else {
		p2_bishops--;
		std::cout << "Player 2's bishop has been taken! Bishops remaining = " << p2_bishops << std::endl;
	}
}



int bishop::get_player() 
{
	return player;
}

std::string bishop::check_type()
{
	return "bishop";
}

std::vector<int> bishop::allowed_moves(board game_board, int pos) 
{
	int player = game_board.squares[pos]->get_player();
	std::vector<int> allowed;
	move_diag(allowed, game_board, pos, player, 'u', 'l');
	move_diag(allowed, game_board, pos, player, 'u', 'r');
	move_diag(allowed, game_board, pos, player, 'd', 'r');
	move_diag(allowed, game_board, pos, player, 'd', 'l');
	return allowed;
}