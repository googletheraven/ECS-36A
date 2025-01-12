#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "connectn.h"

int main(int arguments, char *earguments_[]) {
    
    // Check to see if there are not the proper number of arguments
    if (arguments < 4) {
        printf("Not enough arguments entered\n");
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
        return EXIT_SUCCESS;
    }
    if (arguments>4)
    {
        printf("Too many arguments entered\nUsage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win");
        return EXIT_SUCCESS;
    }


    // Get the number of rows, number of columns, and pieces in a row needed to win
    int number_of_rows = atoi(earguments_[1]);
    int columns_number = atoi(earguments_[2]);
    int pieces_here_to_win = atoi(earguments_[3]);

    // Check to see if any of the numbers inputted are not positive integers
    if (number_of_rows <= 0 || columns_number <= 0 || pieces_here_to_win <= 0) {
        printf("Invalid values entered for board dimensions or pieces in a row.\n");
        printf("Usage: connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
        return EXIT_FAILURE;
    }

    // Established the initial game board
    Board_To_Play_On board_to_play_on;
    board_to_play_on.number_of_rows = number_of_rows;
    board_to_play_on.number_of_columns = columns_number;
    board_to_play_on.pieces_to_win = pieces_here_to_win;
    board_to_play_on.player_number_one = 'X';
    board_to_play_on.player_number_two = 'O';

    get_a_new_board(&board_to_play_on); 

    // Starting the game
    int currentPlayer = 1; // Put the current player as player one
    while (1) {
        display_a_new_board(&board_to_play_on); // Print the new board

        // Establish the player symbol
        char playerSymbol = (currentPlayer == 1) ? board_to_play_on.player_number_one : board_to_play_on.player_number_two;
        // Column the player want to input; variable being initialized
        int column;
        
        // Get a move from the currrent play that is in bounds
        while (1) {
            column = input_from_player_for_move(&board_to_play_on, playerSymbol);

            // Playerr makes a move
            if (player_makes_a_move(&board_to_play_on, column, playerSymbol)) {
                break;
            }
        }

        // Check if the player won or if there is a tie
        char winner = who_won_the_game(&board_to_play_on);
        if (winner != ' ') {
            display_a_new_board(&board_to_play_on);
            if (winner == 'T') {
                printf("Tie game!\n");
            } 
            else if (winner == 'X')
            {
                printf("Player 1 Won!\n");
            }
            else
            {
                printf("Player 2 Won!\n");
            }
            break;
        }

        // Check if the board is full and there is a tie
        if (is_the_board_full(&board_to_play_on)) {
            display_a_new_board(&board_to_play_on);
            printf("Tie game!\n");
            break;
        }

        // Switch to the other player
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    clear_the_board(&board_to_play_on); 
    return EXIT_SUCCESS;
}