//
// Created by x on 2022/6/19.
//


#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Heap {
private:
public:
    size_t size_;
    size_t capacity_;
    vector<int> vec_;
    explicit Heap(size_t capacity) : capacity_(capacity+1), vec_(capacity), size_(0) {}

    explicit Heap(vector<int>&& vec) : vec_(vec), capacity_(vec.size()+1), size_(vec.size()-1) {
        for (size_t i = size_ / 2; i > 0; i--) {
            heapify(i);
        }
    }

    void heapify(size_t curr) {
        while (true) {
            size_t max_pos = curr;
            if (curr * 2 <= size_ && vec_[curr] < vec_[curr*2]) max_pos = curr * 2;
            if (curr * 2 + 1 <= size_ && vec_[max_pos] < vec_[curr*2+1]) max_pos = curr * 2 + 1;
            if (max_pos == curr) return ;
            swap(vec_[curr], vec_[max_pos]);
            curr = max_pos;
        }
    }

    void insert(int val) {
        if (size_ >= capacity_) return ;
        size_++;
        vec_[size_] = val;
        size_t curr = size_;
        while (curr/2 > 0 && vec_[curr] > vec_[curr/2]) {
            swap(vec_[curr], vec_[curr/2]);
            curr = curr / 2;
        }
    }

    int pop() {
        if (size_ == 0) return INT32_MIN;
        int res = vec_[1];
        vec_[1] = vec_[size_];
        size_--;
        heapify(1);
        return res;
    }
};

int main() {
    // 堆中第一个位置不存储元素
    Heap h({0,10,8,4,88,2,6,4,8,22,6,99});
    for (int i = h.size_; i > 0; i--) {
        cout << h.pop() << endl;
    }
}