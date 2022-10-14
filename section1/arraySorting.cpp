/*****************************
 * @name Module Name: Sorting array and calculating the random time, sorted time and reverse time.
 * @author Faisal Javed
 * @date 7th October, 2022
 * Purpose: CS-700 Assignment 2
 * Student ID: 200491169
 ****************************/

#include <iostream> /// library that controls reading from and writing to the standard streams.
#include <chrono> /// A framework that relates a time point to real physical time. The library provides at least three clocks that provide means to express the current time.
#include <cstdlib> /// library that offers reliable and efficient functions for dynamic memory allocation, conversion between datatypes, pseudo-random number generation, process control, searching and sorting, math, and multibyte or wide characters.
#include <iomanip> /// library which helps us in manipulating the output of the program.
#include "arraySorting.h" /// user-defined header @file arraySorting.h to propagate declarations to code file.

/**
 * 'namespace' is used to organise the names of program entities.
 * The below statement declares that program will be accessing entities whose name are the part of namespace called std.
 * */
using namespace std;
/**
 * 'namespace' is used to organise the names of program entities.
 * The below statement declares that program will be accessing entities whose name are the part of namespace called std::chrono.
 * */
using namespace std::chrono;

/**
 * Module Name: Sorting array and calculating the random time, sorted time and reverse time.
 * Author: Faisal Javed
 * Date of Creation: 7th October, 2022
 * Purpose: Method to fill the array with random positive integers between 1-SIZE OF 2D ARRAY.
 *         @param [in,out] void
 *         @return [out] void
 *         @post Post Condition - a 2D int pointer array is initialized with random values.
 * */
void ArraySorting::createRandomIntArray() {
    /// using for loop to iterate through each array
    /// U as a suffix to 0 means only unsigned values
    for (int i = 0U; i < NUMBER_OF_ARRAYS; i++) {
        array[i] = new int[SIZE_OF_2D_ARRAY]; /// creating an array of integers of size @a ArraySorting::SIZE_OF_2D_ARRAY
        /// U as a suffix to 0 means only unsigned values
        for (int j = 0U; j < SIZE_OF_2D_ARRAY; j++) {
            array[i][j] = rand() % SIZE_OF_2D_ARRAY + 1; /// using rand() function to generate a random value from 1 to SIZE_OF_2D_ARRAY and assigning to the array
        }
    }
}

/**
 * Module Name: Sorting array and calculating the random time, sorted time and reverse time.
 * Author: Faisal Javed
 * Date of Creation: 7th October, 2022
 * Purpose: Explicit Constructor to create an object of @class ArraySorting
 *         @param [in] int
 *         @return [out] void
 *         @pre Pre Condition - an integer is passed
 *         @post Post Condition - various operations are performed on a array of size N.
 * */
ArraySorting::ArraySorting(int size) {
    SIZE_OF_2D_ARRAY = size; /// variable @var SIZE_OF_2D_ARRAY is initialized value passed in the constructor.
    /**
     * /// The pseudo-random number generator is initialized using the argument passed as seed.
     * For every different seed value used in a call to srand, the pseudo-random number generator can be expected to generate
     * a different succession of results in the subsequent calls to rand.
     * passed time(0) function that returns the current time in seconds.
     * */
    srand(time(0));
    createRandomIntArray(); /// function call to create an array with random numbers.
    sortArray(estimatedTimeForSortingRandomArr); /// function call to sort the array and calculate the execution time for sorting random array.
    sortArray(estimatedTimeForSortingSortedArr); /// function call to sort the array and calculate the execution time for sorting sorted array.
    reverseSortedArray(); /// function call to reverse the array.
    sortArray(estimatedTimeForReversingSortedArr); /// function call to sort the array and calculate the execution time for sorting reversed array.
}

/**
 * Module Name: Sorting array and calculating the random time, sorted time and reverse time.
 * Author: Faisal Javed
 * Date of Creation: 7th October, 2022
 * Purpose: Method to sort array using merge sort algorithm.
 * The Merge Sort algorithm is a sorting algorithm that is based on the Divide and Conquer paradigm.
 *         @param [in] subArray
 *         @param [in] leftIndex
 *         @param [in] rightIndex
 *         @return [out] void
 *         @pre Pre Condition - an array, and 2 unsigned int values are passed
 *         @post Post Condition - recursion is used to sort array
 * */
