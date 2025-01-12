#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <ctype.h>

char newUnitsToConvert();
char newUnitsDistanceToConvert();
char newUnitsToConvert()
{
    char x;
    printf("Enter the new unit type (F, C, or K): ");
    scanf(" %c", &x);
    return x;
}

char newUnitsDistanceToConvert()
{
    char yyy;
    printf("Enter the new unit type (I,F,Y,M): ");
    scanf(" %c", &yyy);
    return yyy;
}

int main() {
   printf("Pick the type of conversion that you would like to do.\n");
   printf("T or t for temperature\n");
   printf("D or d for distance\n");
   char choice;
   printf("Enter your choice: ");
   scanf("%c", &choice);
   if (choice == 'T' || choice == 't') 
   {
        // Set up the variables for the initial temperature, initial units, and new temperature
        double temperatureInitial;
        char unitInitiall;
        char unitNew = 'd';
        double temperatureNew;

        // Get input for the initial temeprature and initial unit
        printf("Enter the temperature followed by its suffix (F, C, or K): ");
        scanf("%lf %c", &temperatureInitial, &unitInitiall);
        if (isalpha(unitInitiall) && (unitInitiall != 'F' && unitInitiall != 'f' && unitInitiall != 'C' && unitInitiall != 'c' && unitInitiall != 'K' && unitInitiall != 'k'))
        {
            printf("%c is not a valid temperature type. Ending program.", toupper(unitInitiall));
            return 0;
        }
        if (isdigit(unitInitiall))
        {
            printf("%c is not a valid temperature type. Ending program.", unitInitiall);
            return 0;
        }
        if (!(isalpha(unitInitiall)))
        {
            printf("%c is not a valid temperature type. Ending program.", unitInitiall);
            return 0;
        }

        
        if (unitInitiall == 'K' || unitInitiall == 'k')
        {
            // Set the variable and get the new unit as input with the newUnitsToConvert Function
            unitNew = newUnitsToConvert();

            if (unitNew == 'C' || unitNew == 'c')
            {
                temperatureNew = temperatureInitial - 273.15;
                printf("%0.2lf%c is %0.2lf%c", temperatureInitial, toupper(unitInitiall), temperatureNew, toupper(unitNew));
            }
            else if (unitNew == 'K' || unitNew == 'k')
            {
                printf("%0.2lf%c is %0.2lf%c", temperatureInitial, toupper(unitInitiall), temperatureInitial, toupper(unitInitiall));
            }
            else if (unitNew == 'F' || unitNew == 'f')
            {
                temperatureNew = temperatureInitial - 273.15;
                temperatureNew = temperatureNew * 9 / 5;
                temperatureNew = temperatureNew + 32;
                printf("%0.2lf%c is %0.2lf%c", temperatureInitial, toupper(unitInitiall), temperatureNew, toupper(unitNew));
            }
            else if (isalpha(unitNew))
            {
                printf("%c is not a valid temperature type. Ending program.", toupper(unitNew));
            }
            else
            {
                printf("%c is not a valid temperature type. Ending program.", unitNew);
            }
        }
        else if (unitInitiall == 'C' || unitInitiall == 'c')
        {
            // Set the variable and get the new unit as input with the newUnitsToConvert Function
            unitNew = newUnitsToConvert();
            if (unitNew == 'K' || unitNew == 'k')
            {
                temperatureNew = temperatureInitial + 273.15;
                printf("%0.2lf%c is %0.2lf%c", temperatureInitial, toupper(unitInitiall), temperatureNew, toupper(unitNew));
            }
            else if (unitNew == 'C' || unitNew == 'c')
            {
                printf("%0.2lf%c is %0.2lf%c", temperatureInitial, toupper(unitInitiall), temperatureInitial, toupper(unitInitiall));
            }
            else if (unitNew == 'F' || unitNew == 'f')
            {
                temperatureNew = temperatureInitial * 9 / 5;
                temperatureNew = temperatureNew + 32;
                printf("%0.2lf%c is %0.2lf%c", temperatureInitial, toupper(unitInitiall), temperatureNew, toupper(unitNew));
            }
            else if (isdigit(unitNew))
            {
                printf("%c is not a valid temperature type. Ending program.", unitNew);
            }
            else
            {
                printf("%c is not a valid temperature type. Ending program.", toupper(unitNew));
            }
        }
        else if (unitInitiall == 'F' || unitInitiall == 'f')
        {
            // Set the variable and get the new unit as input with the newUnitsToConvert Function
            unitNew = newUnitsToConvert();

            if (unitNew == 'C' || unitNew == 'c')
            {
                temperatureNew = temperatureInitial - 32;
                temperatureNew = temperatureNew * 5 / 9;
                printf("%0.2lf%c is %0.2lf%c", temperatureInitial, toupper(unitInitiall), temperatureNew, toupper(unitNew));
            }
            else if (unitNew == 'F' || unitNew == 'f')
            {
                printf("%0.2lf%c is %0.2lf%c", temperatureInitial, toupper(unitInitiall), temperatureInitial, toupper(unitInitiall));
            }
            else if (unitNew == 'K' || unitNew == 'k')
            {
                temperatureNew = temperatureInitial - 32;
                temperatureNew = temperatureNew * 5 / 9;
                temperatureNew = temperatureNew + 273.15;
                printf("%0.2lf%c is %0.2lf%c", temperatureInitial, toupper(unitInitiall), temperatureNew, toupper(unitNew));
            }
            else if (isdigit(unitNew))
            {
                printf("%c is not a valid temperature type. Ending program.", unitNew);
            }
            else
            {
                printf("%c is not a valid temperature type. Ending program.", toupper(unitNew));
            }
        }
        else
        {
            printf("H");
        }    
   } 
   else if (choice == 'D' || choice == 'd') 
   {
        double initialDistance;
        char initialDistanceUnit;
        double newDistance;
        char newDistanceUnit = 'd';

        // Get the intial distance and the initial units
        printf("Enter the distance followed by its suffix (I,F,Y,M): ");
        scanf("%lf %c", &initialDistance, &initialDistanceUnit);

        if (isalpha(initialDistanceUnit) && (initialDistanceUnit != 'I' && initialDistanceUnit != 'i' && initialDistanceUnit != 'F' && initialDistanceUnit != 'f' && initialDistanceUnit != 'Y' && initialDistanceUnit != 'y' && initialDistanceUnit != 'M' && initialDistanceUnit != 'm'))
        {
            printf("%c is not a valid distance type. Ending program.", toupper(initialDistanceUnit));
            return 0;
        }
        if (isdigit(initialDistanceUnit))
        {
            printf("%c is not a valid distance type. Ending program.", initialDistanceUnit);
            return 0;
        }
        if (!(isalpha(initialDistanceUnit)))
        {
            printf("%c is not a valid distance type. Ending program.", initialDistanceUnit);
            return 0;
        }

        if (initialDistanceUnit == 'I' || initialDistanceUnit == 'i')
        {
            newDistanceUnit = newUnitsDistanceToConvert();
            
            if (newDistanceUnit == 'F' || newDistanceUnit == 'f')
            {
                newDistance = initialDistance / 12;
                printf("%0.2lf%c is %0.2lf%c", initialDistance, toupper(initialDistanceUnit), newDistance, toupper(newDistanceUnit));
            }
            else if(newDistanceUnit == 'Y' || newDistanceUnit == 'y')
            {
                newDistance = initialDistance / 36;
                printf("%0.2lf%c is %0.2lf%c", initialDistance, toupper(initialDistanceUnit), newDistance, toupper(newDistanceUnit));
            }
            else if(newDistanceUnit == 'M' || newDistanceUnit == 'm')
            {
                newDistance = initialDistance / 63360;
                printf("%0.2lf%c is %0.2lf%c", initialDistance, toupper(initialDistanceUnit), newDistance, toupper(newDistanceUnit));
            }
            else if(newDistanceUnit == 'I' || newDistanceUnit == 'i')
            {
                printf("%0.2lf%c is %0.2lf%c", initialDistance, toupper(initialDistanceUnit), initialDistance, toupper(initialDistanceUnit));
            }
            else if(isalpha(newDistanceUnit))
            {
                printf("%c is not a valid distance type. Ending program.", toupper(newDistanceUnit));
            }
            else
            {
                printf("%c is not a valid distance type. Ending program.", newDistanceUnit);
            }
            
        }
        else if (initialDistanceUnit == 'F' || initialDistanceUnit == 'f')
        {
            newDistanceUnit = newUnitsDistanceToConvert();
            
            if (newDistanceUnit == 'I' || newDistanceUnit == 'i')
            {
                newDistance = initialDistance * 12;
                printf("%0.2lf%c is %0.2lf%c", initialDistance, toupper(initialDistanceUnit), newDistance, toupper(newDistanceUnit));
            }
            else if(newDistanceUnit == 'Y' || newDistanceUnit == 'y')
            {
                newDistance = initialDistance / 3;
                printf("%0.2lf%c is %0.2lf%c", initialDistance, toupper(initialDistanceUnit), newDistance, toupper(newDistanceUnit));
            }
            else if(newDistanceUnit == 'M' || newDistanceUnit == 'm')
            {
                newDistance = initialDistance / 5280;
                printf("%0.2lf%c is %0.2lf%c", initialDistance, toupper(initialDistanceUnit), newDistance, toupper(newDistanceUnit));
            }
            else if(newDistanceUnit == 'F' || newDistanceUnit == 'f')
            {
                printf("%0.2lf%c is %0.2lf%c", initialDistance, toupper(initialDistanceUnit), initialDistance, toupper(initialDistanceUnit));
            }
            else if(isalpha(newDistanceUnit))
            {
                printf("%c is not a valid distance type. Ending program.", toupper(newDistanceUnit));
            }
            else
            {
                printf("%c is not a valid distance type. Ending program.", newDistanceUnit);
            }
            
        }
        else if (initialDistanceUnit == 'Y' || initialDistanceUnit == 'y')
        {
            newDistanceUnit = newUnitsDistanceToConvert();
            
            if (newDistanceUnit == 'I' || newDistanceUnit == 'i')
            {
                newDistance = initialDistance * 36;
                printf("%0.2lf%c is %0.2lf%c", initialDistance, toupper(initialDistanceUnit), newDistance, toupper(newDistanceUnit));
            }
            else if(newDistanceUnit == 'F' || newDistanceUnit == 'f')
            {
                newDistance = initialDistance * 3;
                printf("%0.2lf%c is %0.2lf%c", initialDistance, toupper(initialDistanceUnit), newDistance, toupper(newDistanceUnit));
            }
            else if(newDistanceUnit == 'M' || newDistanceUnit == 'm')
            {
                newDistance = initialDistance / 1760;
                printf("%0.2lf%c is %0.2lf%c", initialDistance, toupper(initialDistanceUnit), newDistance, toupper(newDistanceUnit));
            }
            else if(newDistanceUnit == 'Y' || newDistanceUnit == 'y')
            {
                printf("%0.2lf%c is %0.2lf%c", initialDistance, toupper(initialDistanceUnit), initialDistance, toupper(initialDistanceUnit));
            }
            else if(isalpha(newDistanceUnit))
            {
                printf("%c is not a valid distance type. Ending program.", toupper(newDistanceUnit));
            }
            else
            {
                printf("%c is not a valid distance type. Ending program.", newDistanceUnit);
            }
            
        }
        else if (initialDistanceUnit == 'M' || initialDistanceUnit == 'm')
        {
            newDistanceUnit = newUnitsDistanceToConvert();
            
            if (newDistanceUnit == 'I' || newDistanceUnit == 'i')
            {
                newDistance = initialDistance * 63360;
                printf("%0.2lf%c is %0.2lf%c", initialDistance, toupper(initialDistanceUnit), newDistance, toupper(newDistanceUnit));
            }
            else if(newDistanceUnit == 'F' || newDistanceUnit == 'f')
            {
                newDistance = initialDistance * 5280;
                printf("%0.2lf%c is %0.2lf%c", initialDistance, toupper(initialDistanceUnit), newDistance, toupper(newDistanceUnit));
            }
            else if(newDistanceUnit == 'Y' || newDistanceUnit == 'y')
            {
                newDistance = initialDistance * 1760;
                printf("%0.2lf%c is %0.2lf%c", initialDistance, toupper(initialDistanceUnit), newDistance, toupper(newDistanceUnit));
            }
            else if(newDistanceUnit == 'M' || newDistanceUnit == 'm')
            {
                printf("%0.2lf%c is %0.2lf%c", initialDistance, toupper(initialDistanceUnit), initialDistance, toupper(initialDistanceUnit));
            }
            else if (isalpha(newDistanceUnit))
            {
                printf("%c is not a valid distance type. Ending program.", toupper(newDistanceUnit));
            }
            else
            {
                printf("%c is not a valid distance type. Ending program.", newDistanceUnit);
            }
            
        }
   } 
   else if (isalpha(choice))
   {
        printf("Unknown conversion type %c chosen. Ending program.\n", toupper(choice));
   }
   else if (isdigit(choice))
   {
        printf("Unknown conversion type %c chosen. Ending program.\n", choice);
   }
   else 
   {
       printf("Unknown conversion type %c chosen. Ending program.\n", choice);
   }
   return 0;
}
