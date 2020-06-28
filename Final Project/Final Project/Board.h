#include <vector>
#include<string>
#include<memory>

class piece;

#ifndef BOARD
#define BOARD

class board 
{
public:
    // Polymorphic vector of pieces
    std::vector<std::shared_ptr<piece>> squares;
    board();
    ~board() {}
    void move_piece(int o, int n);
    void print_board(std::vector<int> allowed, std::vector<std::string> p1_moves, std::vector<std::string> p2_moves, int player);
    bool check_check(int player);
};

#endif