#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "canvas.h"
#include "commands.h"

void printing_help_commands() {
    /**
    prints all commands the program takes
    @returns: nothing
    */
    printf("Commands:\n");
    printf("Help: h\n");
    printf("Quit: q\n");
    printf("Draw line: w row_start col_start row_end col_end\n");
    printf("Resize: r num_rows num_cols\n");
    printf("Add row or column: a [r | c] pos\n");
    printf("Delete row or column: d [r | c] pos\n");
    printf("Erase: e row col\n");
    printf("Save: s file_name\n");
    printf("Load: l file_name\n");
}

char** making_a_canvas(Canvas board) {
    /**
    creates an empty matrix with dimensions inside struct
    @board: a struct holding the dimensions
    @returns: a char matrix initialized with *'s
    */
    char** canvas;
    canvas = (char**)malloc(board.number_of_rows * sizeof(char*));
    for (int i = 0; i < board.number_of_rows; ++i) {
        canvas[i] = (char*)malloc(board.number_of_columns * sizeof(char));
    }
    for (int i = 0; i < board.number_of_rows; ++i) {
        for (int j = 0; j < board.number_of_columns; ++j) {
            canvas[i][j] = '*';
        }
    }
    return canvas;
}

void displaying_the_canvas(Canvas board) {
    /**
    prints the current canvas to the screen
    @board: a struct holding the canvas contents
    @returns: nothing
    */
    int row_num = board.number_of_rows - 1;

    for (int i = row_num; i >= 0; --i, --row_num) {
        printf("%d ", row_num);
        for (int j = 0; j < board.number_of_columns; ++j) {
            printf("%c ", board.table_here[i][j]);
        }
        printf("\n");
    }
    
    printf("  ");
    for (int i = 0; i < board.number_of_columns; ++i) {
        printf("%d ", i);
    }
    printf("\n");
}

char* getting_the_file_name() {
    /**
    reads file name from command argument
    @returns: a string of the file name
    */
    char ch = '?';
    int CUR_MAX = 20;
    char* buffer = (char*)malloc(sizeof(char) * CUR_MAX);
    int length = 0;

    while (ch != '\n') {
        if (length == CUR_MAX) {
            CUR_MAX *= 2;
            buffer = realloc(buffer, CUR_MAX);
        }
        ch = getc(stdin);
        if (!isspace(ch)) {
            buffer[length] = ch;
            length++;
        }
    }

    return buffer;
}

void save_this(Canvas board) {
    /**
    saves the current canvas to a text file
    @board: a struct holding the canvas contents
    @modifies: a text file
    */
    FILE* fp;
    char* file_name = getting_the_file_name();
    fp = fopen(file_name, "w");
    if (fp == NULL) {
        printf("Improper save command or file could not be created.\n");
        return;
    }

    fprintf(fp, "%d %d", board.number_of_rows, board.number_of_columns);
    fprintf(fp, "\n");
    for (int row = 0; row < board.number_of_rows; ++row) {
        for (int col = 0; col < board.number_of_columns; ++col) {
            fprintf(fp, "%c", board.table_here[row][col]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

void load_this(Canvas* board) {
    /**
    replaces the current canvas with one loaded from a text file
    @board: a pointer to a struct holding the canvas being replaced
    @modifies: board
    */
    FILE* fp;
    char* file_name = getting_the_file_name();
    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Improper load command or file could not be opened.\n");
        return;
    }
    
    free(board->table_here);
    fscanf(fp, "%d %d", &board->number_of_rows, &board->number_of_columns);
    board->table_here = making_a_canvas(*board);

    for (int row = 0; row < board->number_of_rows; ++row) {
        for (int col = 0; col < board->number_of_columns; ++col) {
            fscanf(fp, "%c ", &board->table_here[row][col]);
            if (board->table_here[row][col] == '\n') {
                col--;
            }
        }
    }
    fclose(fp);
}