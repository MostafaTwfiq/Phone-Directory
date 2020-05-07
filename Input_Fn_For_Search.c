#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Ansi_Colors.h"
#include "Structs.h"
#include "Input_Fn_For_Search.h"
#include "Remove_New_Line.h"

void Input_Fn_For_Search(Data *TheData, Birth *TheBirth, int NOL)
{
    printf("Enter the last name: ");
    fgets((TheData + NOL)->lname, 100, stdin);
    fseek(stdin, 0, SEEK_END);
    Remove_New_Line((TheData + NOL)->lname);
    printf("Enter the first name: ");
    fgets((TheData + NOL)->fname, 100, stdin);
    fseek(stdin, 0, SEEK_END);
    Remove_New_Line((TheData + NOL)->fname);
    printf("Enter the address: ");
    fgets((TheData + NOL)->adress, 100, stdin);
    fseek(stdin, 0, SEEK_END);
    Remove_New_Line((TheData + NOL)->adress);
    printf("Enter the email: ");
    fgets((TheData + NOL)->email, 100, stdin);
    fseek(stdin, 0, SEEK_END);
    Remove_New_Line((TheData + NOL)->email);
    printf("Enter the phone number: ");
    fgets((TheData + NOL)->number, 15, stdin);
    fseek(stdin, 0, SEEK_END);
    Remove_New_Line((TheData + NOL)->number);
    printf("Enter the enter the year of birth: ");
    fgets((TheBirth + NOL)->year, 5, stdin);
    fseek(stdin, 0, SEEK_END);
    Remove_New_Line((TheBirth + NOL)->year);
    printf("Enter the month of birth: ");
    fgets((TheBirth + NOL)->month, 3, stdin);
    fseek(stdin, 0, SEEK_END);
    Remove_New_Line((TheBirth + NOL)->month);
    printf("Enter the day of birth: ");
    fgets((TheBirth + NOL)->day, 3, stdin);
    fseek(stdin, 0, SEEK_END);
    Remove_New_Line((TheBirth + NOL)->day);
}
