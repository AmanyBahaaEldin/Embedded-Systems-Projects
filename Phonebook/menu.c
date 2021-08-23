#include <stdio.h>
#include <stdlib.h>
#include "user_options.h"
#include "menu.h"

void menu(void)
{
    char choise ='0';
    printf("\t\t _*_*_*_*_*_*_*_*_* WELCOME TO YOUR PHONEBOOK *_*_*_*_*_*_*_*_*_\t\t");
    printf("\n\n\t\t\tMenu\t\t\t\n\n");
    printf("\tEnter:\n\t1->Add Contact\t 2->Delete contact\n\t3->Search\t\t4->Edit\n\t\t5->exit\n");
    scanf("%c" , &choise);
    fflush(stdin);
    switch(choise)
    {

    case '1':
        add_contact();
    break;

    case '2':
        delete_contact();
    break;

    case '3':
        search_contact();
    break;

    case '4':
        edit_contact();
    break;

    case '5':
        exit_app();
    break;

    default :
        printf("Enter any key from 1 to 5");
    break;

    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

