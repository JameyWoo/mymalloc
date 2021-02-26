//
// Created by 26220 on 2021/2/23.
//
// 重载一个类的 new 和 delete 操作符

#ifndef MYMALLOC_OVERRIDE_H
#define MYMALLOC_OVERRIDE_H

#include "../../amalloc.h"

#include <iostream>


class Override {
public:
    Override() {}
    Override(int a, int b): x(a), y(b) {}

    void* operator new(size_t size) {
        std::cout << "new" << std::endl;
        return amalloc(size);
    }

    void operator delete(void* ptr) {
        std::cout << "free" << std::endl;
        afree(ptr);
    }

public:
    int x, y;
};

class Over {
public:
    Over() {}
    Over(int a, int b): x(a), y(b) {}

public:
    int x, y;
};


#endif //MYMALLOC_OVERRIDE_H
