
#include "canvas.h"

typedef enum {
    write,
    erase,
    resize,
    add,
    delete,
    save,
    load,
    quit,
    help
} CommandType;

typedef struct {
    CommandType type;
    union {
        struct {
            int start_row;
            int start_column;
            int end_row;
            int end_column;
        } write;
        struct {
            int row;
            int column;
        } erase;
        struct {
            int num_rows;
            int num_columns;
        } resize;
        struct {
            int position;
            bool is_row;
        } add;
        struct {
            int position;
            bool is_row;
        } delete;
        struct {
            char* file_name;
        } save;
        struct {
            char* file_name;
        } load;
    } parameters;
} Command;

Command readCommand();
void executeCommand(Canvas canvas, Command command);