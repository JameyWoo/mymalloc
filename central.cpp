//
// Created by 26220 on 2021/2/22.
//

#include "central.h"


Central::Central() {

}

Central::Central(int sc) : spanClass(sc), nonempty(SpanList(sc)), empty(SpanList(sc)) {
    nmalloc = 0;
}

/*
 * 首先判断nonempty中是否有 span, 如果有那么
 *   从 nonempty 中取出一个 有空闲空间的span, 然后分配空间, 之后判断它是否还有空间
 *   如果没有空间了那么将其移入 empty列表中
 * 如果没有span, 那么调用 mmap进行内存映射分配
 */
Span *Central::malloc(SpanMap *spanMap) {
    // 获取一个span, 每次获取链表头部的span
    auto span = nonempty.newSpan(spanMap);  // 如果nonempty没有span, 则调用mmap分配

    return span;

    // 让这个 span 分配一个空间, 并且设置自己的状态.
//    void *addr = span->malloc();
//    if (span->allocCount == span->nelems) {  // 已经分配满了
//        nonempty.popFront();      // pop链表头部的span
//        empty.pushFront(span);   // 将span插入到首部
//    }
//    nmalloc++;
//    return addr;
}
