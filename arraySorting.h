//
// Created by Faisal Javed on 09/10/22.
//

#pragma once

class ArraySorting {
private:
    static const int NUMBER_OF_ARRAYS = 10;
    unsigned int SIZE_OF_2D_ARRAY;
    double estimatedTimeForSortingRandomArr[NUMBER_OF_ARRAYS];
    double estimatedTimeForSortingSortedArr[NUMBER_OF_ARRAYS];
    double estimatedTimeForReversingSortedArr[NUMBER_OF_ARRAYS];
    int **array = new int * [NUMBER_OF_ARRAYS];
    void createRandomIntArray();
    void mergeSortArray(int [], unsigned int, unsigned int);
    void mergeSubArrays(int [], unsigned int, unsigned int, unsigned int);
    inline void copyNewArrayIntoOriginalArray(const int [], int []) const;
    void swap(int &, int &);

public:
    explicit ArraySorting(int);
    void sortUnsortedArray();
    void sortSortedArray();
    void reverseSortedArray();
};
