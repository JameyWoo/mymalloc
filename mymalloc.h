//
// Created by 26220 on 2021/2/21.
//

#ifndef MYMALLOC_MYMALLOC_H
#define MYMALLOC_MYMALLOC_H

#include <algorithm>
#include <iostream>
#include <map>
#include <thread>

#include "consts.h"
#include "span.h"
#include "central.h"
#include "cache.h"

extern const int spanClasses;
extern const int spanInfo[spanClasses][4];

namespace mymalloc {
    // 代表所有分配空间的结构.
    class Heap {
        // 构造函数
    public:
        Heap();

        // 外部接口
    public:
        void *malloc(int);

        void free(void *);

        // 内部接口
    private:
        void *bigObjectMalloc(int);

        // 成员变量
    public:
        SpanMap spanMap;
        CacheMap cacheMap;

    private:
        Central ctls[spanClasses];  // 每一种span对应一个Central
    };
}

#endif  //MYMALLOC_MYMALLOC_H
