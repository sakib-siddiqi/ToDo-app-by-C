#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void style_bar(int count);
void read_file();
//==== Main Start====//
int main()
{
    int choice;
    style_bar(2);
    printf("\t[1]\tShow All Task.\n");
    printf("\t[2]\tRead One member's Tasks.\n");
    printf("\t[3]\tAdd New Member\n");
    printf("\t[4]\tClose Application\n");
    style_bar(1);
    printf("\n\tEnter Your choice : ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("1");
        break;
    case 2:
        printf("2");
        break;
    case 3:
        printf("3");
        break;
    case 4:
        printf("4");
        break;
    default:
        system("cls");
        main();
    }

    // read_file();
    return 0;
}
//==== Main End====//

void style_bar(int count)
{
    while (count-- > 0)
        printf("\n\t--|---------------------|--\n");
}

void read_file()
{
    FILE *todo_data;
    todo_data = fopen("./Data/todo_data.txt", "a");
    char full_name[30];

    if (todo_data)
    {
        printf("Enter your full name : ");
        gets(full_name);
        fputs(strcat(full_name, "\n"), todo_data);
    }
}