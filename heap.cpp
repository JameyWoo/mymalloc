//
// Created by 26220 on 2021/2/21.
//

#include "heap.h"

#include <sys/mman.h>
#include <assert.h>


mymalloc::Heap::Heap() {
    for (int i = 0; i < spanClasses; i++) {
        ctls[i] = Central(i);
    }
}

void *mymalloc::Heap::malloc(int size) {
    assert(size > 0);  // 要分配内存必须size > 0
    if (size > maxSmallObjectSize) {  // 大对象分配
        return bigObjectMalloc(size);
    }

    Cache* cache;
    auto id = std::this_thread::get_id();
    // 选择对应的 Cache结构来进行内存分配
    if (this->cacheMap.find(id) == this->cacheMap.end()) {
        // 如果没有当前线程id的缓存结构, 那么创建一个
        cache = new Cache(this->ctls, &this->spanMap);
        this->cacheMap[id] = cache;  // 把 central 数组的地址传进去
    }
    cache = this->cacheMap[id];
    return cache->malloc(size);
}

// 大对象的内存分配
void *mymalloc::Heap::bigObjectMalloc(int size) {
    // ! 注意 mmap 分配的最小单位(似乎是页4KB)
    auto addr = mmap(
            NULL,                 //分配的首地址
            size,                         //分配内存大小(不须是页的整数倍, 但系统会按倍数来分配32位1页=4k)
            PROT_READ | PROT_WRITE,  //映射区域保护权限：读|写
            MAP_ANON | MAP_SHARED,  //匿名映射(不涉及文件io), 后面两个参数忽略
            0,                        //要映射到内存中的文件描述符
            0                      //文件映射的偏移量，通常设置为0，必须是页的整数倍
    );
    // 大对象的管理
    Span *span = new Span(addr, size, 1, 1, 0, size);
    spanMap[(bool*)addr] = span;
    return addr;
}


void mymalloc::Heap::free(void *addr) {
    // 根据地址在 spanMap中查找第一个 小于该地址的span.
    auto res = this->spanMap.lower_bound((bool*)addr);
    // 如果没找到
    assert(res != this->spanMap.end());
    // 找到对应的 span
    auto span = res->second;
    bool* addrBool = (bool*)addr;

    // 用一个断言判断, 如果这个地址是错误的, 那么会触发导致程序终止
    assert(addrBool >= (bool*)span->startAddr && addrBool < (bool*)span->startAddr + span->size);

    if (span->spanClass == 0) {
        // 如果需要释放的是大对象
        if (munmap(span->startAddr, span->size)) {
            std::cout << "munmap failed!\n";
        }
        spanMap.erase(res);
        return;
    }

    // 小对象
    // 开始释放空间, 首先计算这个地址是属于span的第几个对象
    int num = (addrBool - (bool*)span->startAddr) / span->size;
    span->bitmap.Del(num);
    span->allocCount--;

    if (span->allocCount == 0) {  // span空间为0, 将空间返还给 操作系统 (munmap). 需要将span从cache链表中删除.
        if(munmap(span->startAddr, spanInfo[span->spanClass][2]) != 0) {
            std::cout << "munmap failed!" << std::endl;
            exit(1);
        }
        auto id = std::this_thread::get_id();
        auto cache = this->cacheMap[id];
        cache->alloc[span->spanClass].pop(span);
        this->spanMap.erase(res);
        return;
    }

    // 小对象 free 之后, 将计数减一
    this->ctls[span->spanClass].nmalloc--;
}
