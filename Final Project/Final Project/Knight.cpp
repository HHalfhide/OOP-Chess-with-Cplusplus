#include"Knight.h"

int knight::p1_knights{};
int knight::p2_knights{};

knight::knight(int p)
{
	player = p;
	if (p == 1) {
		p1_knights++;
		std::cout << "Player 1's knight has been created. Player 1 knights: " << p1_knights << std::endl;
	}
	else {
		p2_knights++;
		std::cout << "Player 2's knight has been created. Player 2 knights: " << p2_knights  << std::endl;
	}

}

knight::~knight()
{
	if (player == 1) {
		p1_knights--;
		std::cout << "Player 1's knight has been taken! Knights remaining = " << p1_knights << std::endl;
	}
	else {
		p2_knights--;
		std::cout << "Player 2's knight has been taken! Knights remaining = " << p2_knights << std::endl;
	}
}

int knight::get_player() 
{
	return player;
}

std::string knight::check_type()
{
	return "knight";
}

std::vector<int> knight::allowed_moves(board game_board, int pos) {
	int player = game_board.squares[pos]->get_player();
	

	// Allowed prelim is allowed moves if there were no other pieces on the board, this only depends on the original position
	std::vector<int> allowed_prelim;

	if (pos == 0) allowed_prelim = { 17,10 };
	else if (pos == 1) allowed_prelim = { 16,18,11 };
	else if (pos == 8) allowed_prelim = { 25,18,2 };
	else if (pos == 9) allowed_prelim = { 24,26,19,3 };

	else if (pos == 56) allowed_prelim = { 50,41 };
	else if (pos == 57) allowed_prelim = { 51,42,40 };
	else if (pos == 48) allowed_prelim = { 58,42,33 };
	else if (pos == 49) allowed_prelim = { 59,43,34,32 };

	else if (pos == 63) allowed_prelim = { 46, 53 };
	else if (pos == 62) allowed_prelim = { 47,45,52 };
	else if (pos == 55) allowed_prelim = { 38,45,61 };
	else if (pos == 54) allowed_prelim = { 39,37,44,60 };

	else if (pos == 7) allowed_prelim = { 22,13 };
	else if (pos == 6) allowed_prelim = { 21,23,12 };
	else if (pos == 15) allowed_prelim = { 30,5,21 };
	else if (pos == 14) allowed_prelim = { 29,31,4,20 };
#
	// Vector positions 16 24 32 40
	else if (pos % 8 == 0 && 15 < pos && pos < 41) allowed_prelim = { pos + 17,pos + 10,pos - 6,pos - 15 };
	// Vector positions 17 25 33 41
	else if ((pos - 1) % 8 == 0 && 16 < pos && pos < 42) allowed_prelim = { pos + 15,pos + 17,pos + 10,pos - 6,pos - 15, pos - 17 };

	// Vector positions 23 31 39 37
	else if ((pos + 1) % 8 == 0 && 22 < pos && pos < 48) allowed_prelim = {pos + 15,  pos - 17,pos - 10,pos + 6};

	// Vector positions 22 30 38 46
	else if ((pos + 2) % 8 == 0 && 21 < pos && pos < 47) allowed_prelim = { pos + 15, pos + 17, pos - 15,  pos - 17,pos - 10,pos + 6 };

	// Vector positions 58 59 60 61
	else if (int{pos/8} == 7 && 57 < pos && pos < 62) allowed_prelim = { pos - 6,  pos - 15,pos - 17,pos - 10 };

	// Vector positions 50 51 52 53
	else if (int{ pos / 8 } == 6 && 49 < pos && pos < 54) allowed_prelim = { pos + 10, pos - 6, pos - 15,  pos - 17,pos - 10,pos + 6 };

	// Vector positions 2 3 4 5 
	else if (int{ pos / 8 } == 0 && 1 < pos && pos < 6) allowed_prelim = { pos + 15,pos + 17,pos + 10,pos + 6 };
	//Vector positions 10 11 12 13
	else if (int{ pos / 8 } == 1 && 9 < pos && pos < 14) allowed_prelim = { pos + 15,pos + 17,pos + 10,pos - 6, pos - 10, pos + 6 };

	// Middle 16
	else allowed_prelim = { pos + 15,pos + 17,pos + 10,pos - 6,pos - 15, pos - 17, pos - 10, pos + 6 };

	std::vector<int> allowed;
	// Check that squares in prelim are free or occupied by opponent, if so add to allowed
	for (auto allowed_prelim_it = allowed_prelim.begin(); allowed_prelim_it < allowed_prelim.end(); allowed_prelim_it++) {
		if (game_board.squares[*allowed_prelim_it] == nullptr || game_board.squares[*allowed_prelim_it]->get_player() != player) allowed.push_back(*allowed_prelim_it);
	}
	return allowed;
}