#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "user_options.h"
#include "typedefs.h"

typedef struct
{
    char name[100];
    char e_mail[100];
    char phone_number[40];
}contact;

void add_contact(void)
{
    contact c ={{0},{0},{0}};
    FILE *file;
    file = fopen("contact_list.txt" , "a");
    printf("\nEnter contact name:");
    gets(c.name);
    printf("\nEnter contact e_mail:");
    gets(c.e_mail);
    printf("\nEnter contact phone number:");
    gets(c.phone_number);

    fprintf(file ,"%s\t\t%s\t\t%s\n", c.name , c.e_mail , c.phone_number);

    fflush(stdin);
    printf("\ncontact saved successfully ^__^\n");

    fclose(file);
    getch();
    //to clear the output screen
    system("cls");
    menu();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void search_contact(void)
{
    sint32 s_flag=0;
    contact s ={{0}, {0},{0}};
    char line[500]={0};
    FILE *file;
    file = fopen("contact_list.txt" , "r");
    char search_param[40]={0};
    if(file == NULL)
    {
        printf("No contacts data in the phonebook!! '_' ");
    }
    else
    {
        printf("Enter the name or the phone number of the contact you want to search for:");
        gets(search_param);

    //Now we need to loop on the contact list to reach the contact data which the user want to search for

        while(fgets(line,500,file))
            {
                sscanf(line, "%[^\t]\t%[^\t]\t%s", &s.name, &s.e_mail, &s.phone_number);
                sint32 compare = strcmp(s.phone_number , search_param);
                //comparing the entered name with the retrieved name
                if((strcmp(s.name , search_param)==0) || (compare==0) )
                {
                    s_flag= 1;
                    //strcpy(contact_name , s.name);
                    printf("%s data:\n" , s.name);
                    printf("name:%s\t\te_mail:%s\t\tphone_number:%s\n", s.name , s.e_mail , s.phone_number);

                }
            }
            if(s_flag== 0)
                {
                printf("Contact not found");
                }

            fclose(file);
    }
    getch();
    //to clear the output screen
    system("cls");
    menu();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void edit_contact(void)
{
    sint32 edit_flag =0;
    contact s ={{0}, {0},{0}};
    contact e ={{0},{0},{0}};
    char line[500]={0};
    FILE *file, *file_temp;
    file = fopen("contact_list.txt" , "r+");
    char edit_name[40]={0};
    if(file == NULL)
    {
        printf("No contacts data in the phonebook!! '_' ");
    }
    else

    {
        file_temp = fopen("temp_file.txt" , "w+");
        if(file_temp == NULL)
        {
            printf("error in opening!! '_' ");
        }
        else
        {
            printf("Enter the name of the contact you want to edit:");
            gets(edit_name);
            fflush(stdin);
            //Now we need to loop on the contact list to reach the contact data which the user want to edit
            while((fgets(line,500,file)))
            {
                 sscanf(line, "%[^\t]\t%[^\t]\t%s", &s.name, &s.e_mail, &s.phone_number);

                //comparing the entered name with the retrieved name
                if(strcmp(s.name , edit_name)==0)
                {
                    //writing the edited contacts to the temporary file
                    printf("\nEnter edited contact name:");
                    gets(e.name);
                    printf("\nEnter edited contact e_mail:");
                    gets(e.e_mail);
                    printf("\nEnter edited contact phone number:");
                    gets(e.phone_number);
                    fprintf(file_temp ,"%s\t\t%s\t\t%s\n", e.name , e.e_mail , e.phone_number);
                    edit_flag=1;
                    break;
                }
                else
                {
                    //writing the other contacts to the temporary file
                    fprintf(file_temp ,"%s\t\t%s\t\t%s\n", s.name , s.e_mail , s.phone_number);
                }
            }
            fclose(file);
            fclose(file_temp);
            //removing the original file and renaming the temporary file with "contact_list"
            remove("contact_list.txt");
            rename("temp_file.txt" , "contact_list.txt");

            if(edit_flag==1)
            {
                printf("\n your data are edited successfully ^__^");

            }
            else
            {
                    printf(" \n contact not found");
            }

        }

    }
    getch();
    //to clear the output screen
    system("cls");
    menu();

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void delete_contact(void)
{
    sint32 deleted_flag =0;
    contact s ={{0},{0},{0}};
    char line[500]={0};
    FILE *file, *file_temp;
    file = fopen("contact_list.txt" , "r+");
    char delete_name[40]={0};
    if(file == NULL)
    {
        printf("No contacts data in the phonebook!! '_' ");
    }
    else
    {
        file_temp = fopen("temp_file.txt" , "w+");
        if(file_temp == NULL)
        {
            printf("error in opening!! '_' ");
        }
        else
        {
            printf("Enter the name of the contact you want to delete:");
            gets(delete_name);
            fflush(stdin);
            //Now we need to loop on the contact list to reach the contact data which the user want to delete
            while((fgets(line,500,file)))
            {
                sscanf(line, "%[^\t]\t%[^\t]\t%s", &s.name, &s.e_mail, &s.phone_number);

                //comparing the entered name with the retrieved name
                if(strcmp(s.name , delete_name)==0)
                {
                    //raising the deleted_flag
                    deleted_flag =1;
                }
                else
                {
                    //writing the other contacts to the temporary file
                    fprintf(file_temp ,"%s\t\t%s\t\t%s\n", s.name , s.e_mail , s.phone_number);
                }
            }
            fclose(file);
            fclose(file_temp);
            //removing the original file and renaming the temporary file with "contact_list"
            remove("contact_list.txt");
            rename("temp_file.txt" , "contact_list.txt");
            if(deleted_flag==1)
            {
                printf("\n your data are deleted successfully ^__^");
            }
            else
            {
                    printf(" \n contact not found");
            }
        }
    }
    getch();
    //to clear the output screen
    system("cls");
    menu();
}

void exit_app(void)
{
    exit(0);
}
