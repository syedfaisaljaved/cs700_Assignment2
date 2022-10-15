/*****************************
 * @name Module Name: Execution time for sorting random, sorted and reversed arrays. <br>
 * @author Faisal Javed <br>
 * @date 7th October, 2022 <br>
 * Purpose: CS-700 Assignment 2 <br>
 * Student ID: 200491169 <br>
 ****************************/

/**
  * Code placed here is included only once per translation unit. <br>
  * '#pragma once' is non-standard preprocessor directive intended for implementing compiler-specific preprocessor instructions. <br>
  * It's purpose is to replace the include guards that you use in header files to avoid multiple inclusion. <br>
  * */
#pragma once

/**
 * <br><br> Module Name: Execution time for sorting random, sorted and reversed arrays. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 7th October, 2022 <br>
 * Purpose: Class is a user-defined data type, which holds its own data members and member functions,
 *          which can be accessed and used by creating an instance of that class.
 *          Defining @class ArraySorting which contains variables, methods and constructors.
 *          @var int NUMBER_OF_ARRAYS
 *          @var unsigned int SIZE_OF_2D_ARRAY
 *          @var double estimatedTimeForSortingRandomArr[]
 *          @var double estimatedTimeForSortingSortedArr[]
 *          @var double estimatedTimeForReversingSortedArr[]
 *          @var int ** array
 *          @fn createRandomIntArray
 *          @fn mergeSortArray
 *          @fn mergeSubArrays
 *          @fn copyNewArrayIntoOriginalArray
 *          @fn printDoubleDivider
 *          @fn printDivider
 *          @fn printHeader
 *          @fn printRandomTimeResult
 *          @fn printSortedTimeResult
 *          @fn printReverseTimeResult
 *          @fn printArraySize
 *          @fn sortArray
 *          @fn reverseSortedArray
 *          @fn display
 * */
class ArraySorting {
private:
    /**
     * @brief int variable assigned value 10.
     * */
    static const int NUMBER_OF_ARRAYS = 10;
    /**
     * @brief unsigned int variable declared.
     * */
    unsigned int SIZE_OF_2D_ARRAY;
    /**
     * @brief double array declared
     * */
    double estimatedTimeForSortingRandomArr[NUMBER_OF_ARRAYS]{};
    /**
     * @brief double array declared
     * */
    double estimatedTimeForSortingSortedArr[NUMBER_OF_ARRAYS]{};
    /**
     * @brief double array declared
     * */
    double estimatedTimeForReversingSortedArr[NUMBER_OF_ARRAYS]{};
    /**
     * @brief 2D int ** array.
     * In a two dimensional array, we can access each element by using two subscripts,
     * where first subscript represents the row number and second subscript represents the column number.
     * @c int ** array point to a @c int * array which holds a pointer to an @c int value for each element.
     * */
    int **array = new int * [NUMBER_OF_ARRAYS];
    /**
     * @brief method taking no param
     * */
    void createRandomIntArray();
    /**
     * @brief method taking taking 3 params
     * */
    void mergeSortArray(int [], unsigned int, unsigned int);
    /**
     * @brief method taking taking 4 params
     * */
    void mergeSubArrays(int [], unsigned int &, unsigned int &, unsigned int &);
    /**
     * @brief method taking taking 4 params
     * */
    void copyNewArrayIntoOriginalArray(const int [], int [], unsigned int , unsigned int);
    /**
     * @brief method taking taking 2 params
     * */
    void swap(int &, int &);
    /**
     * @brief method taking no param
     * */
    inline void printDoubleDivider();
    /**
     * @brief method taking no param
     * */
    inline void printDivider();
    /**
     * @brief method taking no param
     * */
    inline void printHeader();
    /**
     * @brief method taking no param
     * */
    inline void printRandomTimeResult();
    /**
     * @brief method taking no param
     * */
    inline void printSortedTimeResult();
    /**
     * @brief method taking no param
     * */
    inline void printReverseTimeResult();
    /**
     * @brief method taking no param
     * */
    inline void printArraySize() const;
    /**
     * @brief method taking no param
     * */
    void sortArray(double timeArray[]);
    /**
     * @brief method taking no param
     * */
    void reverseSortedArray();

public:
    /**
     * @brief explicit Constructor taking 1 param
     * @param [in] int
     * @return [out] void
     * @pre Pre Condition - an integer is passed
     * @post Post Condition - various operations are performed on a array of size N.
     * */
    explicit ArraySorting(int);
    /**
     * @brief method taking no param
     * */
    void display();
};
