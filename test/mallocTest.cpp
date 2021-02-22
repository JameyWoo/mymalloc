#include <iostream>
#include "../mymalloc.h"

using namespace std;

int main() {
    mymalloc::Heap mc;
    cout << mc.malloc(100000) << endl;
    cout << mc.malloc(100000) << endl;
//    mc.malloc(0);
    for (int i = 0; i < 1025; i++) {
        cout << "size = " << i + 1 << ": " << mc.malloc(8) << endl;
    }
    cout << "end" << endl;
}