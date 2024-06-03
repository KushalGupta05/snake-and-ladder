#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char username[20],password[20];
    char ch = 0;
    int i=0;
    printf("Enter the username:");
    scanf("%s",username);
    printf("Enter the password:");
    while((ch = getch()) != 13)
    {
        printf("*");
        password[i] = ch;
        i++;
    }
    password[i] = '\0';
    printf("\nThe Entered password is %s",password);
    getch();
}