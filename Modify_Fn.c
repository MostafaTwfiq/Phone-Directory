#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Ansi_Colors.h"
#include "Structs.h"
#include "Input_Fn.h"
#include "Validations.h"
#include "Remove_New_Line.h"
#include "Modify_Fn.h"

void Modify_Fn(Data *TheData, Birth *TheBirth, int NOL)
{
    int ToF = 0;
    int counter = 0;
    char lname[100];
    char number[100];
    int index[NOL];
    printf("Enter the last name that you want to search for it: ");
    fgets(lname, 100, stdin);
    fseek(stdin, 0, SEEK_END);
    Remove_New_Line(lname);
    for(int i = 0; i < NOL; i++)
    {
        if(!stricmp((TheData + i)->lname, lname))
        {
            ToF = 1;
            *(index + counter) = i;
            counter++;
            printf("%d:-\n", counter);
            printf("First name: %s\n",(TheData + i)->fname);
            printf("Last name: %s\n",(TheData + i)->lname);
            printf("Address: %s\n",(TheData + i)->adress);
            printf("Number: %s\n",(TheData + i)->number);
            printf("Email: %s\n",(TheData + i)->email);
            printf("The birth: %s-%s-%s\n",(TheBirth + i)->day, (TheBirth + i)->month, (TheBirth + i)->year);
            printf(ANSI_COLOR_BLUE "------------------\n" ANSI_COLOR_RESET);
        }
    }
    if(ToF)
    {
        printf("Choose one of the results numbers to be modified:- ");
        fgets(number, 100, stdin);
        fseek(stdin, 0, SEEK_END);
        Remove_New_Line(number);
        if(atoi(number) && 0 < atoi(number) && atoi(number) <= counter)
        {
            Input_Fn(TheData, TheBirth, (*(index + atoi(number) - 1)));
            printf(ANSI_COLOR_BOLD_GREEN "Done the contact has been modified!\n\n" ANSI_COLOR_RESET);
        }
        else
        {
            printf(ANSI_COLOR_RED  "You selected a wrong number please try again.\n\n" ANSI_COLOR_RESET);
        }
    }
    else
    {
        printf(ANSI_COLOR_RED  "There is no matches.\n\n" ANSI_COLOR_RESET);
    }
}
