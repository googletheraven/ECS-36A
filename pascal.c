#include <stdio.h>


int binomialCoefficient(int n, int k) {
   if (k == 0 || k == n) {
       return 1;
   }
   
   int result = 1;
   if (k > n - k) {
       k = n - k;
   }

   for (int i = 0; i < k; i++) {
       result *= (n - i);
       result /= (i + 1);
   }
   
   return result;
}

int main() {
   int levels;

   printf("Please enter how many levels of Pascal's Triangle you would like to see: ");
   scanf("%d", &levels);

   for (int i = 0; i < levels; i++) {
       for (int j = 0; j <= i; j++) {
           printf("%d ", binomialCoefficient(i, j));
       }
       printf("\n");
   }

   return 0;
}