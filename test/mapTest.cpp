//
// Created by 26220 on 2021/2/22.
//

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

struct Compare {
    bool operator()(const bool* k1, const bool* k2)const {
        return k2 > k1;
    }
};

void IntStarTest() {
    map<bool*, int, std::greater<bool*> > m;
//    map<bool*, int, Compare> m;

    bool a = 3;
    bool b = 2;
    bool c = 1;
    bool d = 4;

    m[&a] = a;
//    m[&b] = 2;
//    m[&c] = 1;
    m[&d] = 4;

    auto x = m.lower_bound(&c);
    // 注意这个没找到结果的判断, 非常重要.
    if (x != m.end()) {
        cout << x->first << ' ' << x->second << endl;
    }
}

void MapCompareTest() {
    map<int, int, greater<int>> m;
    for (int i = 0; i < 5; i++) {
        m[2 * i] = i;
    }
    auto x = m.lower_bound(6);
    cout << x->first << ' ' << x->second << endl;
}


void SubTest() {
    bool a = 3;
    bool b = 4;
    auto x = &a - &b;
    cout << x << endl;

    cout << &a << endl;
    cout << (&a + 1) << endl;

    auto a1 = &a;
    auto a2 = (&a + 1);
    cout << a1 << ' ' << a2 << endl;
}


int main() {
    IntStarTest();
    MapCompareTest();
    SubTest();
}