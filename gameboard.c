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
void display(int positions[MAX_PLAYERS], int squares[MAX_SQUARES]) {
    printf("\nCurrent State of the Game:\n");
    for (int i = 10; i >= 1; i--) {
        for (int j = 1; j <= 10; j++) {
            int position = (i % 2 != 0) ? (i - 1) * 10 + j : (i - 1) * 10 + (10 - j + 1);

            if (position == positions[0]) {
                printf("[P1]\t");
            } else if (position == positions[1]) {
                printf("[P2]\t");
            } else {
                if (position == 77) {
                    printf("[ S]\t");  // Snake position
                } else if (position == 28) {
                    printf("[ L]\t");  // Ladder position
                } else {
                    printf("[%02d]\t", position);
                }
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    srand(time(NULL));
    char choice;
    int current;
    int players[MAX_PLAYERS] = {1,1};
    int squares[MAX_SQUARES] = {-1};
    printf("WELCOME TO SANKE AND LADDER GAME\nTHE INSTRUCTIONS FOR THE GAME ARE:\n1.)THERE WILL BE 2 PLAYERS PLAYING THE GAME\n2.)EACH PLAYER WILL PRESS ENTER TO ROLL THE DICE\n3.)THE [S] REPRESENTS SNAKE IN THE BARD AND IT WILL TAKE YOU BACK 27 POINTS\n4.) THE [L] REPRESENTS LADDER IN THE BOARD WHICH WILL TAKE YOU 60 POINTS FURTHER\n\nSTART\n");
    while (players[0] != 100 || players[1] != 100)
    {
        display(players, squares);
        for(int i = 0; i<MAX_PLAYERS;i++)
        {
            printf("PLAYER %d Press Enter to roll the dice:",i+1);
            choice = getchar();
            clearbuffer();
            if (choice == '\n')
            {
                current = rolldice();
                printf("Player %d got %d\n",i+1,current);
                players[i] += current;
                if (squares[players[i] - 1] != 0) {
                    int destination = squares[players[i] - 1];
                    printf("YOU GOT ");
                    if (destination > players[i]) {
                        printf("LADDER\n");
                    } else {
                        printf("BITTEN BY SNAKE\n");
                    }
                    players[i] = destination;
                }
                display(players,squares);
            }
        }
    }
    if(players[0] == 100 )
    {
        printf("Congratulations PLAYER 1 YOU WON\n");
    }
    else 
    {
        printf("Congratulations PLAYER 2 YOU WON\n");
    }
    return 0;
}