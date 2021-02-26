//
// Created by 26220 on 2021/2/22.
//

#include "span.h"

// Span 构造函数
Span::Span(void *sa, int s, int n, int a, int sc, int es)
    : startAddr(sa), size(s), nelems(n), allocCount(a), spanClass(sc),
      elemsize(es), bitmap(n) {}

// 从 Span 上分配一个对象
void *Span::malloc() {
  for (int i = 0; i < nelems; i++) {
    if (bitmap.Get(i) == 0) {
      bitmap.Set(i);
      allocCount++;
      // 注意这个地址的计算要测试一下
      return (void *)((char *)startAddr + elemsize * i);
    }
  }
}

Span::Span() {
  // 空空如也
}

// SpanList 构造
SpanList::SpanList() {}

SpanList::SpanList(int sc) {
  spanClass = sc;
  list = nullptr;
}

Span *SpanList::newSpan(SpanMap *spanMap) {
  // 没有 span了, 则调用mmap分配一个
  auto addr =
      mmap(NULL,                   //分配的首地址
           spanInfo[spanClass][2], //分配内存大小(必须是页的整数倍, 32位1页=4k)
           PROT_READ | PROT_WRITE, //映射区域保护权限：读|写
           MAP_ANON | MAP_SHARED, //匿名映射(不涉及文件io), 后面两个参数忽略
           0,                     //要映射到内存中的文件描述符
           0 //文件映射的偏移量，通常设置为0，必须是页的整数倍
      );
  // ! 产生 span的地方, 需要添加到 spanMap结构中
  Span *span = new Span(addr, spanInfo[spanClass][2], spanInfo[spanClass][3], 0,
                        spanClass, spanInfo[spanClass][1]);
  (*spanMap)[(bool *)addr] = span;
  span->prev = span;
  span->next = span;
  return span;
}

// 弹出列表首部
void SpanList::popFront() {
  if (list->next == list) { // 如果链表只有一个元素, 那么直接让它指向空指针
    list = nullptr;
  } else {
    auto tmp = list->next;
    list->prev->next = list->next;
    list->next->prev = list->prev;

    list = tmp; // 非常重要!
  }
}

// 将 span 放到列表的首部.
void SpanList::pushFront(Span *span) {
  if (list == nullptr) {
    list = span;
    list->next = list;
    list->prev = list;
  } else {
    list->prev->next = span;
    span->prev = list->prev;
    list->prev = span;
    span->next = list;

    list = span; // 这一步非常重要
  }
}

void SpanList::pushBack(Span *pSpan) {
  // 先判断是否为空
  if (list == nullptr) {
    list = pSpan;
    list->prev = list;
    list->next = list;
  } else {
    list->prev->next = pSpan;
    pSpan->prev = list->prev;
    pSpan->next = list;
    list->prev = pSpan;
  }
}

// 将传递进来的 pSpan删除掉
void SpanList::pop(Span *pSpan) {
  // 当链表为空 时
  if (list == nullptr || pSpan == nullptr) {
    return;
  }
  if (list == pSpan) { // 当pSpan是链表头时, 可调用其他接口直接实现.
                       // 这种情况也包含了只有一个元素的情况
    this->popFront();
  } else { // 当节点在链表的其他部位时
    pSpan->prev->next = pSpan->next;
    pSpan->next->prev = pSpan->prev;
  }
}
