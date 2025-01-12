#ifndef CONNECTN_H
#define CONNECTN_H

// Struct representing the game board
typedef struct {
    char **board_to_play_on; // Array with two values to represent the board
    int number_of_rows;  // Number of rows inputted from the user
    int number_of_columns;  // Number of columns inputted from the userr
    char player_number_one;  // "X" representing player number one
    char player_number_two;  // "O" representing player number two
    int pieces_to_win;  // The pieces that are required to win the game
} Board_To_Play_On;

// Function prototypes
void get_a_new_board(Board_To_Play_On *board_to_play_on); // You are creating the board for the game
void display_a_new_board(Board_To_Play_On *board_to_play_on); // Display the board on the screen
int player_makes_a_move(Board_To_Play_On *board_to_play_on, int columns_here, char current_player); // You help the player make their move
int input_from_player_for_move(Board_To_Play_On *board_to_play_on, char current_player); // Get a column from the player
char who_won_the_game(Board_To_Play_On *board_to_play_on); // Check who won the game
int is_the_board_full(Board_To_Play_On *board_to_play_on); // Check to see if the board is full and there is a tie game
void clear_the_board(Board_To_Play_On *board_to_play_on); // Clear the board after the game is over

#endif
