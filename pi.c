#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_input(int *seed__, int *runs) {
    printf("Enter the seed for the random number generator: ");
    scanf("%d", seed__);
    printf("Enter the number of iterations to run: ");
    scanf("%d", runs);
    while (*runs <= 0) {
        printf("Enter the number of iterations to run: ");
        scanf("%d", runs);
    }
    return 0;
}

double calculate_pi(int seed__, int iterations__) {
    srand(seed__);
    int insideCircleCountsHere = 0;
    for (int n = 0; n < iterations__; n++) {
        double x = (double)rand() / RAND_MAX * 2 - 1;
        double y = (double)rand() / RAND_MAX * 2 - 1;
        if (x * x + y * y <= 1) {
            insideCircleCountsHere++;
        }
    }
    return 4 * (double)insideCircleCountsHere / iterations__;
}

int main() {
    int seed__, iterations__;
    get_input(&seed__, &iterations__);
    double estmination_pi = calculate_pi(seed__, iterations__);
    printf("The value of pi is %.2f.\n", estmination_pi);
    return 0;
}