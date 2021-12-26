#include <stdio.h>
#include <string.h>

void read_file();
//==== Main Start====//
int main()
{
    read_file();
    return 0;
}
//==== Main End====//

void read_file()
{
    FILE *todo_data;
    todo_data = fopen("./Data/todo_data.txt", "a");
    char full_name[30];

    if (todo_data)
    {
        printf("Enter your full name : ");
        gets(full_name);
        fputs(strcat(full_name,"\n"), todo_data);
    }
}