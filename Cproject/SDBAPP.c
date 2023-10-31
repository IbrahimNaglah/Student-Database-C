#include <stdio.h>
#include <stdlib.h>
#include "SDB.h"
#include "STD.h"

#define Max_students 10

uint32 count,added;
student students[Max_students]; //so i used this only

uint32 student_IDs; //Not Recommended as array cannot modified in runtime.

void SDB_action(uint8 choice)
{
    //Function actions depends on user input
    int id;


    switch(choice)
    {
    case 1:

        if(SDB_AddEntry())
            printf("\n(Data added successfully)\n");
        else
            printf("\n(The data entered is incorrect,or unable to add student data. Database is full)\n");

        break;
    case 2:
        printf("\nNumber of Students in the database: %d\n",SDB_GetUsedSize());
        break;
    case 3:
        printf("\nEnter Student ID:\n");
        scanf("%d",&id);
        SDB_ReadEntry(id);
        break;
    case 4:
        SDB_GetList(&count,&student_IDs);
        break;
    case 5:
        printf("\nEnter Student ID:\n");
        scanf("%d",&id);
        SDB_IsIdExist(id);
            if (SDB_IsIdExist(id) == 1)
                printf("(ID exists)");
            else
                printf("(ID does not exist)");
        break;
    case 6:
        printf("\nEnter Student ID:\n");
        scanf("%d",&id);
        SDB_DeletEntry(id);
        break;
    case 7:
        if(SDB_IsFull() == 1)
            printf("\n(The database is full)");
        else
            printf("\n(The database is not full)");
        break;
    default:
            printf("\n(Invalid choice. Please choose a valid option)\n");
            break;
    }
}


void SDB_APP()
{
    int choice;
    printf("App Options: ");
        printf("\n 1. To add entry, enter 1"
"\n 2. To get used size in database, enter 2"
"\n 3. To read student data, enter 3"
"\n 4. To get the list of all student IDs, enter 4"
"\n 5. To check is ID is existed, enter 5"
"\n 6. To delete student data, enter 6"
"\n 7. To check is database is full, enter 7"
"\n 8. To exit enter 0\n");
    while(1)
    {


        printf("\nPlease Enter number : ");
        scanf("%d",&choice);

        if(choice == 0)break;

        SDB_action(choice);
    }
}

