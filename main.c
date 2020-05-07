#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Load_Fn.h"
#include "Ansi_Colors.h"
#include "Structs.h"
#include "FirstOpen_Fn.h"
#include "NumberOfElements.h"

#include "separate.h"
#include "Multi_Search_Fn.h"
#include "Search_Fn.h"
#include "Add_Fn.h"
#include "Input_Fn.h"
#include "Validations.h"
#include "Input_Fn_For_Search.h"
#include "Remove_New_Line.h"
#include "Delete_Fn.h"
#include "Modify_Fn.h"
#include "Save_Fn.h"
#include "Print_Fn.h"
#include "Quit_Fn.h"

//****This project done by Mostafa Twfiq****

int main()
{
    system("COLOR");
    printf(ANSI_COLOR_BOLD_RED "                                     *****WELCOME TO THE PHONE DIRECTORY*****\n\n\n\n\n" ANSI_COLOR_RESET);
    int NOL = 0; //a variable that knows the number of lines
    char choose[20];
    int check = 0;
    int check1 = 1;
    char **elements2;
    elements2 = Load_Fn(&NOL);
    Data *TheData;
    TheData = malloc(sizeof(Data) * NOL);
    Birth *TheBirth;
    TheBirth = malloc(sizeof(Birth) * NOL);
    separate(elements2, TheData, TheBirth, NOL);
    Load_Valid_Fn(TheData, TheBirth, &NOL, &check);
    for(int i = 0; i < NOL; i++){
        free(elements2[i]);
    }
    free(elements2);
    while(1)
    {
        printf(ANSI_COLOR_WHITE "Please choose a number from the following:- \n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_BOLD_BLUE "   1- Search for a contact. --->   ( Search )\n   2- Add a contact. --->   ( Add )\n   3- Delete a contact. --->   ( Delete )\n   4- Modify a contact. --->   ( Modify )\n   5- Print the contacts. --->   ( Print )\n   6- Save changes. --->   ( Save )\n   7- Quit the program. --->   ( Quit )\n\n  :- " ANSI_COLOR_RESET);
        fgets(choose, 9, stdin);
        fseek(stdin, 0, SEEK_END);
        Remove_New_Line(choose);
        if(!stricmp(choose, "Search") || !strcmp(choose, "1"))
        {
            Search_Fn(TheData, TheBirth, NOL);
        }
        else if(!stricmp(choose, "Add") || !strcmp(choose, "2"))
        {
            check1 = 0;
            if(check == 0)
            {
                TheData = realloc(TheData, sizeof(Data) * (NOL + 1));
                TheBirth = realloc(TheBirth, sizeof(Birth) * (NOL + 1));
            }
            else
            {
                check--;
            }
            Add_Fn(TheData, TheBirth, &NOL);
        }
        else if(!stricmp(choose, "Delete") || !strcmp(choose, "3"))
        {
            check1 = 0;
            Delete_Fn(TheData, TheBirth, &NOL, &check);
        }
        else if(!stricmp(choose, "Modify") || !strcmp(choose, "4"))
        {
            check1 = 0;
            Modify_Fn(TheData, TheBirth, NOL);
        }
        else if(!stricmp(choose, "Print") || !strcmp(choose, "5"))
        {
            check1 = 0;
            char ch[10];
            printf("Please choose the way that you want to sort the data by to print it:- \n");
            printf("1- Sort by last name.\n2- Sort by the data of birth.\n:- ");
            fgets(ch, 10, stdin);
            fseek(stdin, 0, SEEK_END);
            Remove_New_Line(ch);
            if(!stricmp(ch, "last name") || !stricmp(ch, "name") || !strcmp(ch, "1"))
            {
                sortByLname(TheData, TheBirth, NOL);
                Print_Fn(TheData, TheBirth, NOL);
            }
            else if(!stricmp(ch, "birth") || !strcmp(ch, "2"))
            {
                SortByDOB(TheData, TheBirth, NOL);
                Print_Fn(TheData, TheBirth, NOL);
            }
            else
            {
                printf(ANSI_COLOR_RED  "You entered a wrong choice please try again.\n\n" ANSI_COLOR_RESET);
            }
        }
        else if(!stricmp(choose, "Save") || !strcmp(choose, "6"))
        {
            Save_Fn(TheData, TheBirth, NOL);
            check1 = 1;
        }
        else if(!stricmp(choose, "Quit") || !strcmp(choose, "7"))
        {
            Quit_Fn(TheData, TheBirth, NOL, check1);
        }
        else
        {
            printf(ANSI_COLOR_RED  "You entered a non valid choice please try again.\n\n" ANSI_COLOR_RESET);
        }
    }
    return 0;
}
