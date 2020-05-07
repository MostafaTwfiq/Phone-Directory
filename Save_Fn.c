#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Ansi_Colors.h"
#include "Structs.h"
#include "Save_Fn.h"

void Save_Fn(Data *TheData, Birth *TheBirth, int NOL)
{
    FILE *dir = fopen("PhoneDirectory.txt", "w");
    if(!dir)
    {
        printf(ANSI_COLOR_RED  "There is something wrong!!" ANSI_COLOR_RESET);
        exit(-1);
    }
    for(int i = 0; i < NOL; i++)
    {
        fprintf(dir, "%s,%s,%s-%s-%s,%s,%s,%s\n", (TheData + i)->lname, (TheData + i)->fname, (TheBirth + i)->day, (TheBirth + i)->month, (TheBirth + i)->year, (TheData + i)->adress, (TheData + i)->email, (TheData + i)->number);
    }
    fclose(dir);
    printf(ANSI_COLOR_BOLD_GREEN "Done Saving!\n\n" ANSI_COLOR_RESET);
}
