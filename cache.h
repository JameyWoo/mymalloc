//
// Created by 26220 on 2021/2/22.
//

#ifndef MYMALLOC_CACHE_H
#define MYMALLOC_CACHE_H

#include "consts.h"
#include "span.h"
#include "central.h"

#include <thread>
#include <map>
#include <mutex>


class Cache;
using CacheMap = std::map<std::thread::id, Cache*>;

class Cache {
public:
    Cache();
    Cache(Central[spanClasses], SpanMap*);

public:
    void* malloc(int);

public:
    SpanList alloc[spanClasses];
    Central ctl[spanClasses];  // 一个指向 Heap对象的指针, 在使用它的时候需要动态地转化
    SpanMap * spanMap;

private:
    std::mutex mtx;
};


#endif //MYMALLOC_CACHE_H
