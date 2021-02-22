//
// Created by 26220 on 2021/2/22.
//

#ifndef MYMALLOC_CENTRAL_H
#define MYMALLOC_CENTRAL_H

#include "span.h"

// 如果 nonempty 为空, 那么需要从内存映射中申请一块空间
class Central {
public:
    Central();

    Central(int sc);

public:
    // 被 heap调用
    Span *malloc(SpanMap *);  // 不需要传入大小, 只需要分配固定的大小对应的起始地址

public:
    // 还有内存可用的span
    SpanList nonempty;
    // 已经消耗完的span列表
    SpanList empty;
    // 已分配的对象的个数
    int nmalloc;

private:
    int spanClass;      // span的类别
};


#endif //MYMALLOC_CENTRAL_H
