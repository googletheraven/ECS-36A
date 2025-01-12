#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool is_it_valid_formatting(int argumenntshere, int number_args_needed);
int getting_valid_numbers(char* input_to_get);int get_pos_int(char* input_to_get);
int getting_integers(char* input_to_get, int minimum____imum_value);
double getting_possible_doubles(char* input_to_get);
double minimum____(double a, double b);
double investing_tht_money_paying_first(double money_to_invest,double rate_of_return_yearly,int age_you_are_now,int age_of_retirement,double amount_in_the_loans,double yearly_interest,double amount_of_loan_To_pay);

bool is_it_valid_formatting(int argumenntshere, int number_args_needed)
{
    char on_a_new_line = '\n';
    bool valid_ = true;

    if(argumenntshere != number_args_needed)
    {
        valid_ = false;
    }

    do
    {
        scanf("%c", &on_a_new_line);
        if(!isspace(on_a_new_line))
        {
            valid_ = false;
        }
    }
    while(on_a_new_line != '\n');
    return valid_;

}

int getting_valid_numbers(char* input_to_get)
{
    int argumenntshere, number;
    do
    {
        printf("%s", input_to_get);argumenntshere = scanf("%d", &number);
    }
    while(!is_it_valid_formatting(argumenntshere, 1));
    return number;
}

int get_pos_int(char* input_to_get)
{
    int argumenntshere, number;
    do
    {
        printf("%s", input_to_get);argumenntshere = scanf("%d", &number);
    }
    while(!(is_it_valid_formatting(argumenntshere, 1) && number >= 0));
    return number;
}

int getting_integers(char* input_to_get, int minimum____imum_value)
{
    int argumenntshere, number;
    do
    {
        printf("%s", input_to_get);argumenntshere = scanf("%d", &number);
    }
    while(!(is_it_valid_formatting(argumenntshere, 1) && number >= minimum____imum_value));
    return number;
}

double getting_possible_doubles(char* input_to_get)
{
    int argumenntshere;
    double number;
    do
    {
        printf("%s", input_to_get);
        argumenntshere = scanf("%lf", &number);
    }
    while(!(is_it_valid_formatting(argumenntshere, 1) && number >= 0));
    return number;
}

double minimum____(double aaa, double bbb)
{
    return aaa < bbb ? aaa : bbb;
}

double investing_tht_money_paying_first(double money_to_invest,double rate_of_return_yearly,int age_you_are_now,int age_of_retirement,double amount_in_the_loans,double yearly_interest,double amount_of_loan_To_pay)
{
    double montly_interest = yearly_interest / 12.0;
    double monthly_rate_of_return = rate_of_return_yearly / 12.0;
    double savings_here = 0;

    int retirement_months = (age_of_retirement - age_you_are_now) * 12;
    int month_jjj;

    for(month_jjj = 0; month_jjj < retirement_months; ++month_jjj)
    {
        amount_in_the_loans *= 1 + montly_interest;
        savings_here *= 1 + monthly_rate_of_return;
        amount_of_loan_To_pay = minimum____(amount_of_loan_To_pay, amount_in_the_loans);
        amount_in_the_loans -= amount_of_loan_To_pay;
        savings_here += money_to_invest - amount_of_loan_To_pay;
    }

    if(amount_in_the_loans > 0)
    {
        printf("Warning! After you retire you will still have $%.2lf inloans left.\n", amount_in_the_loans);
    }

    return savings_here;
}

void run()
{
    double money_to_invest;
    double amount_in_the_loans, yearly_interest, amount_of_loan_To_pay;
    double rate_of_return_yearly;
    int age_you_are_now, age_of_retirement;
    double savings_if_the_loans_are_payed_first;
    double savings_minimum____imum_amount_of_loan_To_pays;
    amount_in_the_loans = getting_possible_doubles("Enter how much you owe in loans: ");
    yearly_interest = getting_possible_doubles("Enter the annual interest rate of the loans: ");
    amount_of_loan_To_pay = getting_possible_doubles("Enter your minimum monthly loan payment: ");
    money_to_invest = getting_possible_doubles("Enter how much money you will beputting towards loans/retirement each month: ");
    if(amount_of_loan_To_pay > money_to_invest)
    {
        printf("You didn't set aside enough money to pay off our loans. Ending program.\n");
        exit(0);
    }
    age_you_are_now = get_pos_int("Enter your current age: ");
    age_of_retirement = getting_integers("Enter the age you plan to retire at: ",age_you_are_now);
    rate_of_return_yearly = getting_possible_doubles("Enter your predicted annual rate of return: ");
    savings_if_the_loans_are_payed_first = investing_tht_money_paying_first(money_to_invest,rate_of_return_yearly, age_you_are_now, age_of_retirement,amount_in_the_loans, yearly_interest, money_to_invest);
    savings_minimum____imum_amount_of_loan_To_pays =investing_tht_money_paying_first(money_to_invest,rate_of_return_yearly, age_you_are_now, age_of_retirement,amount_in_the_loans, yearly_interest, amount_of_loan_To_pay);
    if(savings_if_the_loans_are_payed_first > savings_minimum____imum_amount_of_loan_To_pays)
    {
        printf("You should apply all $%.2lf towards your loan before making any investments.\n", money_to_invest);
        printf("If you do you will have $%.2lf when you retire as opposed to $%.2lf if you only made minimum payments.\n",savings_if_the_loans_are_payed_first,savings_minimum____imum_amount_of_loan_To_pays);
    }
    else
    {
        printf("You should only make the minimum payments on your loan and apply the rest towards retirement.\n");
        printf("If you do you will have $%.2lf when you retire as opposed to $%.2lf if you paid off your loan before investing.\n",savings_minimum____imum_amount_of_loan_To_pays,savings_if_the_loans_are_payed_first);

    }
}

// Here to get the function to run
int main()
{
    // Calls to a void function to run the program properly
    run();
    // Exit program
    return 0;
}