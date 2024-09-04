/*****************************************************************
//
//  NAME:        Jarren Seson
//
//  HOMEWORK:    Project2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  jarren seson
//
//  DATE:        November 25, 2023
//
//  FILE:        llist.cpp
//
//  DESCRIPTION: Function definitions for the functions declared
//               in database.h
//
****************************************************************/
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <sstream>
#include <fstream>
#include "llist.h"
using namespace std;
/*****************************************************************
//
//  Function name: addRecord
//
//  DESCRIPTION:   Prints function name and parameters passed. 
//
//  Parameters:    struct record*: pointer to pointer to a 
//                                    record structure
//                 int account_num: account number
//                 char name[]: name
//                 char address[]: address  
// 
//  Return values: return_value: 0: success
//                               1: failure                
//
****************************************************************/
int llist::addRecord(int account_num, char name[], char address[])
{
    int return_value = 1;
    struct record * previous_record;
    struct record * current_record;
    struct record * temp;
    current_record = this->start;
    previous_record = NULL;
    #ifdef debug
        std::cout << "\n/**************************************************************************";
        std::cout << "\n//ENTERING: addRecord";
        std::cout << "\n//Parameters";
        std::cout << "\n//Account Number: " << account_num;
        std::cout << "\n//Name: " << name;
        std::cout << "\n//Address: " << address;
        std::cout << "\n***************************************************************************\n";
    #else
        if(current_record == NULL)
        {
            current_record = (struct record *) new record;
            (this)->start = current_record;
            (current_record)->accountno = account_num;          
            strncpy((current_record)->name, name, 30);       
            strncpy((current_record)->address, address, 50);       
            (current_record)->next = NULL;
            return_value = 0;
        } 
        else
        {
            if(account_num > (current_record)->accountno)
            {
                temp = (struct record *) new record;
                temp->accountno = account_num;          
                strncpy((temp)->name, name, 30);       
                strncpy((temp)->address, address, 50);       
                (temp)->next = current_record;
                (this)->start = temp;
                return_value = 0;
            }
            else
            {
                while(current_record != NULL && account_num < ((current_record)->accountno))
                {
                    temp = (current_record)->next;
                    previous_record = current_record; 
                    current_record = temp;                    
                } 
                if(current_record != NULL && account_num == (current_record)->accountno) /* accounting for the middle of the list and account already existing */
                {
                    return_value = 1;
                }
                else
                {
                    temp = (struct record *) new record;
                    (previous_record)->next = temp;
                    (temp)->accountno = account_num;
                    strncpy((temp)->name, name, 30);   
                    strncpy((temp)->address, address, 50);
                    (temp)->next = current_record;
                    return_value = 0;
                }  
            }
        }
    #endif
    return return_value;
}    

