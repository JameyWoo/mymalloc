//
// Created by 26220 on 2021/2/22.
//

// ! 查看当前的进程/线程处于哪个CPU核心上运行: sched_getcpu()

#include <sched.h>
#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

int main() {
    int cpu = sched_getcpu();
    cout << "in cpu: " << cpu << endl;

    for (int i = 0; i < 10; i++) {
        thread{[](){
            cout << "in cpu: " << sched_getcpu() << endl;
            sleep(1);
        }}.detach();
    }
    sleep(3);
}