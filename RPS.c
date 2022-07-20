#include <stdio.h>

void welcome(); // Function Declaration
int getNumRounds(); // Function Declaration

int main (void)
{
    // Local Declarations
    int numRounds; // max rounds to play (aka best of ODD_NUMBER)

    // Statements
    welcome(); // function call
    numRounds = getNumRounds();

    return 0;
    // main
}

void welcome()
{
    // Statements
    printf("Welcome to the Rock/Paper/Scissors Game!\n\n");
}

int getNumRounds()
{
    // Local Declarations
    int numRounds; // input value to return

    // Statements
    do
    {
        numRounds = 0;
        printf("Please enter the max number of rounds -> ");
        scanf("%d", &numRounds);

        if (numRounds % 2 == 0)
        {
            printf("Invalid option! Please enter an odd number.\n\n");
        }
    } while (numRounds % 2 == 0);

    return numRounds; // return input value
}