/*****************************************************************
//
//  Function name: printAllRecords
//
//  DESCRIPTION:   Prints function name 
//
//  Parameters:    Record* myRecord: pointer to record object
//
//  Return values: N/A                 
//
****************************************************************/
void llist::printAllRecords()
{
    struct record* temp;
    struct record* next_record;
    next_record = (this)->start;
    #ifdef debug
        std::cout << "\n/***************************************************************************";
        std::cout << "\n//ENTERING: printAllRecords";
        std::cout << "\n/***************************************************************************\n";
    #else
        if(start == NULL)
        {
            std::cout << "\n\n\tThe database is empty\n";
        }
        else
        {
            while(next_record != NULL)
            {
                std::cout << "\n\tAccount#: " << (next_record)->accountno;
                std::cout << "\n\tName: " << (next_record)->name;
                std::cout << "\n\tAddress: " << (next_record)->address << "\n";
                temp = (next_record)->next;
                next_record = temp;
            }
        }
    #endif
}
/*****************************************************************
//
//  Function name: findRecord
//
//  DESCRIPTION:   prints fuction name and parameters
//  
//  Parameters:    Record* myRecord: pointer to record object
//                 int account_num: account number
//
//  Return values: N/A                 
//
****************************************************************/
int llist::findRecord (int account_num)
{
    int return_value = 1;
    struct record* temp;
    struct record* next_record;
    next_record = this->start;

    #ifdef debug
        std::cout << "\n/***************************************************************************";
        std::cout << "\n//ENTERING: findRecord";
        std::cout << "\n//Parameters";
        std::cout << "\nAccount Number:" << account_num;
        std::cout << "\n/***************************************************************************\n";
    #else
        if(start == NULL)
        {
            std::cout << "\n\tNo account with that account number exists\n";
        }
        else
        {
            while(next_record != NULL && account_num < ((next_record)->accountno))
            {
                temp = (next_record)->next;
                next_record = temp;                    
            } 
            if(next_record != NULL && (next_record)->accountno == account_num)
            {
                std::cout << "\n\tAccount#: " << (next_record)->accountno; 
                std::cout << "\n\tName: " << (next_record)->name;
                std::cout << "\n\tAddress: " << (next_record)->address;
                return_value = 0;
            }
            else
            {
                std::cout << "\n\tNo account with that number exists";
                return_value = 1;
            }
        }      
    #endif
    return return_value;
}

/*****************************************************************
//
//  Function name: deleteRecord
//
//  DESCRIPTION:   prints fuction name and parameters
//  
//  Parameters:    Record* myRecord: pointer to record object
//                 int account_num: account number
//
//  Return values: 1: success
//                 0: failure       
//
****************************************************************/
int llist::deleteRecord(int account_num)
{
    int return_value;
    struct record* next_record;
    struct record* current_record;
    struct record* temp = NULL;
    current_record = NULL;
    next_record = this->start;
    #ifdef debug
        std::cout << "\n/***************************************************************************";
        std::cout << "\n//ENTERING: deleteRecord";
        std::cout << "\n//Parameters";
        std::cout << "\n//Account Number: " << account_num;
        std::cout << "\n/***************************************************************************\n";
    #else
        if(next_record == NULL)
        {
            return_value = 0;
        }
        else
        {
            while(account_num < (next_record)->accountno)
            {
                current_record = next_record;
                temp = (next_record)->next;
                next_record = temp;
            }
            if(account_num == (next_record)->accountno)
            {
                if(next_record == (this)->start)
                {
                    temp = (next_record)->next;
                    (this)->start = temp;
                    delete(next_record);
                    return_value = 1;
                }
                else if(next_record == NULL)/*accounting for last element in linked list. however, can also interfere with the first element */
                {
                    temp = (next_record)->next;
                    next_record = temp;
                    delete(next_record);
                    return_value = 1;
                }
                else
                {
                    temp = (next_record)->next;
                    (current_record)->next = temp;
                    delete(next_record);
                    return_value = 1;
                }
            }
            else
            {
                return_value = 0;
            }
        }
    #endif
    return return_value;
}

