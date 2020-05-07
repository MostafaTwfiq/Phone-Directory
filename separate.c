#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Structs.h"
#include "separate.h"

void separate(char **elements, Data *TheData, Birth *TheBirth, int NOL)
{
    char **birth;
    birth = malloc(sizeof(*birth) * NOL);
    for(int i = 0; i < NOL; i++)
    {
        *(birth + i) = malloc(sizeof(Birth));
    }
    for(int i = 0; i < NOL; i++)
    {
        mystrcpy((TheData + i)->lname, strtok(*(elements + i), ","), 99);
        mystrcpy((TheData + i)->fname, strtok(NULL, ","), 99);
        strcpy(*(birth + i), strtok(NULL, ","));
        mystrcpy((TheData + i)->adress, strtok(NULL, ","), 99);
        mystrcpy((TheData + i)->email, strtok(NULL, ","), 99);
        mystrcpy((TheData + i)->number, strtok(NULL, ","), 11);
    }
    for(int i = 0; i < NOL; i++)
    {
        strcpy((TheBirth + i)->day, strtok(*(birth + i), "-"));
        strcpy((TheBirth + i)->month, strtok(NULL, "-"));
        strcpy((TheBirth + i)->year, strtok(NULL, "-"));
    }
}

void mystrcpy(char *p1, char *p2, int x){
    if(strlen(p2) < x){
        x = strlen(p2);
    }
    int i = 0;
    for(i = 0; i < x; i++){
        if(p2[i] != '\0'){
            p1[i] = p2[i];
        }
    }
    p1[i] = '\0';
}
