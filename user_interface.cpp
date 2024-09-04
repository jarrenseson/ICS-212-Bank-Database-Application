/*****************************************************************
//
//  NAME:        Jarren Seson
//
//  HOMEWORK:    Project1
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        October27, 2023
//
//  FILE:        user_interface.c
//
//  DESCRIPTION: source code for user_interface.
//  
//
****************************************************************/
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <sstream>
#include "llist.h"
using namespace std;
/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Displays menu options to user, allows user
//                 to input option, checks validity of option,
//                 and makes calls to database function 
//                 based on the inputted option.
//
//  Parameters:   int argc: amount of strings in command line
//                char* argv[]: the strings in the command line
//
//  Return values: return_value: 0: success
//                               1: failure
//
****************************************************************/
int main(int argc, char* argv[])
{
    char option_to_test[15];
    char add[4] = "add";
    char printall[9] = "printall";
    char find[5] = "find";
    char del[7] = "delete";
    char quit[5] = "quit";
    char nullCharacter = '\0';
    char * nullChar = &nullCharacter;
    int valid_input;
    int account_number;
    int valid_account_number = 1;
    char clear_buffer[1000];
    int option_code;
    char name[30];
    char address[50];
    int return_value;
    string strAccNum;
    llist linkedList;
 
    #ifdef debug
        cout << "\n/***************************************************************************";
        cout << "\n//YOU ARE NOW IN DEBUG MODE";
        cout << "\n/***************************************************************************";
    #endif
    cout << "\n\tHello! Welcome to Jarren bank!\n\n";
    do
    {
        do
        {
            cout << "\n\n\tActions";
            cout << "\n\tadd: add a new record to the database";
            cout << "\n\tprintall: print all records in the database";
            cout << "\n\tfind: find record with a specified account #";
            cout << "\n\tdelete: delete existing record with given account number from the database";
            cout << "\n\tquit: quit the program\n";
            cout << "\n\tSelect an action: ";
            cin.getline(option_to_test, 15);
            strcat(option_to_test, "\n");
                /*fgets(option_to_test, 15, stdin);*/
            if(strlen(option_to_test) - 1 > 8)
            {
                cout << "\n\tInput an option or a substring of an option!\n";
            }
            else
            {
                if(strcmp(option_to_test, "\n") != 0)
                {
                    if(strncmp(option_to_test, add, strlen(option_to_test) - 1) == 0)
                    { 
                        option_code = 1;
                        valid_input = 1;
                    }
                    else if(strncmp(option_to_test, printall, strlen(option_to_test) - 1) == 0)
                    {
                        option_code = 2;
                        valid_input = 1;
                    }
                    else if(strncmp(option_to_test, find, strlen(option_to_test) - 1) == 0)
                    {
                        option_code = 3;
                        valid_input = 1;
                    }
                    else if(strncmp(option_to_test, del, strlen(option_to_test) - 1) == 0)
                    {
                        option_code = 4;
                        valid_input = 1;
                    }
                    else if(strncmp(option_to_test, quit, strlen(option_to_test) - 1) == 0)
                    {
                        valid_input = 1;
                        option_code = 5;
                    }
                    else                     
                    {
                        cout << "\n\tInput an option or a substring of an option!\n";
                        valid_input = 0;
                    }         
                }
                else
                {
                    cout << "\n\tInput an option or a substring of an option!\n";
                    valid_input = 0;
                }        
            }
        }
        while(!valid_input);
        if(option_code == 1 || option_code == 3 || option_code == 4)
        {
            do
            {   
                cout << "\n\tEnter account number: ";
                getline(cin,strAccNum);
                stringstream(strAccNum) >> account_number;
                if(stringstream(strAccNum).good())
                    /* not_string = scanf("%d", &account_number);
                    if(not_string)*/
                {
	            if(account_number <= 0)
                    {
                        cout << "\n\tEnter an account number greater than 0!\n";
                        valid_account_number = 0;
                        /*cin.getline(clear_buffer, 1000);*/
                        /*fgets(clear_buffer, 1000, stdin);*/
                    }
                    else if (account_number > 0)
                    {
                        valid_account_number = 1;
                        /*cin.getline(clear_buffer, 1000);*/
                        /*fgets(clear_buffer, 1000, stdin);*/
                    }
                }
                else
                {
                    cout << "\n\tDo not enter a char\n";
                    valid_account_number = 0;
                    cin.getline(clear_buffer, 1000);
                        /*fgets(clear_buffer, 1000, stdin);*/
                }
            }
            while(valid_account_number != 1);
            if(option_code == 1)
            {
                cout << "\n\tEnter your address: ";
                    /*fgetc(stdin);*/                              /**/
                cin.get(address, 50,'%');
                /*strcat(address, nullChar);*/
                    /* NEED TO APPEND NULL CHARACTER TO THE END OF THE ADDRESS CSTRING */
                    /*getaddress(address, 50);*/
                cin.getline(clear_buffer, 1000);
                cout << "\n\tEnter your name: ";
                cin.getline(name, 29);
                    /*fgets(name, 30, stdin);*/
                strcat(name, nullChar);
                /*strcpy(&name[strlen(name)], nullChar);*/
                if(linkedList.addRecord(account_number, name, address) == 0)
                {
                    cout << "\n\n\tAccount added\n";
                }
                else
                {
                    cout << "\n\n\tAccount with account number " << account_number << " already exists\n";
                }
            }
            else if(option_code == 3)
            {
                linkedList.findRecord(account_number);
            }
            else if(option_code == 4)
            {
                if(linkedList.deleteRecord(account_number) == 1)
                {
                    cout << "\n\n\tAccount deleted successfully\n";
                }
            }
        }
        else if(option_code == 2)
        {
            linkedList.printAllRecords();
        }
    }
    while(option_code !=5);
    if(option_code == 5)
    {
        return_value = 0;
    }
    return return_value;
}
