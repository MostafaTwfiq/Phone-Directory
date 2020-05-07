#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

typedef struct
{
    char fname[100];
    char lname[100];
    char adress[100];
    char email[100];
    char number[12];
} Data;

typedef struct
{
    char day[3];
    char month[3];
    char year[5];
} Birth;

#endif // STRUCTS_H_INCLUDED
