#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_PLAYERS 2
#define MAX_SQUARES 100
void clearbuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
int rolldice()
{
    int random = (rand() % 6) + 1;
    return random;
}
// Function to display the current state of the game
void display_game(int positions[MAX_PLAYERS], int squares[MAX_SQUARES]) {
    int i;
    printf("\nCurrent State of the Game:\n");
    for(i = 0; i < MAX_SQUARES; i++) {
        if(i == 0) {
            printf("    ");
        }
        if(i < 10) {
            printf(" ");
        }
        printf("%2d ", i+1);
        if((i % 10) == 0) {
            printf("\n");
        }
    }
    for(i = 0; i < MAX_PLAYERS; i++) {
        if(positions[i] != -1) {
            printf("\nPlayer %d: ", i+1);
            if(positions[i] < 10) {
                printf(" ");
            }
            printf("%2d ", positions[i]);
            if(squares[positions[i]-1] != -1) {
                printf("(Ladder to %d, Snake to %d)", squares[positions[i]-1], -squares[positions[i]-1]);
            }
        }
    }
    printf("\n");
}
int main()
{
    srand(time(NULL));
    char choice;
    int player1 = 1, player2 = 1;
    printf("WELCOME TO SANKE AND LADDER GAME\nTHE INSTRUCTIONS FOR THE GAME ARE:\n1.)THERE WILL BE 2 PLAYERS PLAYING THE GAME\n2.)EACH PLAYER WILL PRESS ENTER TO ROLL THE DICE\n3.)THE [S] REPRESENTS SNAKE IN THE BARD AND IT WILL TAKE YOU BACK 27 POINTS\n4.) THE [L] REPRESENTS LADDER IN THE BOARD WHICH WILL TAKE YOU 60 POINTS FURTHER\n\nSTART\n");
    while (player1 != 100 || player2 != 100)
    {
        display(player1, player2);
        printf("PLAYER 1 Press Enter to roll the dice:");
        choice = getchar();
        clearbuffer();
        if (choice == '\n')
        {
            player1 = player1 + rolldice();
            if (player1 == 22) // checking for ladder
            {
                player1 = player1 + 60;
                printf("YES YOU GOT LADDER\n");
            }
            if (player1 == 76) // checking for snake
            {
                player1 = player1 - 27;
                printf("YOU GOT BITTEN BY SNAKE\n");
            }
            display(player1, player2);
        }
        printf("PLAYER 2 Press Enter to roll the dice:");
        choice = getchar();
        clearbuffer();
        if (choice == '\n')
        {
            player2 = player2 + rolldice();
            if (player2 == 22)
            {
                player2 = player2 + 60;
                printf("YES YOU GOT LADDER\n");
            }
            if (player2 == 76)
            {
                player2 = player2 - 27;
                printf("YOU GOT BITTEN BY SNAKE\n");
            }
            display(player1, player2);
        }
    }
    return 0;
}