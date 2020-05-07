#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Ansi_Colors.h"
#include "Structs.h"
#include "Validations.h"

void Validation_Birth(char *element, int nm, char *month, int type)
{
    char *index = element;
    if(nm == 1)
    {
        while(*element != '\0')
        {
            if(!(*element >= '0' && *element <= '9'))
            {
                strcpy(index, "\0");
                if(type){
                printf(ANSI_COLOR_RED "Please Enter a valid year of birth.\n" ANSI_COLOR_RESET);
                }
                return;
            }
            element++;
        }
        if(1900 > atoi(index) || atoi(index) > 2015)
        {
            strcpy(index, "\0");
            if(type){
            printf(ANSI_COLOR_RED "Please Enter a valid year of birth (between 1900 - 2015).\n" ANSI_COLOR_RESET);
            }
            return;
        }
    }
    //----------
    if(nm == 2)
    {
        while(*element != '\0')
        {
            if(!(*element >= '0' && *element <= '9'))
            {
                strcpy(index, "\0");
                if(type){
                printf(ANSI_COLOR_RED "Please Enter a valid month of birth.\n" ANSI_COLOR_RESET);
                }
                return;
            }
            element++;
        }
        if(1 > atoi(index) || atoi(index) > 12)
        {
            strcpy(index, "\0");
            if(type){
            printf(ANSI_COLOR_RED "Please Enter a valid month of birth (between 1 - 12).\n" ANSI_COLOR_RESET);
            }
            return;
        }
    }
    //--------------
    if(nm == 3)
    {
        while(*element != '\0')
        {
            if(!(*element >= '0' && *element <= '9'))
            {
                strcpy(index, "\0");
                if(type){
                printf(ANSI_COLOR_RED "Please Enter a valid day of birth.\n" ANSI_COLOR_RESET);
                }
                return;
            }
            element++;
        }
        if((1 > atoi(index)) || (atoi(index) > 31))
        {
            strcpy(index, "\0");
            if(type){
            printf(ANSI_COLOR_RED "Please Enter a valid day of birth. (between 1 - 31)\n" ANSI_COLOR_RESET);
            }
            return;
        }
        else if(atoi(month) == 4 || atoi(month) == 6 || atoi(month) == 9 || atoi(month) == 11)
        {
            if(atoi(index) > 30)
            {
                strcpy(index, "\0");
                if(type){
                printf(ANSI_COLOR_RED "Please Enter a valid day of birth. (between 1 - 30)\n" ANSI_COLOR_RESET);
                }
                return;
            }
        }
        else if(atoi(month) == 2)
        {
            if(atoi(index) > 29)
            {
                strcpy(index, "\0");
                if(type){
                printf(ANSI_COLOR_RED "Please Enter a valid day of birth. (between 1 - 29)\n" ANSI_COLOR_RESET);
                }
                return;
            }
        }
    }
}

void Validation_String(char *element, int nm)
{
    char *index = element;
    while(*element != '\0')
    {
        if(*element == ',')
        {
            strcpy(index, "\0");
            if(nm == 1)
            {
                printf(ANSI_COLOR_RED "Please Enter a valid name.\n" ANSI_COLOR_RESET);
            }
            else
            {
                printf(ANSI_COLOR_RED "Please Enter a valid address.\n" ANSI_COLOR_RESET);
            }
            break;
        }
        element++;
    }
}

void Validation_Number(char *element, int type)
{
    char *index = element;
    while(*element != '\0')
    {
        if(!(*element >= '0' && *element <= '9'))
        {
            strcpy(index, "\0");
            if(type){
            printf(ANSI_COLOR_RED "Please Enter a valid number.\n" ANSI_COLOR_RESET);
            }
            break;
        }
        element++;
    }
}

void Validation_Email(char *element, int type)
{
    char *index = element;
    int at = 0;
    int element_length = strlen(index) - 1;
    if(stricmp((element + element_length - 3), ".com") || *element == '@')
    {
        strcpy(index, "\0");
        if(type){
        printf(ANSI_COLOR_RED "Please Enter a valid email.\n" ANSI_COLOR_RESET);
        }
        return;
    }
    while(*element != '\0')
    {
        if(*element == '@')
        {
            at++;
        }
        element++;
    }
    element = index;
    if(!stricmp((element + element_length - 4), "@.com"))
    {
        strcpy(index, "\0");
        if(type){
        printf(ANSI_COLOR_RED "Please Enter a valid email.\n" ANSI_COLOR_RESET);
        }
        return;
    }
    if(!(at == 1))
    {
        strcpy(index, "\0");
        if(type){
        printf(ANSI_COLOR_RED "Please Enter a valid email.\n" ANSI_COLOR_RESET);
        }
        return;
    }
    while(*element != '\0')
    {
        if(*element == ',' || ((*(element) == *(element + 1)) && *(element) == '.'))
        {
            strcpy(index, "\0");
            if(type){
            printf(ANSI_COLOR_RED "Please Enter a valid email.\n" ANSI_COLOR_RESET);
            }
            break;
        }
        element++;
    }
}
