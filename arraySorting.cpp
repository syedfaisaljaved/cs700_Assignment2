//
// Created by Faisal Javed on 09/10/22.
//
#include <cstdlib>
#include "arraySorting.h"

void ArraySorting::createRandomIntArray() {
    for(int i = 0U; i < NUMBER_OF_ARRAYS; i++){
        array[i] = new int[SIZE_OF_2D_ARRAY];
        for(int j = 0U; j < SIZE_OF_2D_ARRAY; j++){
            array[i][j] = rand() % 200 - 100;
        }
    }
}

ArraySorting::ArraySorting(int size) {
    SIZE_OF_2D_ARRAY = size;
    createRandomIntArray();
}

void ArraySorting::sortUnsortedArray() {
    for(int i = 0U; i < NUMBER_OF_ARRAYS; i++){
        mergeSortArray(array[i], 0, SIZE_OF_2D_ARRAY-1);
    }
}

void ArraySorting::mergeSortArray(int subArray[], unsigned int, unsigned int) {

}

