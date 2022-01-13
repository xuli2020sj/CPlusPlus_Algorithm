//
// Created by x on 2022/1/13.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;

int n = 0; //data
unique_lock<mutex> mtx;
condition_variable condition_var;

void threadRun() {
    while (n < 16) {
        mtx.lock();
        n++;
        cout << "Thread ID: " << this_thread::get_id() << "n= " << n << endl;
        mtx.unlock();
        this_thread::sleep_for(chrono::seconds(1));
    }
}

void cond_wait() {
    mtx.lock();
    //阻塞线程，直至条件成立
    condition_var.wait(mtx);
    std::cout << "----threadID " << std::this_thread::get_id() <<" run" << std::endl;
    //等待 2 秒
    std::this_thread::sleep_for(std::chrono::seconds(2));
    mtx.unlock();
}

void cond_notify() {
    std::cout << "go running\n";
    //阻塞线程 2 秒钟
    std::this_thread::sleep_for(std::chrono::seconds(2));
    //通知所有等待的线程条件成立
    condition_var.notify_all();
}

void testMutex() {
    //调用第 1 种构造函数
    thread thread1(threadRun);
    //调用移动构造函数
    thread thread2 = std::thread(threadRun);
    //阻塞主线程，等待 thread1 线程执行完毕
    thread2.join();
    thread1.join();
}

void testConditionVar() {
    thread threads[8];

//    for (auto& th : threads) {
//        th = thread(cond_wait);
//    }

    for (int i = 0; i < 1; ++i) threads[i] = thread(cond_wait);

    thread threadNotify(cond_notify);
    threadNotify.join();
    for (auto& th : threads) {
        th.join();
    }
}

int main() {
    testConditionVar();
    return 0;
}