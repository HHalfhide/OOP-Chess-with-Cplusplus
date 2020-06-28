
#include <vector>
class board;

// These functions add availabe sqaures to a vector in different directions
void move_diag(std::vector<int>& allowed, board game_board, int pos, int player, char u_or_d, char l_or_r);
void move_vert(std::vector<int>& allowed, board game_board, int pos, int player, char u_or_d);
void move_horiz(std::vector<int>& allowed, board game_board, int pos, int player, char l_or_r);