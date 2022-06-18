//
// Created by x on 2022/6/18.
//

#include <future>
#include <thread>
#include <chrono>
#include <iostream>


int work() {
    using namespace std::chrono;
    std::this_thread::sleep_for(3s);
    return 88;
}

int main() {
    auto t = std::async(std::launch::async, work);
    std::cout << "do other thing" << std::endl;
    std::cout << "get anwser" << t.get() << std::endl;
    std::cout << "job done" << std::endl;
}