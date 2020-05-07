#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Ansi_Colors.h"
#include "Structs.h"
#include "Print_Fn.h"

int DobComN(Data data1, Data data2)
{
    char *p1 = data1.lname;
    char *p2 = data2.lname;
    while(*p1 != '\0')
    {
        if(*p1 >= 'A' && *p1 <= 'Z')
        {
            *p1 += 32;
        }
        p1++;
    }
    while(*p2 != '\0')
    {
        if(*p2 >= 'A' && *p2 <= 'Z')
        {
            *p2 += 32;
        }
        p2++;
    }
    if(strcmp(data1.lname, data2.lname) == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void sortByLname(Data *TheData, Birth *TheBirth, int NOL)
{
    int ToF = 1;
    while(ToF)
    {
        ToF = 0;
        for(int i = 0; i < (NOL - 1); i++)
        {
            if(DobComN(*(TheData + i), *(TheData + i + 1)))
            {
                ToF = 1;
                Swap_Fn(TheData, TheBirth, i);
            }
        }
    }
}

int DobComB(Birth birth1, Birth birth2)
{
    return ((atoi(birth1.year) * 10000 + atoi(birth1.month) * 100 + atoi(birth1.day))-(atoi(birth2.year) * 10000 + atoi(birth2.month) * 100 + atoi(birth2.day)));
}

void Swap_Fn(Data *TheData, Birth *TheBirth, int i)
{
    Data NewData;
    Birth NewBirth;
    NewData = *(TheData + i);
    NewBirth = *(TheBirth + i);
    *(TheData + i) = *(TheData + i + 1);
    *(TheBirth + i) = *(TheBirth + (i + 1));
    *(TheData + (i + 1)) = NewData;
    *(TheBirth + (i + 1)) = NewBirth;
}

void SortByDOB(Data *TheData, Birth *TheBirth, int NOL)
{
    int ToF = 1;
    while(ToF)
    {
        ToF = 0;
        for(int i = 0; i < (NOL - 1); i++)
        {
            if(DobComB(*(TheBirth + i), *(TheBirth + i + 1)) > 0)
            {
                ToF = 1;
                Swap_Fn(TheData, TheBirth, i);
            }
        }
    }
}

void Print_Fn(Data *TheData, Birth *TheBirth, int NOL)
{
    for(int i = 0; i < NOL; i++)
    {
        printf("%d-\n", i + 1);
        printf("First name: %s\n",(TheData + i)->fname);
        printf("Last name: %s\n",(TheData + i)->lname);
        printf("Address: %s\n",(TheData + i)->adress);
        printf("Phone Number: %s\n",(TheData + i)->number);
        printf("Email: %s\n",(TheData + i)->email);
        printf("Data of birth: %s-%s-%s\n",(TheBirth + i)->day, (TheBirth + i)->month, (TheBirth + i)->year);
        printf(ANSI_COLOR_BLUE "---------------\n" ANSI_COLOR_RESET);
    }
}
