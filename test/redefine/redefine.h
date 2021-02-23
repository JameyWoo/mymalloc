//
// Created by 26220 on 2021/2/23.
//

#ifndef MYMALLOC_REDEFINE_H
#define MYMALLOC_REDEFINE_H

#include <cstdio>


extern "C" void* tc_malloc(size_t size) {
    printf("hello");
    return NULL;
}

extern "C" void tc_free(void* ptr) {
    return;
}

#define ALIAS(tc_fn)   __attribute__ ((alias (#tc_fn)))

extern "C" {
void* malloc(size_t size) __THROW               ALIAS(tc_malloc);
void free(void* ptr) __THROW                    ALIAS(tc_free);
}

#endif //MYMALLOC_REDEFINE_H
