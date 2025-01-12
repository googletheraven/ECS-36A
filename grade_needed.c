/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    // Declare variables for the grade I want in the class, the percent to get the grade I want, the percent I have now, and the weight of the final
    char gradeIwant;
    double gradePercent;
    double percentIHaveNow;
    double theWeightOfTheFinal;
    
    // Ask for the grade that I want in the class
    printf("Enter the grade you want in the class: ");
    scanf(" %c", &gradeIwant);

    // Ask for what I need to get that grade
    printf("Enter the percent you need to get that grade: ");
    scanf("%lf", &gradePercent);

    // Ask for the current percentage in the class
    printf("Enter your current percent in the class: ");
    scanf("%lf", &percentIHaveNow);

    // Ask for the weight of the final
    printf("Enter the weight of the final: ");
    scanf("%lf", &theWeightOfTheFinal);
    
    // Get the weight of the final, divide by hundred to convert to a decimal
    // Subtract that weight by 1 to get the current percentage of points in the gradebook
    // Multiply the current percentage of the points in the gradebook by the percent I have now
    // Subtract the grade I want in that class with the current percent I have now
    // Divide that by the weight of the final divided by 100
    double finalGrade = (gradePercent - (1 - (theWeightOfTheFinal / 100)) * percentIHaveNow) / (theWeightOfTheFinal / 100);

    // Print the final grade
    printf("You need to get at least %.2lf%% on the final to get a %c in the class.\n", finalGrade, gradeIwant);

    return 0;
}
