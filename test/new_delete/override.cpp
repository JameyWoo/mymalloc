//
// Created by 26220 on 2021/2/23.
//

#include "override.h"

#include <iostream>

int main() {
    Override *o = new Override(1, 2);
    std::cout << o->x << ", " << o->y << std::endl;
    delete o;
    std::cout << o->x << ", " << o->y << std::endl;

    Over *ov = new Over(2, 3);
    std::cout << ov->x << ", " << ov->y << std::endl;
    delete ov;
    // 默认的重置之后好像会将值清零
    std::cout << ov->x << ", " << ov->y << std::endl;
}