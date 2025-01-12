//header files

#include <stdio.h>

//start of main program

int main()
{

    //variable declrations

    int rows, columns_, hhh, ggg;

    //array declrations

    double first_matrix[100][100], second_matrix[100][100];

    int final[100][100];

    //input validation of row

    do
    {

        printf("Please enter the number of rows: ");

        scanf("%d", &rows);

        if(rows<1)
        {

            printf("Inavlid rows..!!!row should be greater than or equal to 1.\n");

        }

    }
    while(rows<1);

    //input validation of number of columns

    do

    {

        printf("Please enter the number of columns: ");

        scanf("%d", &columns_);

        if(columns_<1)

        {

            printf("Inavlid columns..!!!columns should be greater than or equal to 1.\n");

        }

    }
    while(columns_<0);

    //enter matrix A


    printf("Enter Matrix A\n");

    for (hhh = 0; hhh < rows; hhh++)
    {
        for (ggg = 0; ggg < columns_; ggg++)
        {
            scanf("%lf", &first_matrix[hhh][ggg]);
        }
    }

    
    //enter matrix B
    printf("Enter Matrix B\n");

    for (hhh = 0; hhh < rows; hhh++)
    {
        for (ggg = 0 ; ggg < columns_; ggg++)
        {
            scanf("%lf", &second_matrix[hhh][ggg]);
        }
    }

    
    //calculate sum of matrix

    printf("A + B = \n");

    for (hhh = 0; hhh < rows; hhh++)
    {
        for (ggg = 0 ; ggg < columns_; ggg++) 
        {

            final[hhh][ggg] = first_matrix[hhh][ggg] + second_matrix[hhh][ggg];

            printf("%d ", final[hhh][ggg]);

        }

        printf("\n");

    }

    return 0;

}//end of the program