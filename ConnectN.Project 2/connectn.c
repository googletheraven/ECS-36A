#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "connectn.h"

// Function to create the game board
void get_a_new_board(Board_To_Play_On *board_to_play_on) {
    int i, j;
    board_to_play_on->board_to_play_on = (char **) malloc(board_to_play_on->number_of_rows * sizeof(char *));
    for (i = 0; i < board_to_play_on->number_of_rows; i++) {
        board_to_play_on->board_to_play_on[i] = (char *) malloc(board_to_play_on->number_of_columns * sizeof(char));
        for (j = 0; j < board_to_play_on->number_of_columns; j++) {
            board_to_play_on->board_to_play_on[i][j] = '*';
        }
    }
}

// Function to print the game board
void display_a_new_board(Board_To_Play_On *board_to_play_on) {
    int i, j;
    for (i = board_to_play_on->number_of_rows - 1; i >= 0; i--) {
        printf("%d ", i);
        for (j = 0; j < board_to_play_on->number_of_columns; j++) {
            printf("%c ", board_to_play_on->board_to_play_on[i][j]);
        }
        printf("\n");
    }
    printf("  ");
    for (j = 0; j < board_to_play_on->number_of_columns; j++) {
        printf("%d ", j);
    }
    printf("\n");
}

// Function to make a move on the game board
int player_makes_a_move(Board_To_Play_On *board_to_play_on, int columns_here, char current_player) {
    int i;
    if (board_to_play_on->board_to_play_on[board_to_play_on->number_of_rows - 1][columns_here] != '*') {
        return 0;
    }
    for (i = 0; i < board_to_play_on->number_of_rows; i++) {
        if (board_to_play_on->board_to_play_on[i][columns_here] == '*') {
            board_to_play_on->board_to_play_on[i][columns_here] = current_player;
            return 1;
        }
    }
    return 0;
}

// Function to get a move from the user
int input_from_player_for_move(Board_To_Play_On *board_to_play_on, char current_player)
{
    int col;
    while (1) {
        printf("Enter a column between 0 and %d to play in: ", board_to_play_on->number_of_columns - 1);
        if (scanf("%d", &col) != 1) {
            while (getchar() != '\n');  // clear input buffer
            continue;
        }
        else if (col < 0 || col >= board_to_play_on->number_of_columns) {
            continue;
        }
        else
        {
            return col;
        }
    }
}

char who_won_the_game(Board_To_Play_On *board_to_play_on) {
   int i, j;

   // Check horizontally
   for (i = 0; i < board_to_play_on->number_of_rows; i++) {
       for (j = 0; j <= board_to_play_on->number_of_columns - board_to_play_on->pieces_to_win; j++) {
           char symbol = board_to_play_on->board_to_play_on[i][j];
           int count = 0;
           for (int k = 0; k < board_to_play_on->pieces_to_win; k++) {
               if (board_to_play_on->board_to_play_on[i][j + k] == symbol && symbol != '*') {
                   count++;
               }
           }
           if (count == board_to_play_on->pieces_to_win) {
               return symbol;
           }
       }
   }

   // Check vertically
   for (j = 0; j < board_to_play_on->number_of_columns; j++) {
       for (i = 0; i <= board_to_play_on->number_of_rows - board_to_play_on->pieces_to_win; i++) {
           char symbol = board_to_play_on->board_to_play_on[i][j];
           int count = 0;
           for (int k = 0; k < board_to_play_on->pieces_to_win; k++) {
               if (board_to_play_on->board_to_play_on[i + k][j] == symbol && symbol != '*') {
                   count++;
               }
           }
           if (count == board_to_play_on->pieces_to_win) {
               return symbol;
           }
       }
   }

   // Check diagonally (from top-left to bottom-right)
   for (i = 0; i <= board_to_play_on->number_of_rows - board_to_play_on->pieces_to_win; i++) {
       for (j = 0; j <= board_to_play_on->number_of_columns - board_to_play_on->pieces_to_win; j++) {
           char symbol = board_to_play_on->board_to_play_on[i][j];
           int count = 0;
           for (int k = 0; k < board_to_play_on->pieces_to_win; k++) {
               if (board_to_play_on->board_to_play_on[i + k][j + k] == symbol && symbol != '*') {
                   count++;
               }
           }
           if (count == board_to_play_on->pieces_to_win) {
               return symbol;
           }
       }
   }

   // Check diagonally (from top-right to bottom-left)
   for (i = 0; i <= board_to_play_on->number_of_rows - board_to_play_on->pieces_to_win; i++) {
       for (j = board_to_play_on->pieces_to_win - 1; j < board_to_play_on->number_of_columns; j++) {
           char symbol = board_to_play_on->board_to_play_on[i][j];
           int count = 0;
           for (int k = 0; k < board_to_play_on->pieces_to_win; k++) {
               if (board_to_play_on->board_to_play_on[i + k][j - k] == symbol && symbol != '*') {
                   count++;
               }
           }
           if (count == board_to_play_on->pieces_to_win) {
               return symbol;
           }
       }
   }

   // No winner found
   return ' ';
}

int is_the_board_full(Board_To_Play_On *board_to_play_on) {
   for (int i = 0; i < board_to_play_on->number_of_rows; i++) {
       for (int j = 0; j < board_to_play_on->number_of_columns; j++) {
           if (board_to_play_on->board_to_play_on[i][j] == '*') {
               return 0; // Not full
           }
       }
   }
   return 1; // Full
}

void clear_the_board(Board_To_Play_On *board_to_play_on) {
   for (int i = 0; i < board_to_play_on->number_of_rows; i++) {
       free(board_to_play_on->board_to_play_on[i]);
   }
   free(board_to_play_on->board_to_play_on);
}

