#ifndef COMMANDS_H
#define COMMANDS_H

    int validatingArguments(char* format, ...);
    void drawing_vertically(Canvas* board, int col, int row_start, int row_end);
    void drawing_horizontally(Canvas* board, int col_start, int col_end, int row);
    void drawing_up_diagonal(Canvas* board, int col_start, int row_start, int col_end, int row_end);
    void drawing_down_diagonal(Canvas* board, int col_start, int row_start, int col_end, int row_end);
    void write_this(Canvas* board);
    void erase_this(Canvas* board);
    void add_this(Canvas* board);
    void _delete_this(Canvas* board);
    void resize_this(Canvas* board);

#endif