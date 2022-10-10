//
// Created by Faisal Javed on 09/10/22.
//
#include <cstdlib>
#include <ctime>
#include "arraySorting.h"

void ArraySorting::createRandomIntArray() {
    for (int i = 0U; i < NUMBER_OF_ARRAYS; i++) {
        array[i] = new int[SIZE_OF_2D_ARRAY];
        for (int j = 0U; j < SIZE_OF_2D_ARRAY; j++) {
            array[i][j] = rand() % 200 - 100;
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
        clock_t startTime = clock();
        mergeSortArray(array[i], 0, SIZE_OF_2D_ARRAY - 1);
        clock_t endTime = clock();

        double milliseconds = ((endTime - startTime) / CLOCKS_PER_SEC) * 1000.0;

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

void ArraySorting::mergeSubArrays(int subArray[], unsigned int leftIndex, unsigned int middleIndex,
                                  unsigned int rightIndex) {
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

    copyNewArrayIntoOriginalArray(newSubArray, subArray);
}

inline void ArraySorting::copyNewArrayIntoOriginalArray(const int newArray[], int originalArray[]) const {
    for (int iterator = 0U; iterator < SIZE_OF_2D_ARRAY; iterator++) {
        originalArray[iterator] = newArray[iterator];
    }
}

void ArraySorting::sortSortedArray() {
    for (int i = 0U; i < NUMBER_OF_ARRAYS; i++) {
        mergeSortArray(array[i], 0, SIZE_OF_2D_ARRAY - 1);
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

