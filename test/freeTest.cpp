#include <iostream>
#include <unistd.h>

#include "../heap.h"

using namespace std;

void freeSmallTest() {
    mymalloc::Heap mc;
    for (int i = 0; i < 1023; i++) {
        mc.malloc(8);
    }
    auto a = mc.malloc(8);
    mc.free(a);
    auto b = mc.malloc(8);

    mc.malloc(8);

    mc.free(b);
    sleep(1);
}

// 这种大对象free之后, 它的映射的页要回收(munmap), 并且它的 span要从 spanMap中删除
void freeBigTest() {
    mymalloc::Heap mc;
    auto x = mc.malloc(100000);
    mc.free(x);

    sleep(1);
}

int main() {
    freeSmallTest();
    freeBigTest();
}