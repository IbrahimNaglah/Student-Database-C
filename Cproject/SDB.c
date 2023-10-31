#include <stdio.h>
#include <stdlib.h>

#include "STD.h"
#include "SDB.h"

#define Max_students 10 //Max_students will be substituted by 10 before compilation process.

student students[Max_students];
uint32 count,added; //count is a global variable counts the stores number of students in the database after adding or deleting process.
//added stores the number of added or deleted student.



bool SDB_IsFull()
{
    //Database is full or not
    /* Max_students is the maximum number of students can be stored, defined in Macro by 10

       count assigned with the number of students in database.
       Function return 1 if count == Max_students
       return 0 if count not equal Max_students.
       */
    return count==Max_students;

}

uint8 SDB_GetUsedSize()
{

    printf("The number of added students = %d",added);
    //return the number of students in database
    return count;
}

bool SDB_AddEntry()
{
    //function used to add student with his informations in database

    //There 2 Conditional Statements used to stop function

    //First condition: if the database is full of students.
    if (count > Max_students)
        {
            printf("(Cannot add more students)\n");
            return 0;
        }


    //Enter Students info
    printf("Please Enter the following: ");
    printf("\n ID: ");
    scanf("%d",&students[count].Student_ID);
    printf("\n Year: ");
    scanf("%d",&students[count].Student_year);

    printf("\n Course 1_ID: ");
    scanf("%d",&students[count].Course1_ID);
    printf("\n Course 2_ID: ");
    scanf("%d",&students[count].Course2_ID);
    printf("\n Course 3_ID: ");
    scanf("%d",&students[count].Course3_ID);

    printf("\n Course 1_grade: ");
    scanf("%d",&students[count].Course1_grade);
    printf("\n Course 2_grade: ");
    scanf("%d",&students[count].Course2_grade);
    printf("\n Course 3_grade: ");
    scanf("%d",&students[count].Course3_grade);

    //Second condition: Informations entered exceeds its range
    if(students[count].Student_ID>10000 || students[count].Student_ID == 0 || students[count].Student_year>5
       || students[count].Course1_ID>10000 || students[count].Course1_ID==0 || students[count].Course2_ID>10000
       || students[count].Course2_ID==0 ||students[count].Course3_ID>10000 || students[count].Course3_ID==0
       || students[count].Course1_grade>10 || students[count].Course2_grade>20 || students[count].Course3_grade>100)
    {
        return 0;
    }

    count += 1; //Here we update number of students and increment it by 1 as we added 1 student to our database
    added += 1;
    return 1;

    /* return 1; means program run successfully.
       return 0; means program failed to run. */

}

void SDB_DeletEntry (uint32 id)
{
    /* Function used to delete 1 student with a given id from database. */


    /*for loop help us to review all student ids by incrementing i which is index of array
      by 1 for each loop.

      if condition: to see if the student number i id is equal to given id
      if so delete the informations of that student in database, 0 means no data */
    for(int i = 0 ; i < count ; i++)
    {
        if(id == students[i].Student_ID)
        {

                students[i].Student_ID = 0;
                students[i].Student_year = 0;
                students[i].Course1_grade = 0;
                students[i].Course1_ID = 0;
                students[i].Course2_grade = 0;
                students[i].Course2_ID = 0;
                students[i].Course3_grade = 0;
                students[i].Course3_ID = 0;
        }
    }
    count--;//Here we decrement the number of students by 1; it means we deleted 1 student from database.
}

bool SDB_ReadEntry(uint32 id)
{
    /*Function used to read student informations with given id. */

    /*for loop help us to review all student ids by incrementing i which is index of array
      by 1 for each loop.

      if condition: to see if the student number i id is equal to given id
      if so read the informations of that student which stored in database.
      */
    for(int i = 0 ; i < count ; i++)
    {
        if(id == students[i].Student_ID)
        {
            printf("\n(Data exist)\n");
            printf("\n ID: %d",students[i].Student_ID);

            printf("\n Year: %d",students[i].Student_year);


            printf("\n Course 1_ID: %d",students[i].Course1_ID);

            printf("\n Course 2_ID: %d",students[i].Course2_ID);

            printf("\n Course 3_ID: %d",students[i].Course3_ID);


            printf("\n Course 1_grade: %d",students[i].Course1_grade);

            printf("\n Course 2_grade: %d",students[i].Course2_grade);

            printf("\n Course 3_grade: %d\n",students[i].Course3_grade);
            return 1;
        }
    }
    return 0;
    printf("\n(This ID not in database)\n");
    /*return 1; means id found succesfully.
      return 0; means program failed to find given id. */
}

void SDB_GetList(uint8* count, uint32* list)
{
    /*Prints the number of Students with their ids*/
    printf("\n");
    for(int index = 0 ; index < *count ; index++)
    {
        //printf("Student no. %d = %d\n",index+1,list[index]);
        printf("Student no. %d = %d\n",index+1,students[index].Student_ID);
    }
}


bool SDB_IsIdExist(uint32 id)
{
    /*To check if id exist in database*/

    for(int i = 0 ; i < count ; i++)
    {
        if(id == students[i].Student_ID)
        {

            return 1;
        }
    }
    return 0;
}


