//
// Created by x on 2022/1/9.
//

#include "Sort.h"
#include "algorithm"
#include <iostream>

#include <chrono>
#include <random>

using namespace std::chrono;
int main() {
    uniform_int_distribution<int> u(0, 10000);
    default_random_engine e(1);
    vector<int> vec;
    for (int i = 0; i < 10000; i++) {
        vec.push_back(u(e));
    }
//    sort::bubbleSort(vec);

    steady_clock::time_point t1 = steady_clock::now();

    sort::selectonSort(vec);
    steady_clock::time_point t2 = steady_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

    for_each(vec.begin(), vec.end(), [](int val) {
        cout << val << endl;
    });
    cout << "time span: " << duration_cast<milliseconds>(time_span).count() << "ms" << endl;
}