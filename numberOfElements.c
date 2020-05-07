#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ansi_Colors.h"
#include "NumberOfElements.h"

int numberOfElements()
{
    FILE *dir;
    dir = fopen("PhoneDirectory.txt", "r"); //the pointer of the file
    if(!dir)
    {
        printf(ANSI_COLOR_RED  "There is something wrong!!" ANSI_COLOR_RESET);
        exit(-1);
    }
    char c;
    int counter = 0;
    for (c = getc(dir); c != EOF; c = getc(dir))
    {
        if (c == '\n')  // Increment count if this character is newline
        {
            counter = counter + 1;
        }
    }
    fclose(dir);
    return counter;
}
