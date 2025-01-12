#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

double probNotDrew(double totCards, double totCopies, double times)
{
    double i;
    double result = 1.0;
    for(i = 0.0; i < times; ++i)
    {
        result *= 1.0 - totCopies / (totCards - i);
    }
    return result;
}

double probNotDuringMulligan(double totCards, double totCopies, double sizeOfHand, double mulligan)
{
    double leftCards = totCards - sizeOfHand;
    return probNotDrew(leftCards, totCopies, mulligan);
}

double probNotDuringDraw(double totCards, double totCopies, double sizeOfHand, double turn)
{
    double leftCards = totCards - sizeOfHand;
    return probNotDrew(leftCards, totCopies, turn);
}

void GetProbability(){
    double totCards;
    double totCopies;
    double sizeOfHand;
    double mulligan__;
    double turn;
    double overallProbability;
    double probablyNotInOP;
    double probablyNotINNDRaw;
    double probabblyNotInMulliagn;

    printf("Enter how many total cards there are in the deck: ");
    scanf("%lf", &totCards);
    printf("Enter how many copies of the card that you are looking for are in the deck: ");
    scanf("%lf", &totCopies);
    printf("Enter your initial hand size: ");
    scanf("%lf", &sizeOfHand);
    printf("Enter how many cards you are mulliganing: ");
    scanf("%lf", &mulligan__);
    printf("Enter what turn you want to draw the card by: ");
    scanf("%lf", &turn);
    probablyNotInOP = probNotDrew(totCards, totCopies, sizeOfHand);
    probabblyNotInMulliagn = probNotDuringMulligan(totCards, totCopies, sizeOfHand, mulligan__);
    probablyNotINNDRaw = probNotDuringDraw(totCards, totCopies, sizeOfHand, turn);
    overallProbability = 1.0 - probablyNotInOP *probabblyNotInMulliagn * probablyNotINNDRaw;
    printf("The probability of drawing at least one of the cards by turn %d given you mulliganed %d cards is %.2lf\n", (int) turn, (int) mulligan__, overallProbability);
}

int main()
{
    GetProbability();
    return 0;
}