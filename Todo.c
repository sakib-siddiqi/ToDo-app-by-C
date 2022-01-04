#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void style_bar(int count);
void display_option(char text[]);
void display_menu(int *option);
void display_one();
void add_one(FILE *all_task);
void file_error();
void display_all(FILE *read_all, char task[50]);
// void write_one(char user_name);
void write_all(FILE *all_task);
//==== Main Start====//
int main()
{
    int option;
    char task[50];
    FILE *all_taks;
    all_taks = fopen("./Data/all_task.txt", "r");
    display_menu(&option);
    switch (option)
    {
    case 1:
        if (all_taks != NULL)
            display_all(all_taks, task);
        break;
    case 2:
        if (all_taks != NULL)
            display_one();
        break;
    case 3:

        if (all_taks != NULL)
        {
            all_taks = fopen("./Data/all_task.txt", "a");
            add_one(all_taks);
        }
        break;
    case 4:
        break;
    default:
        system("cls");
        main();
    }
    return 0;
}
//==== Main End====//

//==== Style Bar Start ====//
void style_bar(int count)
{
    while (count-- > 0)
        printf("\n\t--|---------------------|--\n");
}
//==== Style Bar End ====//

//==== option's display start=====//
void display_option(char text[])
{
    printf("\t%s\n", text);
}
//==== option's display end=====//

//==== choice option Start =====//
void display_menu(int *option)
{
    printf("\n\n");
    style_bar(3);
    display_option("1. Display All tasks");
    display_option("2. Display One user's Tasks");
    display_option("3. Add One user's Tasks");
    display_option("4. Exit");
    style_bar(1);
    printf("Enter Your Choice : ");
    scanf("%d", option);
}
//==== choice option End =====//

//==== Read All start =====//
void display_all(FILE *all_task, char task[50])
{
    int i = 1;
    system("cls");
    while (!feof(all_task))
    {
        fgets(task, 50, all_task);
        if (feof(all_task))
            break;
        printf("[%d]. %s", i, task);
        i++;
    }
    fclose(all_task);
    main();
}
//==== Read All End =====//

//==== FILE error start =====//
void file_error()
{
    system("cls");
    system("Color 4");
    printf("\n\n\n");
    printf("\t!! ERROR !!\n");
    printf("\tFile not found.\n");
    main();
}
//==== FILE error End =====//

//==== Display One user's task Start =====//
void display_one()
{
    char user_name[30], this_user_task[50], file_path[50] = "./Data/users/";
    FILE *user_file;
    printf("Enter user's Name : ");
    scanf("%s", &user_name);
    strcat(file_path, user_name);
    strcat(file_path, ".txt");
    user_file = fopen(file_path, "r");
    if (user_file == NULL)
        file_error();
    else
    {
        int i = 1;
        system("cls");
        while (!feof(user_file))
        {
            fgets(this_user_task, 50, user_file);
            printf("[%d]. %s", i, this_user_task);
            i++;
            if (feof)
                break;
        }
    }
    main();
}
//==== Display One user's task End =====//

//==== Add One user's task Start =====//
void add_one(FILE *all_task)
{
    char user_name[30], file_path[50] = "./Data/users/";
    FILE *user_file;
    printf("Enter user's Name : ");
    scanf("%s", &user_name);
    strcat(file_path, user_name);
    strcat(file_path, ".txt");
    user_file = fopen(file_path, "a");
    if (user_file == NULL)
        file_error();
    char new_task[50];
    printf("Assign a new task : ");
    getchar();
    gets(new_task);
    fputs(strcat(new_task, "\n"), user_file);
    fputs(new_task, all_task);
    system("cls");
    main();
}
//==== Add One user's task End =====//