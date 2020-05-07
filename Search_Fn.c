#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Ansi_Colors.h"
#include "Structs.h"
#include "Multi_Search_Fn.h"
#include "Search_Fn.h"
#include "Input_Fn_For_Search.h"
#include "Remove_New_Line.h"

void Search_Fn(Data *TheData, Birth *TheBirth, int NOL)
{
    int ToF = 0;
    int counter = 1;
    Data TheData1;
    Birth TheBirth1;
    Input_Fn_For_Search(&TheData1, &TheBirth1, 0);
    for(int i = 0; i < NOL; i++)
    {
        if(Multi_Search_Fn(TheData1.lname, (TheData + i)->lname) &&
                Multi_Search_Fn(TheData1.fname, (TheData + i)->fname) &&
                Multi_Search_Fn(TheData1.adress, (TheData + i)->adress) &&
                Multi_Search_Fn(TheData1.number, (TheData + i)->number) &&
                Multi_Search_Fn(TheData1.email, (TheData + i)->email) &&
                Multi_Search_Fn(TheBirth1.day, (TheBirth + i)->day) &&
                Multi_Search_Fn(TheBirth1.month, (TheBirth + i)->month) &&
                Multi_Search_Fn(TheBirth1.year, (TheBirth + i)->year))
        {
            ToF = 1;
            printf("%d:-\n", counter);
            counter++;
            printf("First name: %s\n",(TheData + i)->fname);
            printf("Last name: %s\n",(TheData + i)->lname);
            printf("Address: %s\n",(TheData + i)->adress);
            printf("Number: %s\n",(TheData + i)->number);
            printf("Email: %s\n",(TheData + i)->email);
            printf("The birth: %s-%s-%s\n",(TheBirth + i)->day, (TheBirth + i)->month, (TheBirth + i)->year);
            printf(ANSI_COLOR_BLUE "------------------\n\n" ANSI_COLOR_RESET);
        }
    }
    if(!ToF)
    {
        printf(ANSI_COLOR_RED  "There is no one with this information.\n\n" ANSI_COLOR_RESET);
    }
}
