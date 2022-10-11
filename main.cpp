#include <iostream>
#include "arraySorting.h"
using namespace std;
int main() {
    ArraySorting arraySorting1 = ArraySorting(100000);
    arraySorting1.display();

    ArraySorting arraySorting2 = ArraySorting(1000000);
    arraySorting2.display();

    ArraySorting arraySorting3 = ArraySorting(10000000);
    arraySorting3.display();
    return 0;
}