void ArraySorting::mergeSortArray(int subArray[], unsigned int leftIndex, unsigned int rightIndex) {

    /**
     * if the left index is greater or equal to the right index then return,
     * it means the all elements of array is traversed.
     * */
    if (leftIndex >= rightIndex) { /// @if
        return;
    } /// @endif

    /**
     * assign value to @c middleIndex by subtracting @c leftIndex from @c rightIndex then dividing by 2 and then adding it to @c leftIndex.
     * */
    unsigned int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;
    /**
     * recursion call to @a ArraySorting::mergeSortArray
     * takes @c array, @c leftIndex, and @c middleIndex as arguments.
     * */
    mergeSortArray(subArray, leftIndex, middleIndex);
    /**
     * recursion call to @a ArraySorting::mergeSortArray
     * takes @c array, @c middleIndex+1, and @c rightIndex as arguments.
     * */
    mergeSortArray(subArray, middleIndex + 1, rightIndex);
    /**
     * function @a ArraySorting::mergeSubArrays called to merge the sorted arrays
     * takes @c array, @c leftIndex, @c middleIndex and @c rightIndex as arguments.
     * */
    mergeSubArrays(subArray, leftIndex, middleIndex, rightIndex);

}

/**
 * Module Name: Sorting array and calculating the random time, sorted time and reverse time.
 * Author: Faisal Javed
 * Date of Creation: 7th October, 2022
 * Purpose: Method to merge the sorted arrays.
 *         @param [in] subArray
 *         @param [in] leftIndex
 *         @param [in] middleIndex
 *         @param [in] rightIndex
 *         @return [out] void
 *         @pre Pre Condition - an array, and 3 unsigned int values are passed
 * */
void ArraySorting::mergeSubArrays(int subArray[], unsigned int &leftIndex, unsigned int &middleIndex,
                                  unsigned int &rightIndex) {

    /**
     * Initializing an @c int pointer array.
     * @c int * array holds a pointer to an @c int value for each element.
     * */
    int *newSubArray = new int[rightIndex - leftIndex + 1];

    unsigned int startIndexPointer = leftIndex; /// assigning @c leftIndex value to an unsigned int @c startIndexPointer variable.
    unsigned int endIndexPointer = middleIndex + 1; /// assigning @c middleIndex+1 value to an unsigned int @c endIndexPointer variable.
    unsigned int newIndexPointer = 0; /// assigning 0 to @c newIndexPointer variable.

    /**
     * using while loop to insert value of old array to new array in sorted manner,
     * until @c startIndexPointer is less than or equal to @c middleIndex and
     * @c endIndexPointer is also less than and equal to @c rightIndex.
     * */
    while (startIndexPointer <= middleIndex && endIndexPointer <= rightIndex) {

        /// if the element at startIndex is less than or equal to the element at endIndex
        if (subArray[startIndexPointer] <= subArray[endIndexPointer]) { /// @if
            newSubArray[newIndexPointer] = subArray[startIndexPointer]; /// assign value of old array at startIndex to new array.
            startIndexPointer++; /// increment @c startIndexPointer
        } else {
            newSubArray[newIndexPointer] = subArray[endIndexPointer]; /// else assigning value of old array at endIndex to new array.
            endIndexPointer++; /// increment @c endIndexPointer
        } /// @endif
        newIndexPointer++;  /// increment @c newIndexPointer
    }

    /**
     * using while loop to insert value of old array to new array in sorted manner,
     * until @c startIndexPointer is less than or equal to @c middleIndex
     * which indicates the array is not completely inserted to the new array
     * */
    while (startIndexPointer <= middleIndex) {
        newSubArray[newIndexPointer] = subArray[startIndexPointer]; /// assign value of old array at startIndex to new array.
        startIndexPointer++; /// increment @c startIndexPointer
        newIndexPointer++; /// increment @c newIndexPointer
    }

    /**
     * using while loop to insert value of old array to new array in sorted manner,
     * until @c endIndexPointer is less than or equal to @c rightIndex
     * which indicates the array is not completely inserted to the new array
     * */
    while (endIndexPointer <= rightIndex) {
        newSubArray[newIndexPointer] = subArray[endIndexPointer]; /// assign value of old array at endIndex to new array.
        endIndexPointer++; /// increment @c endIndexPointer
        newIndexPointer++; /// increment @c newIndexPointer
    }

    /**
     * function @a ArraySorting::copyNewArrayIntoOriginalArray is called to copy the values of new array into the old array.
     * takes @c newSubArray, @c subArray, @c rightIndex - leftIndex + 1, and @c leftIndex as arguments.
     * */
    copyNewArrayIntoOriginalArray(newSubArray, subArray, rightIndex - leftIndex + 1, leftIndex);

    delete[] newSubArray; /// deleting the new array after the content of it is copied to the old array. freeing up memory space.
}

