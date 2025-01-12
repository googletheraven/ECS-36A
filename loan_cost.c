

#include <stdio.h>
#include <math.h>

int main() {
  // Set variable for principle of loan (amount of money taken for a loan)
  double principal;

  // Set variable for the interest rate yearly
  double annual_interest_rate;

  // Set the variable for the number of payments the person has to make
  int number_of_payments;

// Ask the person how much money they want to borrow and get a double input for how much money they want to borrow
printf("Please enter the amount of money you borrowed:$");
  scanf("%lf", &principal);

// Ask the person to enter the yearly interest rate and get a double input for that
printf("Please enter the annual interest rate: ");
  scanf("%lf", &annual_interest_rate);

// Ask the person to enter how many payments they would have to make and get a double input for that 
printf("Please enter the number of payments to be made: ");
  scanf("%d", &number_of_payments);

// Calculate the monthly interest rate by taking the annual interest rate and dividing it by 12
  double monthly_interest_rate = annual_interest_rate / 12;

// Calculate the monthly payment using the interest equation multiplying the principal and the monthly interest rate on the numerator and dividing that by 1 - (1+ the monthly interest rate to the power of the number of payments)
  double monthly_payment = (principal * monthly_interest_rate) / (1 - pow((1 + monthly_interest_rate), -number_of_payments));

// Take the monthly payment and multiply that by the number of payments to get the total cost
  double total_cost = monthly_payment * number_of_payments;

// Print the results to the user.
  printf("A loan of $%.2f with an annual interest of %.2f paid off over %d months will have monthly payments of $%.2f.\n", principal, annual_interest_rate, number_of_payments, monthly_payment);
  printf("In total, you will pay $%.2f, making the cost of your loan $%.2f.\n", total_cost, total_cost - principal);

  return 0;
}