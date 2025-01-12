#include <stdio.h>
#include <stdlib.h>
#include "file.h"
void saveCanvas(Canvas canvas, char* file_name) {
   FILE* file = fopen(file_name, "w");
   if (file == NULL) {
       printf("Error opening file for writing\n");
       return;
   }
   // Implement the logic to save the canvas to a file
   for (int i = 0; i < canvas.rows; i++) {
       for (int j = 0; j < canvas.columns; j++) {
           fprintf(file, "%c ", canvas.data[i][j]);
       }
       fprintf(file, "\n");
   }
   fclose(file);
}
void loadCanvas(Canvas* canvas, char* file_name) {
   FILE* file = fopen(file_name, "r");
   if (file == NULL) {
       printf("Error opening file for reading\n");
       return;
   }
   // Implement the logic to load the canvas from a file
   for (int i = 0; i < canvas->rows; i++) {
       for (int j = 0; j < canvas->columns; j++) {
           fscanf(file, " %c", &canvas->data[i][j]);
       }
   }
   fclose(file);
}