/**
 * Module Name: Sorting array and calculating the random time, sorted time and reverse time.
 * Author: Faisal Javed
 * Date of Creation: 7th October, 2022
 * Purpose: Method to copy the values of an array to another array
 *         @param [in] newArray
 *         @param [in] originalArray
 *         @param [in] arrayLength
 *         @param [in] index
 *         @return [out] void
 *         @pre Pre Condition - 2 arrays, and 2 unsigned int values are passed
 *         @post Post Condition - array is copied to another array.
 * */
void ArraySorting::copyNewArrayIntoOriginalArray(const int newArray[], int originalArray[], unsigned int arrayLength,
                                                 unsigned int index) {
    for (int i = 0; i < arrayLength; index++, i++) {
        originalArray[index] = newArray[i];
    }
}

/**
 * Module Name: Sorting array and calculating the random time, sorted time and reverse time.
 * Author: Faisal Javed
 * Date of Creation: 7th October, 2022
 * Purpose: Method to sort the array by calling merge sort algorithm and
 * calculating the execution time for sorting the array.
 *         @param [in] timeArray
 *         @return [out] void
 *         @pre Pre Condition - an array is passed
 *         @post Post Condition - execution time for each array is stored in an array
 * */
void ArraySorting::sortArray(double timeArray[]) {
    /** using for loop to iterate thorugh each array and
     * calculate the execution time.
     * U as a suffix to 0 means only unsigned values
     * */
    for (int i = 0U; i < NUMBER_OF_ARRAYS; i++) {

        auto startTime = steady_clock::now(); /// storing the time point representing the current time in @c startTime variable.

        mergeSortArray(array[i], 0, SIZE_OF_2D_ARRAY - 1); /// calling function @a ArraySorting::mergeSortArray to sort the array using merge sort.

        auto endTime = steady_clock::now(); /// storing the time point representing the current time in @c endTime variable.

        timeArray[i] = duration_cast<microseconds>(endTime - startTime).count() / 1000.0; /// calculating the elapsed time in millisecond from startTime and endTime.

    }
}

/**
 * Module Name: Sorting array and calculating the random time, sorted time and reverse time.
 * Author: Faisal Javed
 * Date of Creation: 7th October, 2022
 * Purpose: Method to reverse the an array.
 *         @param [in] void
 *         @return [out] void
 *         @post Post Condition - array is reversed
 * */
void ArraySorting::reverseSortedArray() {
    /**
     * using 2 for loops to iterate through each array
     * and swap the values to reverse the array
     * U as a suffix to 0 means only unsigned values
     * */
    for (int i = 0U; i < NUMBER_OF_ARRAYS; i++) {
        /// U as a suffix to 0 means only unsigned values
        for (int j = 0U; j < SIZE_OF_2D_ARRAY / 2; j++) {
            swap(array[i][j], array[i][SIZE_OF_2D_ARRAY - j - 1]); /// calling function @a ArraySorting::swap to swap values of 2 integers.
        }
    }
}

/**
 * Module Name: Sorting array and calculating the random time, sorted time and reverse time.
 * Author: Faisal Javed
 * Date of Creation: 7th October, 2022
 * Purpose: Method to swap the values.
 *         @param [in] void
 *         @return [out] void
 *         @pre Pre Condition - 2 int are passed.
 *         @post Post Condition - values are swapped.
 * */
void ArraySorting::swap(int &firstValue, int &secondValue) {
    int temp = firstValue; /// using a temporary variable to store the first value.
    firstValue = secondValue; /// assigning the value of 2nd variable to first variable.
    secondValue = temp; /// assigning the value of first variable stored in a temporary variable to the 2nd variable.
}

