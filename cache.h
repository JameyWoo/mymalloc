//
// Created by 26220 on 2021/2/22.
//

#ifndef MYMALLOC_CACHE_H
#define MYMALLOC_CACHE_H

#include "mymalloc.h"

class Cache {
public:
    Span alloc[spanClasses];
};


#endif //MYMALLOC_CACHE_H
