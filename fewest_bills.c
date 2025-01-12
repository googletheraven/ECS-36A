/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

// Main function
int main()
{
    // Ask for the amount of amount of money to withdraw : You print for the ask portion and have a seprate function to get input
    printf("Please enter the amount of money you wish to withdraw: ");
    int Money;
    scanf("%d", &Money);
    
    // Get number of hundreds
    int numHundreds = Money / 100;
    // Get the remainder so that there are no hundred dollar bills left
    Money = Money % 100;
    //  Get number of fifties
    int numFifties = Money / 50;
    // Get the remainder so that there are no fifty dollar bills left
    Money = Money % 50;
    int numTwenties = Money / 20;
    Money = Money % 20;
    int numTens = Money / 10;
    Money = Money % 10;
    int numFives = Money / 5;
    Money = Money % 5;
    int numOnes = Money;
    
    // Print result
    printf("You received %d hundred(s)", numHundreds);
    printf("\nYou received %d fifty(s)", numFifties);
    printf("\nYou received %d twenty(s)", numTwenties);
    printf("\nYou received %d ten(s)", numTens);
    printf("\nYou received %d five(s)", numFives);
    printf("\nYou received %d one(s)", numOnes);

    return 0;
}
