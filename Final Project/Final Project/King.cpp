#include"King.h"


king::king(int p)
{
	player = p;
}

int king::get_player() 
{
	return player;
}

std::string king::check_type()
{
	return "king";
}

std::vector<int> king::allowed_moves(board game_board, int pos) 
{
	int player = game_board.squares[pos]->get_player();
	std::vector<int> allowed;
	// If in corner positions 
	if (pos == 0) {
		if (game_board.squares[8] == nullptr || game_board.squares[8]->get_player() != player) allowed.push_back(8);
		if (game_board.squares[9] == nullptr || game_board.squares[9]->get_player() != player) allowed.push_back(9);
		if (game_board.squares[1] == nullptr || game_board.squares[1]->get_player() != player) allowed.push_back(1);
	}
	else if (pos == 7) {
		if (game_board.squares[15] == nullptr || game_board.squares[15]->get_player() != player) allowed.push_back(15);
		if (game_board.squares[14] == nullptr || game_board.squares[14]->get_player() != player) allowed.push_back(14);
		if (game_board.squares[6] == nullptr || game_board.squares[6]->get_player() != player) allowed.push_back(6);
	}
	else if (pos == 63) {
		if (game_board.squares[55] == nullptr || game_board.squares[55]->get_player() != player) allowed.push_back(55);
		if (game_board.squares[54] == nullptr || game_board.squares[54]->get_player() != player) allowed.push_back(54);
		if (game_board.squares[62] == nullptr || game_board.squares[62]->get_player() != player) allowed.push_back(62);
	}
	else if (pos == 56) {
		if (game_board.squares[57] == nullptr || game_board.squares[57]->get_player() != player) allowed.push_back(57);
		if (game_board.squares[49] == nullptr || game_board.squares[49]->get_player() != player) allowed.push_back(49);
		if (game_board.squares[48] == nullptr || game_board.squares[48]->get_player() != player) allowed.push_back(48);
	}

	// If in bottom position (123456)
	else if (int{ pos / 8 } == 0 && pos != 0 && pos != 7) {
		if (game_board.squares[pos + 8] == nullptr || game_board.squares[pos + 8]->get_player() != player) allowed.push_back(pos + 8);
		if (game_board.squares[pos + 1] == nullptr || game_board.squares[pos + 1]->get_player() != player) allowed.push_back(pos + 1);
		if (game_board.squares[pos - 1] == nullptr || game_board.squares[pos - 1]->get_player() != player) allowed.push_back(pos - 1);
		if (game_board.squares[pos + 7] == nullptr || game_board.squares[pos + 7]->get_player() != player) allowed.push_back(pos + 7);
		if (game_board.squares[pos + 9] == nullptr || game_board.squares[pos + 9]->get_player() != player) allowed.push_back(pos + 9);
	}

	// If in top position (57-62)
	else if (int{ pos / 8 } == 7 && pos != 56 && pos != 63) {
		if (game_board.squares[pos - 8] == nullptr || game_board.squares[pos - 8]->get_player() != player) allowed.push_back(pos - 8);
		if (game_board.squares[pos + 1] == nullptr || game_board.squares[pos + 1]->get_player() != player) allowed.push_back(pos + 1);
		if (game_board.squares[pos - 1] == nullptr || game_board.squares[pos - 1]->get_player() != player) allowed.push_back(pos - 1);
		if (game_board.squares[pos - 7] == nullptr || game_board.squares[pos - 7]->get_player() != player) allowed.push_back(pos - 7);
		if (game_board.squares[pos - 9] == nullptr || game_board.squares[pos - 9]->get_player() != player) allowed.push_back(pos - 9);
	}

	// If in left position (8,16...48)
	else if (pos % 8  == 0 && pos != 0 && pos != 56) {
		if (game_board.squares[pos - 8] == nullptr || game_board.squares[pos - 8]->get_player() != player) allowed.push_back(pos - 8);
		if (game_board.squares[pos + 1] == nullptr || game_board.squares[pos + 1]->get_player() != player) allowed.push_back(pos + 1);
		if (game_board.squares[pos + 8] == nullptr || game_board.squares[pos + 8]->get_player() != player) allowed.push_back(pos + 8);
		if (game_board.squares[pos - 7] == nullptr || game_board.squares[pos - 7]->get_player() != player) allowed.push_back(pos - 7);
		if (game_board.squares[pos + 9] == nullptr || game_board.squares[pos + 9]->get_player() != player) allowed.push_back(pos + 9);
	}

	// If in right position (15,23...55)
	else if ((pos+1) % 8 == 0 && pos != 7 && pos != 63) {
		if (game_board.squares[pos - 8] == nullptr || game_board.squares[pos - 8]->get_player() != player) allowed.push_back(pos - 8);
		if (game_board.squares[pos - 1] == nullptr || game_board.squares[pos - 1]->get_player() != player) allowed.push_back(pos - 1);
		if (game_board.squares[pos + 8] == nullptr || game_board.squares[pos + 8]->get_player() != player) allowed.push_back(pos + 8);
		if (game_board.squares[pos + 7] == nullptr || game_board.squares[pos + 7]->get_player() != player) allowed.push_back(pos + 7);
		if (game_board.squares[pos - 9] == nullptr || game_board.squares[pos - 9]->get_player() != player) allowed.push_back(pos - 9);
	}

	// If in middle squares
	else {
		if (game_board.squares[pos - 8] == nullptr || game_board.squares[pos - 8]->get_player() != player) allowed.push_back(pos - 8);
		if (game_board.squares[pos - 1] == nullptr || game_board.squares[pos - 1]->get_player() != player) allowed.push_back(pos - 1);
		if (game_board.squares[pos + 1] == nullptr || game_board.squares[pos + 1]->get_player() != player) allowed.push_back(pos + 1);
		if (game_board.squares[pos + 8] == nullptr || game_board.squares[pos + 8]->get_player() != player) allowed.push_back(pos + 8);
		if (game_board.squares[pos + 7] == nullptr || game_board.squares[pos + 7]->get_player() != player) allowed.push_back(pos + 7);
		if (game_board.squares[pos - 9] == nullptr || game_board.squares[pos - 9]->get_player() != player) allowed.push_back(pos - 9);
		if (game_board.squares[pos - 7] == nullptr || game_board.squares[pos - 7]->get_player() != player) allowed.push_back(pos - 7);
		if (game_board.squares[pos + 9] == nullptr || game_board.squares[pos + 9]->get_player() != player) allowed.push_back(pos + 9);
	}
	return allowed;
}