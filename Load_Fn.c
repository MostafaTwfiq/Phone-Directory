#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ansi_Colors.h"
#include "Structs.h"
#include "Load_Fn.h"
#include "NumberOfElements.h"
#include "FirstOpen_Fn.h"
#include "Validations.h"
#include "Remove_New_Line.h"

char **Load_Fn(int *NOL)
{
    int counter = 0;
    int counter2 = 0;
    FILE *dir;
    char **elements;
    dir = fopen("PhoneDirectory.txt", "a");
    if(!dir)
    {
        printf(ANSI_COLOR_RED "There is something wrong!!" ANSI_COLOR_RESET);
        exit(-1);
    }
    fclose(dir);
    *NOL = numberOfElements();
    if(!(*NOL))
    {
        FirstOpen_Fn();
        *NOL += 1;
    }
    dir = fopen("PhoneDirectory.txt", "r");
    if(!dir)
    {
        printf(ANSI_COLOR_RED "There is something wrong!!" ANSI_COLOR_RESET);
        exit(-1);
    }
    elements = malloc(4 * (*NOL));
    for(int i = 0; i < *NOL; i++)
    {
        *(elements + i) = malloc(sizeof(Data) + sizeof(Birth) + 1);
        fgets(*(elements + i), (sizeof(Data) + sizeof(Birth) + 1), dir);
        if(*(*(elements + i) + strlen(*(elements + i)) - 1) != '\n'){
            char c = '\0';
            c = fgetc(dir);
            while(c != '\n' && c != EOF){
                c = fgetc(dir);
            }
        }
        Remove_New_Line(*(elements + i));
    }
    for(int i = 0; i < *NOL; i++)
    {
        for(int j = 0; j + 1; j++)
        {
            if(*(*(elements + i) + j) == ',')
            {
                counter++;
            }
            else if(*(*(elements + i) + j) == '\0')
            {
                break;
            }
        }
        int m = 0;
        while(*(*(elements + i) + m) != '\0')
        {
            while(*(*(elements + i) + m) != ',' && *(*(elements + i) + m) != '\0')
            {
                m++;
            }
            m++;
            counter2++;
            if(counter2 == 2)
            {
                counter2 = 0;
                while(*(*(elements + i) + m) != ',' && *(*(elements + i) + m) != '\0')
                {
                    if(*(*(elements + i) + m) == '-')
                    {
                        counter2++;
                    }
                    m++;
                }
                break;
            }
        }
        if(counter != 5 || counter2 != 2)
        {
            *NOL -= 1;
            if(i != *NOL)
            {
                for(int k = i; k < *NOL; k++)
                {
                    strcpy(*(elements + k), *(elements + k + 1));
                }
                i = -1;
            }
        }
        counter = 0;
        counter2 = 0;
    }

    fclose(dir);
    printf(ANSI_COLOR_BOLD_GREEN "*****Done loading!*****\n"ANSI_COLOR_RESET);
    return elements;
}

void Load_Valid_Fn(Data *TheData, Birth *TheBirth, int *NOL, int *check)
{
    for(int i = 0; i < *NOL; i++)
    {
        Validation_Email((TheData + i)->email, 0);
        Validation_Number((TheData + i)->number, 0);
        Validation_Birth((TheBirth + i)->year, 1, "\0", 0);
        Validation_Birth((TheBirth + i)->month, 2, "\0", 0);
        Validation_Birth((TheBirth + i)->day, 3, (TheBirth + i)->month, 0);
        if(!strlen((TheData + i)->fname) || !strlen((TheData + i)->lname) || !strlen((TheData + i)->adress) || !strlen((TheData + i)->email) || !strlen((TheData + i)->number) || !strlen((TheData + i)->adress) || !atoi((TheBirth + i)->month) || !atoi((TheBirth + i)->day))
        {
            *NOL -= 1;
            (*check)++;
            if(i != *NOL)
            {
                for(int k = i; k < *NOL; k++)
                {
                    *(TheData + k) = *(TheData + k + 1);
                    *(TheBirth + k) = *(TheBirth + k + 1);
                }
                i = -1;
            }
        }
    }
}
