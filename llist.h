/*****************************************************************
//
//  NAME:        Jarren Seson
//
//  HOMEWORK:    project2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        November 26, 2023
//
//  FILE:        llist.h
//
//  DESCRIPTION: class decleration for llist
//
****************************************************************/
#include "record.h"

#ifndef LLIST
#define LLIST
class llist
{
    private:
        record * start;
        char filename[20];
        int readfile();
        int writefile();
        void cleanup();
  
    public:
        llist();
        llist(char []);
        llist(const llist&);
        ~llist();
        int addRecord(int, char[], char[]);
        int findRecord(int);
        void printAllRecords();
        int deleteRecord(int);
        llist& operator=(const llist&);
};
#endif
