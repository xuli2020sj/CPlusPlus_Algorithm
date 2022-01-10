//
// Created by x on 2022/1/9.
//

#ifndef CPLUSPLUS_ALGORITHM_SINGLETON_H
#define CPLUSPLUS_ALGORITHM_SINGLETON_H


class Singleton {
private:
    Singleton() = default;
public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }
        ~Singleton() = default;
        Singleton(const Singleton&) = delete;
        Singleton& operator=(Singleton) = delete;
};
#endif //CPLUSPLUS_ALGORITHM_SINGLETON_H
