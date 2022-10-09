//
// Created by Faisal Javed on 09/10/22.
//

#pragma once
#include <ctime>

class ArraySorting {
private:
    const int NUMBER_OF_ARRAYS = 10;
    unsigned int SIZE_OF_2D_ARRAY;
    clock_t startTime{};
    clock_t endTIme{};
    int **array = new int * [NUMBER_OF_ARRAYS];
    void createRandomIntArray();


public:
    explicit ArraySorting(int);

    void sortUnsortedArray();
    void sortSortedArray();
    void inverseSortedArray();
    void mergeSortArray(int [], unsigned int, unsigned int);
};
