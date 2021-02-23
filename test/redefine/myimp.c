// myimp.c

// 看这篇文章, 帮我实验成功.
// https://stackoverflow.com/questions/48660176/how-i-can-make-alias-on-external-defined-function-in-c
// 我经过测试, 发现相同的代码, gcc(c文件)可以, 但是g++(cpp文件)却失败了, 说是
// test1.cpp:16:1: error: ‘int coolguy(int, int)’ aliased to undefined symbol ‘myadd’

#include <stdio.h>

int
myadd(int x, int y)
{
    return x+y;
}

int
coolguy (int x, int y) __attribute__((alias("myadd")));

int main() {
    printf("%d\n", myadd(1, 2));
    printf("%d\n", coolguy(1, 2));
}