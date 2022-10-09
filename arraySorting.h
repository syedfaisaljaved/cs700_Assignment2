//
// Created by Faisal Javed on 09/10/22.
//

#pragma once
#include <ctime>

class ArraySorting {
private:
    int SIZE;
    clock_t startTime;
    clock_t endTIme;
    int array[];
    void createRandomIntArray();


public:
    ArraySorting();
    explicit ArraySorting(int);

    void sortUnsortedArray();
    void inverseSortedArray();
};
