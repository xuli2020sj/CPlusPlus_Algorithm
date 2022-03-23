//
// Created by x on 2022/2/19.
//

#ifndef IPC_MULTITHREAD_HEAD_H
#define IPC_MULTITHREAD_HEAD_H

#include <vector>

class Heap {
private:
    std::vector<int> vec;
public:
    Heap(int n) {
        vec.resize(n);
    }


};
#endif//IPC_MULTITHREAD_HEAD_H
