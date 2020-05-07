#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Ansi_Colors.h"
#include "Structs.h"
#include "Input_Fn.h"
#include "Validations.h"
#include "Remove_New_Line.h"

void Input_Fn(Data *TheData, Birth *TheBirth, int NOL)
{
    strcpy((TheData + NOL)->lname, "\0");
    strcpy((TheData + NOL)->fname, "\0");
    strcpy((TheData + NOL)->adress, "\0");
    strcpy((TheData + NOL)->number, "\0");
    strcpy((TheData + NOL)->email, "\0");
    strcpy((TheBirth + NOL)->day, "\0");
    strcpy((TheBirth + NOL)->month, "\0");
    strcpy((TheBirth + NOL)->year, "\0");
    while(!strlen((TheData + NOL)->lname))
    {
        printf("Enter the last name: ");
        fgets((TheData + NOL)->lname, 100, stdin);
        fseek(stdin, 0, SEEK_END);
        Remove_New_Line((TheData + NOL)->lname);
        Validation_String((TheData + NOL)->lname, 1);
    }
    while(!strlen((TheData + NOL)->fname))
    {
        printf("Enter the first name: ");
        fgets((TheData + NOL)->fname, 100, stdin);
        fseek(stdin, 0, SEEK_END);
        Remove_New_Line((TheData + NOL)->fname);
        Validation_String((TheData + NOL)->fname, 1);
    }
    while(!strlen((TheData + NOL)->adress))
    {
        printf("Enter the address: ");
        fgets((TheData + NOL)->adress, 100, stdin);
        fseek(stdin, 0, SEEK_END);
        Remove_New_Line((TheData + NOL)->adress);
        Validation_String((TheData + NOL)->adress, 2);
    }
    while(!strlen((TheData + NOL)->email))
    {
        printf("Enter the email: ");
        fgets((TheData + NOL)->email, 100, stdin);
        fseek(stdin, 0, SEEK_END);
        Remove_New_Line((TheData + NOL)->email);
        Validation_Email((TheData + NOL)->email , 1);
    }
    while(!strlen((TheData + NOL)->number))
    {
        printf("Enter the phone number: ");
        fgets((TheData + NOL)->number, 15, stdin);
        fseek(stdin, 0, SEEK_END);
        Remove_New_Line((TheData + NOL)->number);
        Validation_Number((TheData + NOL)->number, 1);
    }
    while(!atoi((TheBirth + NOL)->year))
    {
        printf("Enter the enter the year of birth: ");
        fgets((TheBirth + NOL)->year, 5, stdin);
        fseek(stdin, 0, SEEK_END);
        Remove_New_Line((TheBirth + NOL)->year);
        Validation_Birth((TheBirth + NOL)->year, 1, "\0", 1);
    }
    while(!atoi((TheBirth + NOL)->month))
    {
        printf("Enter the month of birth: ");
        fgets((TheBirth + NOL)->month, 3, stdin);
        fseek(stdin, 0, SEEK_END);
        Remove_New_Line((TheBirth + NOL)->month);
        Validation_Birth((TheBirth + NOL)->month, 2, "\0", 1);
    }
    while(!atoi((TheBirth + NOL)->day))
    {
        printf("Enter the day of birth: ");
        fgets((TheBirth + NOL)->day, 3, stdin);
        fseek(stdin, 0, SEEK_END);
        Remove_New_Line((TheBirth + NOL)->day);
        Validation_Birth((TheBirth + NOL)->day, 3, (TheBirth + NOL)->month, 1);
    }
}
