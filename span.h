//
// Created by 26220 on 2021/2/22.
//

#ifndef MYMALLOC_SPAN_H
#define MYMALLOC_SPAN_H

#include "bitmap.h"
#include "consts.h"
#include <sys/mman.h>
#include <map>
#include <vector>

class Span;

class SpanList;

// 重命名, 原格式太复杂
using SpanMap = std::map<bool *, Span *, std::greater<bool *>>;

class Span {
public:
    Span();
    Span(void *sa, int s, int n, int a, int sc, int es);

public:
    void *malloc();

public:
    Span *next;
    Span *prev;

    // 已分配个数
    int allocCount;
    // 总共可分配个数
    int nelems;

    // 对于一个 地址, 可以根据它的地址找到所属的span, 以及对应的位置
    // 但这个结构需要用一个hahstable来存储
    // Span 的起始地址
    void *startAddr;

    // span的size, 单位为byte
    int size;

    // 一个bitmap结构, 表示这个span空闲的位置
    BitMap bitmap;

    // 所属的span的类别id
    int spanClass;

    // 单个元素的大小
    int elemsize;
};


// 一个span的链表, 封装了一些方法
class SpanList {
public:
    SpanList();

    SpanList(int sc);

public:
    Span *newSpan(SpanMap *spanMap);

    void popFront();

    void pushFront(Span *);

    void pushBack(Span *pSpan);

    void pop(Span *pSpan);

public:
    Span *list;
    int spanClass;
};


#endif //MYMALLOC_SPAN_H
