#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Structs.h"
#include "Ansi_Colors.h"
#include "Add_Fn.h"
#include "Input_Fn.h"

void Add_Fn(Data *TheData, Birth *TheBirth, int *NOL)
{
    *NOL += 1;
    Input_Fn(TheData, TheBirth, (*NOL - 1));
    printf(ANSI_COLOR_BOLD_GREEN "Done the contact has been added!\n\n" ANSI_COLOR_RESET);
}