/*****************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   writes the presented array into the file with
//                 the name filename 
//
//  Parameters:    struct pokemon pokearray[]: array of the
//                                             structure pokemon 
//                                             that holds the
//                                             desired input 
//                                             to the file with
//                                             filename
//                 int num: size of the array desired to be
//                          written into the file with filename 
//                 char filename[]: name of file the program
//                                  is supposed to write to
//
//  Return values:  0 : File successfully opened 
//                 -1 : File not opened
//
****************************************************************/
int llist::writefile()
{
    int return_value = 0;
    ofstream fp;
    struct record* next_record;
    struct record* temp;
    temp = NULL;
    next_record = this->start;

    #ifdef debug
        std::cout << "\n/***************************************************************************";
        std::cout << "\n//ENTERING: writefile";
        std::cout << "\n/***************************************************************************\n";
    #else
        fp.open((this)->filename, ofstream::out | ofstream::trunc);
        if(fp.is_open())
        {
            while(next_record != NULL)
            {
                fp << (next_record)->accountno << "\n";
                fp << (next_record)->address << "%" << "\n";
                fp << (next_record)->name << "\n";
                temp = (next_record)->next;
                next_record = temp;
            }
            fp << "end\n";
            fp.close();
            return_value = 0;
        }
        else
        {
            return_value = -1;
        }
    #endif
    return return_value;
}
    /*
        if(fp != NULL)
        {
            while(next_record != NULL)
            {
                fprintf(fp, "%d\n", (next_record)->accountno);
                fprintf(fp, "%s\n", (next_record)->address);
                fprintf(fp, "%s\n", (next_record)->name);
                temp = (next_record)->next;
                next_record = temp; 
            }
            fprintf(fp, "%s\n", "end"); 
            fclose(fp);
            return_value = 0;
        }
        else
        {
            return_value = -1;
        }
    #endif
    return return_value; */


