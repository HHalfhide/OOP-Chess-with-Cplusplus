#include"Pawn.h"
#include"Rook.h"
#include"Knight.h"
#include"Bishop.h"
#include"Queen.h"
#include"King.h"
#include"Board.h"
#include<string>
#include <algorithm> 

// Sets the classic set up
void set_board_classic(board& game_board);

std::string remove_spaces(std::string str);

// Checks the form of the original position
bool check_input_form_orig(std::string& pos);

// New check input required for new position, takes into account whether the user enters X (which allows them to select another piece)
bool check_input_form_new(std::string& pos);

// Converts a coordinate string to the vector position
int coor_to_vec_num(std::string coor);

// Checks whether the player has a piece at the specified position
bool check_piece(board game_board, std::string pos, int player);

// Converts vector position to coordinate string
std::string vec_num_to_coor(int num);

// Checks whether the user entered move is in available moves
bool check_allowed(std::vector<int> allowed, std::string new_pos);

// Checks whether the player has entered a valid promotion 
bool check_promotion(std::string& choice);

// Tests a move where piece of type T is taken, if move is not a self check (illegal), add to allowed checked
template <typename T>
void test_move_for_check(board& game_board, int orig_pos, int new_pos, int player, std::vector<int>& allowed_checked);

// Tests list of allowed moves, if move is not a self check (illegal), add to allowed checked
void test_all_for_check(std::vector<int> allowed, board& game_board, int player, int pos, std::vector<int>& allowed_checked);

// Checks whether a player has any legal moves
bool any_legal_moves(board& game_board, int player);

// Performs promotion
void promotion(board& game_board, int player, std::string new_pos);

// Removes white spaces, capitalises, checks input form
bool check_repeat_form(std::string& repeat);

// Creates a string describing the move
std::string move_string(board game_board, std::string original_pos, std::string new_pos);





