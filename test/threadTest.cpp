/*
 * 测试 C++ 线程的特点.
 * 1. 标识自己的线程id
 */

#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

int main() {
    // long long
    std::thread::id x = std::this_thread::get_id();
    cout << x << endl;

    for (int i = 0; i < 3; i++) {
        thread([](){
            cout << std::this_thread::get_id() << endl;
        }).detach();
    }

    sleep(1);

    thread([](){
        cout << std::this_thread::get_id() << endl;
    }).detach();

    sleep(3);
}