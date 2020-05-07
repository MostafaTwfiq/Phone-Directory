#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Ansi_Colors.h"
#include "Structs.h"
#include "Multi_Search_Fn.h"

int Multi_Search_Fn(char *TheData1, char *TheData)
{
    if(*TheData1 == '\0')
    {
        return 1;
    }
    else if(!stricmp(TheData, TheData1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
