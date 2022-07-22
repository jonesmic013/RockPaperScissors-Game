#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void welcome(); // Function Declaration
int getNumRounds(); // Function Declaration
int playRound(); // Function Declaration
void printMove(int move); // Function Declaration
int compareMoves(int playerInput, int comInput); // Function Declaration
void printResults(int round, int playerWins, int comWins, int ties); // Function Declaraton
void goodbye(); // Function Declaration

int main (void)
{
    // Local Declarations
    int numRounds; // max rounds to play (aka best of ODD_NUMBER)
    int playerWins; // round wins by user
    int comWins; // round wins by computer
    int ties; // number of ties
    int roundWinner; // round winner, 1/2 for player/computer, 0 for tie
    int round; // current round number

    // Statements
    welcome(); // function call
    numRounds = getNumRounds(); // function call
    round = 1;
    do
    {
        printf("\n--- Round #%d ---\n", round);
        roundWinner = playRound(); // function call
        if (roundWinner == 1) // player won round
        {
            printf("\nRound %d winner: PLAYER\nPress ENTER to continue.", round);
            playerWins++;
            round++;
        }
        else if (roundWinner == 2) // computer won round
        {
            printf("\nRound %d winner: COMPUTER\nPress ENTER to continue.", round);
            comWins++;
            round++;
        }
        else
        {
            printf("\nRound %d winner: TIE\nReplaying round...\nPress ENTER to continue.", round);
            ties++;
        }
        getchar();
        getchar();
    } while ((playerWins <= ceil((double) numRounds / 2.0) && playerWins <= ceil((double) comWins / 2.0)) && round <= numRounds);

    printResults(round, playerWins, comWins, ties); // function call
    goodbye(); // function call

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
    int roundWinner; // round winner, 1/2 for player/computer, 0 for tie
    int playerInput; // move chosen by player
    int comInput; // move randomly chosen by computer

    // Statements
    do
    {
        playerInput = 0;
        printf("What would you like to do?\n");
        printf("[1] Rock\n[2] Paper\n[3] Scissors\n-> ");
        scanf("%d", &playerInput);

        if (playerInput < 1 || playerInput > 3)
        {
            printf("Invalid option!\n\n");
        }
    } while (playerInput < 1 || playerInput > 3); // must choose 1-3

    // get random move for computer
    comInput = rand() % 3 + 1;

    // print what both people chose
    printf("You chose: ");
    printMove(playerInput); // function call
    printf("COMPUTER chose: ");
    printMove(comInput); // function call

    // now get the round winner
    roundWinner = compareMoves(playerInput, comInput); // function call

    return roundWinner; // return winner of round
}

void printMove(int move)
{
    // Statements
    switch (move)
    {
        case 1: printf("ROCK\n");
                break;
        case 2: printf("PAPER\n");
                break;
        case 3: printf("SCISSORS\n");
                break;
    }
}

int compareMoves(int playerInput, int comInput)
{
    // Local Declarations
    int roundWinner; // round winner, 1/2 for player/computer, 0 for tie

    // Statements
    roundWinner = 2; // default to computer winning

    // check for tie
    if (playerInput == comInput)
    {
        roundWinner = 0;
    }
    else if ((playerInput == 1 && comInput == 3) || (playerInput == 2 && comInput == 1) || (playerInput == 3 && comInput == 2))
    {
        roundWinner = 1;
    } // check all 3 conditions where the player beats the computer

    return roundWinner;
}

void printResults(int round, int playerWins, int comWins, int ties)
{
    // Statements
    printf("\n--------------------");
    printf("\nRounds played: %d", round);
    printf("\nPlayer wins: %d\nComputer wins: %d\nTies: %d", playerWins, comWins, ties);
    printf("\n--------------------");
}

void goodbye()
{
    // Statements
    printf("\n\nThanks for playing!\n");
    printf("Press ENTER to exit.");
    getchar();
}