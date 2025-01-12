#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the Value struct
typedef struct {
    int xxx;
    int yyy;
} Value;

// Function to calculate the distance between two points
double get_the_distance(Value point_one, Value point_two) {
    return sqrt((double)(point_two.xxx - point_one.xxx) * (point_two.xxx - point_one.xxx) + (point_two.yyy - point_one.yyy) * (point_two.yyy - point_one.yyy));
}

// Main function that accepts number of arguments and a string array that accepts string arguments
int main(int argument, char *argument_here[])
{
    // If the arguments are not equal to two, end the program
    if (argument != 2) {
        fprintf(stderr, "Usage: %s <binary_file>\n", argument_here[0]);
        return 1;
    }

    // If the opening file is null, end the program
    FILE *inputted_file = fopen(argument_here[1], "rb");
    if (inputted_file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Integer establishing the amount of numbers in the input
    int numbers_here;
    // Read the file
    fread(&numbers_here, sizeof(int), 1, inputted_file);

    // If the amount of numberrs in the input is less than three, end the program
    if (numbers_here < 3) {
        fprintf(stderr, "Error: At least 3 points are required\n");
        fclose(inputted_file);
        return 1;
    }

    // Set an array with the points
    Value *points = (Value *)malloc(numbers_here * sizeof(Value));
    // If the number of points are not there, end the program
    if (points == NULL) {
        perror("Memory allocation error");
        fclose(inputted_file);
        return 1;
    }

    //
    fread(points, sizeof(Value), numbers_here, inputted_file);
    fclose(inputted_file);

    double perimeter = 0.0;
    for (int i = 0; i < numbers_here; i++) {
        perimeter += get_the_distance(points[i], points[(i + 1) % numbers_here]);
    }

    printf("The perimeter is %.2lf\n", perimeter);

    free(points);
    return 0;
}