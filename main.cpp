/*****************************
 * @name Module Name: 1) Execution time for sorting random, sorted and reversed arrays.
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

#include <iostream> /// library that controls reading from and writing to the standard streams.

/**
 * @file arraySorting.h
 * @brief user-defined header file section1/arraySorting.h.h to propagate declarations to code file.
 * */
#include "section1/arraySorting.h"

/**
 * @file sin_cos.h
 * @brief user-defined header file section2/sin_cos.h.h to propagate declarations to code file.
 * */
#include "section2/sin_cos.h"

/**
 * 'namespace' is used to organise the names of program entities.
 * The below statement declares that program will be accessing entities whose name are the part of namespace called std.
 * */
using namespace std;

/**
 * Module Name: Execution time for sorting random, sorted and reversed arrays.
 * Author: Faisal Javed
 * Date of Creation: 7th October, 2022
 * Purpose: Method to fill the array with random positive integers between 1-SIZE OF 2D ARRAY.
 *         @param [in] void
 *         @return [out] void
 *         @post Post Condition - displays a table in console.
 * */
void arraySortingModule(){
    /// creating an object of @class ArraySorting using explicit constructor which takes an argument.
    ArraySorting arraySorting1 = ArraySorting(100000);
    /// calling @a ArraySorting::display method to display the execution time of arrays
    arraySorting1.display();

    /// creating an object of @class ArraySort using explicit constructor which takes an argument.
    ArraySorting arraySorting2 = ArraySorting(1000000);
    /// calling @a ArraySorting::display method to display the execution time of arrays.
    arraySorting2.display();

    /// creating an object of @class ArraySort using explicit constructor which takes an argument.
    ArraySorting arraySorting3 = ArraySorting(10000000);
    /// calling @a ArraySorting::display method to display the execution time of arrays.
    arraySorting3.display();
}

/**
 * Module Name: White box testing of sines and cosines.
 * Author: Faisal Javed
 * Date of Creation: 7th October, 2022
 * Purpose: Method to fill the array with random positive integers between 1-SIZE OF 2D ARRAY.
 *         @param [in] void
 *         @return [out] void
 *         @post Post Condition - displays a table in console.
 * */
void whiteBoxTesting(){


    /**
     * declaring and initializing test-cases variables for white box testing
     * */
    int var1 = 30; /// @var var1 assigned value 30
    int var2 = 60; /// @var var2 assigned value 60
    int var3 = 100; /// @var var3 assigned value 100
    int var4 = 90; /// @var var4 assigned value 90
    int var5 = 45; /// @var var5 assigned value 45
    int var6 = -240; /// @var var6 assigned value -240
    int var7 = 360; /// @var var7 assigned value 360
    int var8 = 67; /// @var var8 assigned value 67
    int var9 = 92; /// @var var9 assigned value 92
    int var10 = -28; /// @var var10 assigned value -28
    int var11 = 40; /// @var var11 assigned value 40
    int var12 = 12; /// @var var12 assigned value 12
    int var13 = 270; /// @var var13 assigned value 270
    int var14 = -25; /// @var var14 assigned value -25
    int var15 = -30; /// @var var15 assigned value -30
    int var16 = -270; /// @var var16 assigned value -270
    int var17 = -180; /// @var var17 assigned value -180

    /// testing sine function with multiple values of sines
    testSineValues(var1, 4999); /// calling @a testSineValues. takes 2 int as arguments.
    testSineValues(var2, 8660); /// calling @a testSineValues. takes 2 int as arguments.
    testSineValues(var3, 9849); /// calling @a testSineValues. takes 2 int as arguments.
    testSineValues(var4, 9999); /// calling @a testSineValues. takes 2 int as arguments.
    testSineValues(var6, 8660); /// calling @a testSineValues. takes 2 int as arguments.
    testSineValues(var5, 7071); /// calling @a testSineValues. takes 2 int as arguments.
    testSineValues(var7, 0); /// calling @a testSineValues. takes 2 int as arguments.
    testSineValues(var12, 2079); /// calling @a testSineValues. takes 2 int as arguments.
    testSineValues(var13, -9999); /// calling @a testSineValues. takes 2 int as arguments.
    testSineValues(var15, -4999); /// calling @a testSineValues. takes 2 int as arguments.
    testSineValues(var16, -9999); /// calling @a testSineValues. takes 2 int as arguments.
    testSineValues(var17, 0); /// calling @a testSineValues. takes 2 int as arguments.

    cout << endl; /// using @c endl to go to next line.

    /// testing cosine function with multiple values of cosines
    testCosineValues(var1, 8660); /// calling @a testCosineValues. takes 2 int as arguments.
    testCosineValues(var2, 4999); /// calling @a testCosineValues. takes 2 int as arguments.
    testCosineValues(var8, 3906); /// calling @a testCosineValues. takes 2 int as arguments.
    testCosineValues(var12, 9782); /// calling @a testCosineValues. takes 2 int as arguments.
    testCosineValues(var14, 9062); /// calling @a testCosineValues. takes 2 int as arguments.
    testCosineValues(var9, -349); /// calling @a testCosineValues. takes 2 int as arguments.
    testCosineValues(var11, 7662); /// calling @a testCosineValues. takes 2 int as arguments.
    testCosineValues(var10, 8828); /// calling @a testCosineValues. takes 2 int as arguments.
    testCosineValues(var6, -4999); /// calling @a testCosineValues. takes 2 int as arguments.
    testCosineValues(var15, 8660); /// calling @a testCosineValues. takes 2 int as arguments.
    testCosineValues(var16, 0); /// calling @a testCosineValues. takes 2 int as arguments.
    testCosineValues(var17, -9999); /// calling @a testCosineValues. takes 2 int as arguments.
}

/*****************************
 * Module Names:
 *          1) Execution time for sorting random, sorted and reversed arrays.
 *          2) White box testing of sines and cosines.
 * Author: Faisal Javed
 * Date of Creation: 7th October, 2022
 * Purpose: main() Function serves as the starting point for program execution.
 *          It has no arguments and returns 0 if the program is executed successfully.
 *          @param [in] void
 *          @return [out] int
 *          @post Post Condition - int is returned.
 ****************************/
int main() { /// opening brace - program execution starts here.

    /**
     * Module Name: Execution time for sorting random, sorted and reversed arrays.
     * */
    arraySortingModule(); /// calling function @fn arraySortingModule() to sort arrays.

    /**
    * Module Name: White box testing of sines and cosines.
    * */
    whiteBoxTesting(); /// calling function @fn whiteBoxTesting() to test sine and cosine using white box testing.

    return 0; /// returns 0 if the program is executed successfully because main() has a return type of integer.
} /// closing brace - program terminates here.
