/*****************************
 * @name Module Name: 1) Sorting array and calculating the random time, sorted time and reverse time.
 *          2) White box testing of sines and cosines.
 * @author Faisal Javed
 * @date 7th October, 2022
 * Purpose: CS-700 Assignment 2
 * Student ID: 200491169
 ****************************/

/**
 * '#' is called preprocessor directive.
 * '<>' is used for pre-defined header files.
 * It read the program before it is compiled and executes only those lines which starts with '#'
 * */

#include <iostream>

/**
 * @file arraySorting.h
 * @brief user-defined header file grades_section1.h to propagate declarations to code file.
 * */
#include "arraySorting.h"

/**
 * @file sin_cos.h
 * @brief user-defined header file grades_section1.h to propagate declarations to code file.
 * */
#include "sin_cos.h"

/**
 * 'namespace' is used to organise the names of program entities.
 * The below statement declares that program will be accessing entities whose name are the part of namespace called std.
 * */
using namespace std;

void arraySortingModule(){
    ArraySorting arraySorting1 = ArraySorting(100000);
    arraySorting1.display();

    ArraySorting arraySorting2 = ArraySorting(1000000);
    arraySorting2.display();

    ArraySorting arraySorting3 = ArraySorting(10000000);
    arraySorting3.display();
}

void whiteBoxTesting(){
    /*
 for our white box testing, we use different range of values to test
     the outputs of the different functions
 */
    //whitebox test cases

    int var1 = 30;
    int var2 = 60;
    int var3 = 100;
    int var5 = 90;
    int var7 = 45;
    int var9 = -240;
    int var10 = 360;
    int var11 = 67;
    int var12 = 92;
    int var13 = -28;
    int var14 = 40;
    int var15 = 12;
    int var16 = -25.00;

    //testing sines
    testSineValues(var1, 4999);
    testSineValues(var3, 9849);
    testSineValues(var5, 9999);
    testSineValues(var9, 8660);
    testSineValues(var7, 7071);
    testSineValues(var10, 0);
    testSineValues(var15, 2079);
    //testing cosines
    testCosineValues(var1, 8660);
    testCosineValues(var2, 4999);
    testCosineValues(var11, 3906);
    testCosineValues(var15, 9782);
    testCosineValues(var16, 9062);
    testCosineValues(var12, -349);
    testCosineValues(var14, 7662);
    testCosineValues(var13, 8828);
    testCosineValues(var9, -4999);

//    cout << cos(-240);

}

/*****************************
 * Module Names:
 *          1) Calculating Average score and Grades of Students.
 *          2) Calculating Average subject score and grades for every subject of every student.
 * Author: Faisal Javed
 * Date of Creation: 23rd September, 2022
 * Purpose: main() Function serves as the starting point for program execution.
 *          It has no arguments and returns 0 if the program is executed successfully.
 *          @param [in] void
 *          @return [out] int
 *          @post Post Condition - int is returned.
 ****************************/
int main() {
    arraySortingModule();
    whiteBoxTesting();
    return 0;
}
