/*****************************************************************
//
//  NAME:        Jarren Seson
//
//  HOMEWORK:    project2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Jarren Seson
//
//  DATE:        November 14, 2023
//
//  FILE:        record.h
//
//  DESCRIPTION: Definition of record structure
//
****************************************************************/
#ifndef RECORD
#define RECORD
struct record
{
    int accountno;
    char name[30];
    char address[50];
    record* next;
};
#endif

