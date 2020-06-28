
#include "Game functions.h";

// Sets the classic set up
void set_board_classic(board& game_board)
{
    // Place pieces on board
    game_board.squares[0] = std::make_shared<rook>(1);
    game_board.squares[1] = std::make_shared<knight>(1);
    game_board.squares[2] = std::make_shared<bishop>(1);
    game_board.squares[3] = std::make_shared<queen>(1);
    game_board.squares[4] = std::make_shared<king>(1);
    game_board.squares[5] = std::make_shared<bishop>(1);
    game_board.squares[6] = std::make_shared<knight>(1);
    game_board.squares[7] = std::make_shared<rook>(1);
    for (int i{ 8 }; i < 16; i++) { game_board.squares[i] = std::make_shared<pawn>(1); }

    game_board.squares[56] = std::make_shared<rook>(2);
    game_board.squares[57] = std::make_shared<knight>(2);
    game_board.squares[58] = std::make_shared<bishop>(2);
    game_board.squares[59] = std::make_shared<queen>(2);
    game_board.squares[60] = std::make_shared<king>(2);
    game_board.squares[61] = std::make_shared<bishop>(2);
    game_board.squares[62] = std::make_shared<knight>(2);
    game_board.squares[63] = std::make_shared<rook>(2);
    for (int i{ 48 }; i < 56; i++) game_board.squares[i] = std::make_shared<pawn>(2);
}

