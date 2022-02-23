//
// Created by x on 2022/2/23.
//

#ifndef CPP_TASKQUEUE_H
#define CPP_TASKQUEUE_H

#include "semaphore.h"
#include <deque>
#include <mutex>

template<typename T>
class TaskQueue {
private:
    semaphore _sem;
    std::deque<T> _queue;
    std::mutex _mutex;

public:
    template<typename F>
    void push_task(F&& task) {
        {
            std::lock_guard<std::mutex> lk(_mutex);
            _queue.push_back(std::forward<F>(task));
        }
        _sem.post();
    }

    template<typename F>
    void push_task_first(T&& task) {
        {
            std::lock_guard<std::mutex> lk(_mutex);
            _queue.push_front(std::forward<F>(task));
        }
        _sem.post();
    }

    void push_exit(size_t n) {
        _sem.post(n);
    }

    size_t size() {
        std::lock_guard<std::mutex> lk(_mutex);
        return _queue.size();
    }
};

#endif//CPP_TASKQUEUE_H
