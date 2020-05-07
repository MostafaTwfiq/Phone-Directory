#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ansi_Colors.h"
#include "Structs.h"
#include "Remove_New_Line.h"
#include "Save_Fn.h"
#include "Quit_Fn.h"

void Quit_Fn(Data *TheData, Birth *TheBirth, int NOL, int check1)
{
    char ch1[4];
    while(1)
    {
        if(!check1)
        {
            printf(ANSI_COLOR_RED  "You didn't save the changes are you sure you want to close the program ?\n" ANSI_COLOR_RESET);
            while(1)
            {
                printf("1- Yes close without saving. --->   ( Yes )\n2- No save first then close the program. --->   ( No )\n:- ");
                fgets(ch1, 4, stdin);
                fseek(stdin, 0, SEEK_END);
                Remove_New_Line(ch1);
                if(!stricmp(ch1, "Yes") || !strcmp(ch1, "1"))
                {
                    exit(0);
                }
                else if(!stricmp(ch1, "No") || !strcmp(ch1, "2"))
                {
                    Save_Fn(TheData, TheBirth, NOL);
                    exit(0);
                }
                else
                {
                    printf(ANSI_COLOR_RED "You entered a wrong number please try again.\n" ANSI_COLOR_RESET);
                }
            }
        }
        else
        {
            exit(0);
        }
    }
}
