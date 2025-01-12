#include <stdio.h>
#include <stdlib.h>
#include "mat_multiply.h"

void get_matrix_dimensions_from_user(char* prompt, int* num_rows, int* num_cols){
    printf("%s", prompt);
   scanf("%d %d", num_rows, num_cols);
}

int** make_empty_matrix(int num_rows, int num_cols) {
    int** matrix = (int**)malloc(num_rows * sizeof(int*));
   
   for (int i = 0; i < num_rows; ++i) {
       matrix[i] = (int*)malloc(num_cols * sizeof(int));
   }
   
   return matrix;

}

void fill_matrix_from_user_input(int** matrix, int num_rows, int num_cols) {
    for (int i = 0; i < num_rows; ++i) {
       for (int j = 0; j < num_cols; ++j) {
           scanf("%d", &matrix[i][j]);
       }
   }

}

int** matrix_multiply(int** matrix_a, int num_rows_a, int num_cols_a, int** matrix_b, int num_rows_b, int num_cols_b, int* out_num_rows_c, int* out_num_cols_c) 
{
    if (num_cols_a != num_rows_b) 
    {
       printf("Matrix multiplication is not possible. Exiting...\n");
       exit(1);
   }
    *out_num_rows_c = num_rows_a;
   *out_num_cols_c = num_cols_b;
    int** result_matrix = make_empty_matrix(*out_num_rows_c, *out_num_cols_c);

   for (int i = 0; i < *out_num_rows_c; ++i) {
       for (int j = 0; j < *out_num_cols_c; ++j) {
           result_matrix[i][j] = 0;
           for (int k = 0; k < num_cols_a; ++k) {
               result_matrix[i][j] += matrix_a[i][k] * matrix_b[k][j];
           }
       }
   }
   return result_matrix;

}

void print_matrix(int** matrix, int num_rows, int num_cols) {
    for (int i = 0; i < num_rows; ++i) {
       for (int j = 0; j < num_cols; ++j) {
           printf("%d ", matrix[i][j]);
       }
       printf("\n");
   }

}

void delete_matrix(int*** matrix, int num_rows, int num_cols) {
     for (int i = 0; i < num_rows; ++i) {
       free((*matrix)[i]);
   }
   free(*matrix);
   *matrix = NULL;
}
