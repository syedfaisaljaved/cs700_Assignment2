/*****************************
 * @name Module Name: White box testing of sines and cosines.
 * @author Faisal Javed
 * @date 7th October, 2022
 * Purpose: CS-700 Assignment 2
 * Student ID: 200491169
 ****************************/
#pragma once
#include <iostream>

/**
 * Module Name: White box testing of sines and cosines.
 * Author: Faisal Javed
 * Date of Creation: 7th October, 2022
 * Purpose: function prototype to Compute the sine of an angle in degrees.
    @param int The angle in degrees
    @return The sine of x
 * */
int sin(int);

/**
 * Module Name: White box testing of sines and cosines.
 * Author: Faisal Javed
 * Date of Creation: 7th October, 2022
 * Purpose: function prototype to Compute the cosine of an angle in degrees.
    @param int The angle in degrees
    @return The cosine of x
 * */
int cos(int);

/**
 * Module Name: White box testing of sines and cosines.
 * Author: Faisal Javed
 * Date of Creation: 7th October, 2022
 * Purpose: function prototype to Compute the sine of an angle in degrees
    between 0 and 45.
    @param int The angle
    @return The sine of x
    @pre: Pre Condition - 0 <= x < 45
 * */
int sin0to45(int);

/**
 * Module Name: White box testing of sines and cosines.
 * Author: Faisal Javed
 * Date of Creation: 7th October, 2022
 * Purpose: function prototype to Compute the sine of an angle in degrees
    between 45 and 90.
    @param int The angle
    @return The sine of x
    @pre: Pre Condition - 45 <= x <= 90
 * */
int sin45to90(int);

/**
 * Module Name: White box testing of sines and cosines.
 * Author: Faisal Javed
 * Date of Creation: 7th October, 2022
 * Purpose: function prototype to evaluate a polynomial
    @param int The point at which the polynomial is to be evaulated
    @param int The array of coefficients
    @param int The number of coefficients (degree + 1)
    @return x^n-1*coef[0] + x^n-2*coef[1] + ... x*coef[n-2] + coef[n-1]
 * */
int polyEval(int, int[], int);

/**
 * Module Name: White box testing of sines and cosines.
 * Author: Faisal Javed
 * Date of Creation: 7th October, 2022
 * Purpose: function prototype white box test the values of sines.
    @param int
    @param int
    @return void
    @pre Pre Condition - 2 int are passed.
    @post Post Condition - result table is printed
 * */
void testCosineValues(int &, int);

/**
 * Module Name: White box testing of sines and cosines.
 * Author: Faisal Javed
 * Date of Creation: 7th October, 2022
 * Purpose: function prototype white box test the values of cosines.
    @param int
    @param int
    @return void
    @pre Pre Condition - 2 int are passed.
    @post Post Condition - result table is printed
 * */
void testSineValues(int &, int);

/**
 * Module Name: White box testing of sines and cosines.
 * Author: Faisal Javed
 * Date of Creation: 7th October, 2022
 * Purpose: function prototype to print a line using '='
    @param void
    @return void
    @post Post Condition - a line is printed
 * */
inline void printDashedLine();

/**
 * Module Name: White box testing of sines and cosines.
 * Author: Faisal Javed
 * Date of Creation: 7th October, 2022
 * Purpose: function prototype to print the table header
    @param std::string
    @return void
    @post Post Condition - a table header is printed
 * */
inline void printTableHeader(std::string);

/**
 * Module Name: White box testing of sines and cosines.
 * Author: Faisal Javed
 * Date of Creation: 7th October, 2022
 * Purpose: function prototype to print test case result of sine/cosine in a formatted fashion.
    @param passedValue
    @param valueOfSineCosine
    @param expectedValue
    @param result
    @param sineCosine
    @return void
    @post Post Condition - test case result is printed.
 * */
inline void printResult(int &, int &, int &, std::string &, std:: string);