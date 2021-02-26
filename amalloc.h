//
// Created by 26220 on 2021/2/23.
//

#ifndef MYMALLOC_AMALLOC_H
#define MYMALLOC_AMALLOC_H

#include "heap.h"

mymalloc::Heap heap;

extern "C" void* amalloc(size_t size) {
    return heap.malloc(size);
}

extern "C" void afree(void* ptr) {
    return;
}

#endif //MYMALLOC_AMALLOC_H
