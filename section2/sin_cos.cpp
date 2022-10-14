/*****************************
 * @name Module Name: White box testing of sines and cosines.
 * @author Faisal Javed
 * @date 7th October, 2022
 * Purpose: CS-700 Assignment 2
 * Student ID: 200491169
 ****************************/

#include <iostream> /// library that controls reading from and writing to the standard streams.
#include <iomanip> /// library which helps us in manipulating the output of the program.
#include "sin_cos.h" /// user-defined header @file sin_cos.h to propagate declarations to code file.

/**
 * 'namespace' is used to organise the names of program entities.
 * The below statement declares that program will be accessing entities whose name are the part of namespace called std.
 * */
using namespace std;
/** These functions compute the sine and cosine of an angle
    expressed in degrees. The result will be
    an integer representing the sine or cosine as
    ten-thousandths. For example, a result of 7071 represents
    7071e-4 or 0.7071.
*/

/** Compute the sine of an angle in degrees.
    @param x The angle in degrees
    @return The sine of x
*/
int sin(int x) {
    if (x < 0) {
        x = -x;
    }
    x = x % 360;
    if (0 <= x && x <= 45) {
        return sin0to45(x);
    } else if (45 <= x && x <= 90) {
        return sin45to90(x);
    } else if (90 <= x && x <= 180) {
        return sin(180 - x);
    } else {
        return -sin(x - 180);
    }
}

/** Compute the cosine of an angle in degrees.
    @param x The angle in degrees
    @return The cosine of x
*/
int cos(int x) {
    return sin(x + 90);
}

/** Compute the sine of an angle in degrees
    between 0 and 45.
    pre: 0 <= x < 45
    @param x The angle
    @return The sine of x
*/
int sin0to45(int x) {
    // Code to compute sin(x) for x between 0 and 45 degrees
    // Evaluate a polynomial optimized for this range.
    int coef[] = {
            -81, -277, 1747900, -1600};
    return polyEval(x, coef, 4) / 10000;
}

/** Compute the sine of an angle in degrees
    between 45 and 90.
    pre: 45 <= x <= 90
    @param x The angle
    @return The sine of x
*/
int sin45to90(int x) {
    // Code to compute sin(x) for x between 45 and 90 degrees
    // Evaluate a polynomial optimized for this range.
    int coef[] = {
            336, -161420, 75484, 999960000};
    return polyEval(90 - x, coef, 4) / 100000;
}

/** Function to evaluate a polynomial
    @param x The point at which the polynomial is to be evaulated
    @param coef The array of coefficients
    @param n The number of coefficients (degree + 1)
    @return x^n-1*coef[0] + x^n-2*coef[1] + ... x*coef[n-2] + coef[n-1]
*/
int polyEval(int x, int coef[], int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result *= x;
        result += coef[i];
    }
    return result;
}

/**
 * Module Name: White box testing of sines and cosines.
 * Author: Faisal Javed
 * Date of Creation: 7th October, 2022
 * Purpose: function white box test the values of sines.
    @param passedValue
    @param expectedValue
    @return void
    @pre Pre Condition - 2 int are passed.
    @post Post Condition - result table is printed
 * */
void testSineValues(int &passedValue, int expectedValue) {
    int valueOfSine = sin(passedValue); /// storing the value of sin for the passed value in @c valueOfSine
    string result; /// declaring a string @c result to store the result after white box testing
    if (valueOfSine == expectedValue) { /// @if
        result = "PASS"; /// store the value PASS if the if condition is true
    } else {
        result = "FAIL"; /// else store the value FAIL if the if condition is false
    } /// @endif

    printDashedLine(); /// calling function printDashedLine() to print dashed line.
    printTableHeader("Sine"); /// calling function printTableHeader() to print header for sine.
    printDashedLine(); /// calling function printDashedLine() to print dashed line.
    printResult(passedValue, valueOfSine, expectedValue, result, "Sine"); /// calling function printResult() to print the result of whitebox testing.
    printDashedLine(); /// calling function printDashedLine() to print dashed line.
    cout << endl; /// using @c endl to go to next line.
}

/**
 * Module Name: White box testing of sines and cosines.
 * Author: Faisal Javed
 * Date of Creation: 7th October, 2022
 * Purpose: function white box test the values of cosines.
    @param passedValue
    @param expectedValue
    @return void
    @pre Pre Condition - 2 int are passed.
    @post Post Condition - result table is printed
 * */
void testCosineValues(int &passedValue, int expectedValue) {
    int valueOfCosine = cos(passedValue); /// storing the value of sin for the passed value in @c valueOfCosine
    string result; /// declaring a string @c result to store the result after white box testing
    if (valueOfCosine == expectedValue) { /// @if
        result = "PASS"; /// store the value PASS if the if condition is true
    } else {
        result = "FAIL"; /// else store the value FAIL if the if condition is false
    } /// @endif

    printDashedLine(); /// calling function printDashedLine() to print dashed line.
    printTableHeader("Cosine"); /// calling function printTableHeader() to print header for cosine.
    printDashedLine(); /// calling function printDashedLine() to print dashed line.
    printResult(passedValue, valueOfCosine, expectedValue, result, "Cosine"); /// calling function printResult() to print the result of whitebox testing.
    printDashedLine(); /// calling function printDashedLine() to print dashed line.
    cout << endl; /// using @c endl to go to next line.
}

/**
 * Module Name: White box testing of sines and cosines.
 * Author: Faisal Javed
 * Date of Creation: 7th October, 2022
 * Purpose: function to print a line using '='
    @param void
    @return void
    @post Post Condition - a line is printed
 * */
inline void printDashedLine() {
    /// printing '=' to the console.
    /// using @c endl to go to next line.
    cout << "=============================================================" << endl;
}

/**
 * Module Name: White box testing of sines and cosines.
 * Author: Faisal Javed
 * Date of Creation: 7th October, 2022
 * Purpose: function to print the table header
    @param sineCosine
    @return void
    @post Post Condition - a table header is printed
 * */
inline void printTableHeader(string sineCosine) {
    /**
     * using @c left keyword to left-align the data.
     * using @c setw to have a well-formatted output with spacing of the specified width.
     * using pipe '|' to separate columns.
     * using @c endl to go to next line.
     * */
    cout << left << setw(17) << "| " + sineCosine + " Value " << setw(17) << "| Test Value " << setw(17)
         << "| Actual Value "
         << setw(17) << "| Result |" << endl;
}

/**
 * Module Name: White box testing of sines and cosines.
 * Author: Faisal Javed
 * Date of Creation: 7th October, 2022
 * Purpose: function to print test case result of sine/cosine in a formatted fashion.
    @param passedValue
    @param valueOfSineCosine
    @param expectedValue
    @param result
    @param sineCosine
    @return void
    @post Post Condition - test case result is printed.
 * */
inline void printResult(int &passedValue, int &valueOfSineCosine, int &expectedValue, string &result, string sineCosine) {
    /**
     * using @c left keyword to left-align the data.
     * using @c setw to have a well-formatted output with spacing of the specified width.
     * using pipe '|' to separate columns.
     * using @c endl to go to next line.
     * */
    cout << left << setw(17) << "| " + sineCosine + "(" + to_string(passedValue) + ")" << setw(17)
         << "| " + to_string(valueOfSineCosine) << setw(17) << "| " +
                                                               to_string(expectedValue) << setw(17)
         << "| " + result + "   |" << endl;
}
