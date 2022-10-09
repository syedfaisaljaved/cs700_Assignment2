#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main() {
    srand(time(0));
    for(int j = 0; j < 3; j++){
        for(int i =0; i < 100; i++){
            cout << rand() % 200 + (-100) << " ";
        }
        cout << endl;
    }
    return 0;
}
