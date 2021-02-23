//
// Created by 26220 on 2021/2/23.
//

// 将函数包含在 extern "C" {} 中就成功了

#include <iostream>

using namespace std;


extern "C" {
int
myadd(int x, int y) {
    return x + y;
}
}

extern "C" {
int
coolguy(int x, int y) __attribute__((alias("myadd")));
}


int main() {
    cout << myadd(1, 2) << endl;
    cout << coolguy(1, 2) << endl;
}