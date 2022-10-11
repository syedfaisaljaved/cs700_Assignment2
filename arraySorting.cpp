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
            array[i][j] = rand() % 100 + 1;
        }
    }
}

ArraySorting::ArraySorting(int size) {
    SIZE_OF_2D_ARRAY = size;
    srand(time(0));
    createRandomIntArray();
}

void ArraySorting::sortUnsortedArray() {
    for (int i = 0U; i < NUMBER_OF_ARRAYS; i++) {

        auto startTime = steady_clock::now();

        mergeSortArray(array[i], 0, SIZE_OF_2D_ARRAY - 1);

        auto endTime = steady_clock::now();

        double millisecond = duration_cast<microseconds>(endTime - startTime).count() / 1000.0;

        estimatedTimeForSortingRandomArr[i] = millisecond;
    }
}

void ArraySorting::mergeSortArray(int subArray[], unsigned int leftIndex, unsigned int rightIndex) {
    if (leftIndex >= rightIndex) {
        return;
    }

    unsigned int middleIndex = (leftIndex + rightIndex) / 2;
    mergeSortArray(subArray, leftIndex, middleIndex);
    mergeSortArray(subArray, middleIndex + 1, rightIndex);
    mergeSubArrays(subArray, leftIndex, middleIndex, rightIndex);

}

void ArraySorting::mergeSubArrays(int subArray[], unsigned int &leftIndex, unsigned int &middleIndex,
                                  unsigned int &rightIndex) {
    int newSubArray[SIZE_OF_2D_ARRAY];
    unsigned int startIndexPointer = leftIndex;
    unsigned int endIndexPointer = middleIndex + 1;
    unsigned int newIndexPointer = leftIndex;

    while (startIndexPointer <= middleIndex && endIndexPointer <= rightIndex) {
        if (subArray[startIndexPointer] < subArray[endIndexPointer]) {
            newSubArray[newIndexPointer] = subArray[startIndexPointer];
            startIndexPointer++;
        } else {
            newSubArray[newIndexPointer] = subArray[endIndexPointer];
            endIndexPointer++;
        }
        newIndexPointer++;
    }

    if (startIndexPointer > middleIndex) {
        while (endIndexPointer <= rightIndex) {
            newSubArray[newIndexPointer] = subArray[endIndexPointer];
            endIndexPointer++;
            newIndexPointer++;
        }
    } else {
        while (startIndexPointer <= middleIndex) {
            newSubArray[newIndexPointer] = subArray[startIndexPointer];
            startIndexPointer++;
            newIndexPointer++;
        }
    }

    copyNewArrayIntoOriginalArray(newSubArray, subArray, rightIndex, leftIndex);
}

void ArraySorting::copyNewArrayIntoOriginalArray(const int newArray[], int originalArray[], unsigned int &arrayLength,
                                                 unsigned int index) {
    for (; index < arrayLength; index++) {
        originalArray[index] = newArray[index];
    }
}

void ArraySorting::sortSortedArray() {
    for (int i = 0U; i < NUMBER_OF_ARRAYS; i++) {

        auto startTime = high_resolution_clock::now();

        mergeSortArray(array[i], 0, SIZE_OF_2D_ARRAY - 1);

        auto endTime = high_resolution_clock::now();

        double millisecond = duration_cast<microseconds>(endTime - startTime).count() / 1000.0;

        estimatedTimeForSortingSortedArr[i] = millisecond;
    }
}

void ArraySorting::reverseSortedArray() {
    for (int i = 0U; i < NUMBER_OF_ARRAYS; i++) {

        auto startTime = high_resolution_clock::now();

        for (int j = 0U; j < SIZE_OF_2D_ARRAY / 2; j++) {
            swap(array[i][j], array[i][SIZE_OF_2D_ARRAY - j - 1]);
        }

        auto endTime = high_resolution_clock::now();

        double millisecond = duration_cast<microseconds>(endTime - startTime).count() / 1000.0;

        estimatedTimeForReversingSortedArr[i] = millisecond;
    }
}

void ArraySorting::swap(int &firstValue, int &secondValue) {
    int temp = firstValue;
    firstValue = secondValue;
    secondValue = temp;
}

void ArraySorting::display() {


    printDoubleDivider();
    cout << left << setw(20) << "| Time Test";
    for (int i = 0U; i < NUMBER_OF_ARRAYS; i++) {
        cout << left << setw(12) << "| Array " + to_string(i + 1) + " ";
    }
    cout << left << setw(1) << "|" << endl;

    printDoubleDivider();
    cout << left << setw(20) << "| Random Time (ms)";
    for (double i: estimatedTimeForSortingRandomArr) {
        cout << left << setw(12) << "| " + to_string(i) + " ";
    }
    cout << left << setw(1) << "|" << endl;

    printDivider();
    cout << left << setw(20) << "| Sorted Time (ms)";
    for (double i: estimatedTimeForSortingSortedArr) {
        cout << left << setw(12) << "| " + to_string(i) + " ";
    }
    cout << left << setw(1) << "|" << endl;

    printDivider();
    cout << left << setw(20) << "| Reverse Time (ms)";
    for (double i: estimatedTimeForReversingSortedArr) {
        cout << left << setw(12) << "| " + to_string(i) + " ";
    }
    cout << left << setw(1) << "|" << endl;

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

