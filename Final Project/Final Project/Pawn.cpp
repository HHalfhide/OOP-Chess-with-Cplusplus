#include"Pawn.h"

int pawn::p1_pawns{};
int pawn::p2_pawns{};

pawn::pawn(int p)
{
    player = p;
	if (p == 1) {
		p1_pawns++;
		std::cout << "Player 1's pawn has been created. Player 1 pawns: " << p1_pawns << std::endl;
	}
	else {
		p2_pawns++;
		std::cout << "Player 2's pawn has been created. Player 2 pawns: " << p2_pawns << std::endl;
	}
}

pawn::~pawn() 
{
	if (player == 1) {
		p1_pawns--;
		std::cout << "Player 1's pawn has been taken! Pawns remaining = " << p1_pawns << std::endl;
	}
	else {
		p2_pawns--;
		std::cout << "Player 2's pawn has been taken! Pawns remaining = " << p2_pawns << std::endl;
	}
}


int pawn::get_player() 
{
	return player;
}



std::string pawn::check_type() 
{
	return "pawn";
}

std::vector<int> pawn::allowed_moves(board game_board, int pos)
{   
	int player = game_board.squares[pos]->get_player();
	std::vector<int> allowed;
	if (player == 1) {
		
		// Player 1 pawn can move upward one if not obstrcuted 
		if (game_board.squares[pos + 8] == nullptr) allowed.push_back(pos + 8);
		// Player 1 pawn can move upwards two on first go if not obstructed
		if (pos > 7 && pos < 16 && game_board.squares[pos + 8]==nullptr&& game_board.squares[pos + 16]== nullptr ) allowed.push_back(pos + 16);
		// Player 1 pawns can take player 2 pieces diagonally left upwards as long as they are not on the left board edge 
		if (game_board.squares[pos + 7] != nullptr && game_board.squares[pos + 7]->get_player() == 2 && pos % 8 != 0) allowed.push_back(pos + 7);
		// Player 1 pawns can take player 2 pieces diagonally right upwards as long as they are not on the right board edge  
		if (game_board.squares[pos + 9] != nullptr && game_board.squares[pos + 9]->get_player() == 2 && pos % 8 != 7) allowed.push_back(pos + 9);
	}
	else {
		// Player 2 pawn can move downward one if not obstrcuted 
		if (game_board.squares[pos - 8] == nullptr) allowed.push_back(pos - 8);
		// Player 2 pawn can move downward two on first go if not obstructed
		if (pos > 47 && pos < 56 && game_board.squares[pos - 8] == nullptr && game_board.squares[pos - 16] == nullptr) allowed.push_back(pos - 16);
		// Player 2 pawns can take player 1 pieces diagonally left downwards as long as they are not on the left board edge  
		if (game_board.squares[pos - 9] != nullptr && game_board.squares[pos - 9]->get_player() == 1 && pos % 8 != 0) allowed.push_back(pos - 9);
		// Player 2 pawns can take player 1 pieces diagonally right downwards as long as they are not on the right board edge  
		if (game_board.squares[pos - 7] != nullptr && game_board.squares[pos - 7]->get_player() == 1 && pos % 8 != 7) allowed.push_back(pos - 7);
		
	}
	return allowed;
}
