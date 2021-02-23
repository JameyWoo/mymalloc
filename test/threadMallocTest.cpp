#include <iostream>
#include <thread>
#include <unistd.h>

#include "../mymalloc.h"

using namespace std;

void mallocTest() {
    mymalloc::Heap mc;
    for (int i = 0; i < 3; i++) {
        thread([&mc, t=i](){
            cout << this_thread::get_id() << ": ";
            auto x = mc.malloc(10);
            cout << x << endl;
            for (int j = 0; j < 3; j++) {
                cout << mc.malloc(8) << endl;
            }
           sleep(t);
        }).detach();
    }
    sleep(5);

    sleep(3);
}

int main() {
    mallocTest();
}