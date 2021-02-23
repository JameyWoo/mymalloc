//
// Created by 26220 on 2021/2/23.
//

#include "staticTest.h"

#include <iostream>
#include <map>
#include <unistd.h>

using namespace std;

void malloc_test() {
    int* a = (int*)malloc(sizeof(int));
    *a = 1;
    cout << (*a) << endl;
    cout << a << endl;

    for (int i = 1; i < 10; i++) {
        cout << malloc(4 * i) << endl;
    }
}

void amalloc_test() {
    int* a = (int*)amalloc(sizeof(int));
    *a = 1;
    cout << (*a) << endl;
    cout << a << endl;
    for (int i = 1; i < 10; i++) {
        cout << malloc(4 * i) << endl;
    }
}

void while_alloc_test() {
    vector<void*> voids;
    long cnt = 0;
    int t = 100;
    while (t--) {
        for (int i = 1; i < spanClasses; i++) {
            for (int j = 1; j <= 3 * spanInfo[i][3] + 1; j++) {
                int * x = (int*)amalloc(spanInfo[i][1]);
                *x = 110;
                voids.push_back((void*)x);
                cnt += spanInfo[i][1];
            }
        }
    }

    sleep(10);

    for (int i = 0; i < voids.size(); i++) {
        afree(voids[i]);
    }

    cout << cnt << " B." << endl;
    cout << cnt / 1024 << " KB." << endl;
    cout << cnt / (1024 * 1024) << " MB." << endl;

    sleep(1000);
}

int main() {
//    malloc_test();

//    amalloc_test();

    // 一个死循环的测试
    while_alloc_test();
}