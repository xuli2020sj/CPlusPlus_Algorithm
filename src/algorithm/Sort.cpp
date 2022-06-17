//
// Created by x on 2022/1/9.
//

#include "Sort.h"
#include "algorithm"
#include <iostream>

#include <cassert>
#include <chrono>
#include <random>

using namespace std::chrono;



void testSort(sortAlgo) {
    uniform_int_distribution<int> u(0, 1000000);
    default_random_engine e(1);
    vector<int> vec;
    for (int i = 0; i < 10000; i++) {
        vec.push_back(u(e));
    }

    steady_clock::time_point t1 = steady_clock::now();

    sortAlgo;
    sort::merge_sort(vec);
    steady_clock::time_point t2 = steady_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

    //    for_each(vec.begin(), vec.end(), [](int val) {
    //        cout << val << endl;
    //    });
    assert(sort::validateSort(vec));
    cout << "merge sort time span: " << duration_cast<milliseconds>(time_span).count() << "ms" << endl;
}

void testMergeSort() {
    uniform_int_distribution<int> u(0, 1000000);
    default_random_engine e(1);
    vector<int> vec;
    for (int i = 0; i < 10000; i++) {
        vec.push_back(u(e));
    }


    steady_clock::time_point t1 = steady_clock::now();

    sort::merge_sort(vec);
    steady_clock::time_point t2 = steady_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

//    for_each(vec.begin(), vec.end(), [](int val) {
//        cout << val << endl;
//    });
    assert(sort::validateSort(vec));
    cout << "merge sort time span: " << duration_cast<milliseconds>(time_span).count() << "ms" << endl;
}

void testQuickSort() {
    uniform_int_distribution<int> u(0, 1000000);
    default_random_engine e(1);
    vector<int> vec;
    for (int i = 0; i < 10000; i++) {
        vec.push_back(u(e));
    }

    steady_clock::time_point t1 = steady_clock::now();

    sort::quickSort(vec);
    steady_clock::time_point t2 = steady_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

//    for_each(vec.begin(), vec.end(), [](int val) {
//        cout << val << endl;
//    });
    assert(sort::validateSort(vec));
    cout << "quick sort time span: " << duration_cast<milliseconds>(time_span).count() << "ms" << endl;
}

void testBubbleSort() {
    uniform_int_distribution<int> u(0, 1000000);
    default_random_engine e(1);
    vector<int> vec;
    for (int i = 0; i < 10000; i++) {
        vec.push_back(u(e));
    }

    steady_clock::time_point t1 = steady_clock::now();

    sort::bubbleSort(vec);
    steady_clock::time_point t2 = steady_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

    //    for_each(vec.begin(), vec.end(), [](int val) {
    //        cout << val << endl;
    //    });
    assert(sort::validateSort(vec));
    cout << "quick sort time span: " << duration_cast<milliseconds>(time_span).count() << "ms" << endl;
}


int main() {
    testMergeSort();
    testQuickSort();
    testBubbleSort();
}