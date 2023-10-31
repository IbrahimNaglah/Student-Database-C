#include <stdio.h>
#include <stdlib.h>

#include "SDB.h"
#include "STD.h"
#include "SDBAPP.h"

#define Max_students 10
#define NumOfStudents 9

student students[Max_students]; // number of students
uint32 count = NumOfStudents;

    //////////////////////////--DataBase--//////////////////////////////
    //previous defined or old database
    uint32 student_IDs[] = {1001,1002,1003,1004,1005,1006,1007,1008,1009};
    uint32 student_years[] = {1,1,2,2,3,3,4,4,5};

    uint32 Course1_grades[] = {10,7,5,10,8,9,10,10,9};
    uint32 Course1_IDs[] = {1002,1003,1004,1005,1006,1007,1008,1009,10010};


    uint32 Course2_grades[] = {20,16,20,18,19,20,17,14,16};
    uint32 Course2_IDs[] = {1003,1004,1005,1006,1007,1008,1009,10010,10011};

    uint32 Course3_grades[] = {100,90,98,96,97,94,96,99,93};
    uint32 Course3_IDs[] = {1004,1005,1006,1007,1008,1009,10010,10011,10012};
   /////////////////////////////////////////////////////////////////////


int main()
{

/*To store previous declared students informations in struct array called students to modify data*/

    for(int i = 0; i<count ; i++)
    {
    students[i].Student_ID = student_IDs[i];
    students[i].Student_year = student_years[i];

    students[i].Course1_ID = Course1_IDs[i];
    students[i].Course1_grade = Course1_grades[i];

    students[i].Course2_ID = Course2_IDs[i];
    students[i].Course2_grade = Course2_grades[i];

    students[i].Course3_ID = Course3_IDs[i];
    students[i].Course3_grade = Course3_grades[i];
    }
//////////////////////////////////////////////////////////////////

    /*To Start our app or program*/

    SDB_APP();



}
