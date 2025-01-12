#ifndef CANVAS_H
#define CANVAS_H

    typedef struct Canvas {
        int number_of_rows;
        int number_of_columns;
        char** table_here;
    } Canvas;

    void printing_help_commands();
    char** making_a_canvas(Canvas board);
    void displaying_the_canvas(Canvas board);
    char* getting_the_file_name();
    void save_this(Canvas board);
    void load_this(Canvas* board);

#endif