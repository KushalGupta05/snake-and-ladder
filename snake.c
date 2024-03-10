#include<stdio.h>
#include<stdlib.h>
int main()
{
    int arr[100];
    char snake = 'S';
    char ladder = 'L';
    int cd = 100;
    for (int i = 1; i <= 10; i++)
    {
        if (i % 2 != 0)
        {
            for (int j = 0; j < 10; j++)
            {
                if (i == 3 && j == 4)
                {
                    printf("[ %c]\t", snake);
                }
                else
                {
                    printf("[%d]\t", cd);
                }
                cd--;
            }
        }
        else
        {
            for (int k = cd - 9; k <= cd; k++)
            {

                if (k < 10)
                {
                    printf("[0%d]\t", k);
                }
                else if (i == 8 && k % 10 == 2)
                {
                    printf("[ %c]\t", ladder);
                }
                else
                {
                    printf("[%d]\t", k);
                }
            }
            cd = cd - 10;
        }
        printf("\n");
    }
    return 0;
}