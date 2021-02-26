#include <iostream>
#include "heap.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    mymalloc::Heap mc;

    cout << "sizeof(int) = " << sizeof(int) << endl;

    bool *x = (bool *) mc.malloc(sizeof(int));
    *x = 8;

    cout << x << endl;
    cout << *x << endl;

    bool *y = (bool *) mc.malloc(sizeof(int));
    *y = 9;
    cout << y << endl;
    cout << *y << endl;

    for (int i = 0; i < 10; i++) {
        cout << (bool *) mc.malloc(8 + i) << endl;
    }

    return 0;
}
