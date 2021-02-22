#include <iostream>
#include <thread>
#include <unistd.h>

#include "../mymalloc.h"

using namespace std;

void mallocTest() {
    for (int i = 0; i < 10; i++) {
        thread([](){
            cout << this_thread::get_id() << endl;
           sleep(3);
        }).detach();
    }
    sleep(5);
}

int main() {
    mallocTest();
}