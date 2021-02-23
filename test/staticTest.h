//
// Created by 26220 on 2021/2/23.
//

#ifndef MYMALLOC_STATICTEST_H
#define MYMALLOC_STATICTEST_H

#include "../mymalloc.h"

mymalloc::Heap heap;

extern "C" void* tc_malloc(size_t size) {
//    printf("hello");
    return heap.malloc(size);
}

extern "C" void tc_free(void* ptr) {
    heap.free(ptr);
    return;
}

#define ALIAS(tc_fn)   __attribute__ ((alias (#tc_fn)))

extern "C" {
void* amalloc(size_t size) __THROW               ALIAS(tc_malloc);
void afree(void* ptr) __THROW                    ALIAS(tc_free);
}

#endif //MYMALLOC_STATICTEST_H
