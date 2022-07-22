#include <stdio.h>
#include <stdlib.h>

void welcome(); // Function Declaration
int getNumRounds(); // Function Declaration
int playRound(); // Function Declaration

int main (void)
{
    // Local Declarations
    int numRounds; // max rounds to play (aka best of ODD_NUMBER)
    int playerWins; // round wins by user
    int comWins; // round wins by computer
    int roundWinner; // round winner, 0/1 for computer/player
    int round; // current round number

    // Statements
    welcome(); // function call
    numRounds = getNumRounds(); // function call
    round = 1;
    do
    {
        printf("\n--- Round #%d ---\n", round);
        roundWinner = playRound(); // function call
        if (roundWinner) // player won round
        {
            printf("\nRound %d winner: YOU\nPress ENTER to continue.", round);
            playerWins++;
        }
        else // computer won round
        {
            printf("\nRound %d winner: COMPUTER\nPress ENTER to continue.", round);
            comWins++;
        }
        getchar();
        round++;
    } while (playerWins <= (numRounds / 2) || playerWins <= (comWins / 2));

    return 0;
    // main
}

void welcome()
{
    // Statements
    printf("Welcome to the Rock/Paper/Scissors Game!\n");
    printf("You will be playing against the Computer.\n\n");
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

        if (numRounds < 1)
        {
            printf("Invalid option! Please enter a number greater than 0.\n\n");
        }
        if (numRounds % 2 == 0)
        {
            printf("Invalid option! Please enter an odd number.\n\n");
        }
    } while (numRounds % 2 == 0 || numRounds < 1);

    return numRounds; // return input value
}

int playRound()
{
    // Local Declarations
    int roundWinner; // round winner, 0/1 for computer/player
    int playerInput; // move chosen by player
    int comInput; // move randomly chosen by computer

    // Statements
    do
    {
        playerInput = 0;
        printf("What would you like to do?\n");
        printf("[1] Rock\n[2] Paper\n[3] Scissors\n-> ");
        scanf("%d", &playerInput);

        if (playerInput < 0 || playerInput > 4)
        {
            printf("Invalid option!\n\n");
        }
    } while (playerInput < 0 || playerInput > 4); // must choose 1-3
    
    // get random move for computer
    comInput = rand() % 4 + 1;
    printf("\nCOM CHOSE: %d\n", comInput);

    // print what both people chose
    printf("YOU chose: ROCK\n");
    printf("COMPUTER chose: ROCK");

    roundWinner = 0;
    return roundWinner; // return winner of round
}