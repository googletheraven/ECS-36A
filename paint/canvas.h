#include <stdbool.h>

typedef struct {
    int rows;
    int columns;
    char** data;
} Canvas;

Canvas createCanvas(int rows, int columns);
void destroyCanvas(Canvas canvas);