std::string remove_spaces(std::string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

// Checks the form of the original position
bool check_input_form_orig(std::string& pos)
{
    // Remove white spaces
    pos = remove_spaces(pos);

    // Check Length
    if (pos.length() != 2) {
        std::cout << "Input form not correct. ";
        return false;
    }

    // Convert first charecter to upper case
    pos = { char((toupper(pos[0]))), pos[1] };
    std::string l1{ pos.substr(0, 1) };
    std::string n1{ pos.substr(1, 1) };

    // Check against allowed charecters
    if (l1 != "A" && l1 != "B" && l1 != "C" && l1 != "D" && l1 != "E" && l1 != "F" && l1 != "G" && l1 != "H") {
        std::cout << "Input form not correct. ";
        return false;
    }

    if (n1 != "0" && n1 != "1" && n1 != "2" && n1 != "3" && n1 != "4" && n1 != "5" && n1 != "6" && n1 != "7") {
        std::cout << "Input form not correct. ";
        return false;
    }
    else return true;
}


// New check input required for new position, takes into account whether the user enters X (which allows them to select another piece)
bool check_input_form_new(std::string& pos)
{
    // Remove white spaces
    pos = remove_spaces(pos);

    if (pos == "X" || pos == "x") {
        pos = "X";
        return true;
    }
    else {

        // Check length
        if (pos.length() != 2) {
            std::cout << "Input form not correct. ";
            return false;
        }

        // Convert first charecter to upper case
        pos = { char((toupper(pos[0]))), pos[1] };
        std::string l1{ pos.substr(0, 1) };
        std::string n1{ pos.substr(1, 1) };

        // Check against allowed charecters
        if (l1 != "A" && l1 != "B" && l1 != "C" && l1 != "D" && l1 != "E" && l1 != "F" && l1 != "G" && l1 != "H") {
            std::cout << "Input form not correct. ";
            return false;
        }

        if (n1 != "0" && n1 != "1" && n1 != "2" && n1 != "3" && n1 != "4" && n1 != "5" && n1 != "6" && n1 != "7") {
            std::cout << "Input form not correct. ";
            return false;
        }
        else return true;
    }
}


// Converts a coordinate string to the vector position
int coor_to_vec_num(std::string coor)
{
    int col;
    if (coor.substr(0, 1) == "A") col = 0;
    if (coor.substr(0, 1) == "B") col = 1;
    if (coor.substr(0, 1) == "C") col = 2;
    if (coor.substr(0, 1) == "D") col = 3;
    if (coor.substr(0, 1) == "E") col = 4;
    if (coor.substr(0, 1) == "F") col = 5;
    if (coor.substr(0, 1) == "G") col = 6;
    if (coor.substr(0, 1) == "H") col = 7;
    int row{ std::stoi(coor.substr(1,1)) };
    int arr_num{ (8 * row) + col };
    return arr_num;
}

// Checks whether the player has a piece at the specified position
bool check_piece(board game_board, std::string pos, int player)
{
    if (game_board.squares[coor_to_vec_num(pos)] == nullptr || game_board.squares[coor_to_vec_num(pos)]->get_player() != player) {
        std::cout << "You do not have a piece at this position! ";
        return false;
    }
    else return true;
}

// Converts vector position to coordinate string
std::string vec_num_to_coor(int num)
{
    std::vector<std::string> letters{ "A","B", "C", "D", "E", "F", "G", "H" };
    std::string coor{ letters[num % 8] };
    coor += std::to_string(int{ num / 8 });
    return coor;
}

// Checks whether the user entered move is in available moves
bool check_allowed(std::vector<int> allowed, std::string new_pos)
{
    if (new_pos == "X") return true;
    else {
        if (std::find(allowed.begin(), allowed.end(), coor_to_vec_num(new_pos)) != allowed.end()) return true;
        else {
            std::cout << "Move not allowed! ";
            return false;
        }
    }
}

// Checks whether the player has entered a valid promotion 
bool check_promotion(std::string& choice)
{
    // Format input into all lower case with no spaces
    choice = remove_spaces(choice);
    std::transform(choice.begin(), choice.end(), choice.begin(), std::tolower);

    // Check against allowed strings
    if (choice == "knight" || choice == "rook" || choice == "bishop" || choice == "queen") return true;
    else return false;
}

// Tests a move where piece of type T is taken, if move is not a self check (illegal), add to allowed checked
template <typename T>
void test_move_for_check(board& game_board, int orig_pos, int new_pos, int player, std::vector<int>& allowed_checked)
{
    int opponent;
    if (player == 1) opponent = 2;
    else opponent = 1;
 
    // Put stream into fail state so that test moves performed by the programme dont cause output
    std::cout.setstate(std::ios_base::failbit);

    // Perform move
    game_board.move_piece(orig_pos, new_pos);
    
    // If player does not play themselves into check, add to allowed checked
    if (game_board.check_check(player) == false) allowed_checked.push_back(new_pos);
    
    // Move piece back
    game_board.move_piece(new_pos, orig_pos);
    
    // Replace taken piece
    game_board.squares[new_pos] = std::make_shared<T>(opponent);

    // Clear failbit
    std::cout.clear();
}


// Tests list of allowed moves, if move is not a self check (illegal), add to allowed checked
void test_all_for_check(std::vector<int> allowed, board& game_board, int player, int pos, std::vector<int>& allowed_checked)
{
    // Perform each allowed move, if the move does put the player in check then add to allowed_checked
    for (auto allowed_it = allowed.begin(); allowed_it < allowed.end(); allowed_it++) {
        // For moves in which no opponent pieces are taken
        if (game_board.squares[*allowed_it] == nullptr) {
            game_board.move_piece(pos, *allowed_it);
            if (game_board.check_check(player) == false) allowed_checked.push_back(*allowed_it);
            game_board.move_piece(*allowed_it, pos);
        }
        // For moves in which opponent pieces are taken
        else if (game_board.squares[*allowed_it]->check_type() == "pawn") {
            test_move_for_check<pawn>(game_board, pos, *allowed_it, player, allowed_checked);
        }
        else if (game_board.squares[*allowed_it]->check_type() == "rook") {
            test_move_for_check<rook>(game_board, pos, *allowed_it, player, allowed_checked);
        }
        else if (game_board.squares[*allowed_it]->check_type() == "knight") {
            test_move_for_check<knight>(game_board, pos, *allowed_it, player, allowed_checked);
        }
        else if (game_board.squares[*allowed_it]->check_type() == "king") {
            test_move_for_check<king>(game_board, pos, *allowed_it, player, allowed_checked);
        }
        else if (game_board.squares[*allowed_it]->check_type() == "bishop") {
            test_move_for_check<bishop>(game_board, pos, *allowed_it, player, allowed_checked);
        }
        else {
            test_move_for_check<queen>(game_board, pos, *allowed_it, player, allowed_checked);
        }
    }
}

// Checks whether a player has any legal moves
bool any_legal_moves(board& game_board, int player)
{
    std::vector <int> allowed_opponent_all;
    // Find opponent pieces
    for (int i{}; i < 64; i++) {
        if (game_board.squares[i] != nullptr && game_board.squares[i]->get_player() == player) {
            // Get allowed moves for the piece 
            std::vector<int> allowed_opponent;
            allowed_opponent = game_board.squares[i]->allowed_moves(game_board, i);
            test_all_for_check(allowed_opponent, game_board, player, i, allowed_opponent_all);
        }
    }
    if (allowed_opponent_all.size() == 0) return false;
    else return true;
}

// Performs promotion
void promotion(board& game_board, int player, std::string new_pos)
{
    std::cout << "Pawn has reached eighth rank, what would you like to promote it to? ('bishop','knight', 'rook', or 'queen')" << std::endl;
    std::string promotion_choice;
    std::getline(std::cin, promotion_choice);

    // If promotion choice not valid ask again until valid
    while (check_promotion(promotion_choice) == false) {
        std::cout << "Error please type either 'Bishop','Knight', 'Rook', or 'Queen':" << std::endl;
        std::getline(std::cin, promotion_choice);
    }

    // Delete pawn and replace it with the chosen piece
     // Put stream into fail state so that pawn destructor does not output that the pawn is taken
    std::cout.setstate(std::ios_base::failbit);
    game_board.squares[(coor_to_vec_num(new_pos))] = nullptr;
    // Clear failbit
    std::cout.clear(); 
    if (promotion_choice == "bishop") game_board.squares[(coor_to_vec_num(new_pos))] = std::make_shared<bishop>(player);
    else if (promotion_choice == "rook") game_board.squares[(coor_to_vec_num(new_pos))] = std::make_shared <rook>(player);
    else if (promotion_choice == "knight") game_board.squares[(coor_to_vec_num(new_pos))] = std::make_shared<knight>(player);
    else  game_board.squares[(coor_to_vec_num(new_pos))] = std::make_shared<queen>(player);
}

// Removes white spaces, capitalises, checks input form
bool check_repeat_form(std::string& repeat)
{
    // Remove white spaces
    repeat = remove_spaces(repeat);
    if (repeat == "Y" || repeat == "y") {
        repeat = "Y";
        return true;
    }
    else if (repeat == "N" || repeat == "n") {
        repeat = "N";
        return true;
    }
    else return false;
}

std::string move_string(board game_board, std::string original_pos, std::string new_pos)
{
    // Get the first charecter of the piece moved to store the move
    std::string piece;
    if (game_board.squares[coor_to_vec_num(original_pos)]->check_type() == "knight") piece = "N";
    else piece = toupper(game_board.squares[coor_to_vec_num(original_pos)]->check_type()[0]);

    // Create string detailing full move and append to correct players move list 
    std::string move{ piece + " " + original_pos + "-" + new_pos };
    return move;
}
