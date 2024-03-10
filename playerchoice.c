#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void clearbuffer()
{
    int c;
    while((c = getchar) != '\n' && c != EOF);
}
int rolldice()
{
    srand(time(NULL));
    int random = (rand() % 6) + 1;
    return random;
}
int main()
{
    int player1 = 1,player2 = 1;
    char choice;
    while(player1 != 100 || player2 != 100)
    {
        printf("PLAYER 1 Chance Please Press Enter:");
        choice = getchar();
        clearbuffer();
        player1 = player1 + generate();
        printf("PLAYER 2 Chance Plaese Press Enter:");
        choice = getchar();
        clearbuffer();
    }
}