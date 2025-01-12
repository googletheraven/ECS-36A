#include <stdio.h>
#include <math.h>


int main(){

    // Setting up a, b, and c as double variables
    float a;
    float b;
    float c;

    // Give the form for a quadratic equation
    printf("Given a quadratic equation of the form a*x^2 + b * x + c");

    // Ask for a and get input for a as a double
    printf("\nPlease enter a: ");
    scanf("%f", &a);

    // Ask for b and get input as a double
    printf("Please enter b: ");
    scanf("%f", &b);

    // Ask for c and get input as a double
    printf("Please enter c: ");
    scanf("%f", &c);

    // Calculate the number under the square root
    float square_root = ((b * b) - 4 * a * c);
    // Establish variable to do quadratic equation in
    float h;
    float solution_one;
    float solution_two;

    /* If the number is negative, you would print that there are not solutions to this equation, 
    if the number is zero, then there is only one solution you would have to do
    if the number is positive, then you would go solve the equation fully*/
    if (square_root < 0){
        printf("There are no real solutions");
    }
    else if (square_root == 0){
        // Quadratic equation without the square root
        h = (-1 * b)/(2 * a);
        printf("There is one real solution: %0.2f", h);
    }
    else{
        // This is the solution where you add the square root
        solution_one = ((-1 * b) + sqrt(square_root)) / (2 * a);
        // This is the solution where you subtract the square root
        solution_two = ((-1 * b) - sqrt(square_root)) / (2 * a);
        printf("There are 2 real solutions\n");
        printf("Solution 1: %0.2f", solution_one);
        printf("\nSolution 2: %0.2f", solution_two);
    }
    return 0;


}