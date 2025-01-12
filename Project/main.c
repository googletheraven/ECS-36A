
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "canvas.h"
#include "commands.h"

int main(int agrument, char** argvments) {
    Canvas board;
    bool validRowCount = false;
    bool defaultBoard = true;

    board.number_of_rows = 10, board.number_of_columns = 10;
    if (agrument == 3) {
        if (atoi(argvments[1]) != 0) {
            if (atoi(argvments[1]) > 0) {
                board.number_of_rows = atoi(argvments[1]);
                validRowCount = true;
            }
            else {
                printf("The number of rows is less than 1.\n");
            }
        }
        else {
            printf("The number of rows is not an integer.\n");
        }

        if (validRowCount) {
            if (atoi(argvments[2]) != 0) {
                if (atoi(argvments[2]) > 0) {
                    board.number_of_columns = atoi(argvments[2]);
                    defaultBoard = false;
                }
                else {
                    printf("The number of columns is less than 1.\n");
                    board.number_of_rows = 10;
                }
            }
            else {
                printf("The number of columns is not an integer.\n");
                board.number_of_rows = 10;
            }
        }
    }
    else if (agrument != 1) {
        printf("Wrong number of command line arguments entered.\n");
        printf("Usage: ./paint.out [num_rows num_cols]\n");
    }

    if (defaultBoard && agrument != 1) {
        printf("Making default board of 10 X 10.\n");
    }

    board.table_here = making_a_canvas(board);
    displaying_the_canvas(board);

    char command = '\0';
    do {
        printf("Enter your command: ");
        do {
            scanf("%c", &command);
        } while (!isalpha(command));

        if (command == 'h') {
            printing_help_commands();
        }
        else if (command == 'w') {
            write_this(&board);
        }
        else if (command == 'e') {
            erase_this(&board);
        }
        else if (command == 'r') {
            resize_this(&board);
        }
        else if (command == 'a') {
            add_this(&board);
        }
        else if (command == 'd') {
            _delete_this(&board);
        }
        else if (command == 's') {
            save_this(board);
        }
        else if (command == 'l') {
            load_this(&board);
        }
        else if (command != 'q') {
            printf("Unrecognized command. Type h for help.\n");
        }

        if (command != 'q') {
            displaying_the_canvas(board);
        }

        fflush(stdin);
    }
    while (command != 'q');
    free(board.table_here);

    return 0;
}