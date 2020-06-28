#include "Moves.h"
#include "Piece.h"
#include "Board.h"

// These functions add availabe sqaures to a vector in different directions

void move_diag(std::vector<int>& allowed, board game_board, int pos, int player, char u_or_d, char l_or_r) {
	int a{}, b{}, c{};
	if (u_or_d == 'u') { 
		a = 7;
		if (l_or_r == 'l') { b = 0; c = 7;}
		else { b = 1; c = 9;}
	}
	else { 
		a = 0; 
		if (l_or_r == 'l') {b = 0; c = -9;}
		else {b = 1; c = -7;}
	}
	
	while (true) {
		// If next square crosses board edge, stop
		if (int{ pos / 8 } == a || (pos + b) % 8 == 0) break;
		// If next square has an opponents piece, add square to vector and then stop
		if (game_board.squares[pos + c] != nullptr && game_board.squares[pos + c]->get_player() != player) {
			allowed.push_back(pos + c);
			break;
		}
		// If next square has players piece, stop
		else if (game_board.squares[pos + c] != nullptr && game_board.squares[pos + c]->get_player() == player) {
			break;
		}
		// Continue if next square free
		else allowed.push_back(pos + c);
		pos += c;
	}
}

void move_vert(std::vector<int>& allowed, board game_board, int pos, int player, char u_or_d) {
	int a{}, b{};
	if (u_or_d == 'u') { a = 8; b = 7; }
	else { a = -8; b = 0; }
	while (true) {
		// If next square crosses board edge, stop
		if (int{ pos / a } == b) break;
		// If next square has an opponents piece, add square to vector and then stop
		if (game_board.squares[pos + a] != nullptr && game_board.squares[pos + a]->get_player() != player) {
			allowed.push_back(pos + a);
			break;
		}
		// If next square has players piece, stop
		else if (game_board.squares[pos + a] != nullptr && game_board.squares[pos + a]->get_player() == player) {
			break;
		}
		// Continue if next square free
		else allowed.push_back(pos + a);
		pos += a;
	}
}

void move_horiz(std::vector<int>& allowed, board game_board, int pos, int player, char l_or_r) {
	int a{}, b{};
	if (l_or_r == 'l') { a = -1; b = 0; }
	else { a = 1; b = 1; }
	while (true) {
		// If next square crosses board edge, stop
		if ((pos + b) % 8 == 0) break;
		// If next square has an opponents piece, add square to vector and then stop
		if (game_board.squares[pos + a] != nullptr && game_board.squares[pos + a]->get_player() != player) { 
			allowed.push_back(pos + a);
			break;
		}
		// If next square has players piece, stop
		else if (game_board.squares[pos + a] != nullptr && game_board.squares[pos + a]->get_player() == player) {
			break;
		}
		// Continue if next square free
		else allowed.push_back(pos + a);
		pos += a;
	}
}