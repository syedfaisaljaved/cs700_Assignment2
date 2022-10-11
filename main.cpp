#include <iostream>
#include "arraySorting.h"
using namespace std;
int main() {
    ArraySorting arraySorting = ArraySorting(100000);
    arraySorting.sortUnsortedArray();
    arraySorting.sortSortedArray();
    arraySorting.reverseSortedArray();
    arraySorting.display();
}