/**
 * Module Name: Sorting array and calculating the random time, sorted time and reverse time.
 * Author: Faisal Javed
 * Date of Creation: 7th October, 2022
 * Purpose: Method to display a table of execution time of each array for random, sorted and reverse time in a well formatted fashion.
 *         @param [in] void
 *         @return [out] void
 *         @post Post Condition - a table is printed to the console.
 * */
void ArraySorting::display() {

    printArraySize(); /// calling this function @a ArraySorting::printArraySize to print the array size taken.

    printDoubleDivider(); /// calling this function @a ArraySorting::printDoubleDivider to print a divider line.

    printHeader(); /// calling this function @a ArraySorting::printHeader to print the header of the table.

    printDoubleDivider(); /// calling this function @a ArraySorting::printDoubleDivider to print a divider line.

    printRandomTimeResult(); /// calling this function @a ArraySorting::printRandomTimeResult to print the random time results for each array.

    printDivider(); /// calling this function @a ArraySorting::printDivider to print a divider line.

    printSortedTimeResult(); /// calling this function @a ArraySorting::printSortedTimeResult to print the sorted time results for each array.

    printDivider(); /// calling this function @a ArraySorting::printDivider to print a divider line.

    printReverseTimeResult(); /// calling this function @a ArraySorting::printReverseTimeResult to print the reverse time results for each array.

    printDoubleDivider(); /// calling this function @a ArraySorting::printDoubleDivider to print a divider line.
}

/**
 * Module Name: Sorting array and calculating the random time, sorted time and reverse time.
 * Author: Faisal Javed
 * Date of Creation: 7th October, 2022
 * Purpose: inline Method to print a divider line.
 *         @param [in] void
 *         @return [out] void
 *         @post Post Condition - a line is printed to the console.
 * */
inline void ArraySorting::printDoubleDivider() {
    /// printing = to the console.
    /// using @c endl to go to next line.
    cout
            << "============================================================================================================================================="
            << endl;
}

/**
 * Module Name: Sorting array and calculating the random time, sorted time and reverse time.
 * Author: Faisal Javed
 * Date of Creation: 7th October, 2022
 * Purpose: inline Method to print a divider line.
 *         @param [in] void
 *         @return [out] void
 *         @post Post Condition - a line is printed to the console.
 * */
inline void ArraySorting::printDivider() {
    /// printing - to the console.
    /// using @c endl to go to next line.
    cout
            << "---------------------------------------------------------------------------------------------------------------------------------------------"
            << endl;
}

/**
 * Module Name: Sorting array and calculating the random time, sorted time and reverse time.
 * Author: Faisal Javed
 * Date of Creation: 7th October, 2022
 * Purpose: inline Method to print a table header.
 *         @param [in] void
 *         @return [out] void
 *         @post Post Condition - a table header is printed to the console.
 * */
inline void ArraySorting::printHeader() {
    /**
     * using @c left keyword to left-align the data.
     * using @c setw to have a well-formatted output with spacing of the specified width.
     * using pipe '|' to separate columns.
     * */
    cout << left << setw(20) << "| Time Test";

    /// this loops will run until i is equal to length of @a ArraySorting::NUMBER_OF_ARRAYS
    /// U as a suffix to 0 means only unsigned values
    for (int i = 0U; i < NUMBER_OF_ARRAYS; i++) {
        /**
         * using @c left keyword to left-align the data.
         * using @c setw to have a well-formatted output with spacing of the specified width.
         * using to_string() to convert a non string value to string such as int, float, double and char
         * */
        cout << left << setw(12) << "| Array " + to_string(i + 1) + " ";
    }
    /**
     * using @c left keyword to left-align the data.
     * using @c setw to have a well-formatted output with spacing of the specified width.
     * using pipe '|' to separate columns.
     * using @c endl to go to next line.
     * */
    cout << left << setw(1) << "|" << endl;
}

/**
 * Module Name: Sorting array and calculating the random time, sorted time and reverse time.
 * Author: Faisal Javed
 * Date of Creation: 7th October, 2022
 * Purpose: inline Method to print execution time for random array sorting.
 *         @param [in] void
 *         @return [out] void
 *         @post Post Condition - values printed to the console.
 * */
