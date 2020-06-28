#include "Game functions.h"

int main()
{
    // Repeat string
    std::string repeat{"Y"};

    // Game loop
    while (repeat == "Y") {

        // Game variables
        board game_board;
        int count{};
        std::vector<std::string> p1_moves, p2_moves;
        bool legal_moves = true;

        // Place pieces on board
        set_board_classic(game_board);

        // Turn Loop
        while (legal_moves == true) {

            // Turn variables
            std::string original_pos{}, new_pos{ "X" };
            int player{ (count % 2) + 1 }, opponent{ ((count + 1) % 2) + 1 };
           
            // Move selection loop
            while (new_pos == "X") {

                // Selection Varaibles       
                std::vector<int> allowed, allowed_checked;

                //Print out board
                game_board.print_board(allowed, p1_moves, p2_moves, player);

                // Piece selection loop
                while (allowed_checked.size() == 0) {
                    std::cout << std::endl << "Player " << player << " please enter the position of the piece you wish to move:" << std::endl;
                    std::getline(std::cin, original_pos);

                    // Check that input form is good and that they have a piece there if not ask again
                    while (check_input_form_orig(original_pos) == false || check_piece(game_board, original_pos, player) == false) {
                        std::cout << "Please try again:" << std::endl;
                        std::getline(std::cin, original_pos);
                    }

                    // Get allowed moves for piece
                    allowed = game_board.squares[coor_to_vec_num(original_pos)]->allowed_moves(game_board, coor_to_vec_num(original_pos));

                    // Moves where the player does not play themselves into check get added to allowed checked
                    test_all_for_check(allowed, game_board, player, coor_to_vec_num(original_pos), allowed_checked);
                    if (allowed_checked.size() == 0) std::cout << "No allowed moves for this piece.";
                }

                // Now that allowed moves has entries, display the board with them on
                game_board.print_board(allowed_checked, p1_moves, p2_moves, player);
                std::cout << std::endl << "Allowed moves are: ";
                for (auto allowed_checked_it = allowed_checked.begin(); allowed_checked_it < allowed_checked.end(); allowed_checked_it++) {
                    std::cout << vec_num_to_coor(*allowed_checked_it) << " ";
                }

                // New position selection loop
                std::cout << std::endl << "Player " << player << " please enter where you wish to move the piece to (or enter X to go back)" << std::endl;
                std::getline(std::cin, new_pos);
                while (check_input_form_new(new_pos) == false || check_allowed(allowed_checked, new_pos) == false) {
                    std::cout << "Please try again:" << std::endl;
                    std::getline(std::cin, new_pos);
                }
            }

            // Store move
            if (player == 1) p1_moves.push_back(move_string(game_board, original_pos, new_pos));
            else p2_moves.push_back(move_string(game_board, original_pos, new_pos));

            // Move piece
            game_board.move_piece(coor_to_vec_num(original_pos), coor_to_vec_num(new_pos));

            // If pawn has travelled the board promote it 
            if (game_board.squares[coor_to_vec_num(new_pos)]->check_type() == "pawn" && coor_to_vec_num(new_pos) > 55 || coor_to_vec_num(new_pos) < 8) promotion(game_board, player, new_pos);

            // Check whether the opponent has any legal moves
            legal_moves = any_legal_moves(game_board, opponent);

            // Check if opponent is in check
            bool check{ game_board.check_check(opponent) };

            // Result of turn in determined by whether the opponent is in check and whether they have legal move
            if (legal_moves == true && check == true) std::cout << "Player " << opponent << " is in check!" << std::endl;
            else if (legal_moves == false && check == true) std::cout << "Checkmate! Player " << player << " wins!" << std::endl;
            else if (legal_moves == false && check == false) std::cout << "Stalemate! Game over!" << std::endl;
               
            count++;
        }

        // Ask player if they want to play another game
        std::cout << std::endl << "Would you like to play another game (Y/N)?" << std::endl;
        std::getline(std::cin, repeat);
        while (check_repeat_form(repeat) == false) {
            std::cout << "Please enter Y or N:" << std::endl;
            std::getline(std::cin, repeat);
        }
    }
    return 0;
}

