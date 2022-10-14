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
    int var4 = 90;
    int var5 = 45;
    int var6 = -240;
    int var7 = 360;
    int var8 = 67;
    int var9 = 92;
    int var10 = -28;
    int var11 = 40;
    int var12 = 12;
    int var13 = 270;
    int var14 = -25;
    int var15 = -30;
    int var16 = -270;
    int var17 = -180;

    //testing sines
    testSineValues(var1, 4999);
    testSineValues(var2, 8660);
    testSineValues(var3, 9849);
    testSineValues(var4, 9999);
    testSineValues(var6, 8660);
    testSineValues(var5, 7071);
    testSineValues(var7, 0);
    testSineValues(var12, 2079);
    testSineValues(var13, -9999);
    testSineValues(var15, -4999);
    testSineValues(var16, -9999);
    testSineValues(var17, 0);

    cout << endl;

    //testing cosines
    testCosineValues(var1, 8660);
    testCosineValues(var2, 4999);
    testCosineValues(var8, 3906);
    testCosineValues(var12, 9782);
    testCosineValues(var14, 9062);
    testCosineValues(var9, -349);
    testCosineValues(var11, 7662);
    testCosineValues(var10, 8828);
    testCosineValues(var6, -4999);
    testCosineValues(var15, 8660);
    testCosineValues(var16, 0);
    testCosineValues(var17, -9999);

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
//    arraySortingModule();
    whiteBoxTesting();
    return 0;
}