inline void ArraySorting::printRandomTimeResult() {
    /**
     * using @c left keyword to left-align the data.
     * using @c setw to have a well-formatted output with spacing of the specified width.
     * using pipe '|' to separate columns.
     * */
    cout << left << setw(20) << "| Random Time (ms)";

    /// using range based for loop to iterate through the array ArraySorting::estimatedTimeForSortingRandomArr
    for (double i: estimatedTimeForSortingRandomArr) {
        /**
         * using @c left keyword to left-align the data.
         * using @c setw to have a well-formatted output with spacing of the specified width.
         * using @c setprecision = 6 to set the decimal values upto 5 digits.
         * using pipe '|' to separate columns.
         * */
        cout << left << setw(2) << "| " << setw(10) << setprecision(6) << i;
    }
    /**
     * using @c left keyword to left-align the data.
     * using @c setw to have a well-formatted output with spacing of the specified width.
     * using pipe '|' to separate columns.
     * using @c endl to go to next line.
     * */
    cout << left << setw(1) << "|" << endl;
}

/**
 * Module Name: Sorting array and calculating the random time, sorted time and reverse time.
 * Author: Faisal Javed
 * Date of Creation: 7th October, 2022
 * Purpose: inline Method to print execution time for sorted array sorting.
 *         @param [in] void
 *         @return [out] void
 *         @post Post Condition - values printed to the console.
 * */
inline void ArraySorting::printSortedTimeResult() {
    /**
     * using @c left keyword to left-align the data.
     * using @c setw to have a well-formatted output with spacing of the specified width.
     * using pipe '|' to separate columns.
     * */
    cout << left << setw(20) << "| Sorted Time (ms)";

    /// using range based for loop to iterate through the array ArraySorting::estimatedTimeForSortingSortedArr
    for (double i: estimatedTimeForSortingSortedArr) {
        /**
         * using @c left keyword to left-align the data.
         * using @c setw to have a well-formatted output with spacing of the specified width.
         * using @c setprecision = 6 to set the decimal values upto 5 digits.
         * using pipe '|' to separate columns.
         * */
        cout << left << setw(2) << "| " << setw(10) << setprecision(6) << i;
    }

    /**
     * using @c left keyword to left-align the data.
     * using @c setw to have a well-formatted output with spacing of the specified width.
     * using pipe '|' to separate columns.
     * using @c endl to go to next line.
     * */
    cout << left << setw(1) << "|" << endl;
}

/**
 * Module Name: Sorting array and calculating the random time, sorted time and reverse time.
 * Author: Faisal Javed
 * Date of Creation: 7th October, 2022
 * Purpose: inline Method to print execution time for reversed array sorting.
 *         @param [in] void
 *         @return [out] void
 *         @post Post Condition - values printed to the console.
 * */
inline void ArraySorting::printReverseTimeResult() {
    /**
     * using @c left keyword to left-align the data.
     * using @c setw to have a well-formatted output with spacing of the specified width.
     * using pipe '|' to separate columns.
     * */
    cout << left << setw(20) << "| Reverse Time (ms)";

    /// using range based for loop to iterate through the array ArraySorting::estimatedTimeForReversingSortedArr
    for (double i: estimatedTimeForReversingSortedArr) {
        /**
         * using @c left keyword to left-align the data.
         * using @c setw to have a well-formatted output with spacing of the specified width.
         * using @c setprecision = 6 to set the decimal values upto 5 digits.
         * using pipe '|' to separate columns.
         * */
        cout << left << setw(2) << "| " << setw(10) << setprecision(6) << i;
    }

    /**
     * using @c left keyword to left-align the data.
     * using @c setw to have a well-formatted output with spacing of the specified width.
     * using pipe '|' to separate columns.
     * using @c endl to go to next line.
     * */
    cout << left << setw(1) << "|" << endl;
}

/**
 * Module Name: Sorting array and calculating the random time, sorted time and reverse time.
 * Author: Faisal Javed
 * Date of Creation: 7th October, 2022
 * Purpose: inline Method to print array size.
 *         @param [in] void
 *         @return [out] void
 *         @post Post Condition - array size is printed to the console.
 * */
inline void ArraySorting::printArraySize() const {
    /// printing array size to the console. using @c endl to go to next line.
    cout << endl << "For array size: " << SIZE_OF_2D_ARRAY << endl << endl;
}

