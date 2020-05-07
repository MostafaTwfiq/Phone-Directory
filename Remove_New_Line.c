#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Remove_New_Line.h"

void Remove_New_Line(char *Input)
{
    int i = 0;
    int x = strlen(Input);
    while(x)
    {
        if(*(Input + i) == '\n')
        {
            *(Input + i) = '\0';
            break;
        }
        i++;
        x--;
    }
}
