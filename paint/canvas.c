#include <stdlib.h>
#include <string.h>
#include "canvas.h"

Canvas createCanvas(int rows, int columns) {
    Canvas canvas;
    canvas.rows = rows;
    canvas.columns = columns;

    canvas.data = (char**)malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        canvas.data[i] = (char*)malloc(columns * sizeof(char));
        memset(canvas.data[i], ' ', columns);
    }

    return canvas;
}

void destroyCanvas(Canvas canvas) {
    for (int i = 0; i < canvas.rows; i++) {
        free(canvas.data[i]);
    }
    free(canvas.data);
}