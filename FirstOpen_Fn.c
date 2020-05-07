#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Ansi_Colors.h"
#include "Structs.h"
#include "FirstOpen_Fn.h"
#include "Input_Fn.h"

void FirstOpen_Fn()
{
    FILE *dir;
    printf(ANSI_COLOR_RED  "this is the first time you open the program so please enter your first contacts:- \n" ANSI_COLOR_RESET);
    Data TheData;
    Birth TheBirth;
    Input_Fn(&TheData, &TheBirth, 0);
    printf("\n\n");
    dir = fopen("PhoneDirectory.txt", "w");
    if(!dir)
    {
        printf(ANSI_COLOR_RED  "There is something wrong!!" ANSI_COLOR_RESET);
        exit(-1);
    }
    fprintf(dir, "%s,%s,%s-%s-%s,%s,%s,%s\n", TheData.lname, TheData.fname, TheBirth.day, TheBirth.month, TheBirth.year, TheData.adress, TheData.email, TheData.number);
    fclose(dir);
}
