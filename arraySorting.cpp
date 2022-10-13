//
// Created by Faisal Javed on 09/10/22.
//
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <iomanip>
#include "arraySorting.h"

using namespace std;
using namespace std::chrono;

void ArraySorting::createRandomIntArray() {
    for (int i = 0U; i < NUMBER_OF_ARRAYS; i++) {
        array[i] = new int[SIZE_OF_2D_ARRAY];
        for (int j = 0U; j < SIZE_OF_2D_ARRAY; j++) {
            array[i][j] = rand() % SIZE_OF_2D_ARRAY + 1;
        }
    }
}

ArraySorting::ArraySorting(int size) {
    SIZE_OF_2D_ARRAY = size;
    srand(time(0));
    createRandomIntArray();
    sortArray(estimatedTimeForSortingRandomArr);
    sortArray(estimatedTimeForSortingSortedArr);
    reverseSortedArray();
    sortArray(estimatedTimeForReversingSortedArr);
}


void ArraySorting::mergeSortArray(int subArray[], unsigned int leftIndex, unsigned int rightIndex) {
    if (leftIndex >= rightIndex) {
        return;
    }

    unsigned int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;
    mergeSortArray(subArray, leftIndex, middleIndex);
    mergeSortArray(subArray, middleIndex + 1, rightIndex);
    mergeSubArrays(subArray, leftIndex, middleIndex, rightIndex);

}

void ArraySorting::mergeSubArrays(int subArray[], unsigned int &leftIndex, unsigned int &middleIndex,
                                  unsigned int &rightIndex) {
    int *newSubArray = new int[rightIndex - leftIndex + 1];
    unsigned int startIndexPointer = leftIndex;
    unsigned int endIndexPointer = middleIndex + 1;
    unsigned int newIndexPointer = 0;

    while (startIndexPointer <= middleIndex && endIndexPointer <= rightIndex) {
        if (subArray[startIndexPointer] <= subArray[endIndexPointer]) {
            newSubArray[newIndexPointer] = subArray[startIndexPointer];
            startIndexPointer++;
        } else {
            newSubArray[newIndexPointer] = subArray[endIndexPointer];
            endIndexPointer++;
        }
        newIndexPointer++;
    }


    while (startIndexPointer <= middleIndex) {
        newSubArray[newIndexPointer] = subArray[startIndexPointer];
        startIndexPointer++;
        newIndexPointer++;
    }

    while (endIndexPointer <= rightIndex) {
        newSubArray[newIndexPointer] = subArray[endIndexPointer];
        endIndexPointer++;
        newIndexPointer++;
    }

    copyNewArrayIntoOriginalArray(newSubArray, subArray, rightIndex - leftIndex + 1, leftIndex);

    delete[] newSubArray;
}

void ArraySorting::copyNewArrayIntoOriginalArray(const int newArray[], int originalArray[], unsigned int arrayLength,
                                                 unsigned int index) {
    for (int i = 0; i < arrayLength; index++, i++) {
        originalArray[index] = newArray[i];
    }
}

void ArraySorting::sortArray(double timeArray[]) {
    for (int i = 0U; i < NUMBER_OF_ARRAYS; i++) {

        auto startTime = steady_clock::now();

        mergeSortArray(array[i], 0, SIZE_OF_2D_ARRAY - 1);

        auto endTime = steady_clock::now();

        double millisecond = duration_cast<microseconds>(endTime - startTime).count() / 1000.0;

        timeArray[i] = millisecond;
    }
}

void ArraySorting::reverseSortedArray() {
    for (int i = 0U; i < NUMBER_OF_ARRAYS; i++) {

        for (int j = 0U; j < SIZE_OF_2D_ARRAY / 2; j++) {
            swap(array[i][j], array[i][SIZE_OF_2D_ARRAY - j - 1]);
        }

    }
}

void ArraySorting::swap(int &firstValue, int &secondValue) {
    int temp = firstValue;
    firstValue = secondValue;
    secondValue = temp;
}

void ArraySorting::display() {

    printArraySize();

    printDoubleDivider();

    printHeader();

    printDoubleDivider();

    printRandomTimeResult();

    printDivider();

    printSortedTimeResult();

    printDivider();

    printReverseTimeResult();

    printDoubleDivider();
}

inline void ArraySorting::printDoubleDivider() {
    cout
            << "============================================================================================================================================="
            << endl;
}

inline void ArraySorting::printDivider() {
    cout
            << "---------------------------------------------------------------------------------------------------------------------------------------------"
            << endl;
}

inline void ArraySorting::printHeader() {
    cout << left << setw(20) << "| Time Test";
    for (int i = 0U; i < NUMBER_OF_ARRAYS; i++) {
        cout << left << setw(12) << "| Array " + to_string(i + 1) + " ";
    }
    cout << left << setw(1) << "|" << endl;
}

inline void ArraySorting::printRandomTimeResult() {
    cout << left << setw(20) << "| Random Time (ms)";
    for (double i: estimatedTimeForSortingRandomArr) {
        cout << left << setw(2) << "| " << setw(10) << setprecision(6) << i;
    }
    cout << left << setw(1) << "|" << endl;
}

inline void ArraySorting::printSortedTimeResult() {
    cout << left << setw(20) << "| Sorted Time (ms)";
    for (double i: estimatedTimeForSortingSortedArr) {
        cout << left << setw(2) << "| " << setw(10) << setprecision(6) << i;
    }
    cout << left << setw(1) << "|" << endl;
}

inline void ArraySorting::printReverseTimeResult() {
    cout << left << setw(20) << "| Reverse Time (ms)";
    for (double i: estimatedTimeForReversingSortedArr) {
        cout << left << setw(2) << "| " << setw(10) << setprecision(6) << i;
    }
    cout << left << setw(1) << "|" << endl;
}

inline void ArraySorting::printArraySize() {
    cout << endl << "For array size: " << SIZE_OF_2D_ARRAY << endl << endl;
}

