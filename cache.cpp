//
// Created by 26220 on 2021/2/22.
//

#include "cache.h"

Cache::Cache() {

}

Cache::Cache(Central actl[spanClasses], SpanMap* spanMap): spanMap(spanMap) {
    for (int i = 0; i < spanClasses; i++) {
        this->ctl[i] = actl[i];
        alloc[i] = SpanList(i);
    }
}

void *Cache::malloc(int size) {
    // 根据size, 选择一个合适的class
    int spanClass = 1;
    for (int i = 1; i < spanClasses; i++) {
        if (size <= spanInfo[i][1]) {
            spanClass = spanInfo[i][0];
            break;
        }
    }
    SpanList* spanList = &(this->alloc[spanClass]);  // 要用指针!
    /*
     * 三种情况
     * 1. 列表中没有一个span, 即 span == nullptr
     * 2. 列表中有span, 但是都没有了空间
     * 3. 列表中有span, 并且存在空间, 可以分配
     *
     * 情况 1, 2 都需要向central中请求空间
     */
    Span* span = nullptr;
    if (spanList->list == nullptr) {  // 情况 1
        // 锁
        mtx.lock();
        spanList->pushBack(ctl[spanClass].malloc(spanMap));  // central.malloc 会返回一个 span指针
        span = spanList->list;
        // 解锁
        mtx.unlock();
    } else {
        auto p = spanList->list;
        do {
            if (p->allocCount < p->nelems) {  // 有可分配的
                span = p;  // 第三种情况
                break;
            }
            p = p->next;
        } while (p != spanList->list);
        if (span == nullptr) {  // 第二种情况
            // 锁
            mtx.lock();
            spanList->pushFront(ctl[spanClass].malloc(spanMap));
            span = spanList->list;
            // 解锁
            mtx.unlock();
        }
    }
    return span->malloc();
}