/*****************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   reads from the file with filename and stores it
//                 in pokearray.
//
//  Parameters:    struct record ** start: start of the record
//                                         linked list 
//                 int* num: the number of pokemon read from
//                           file with filename 
//                 char filename[]: name of file the program
//                                  is supposed to read from
//
//  Return values:  0 : File successfully opened 
//                 -1 : File not opened
//
****************************************************************/
int llist::readfile()
{
    int return_value = 0;
    ifstream fp;
    int accountno;
    char name[30];
    char address[50];
    char clearBuffer[40];
    fp.open((this)->filename, ifstream::in);
   
    #ifdef debug
        std::cout << "\n/***************************************************************************";
        std::cout << "\n//ENTERING: readfile";
        std::cout << "\n/***************************************************************************\n";
    #else
    if(fp.is_open())
    {
        do
        {
            fp >> accountno;
            if(fp.good())
            {
                fp.getline(clearBuffer, 1);
                fp.getline(address, 50, '%');
                fp.get();
                fp.getline(name, 30);
                addRecord(accountno, name, address);
            }
        }
        while(fp.good());
        return_value = 0;
        fp.close();
        /*do
        {
            stringstream(strAccNum) >> accountno;
            if(stringstream(strAccNum).good())
            {
                fp.getline(clearBuffer, 2);
                fp.getline(address, 50, '%');
                fp.getline(clearBuffer, 2);
                fp.getline(name, 30);
                addRecord(accountno, name, address);
            }
        }
        while(stringstream(strAccNum).good());
        return_value = 0;
        fp.close();*/
    }
    else
    {
        return_value = -1;
    }
    #endif
    return return_value;
/*        if(fp != NULL)
        {
            do
            {
                scanResult = fscanf(fp, "%d", &accountno);
                if(scanResult != 0)
                {
                    fgets(clearBuffer, 2, fp);
                    fgets(address, 50, fp);
                    fgets(clearBuffer, 2, fp);
                    fgets(name, 30, fp);
                    addRecord(accountno, name, address);
                }
            } 
            while(scanResult != 0); 
            return_value = 0;
            fclose(fp);
        }
        else 
        {
            return_value = -1;
        }
    #endif
    return return_value;*/
}
/*****************************************************************
//
//  Function name: cleanup
//
//  DESCRIPTION:   dellocates allocated record space 
//
//  Parameters:    struct record ** start: start of the record
//                                         linked list 
//
//  Return values:  N/A
****************************************************************/
void llist::cleanup()
{
    struct record * next_record;
    struct record * temp;
    next_record = this->start;
    #ifdef debug
        std::cout << "\n/***************************************************************************";
        std::cout << "\n//ENTERING: cleanup";
        std::cout << "\n/***************************************************************************\n";
    #else
        while(next_record != NULL)
        {
            temp = (next_record)->next;
            delete(next_record);
            next_record = temp;
        }
        this->start = NULL;
    #endif
}
/*****************************************************************
//
//  Function name: llist
//
//  DESCRIPTION:   constructor for the linked list
//
//  Parameters:    N/A 
//
//  Return values:  N/A
****************************************************************/
llist::llist()
{
    #ifdef bebug
        std::cout << "\n/***************************************************************************";
        std::cout << "\n//ENTERING: llist()";
        std::cout << "\n/***************************************************************************\n";
    #else
        int i;
        char name[12] = "default.txt";
        this->start = NULL;
        for(i = 0; i < 13; i++)
        {
            this->filename[i] = name[i];
        }
        readfile();
    #endif
}
/*****************************************************************
//
//  Function name: llist
//
//  DESCRIPTION:   overloaded constructor for a linked list
//
//  Parameters:    char[] filename: file to write the linked list to
//
//  Return values:  N/A
****************************************************************/
llist::llist(char fname[])
{
    #ifdef debug
        std::cout << "\n/***************************************************************************";
        std::cout << "\n//ENTERING: llist(char fname[]";
        std::cout << "\n//Parameters";
        std::cout << "\n//char[]fname: " << fname;
        std::cout << "\n/***************************************************************************\n";
    #else
        int i;
        for(i = 0; i < 20; i++)
        {
            filename[i] = fname[i];
        }
        readfile();
    #endif
}
/*****************************************************************
//
//  Function name: llist
//
//  DESCRIPTION:   destructor for the linked list. writes the linked list
//                 to the file with the name associated with the filename
//                 member of the object. also deallocates all of the heap
//                 space dedicated to the records of the linked list.
//
//  Parameters:    N/A
//
//  Return values:  N/A
****************************************************************/
llist::~llist()
{
    #ifdef debug
        std::cout << "\n/***************************************************************************";
        std::cout << "\n//ENTERING: ~llist";
        std::cout << "\n/***************************************************************************\n";
    #else
        writefile();
        cleanup();
    #endif
}
/*****************************************************************
//
//  Function name: llist
//
//  DESCRIPTION:  overloaded constructor for llist. makes a copy of the object given in the parameters. 
//
//  Parameters:    const llist& linkedList: llist to make a copy of
//
//  Return values:  N/A
****************************************************************/
llist::llist(const llist& linkedList)
{
    #ifdef debug
        std::cout << "\n/***************************************************************************";
        std::cout << "\n//ENTERING: llist(const llist&)";
        std::cout << "\n//Parameters";
        std::cout << "\n//const llist&";
        std::cout << "\n/***************************************************************************\n";
    #else
        struct record* temp;
        struct record* next_record;
        next_record = linkedList.start;
        (this)->start = next_record;
        while(next_record != NULL)
        {
            addRecord((next_record)->accountno, (next_record)->address, (next_record)->name);
            temp = (next_record)->next;
            next_record = temp;
        }   
    #endif
}
/*****************************************************************
//
//  Function name: operator=
//
//  DESCRIPTION:  assigns the records of the llist reference in the parameters
//                to the records of the llist object that calls the method.
//
//  Parameters:    const llist& linkedList: llist reference to be copied from
//
//  Return values:  *this: the edited version of the object that called
//                         the method.
****************************************************************/
llist& llist::operator=(const llist& linkedList)
{
    #ifdef debug
        std::cout << "\n/***************************************************************************";
        std::cout << "\n//ENTERING: operator=(const llist&)";
        std::cout << "\n//Parameters";
        std::cout << "\n//const llist&";
        std::cout << "\n/***************************************************************************\n";
    #else
        cleanup();
        struct record* temp;
        struct record* next_record;
        next_record = linkedList.start;
        (this)->start = next_record;
        while(next_record != NULL)
        {
            addRecord((next_record)->accountno, (next_record)->address, (next_record)->name);
            temp = (next_record)->next;
            next_record = temp;
        }
    #endif
    return *this;
}
