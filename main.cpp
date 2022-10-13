#include <iostream>
#include "arraySorting.h"
#include "sin_cos.h"

using namespace std;

void arraySortingModule(){
    ArraySorting arraySorting1 = ArraySorting(100000);
    arraySorting1.display();

    ArraySorting arraySorting2 = ArraySorting(1000000);
    arraySorting2.display();

    ArraySorting arraySorting3 = ArraySorting(10000000);
    arraySorting3.display();
}

int main() {
    arraySortingModule();
//    whiteBoxTesting();
    return 0;
}
