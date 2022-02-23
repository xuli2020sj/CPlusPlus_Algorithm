//
// Created by x on 2022/2/23.
//

#ifndef CPP_SEMAPHORE_H
#define CPP_SEMAPHORE_H

#include <mutex>
#include <condition_variable>

/**
 * 条件变量实现信号量
 */
class semaphore {
private:
    size_t _count; //可用资源数量
    std::recursive_mutex _mutex;
    std::condition_variable_any _cond;
public:
    explicit semaphore(size_t initial = 0)  {
        _count = initial;
    }

    void post(size_t n = 1) {
        std::unique_lock<std::recursive_mutex> lock(_mutex);
        _count += n;
        if (n == 1) {
            _cond.notify_one();
        } else {
            _cond.notify_all();
        }
    }

    void wait() {
        std::unique_lock<std::recursive_mutex> lock(_mutex);
        // 避免虚假唤醒
        while (_count == 0) {
            _cond.wait(_mutex);
        }
        _count--;
    }
};

#endif//CPP_SEMAPHORE_H
