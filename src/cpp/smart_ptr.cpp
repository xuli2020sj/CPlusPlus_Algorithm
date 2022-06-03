#include <utility>
#include <iostream>

template <typename T>
class auto_ptr {
private:
    T* _ptr;

public:
    explicit auto_ptr(T* ptr = nullptr) : _ptr(ptr) {}

    ~auto_ptr() {
        delete _ptr;
    };

    T* get() const {
        return _ptr;
    }

    T* release() {
        T* ptr = _ptr;
        _ptr = nullptr;
        return ptr;
    }

    auto_ptr(const auto_ptr & other) {
        _ptr = other.release();
    }

    // 强异常安全性 生成临时对象
    auto_ptr & operator=(auto_ptr& rhs) {
        auto_ptr(rhs).swap(*this);
        return *this;
    }

    void swap(auto_ptr & rhs) {
        using std::swap; swap(_ptr, rhs.ptr_);
    }
};

class shared_count {
private:
    std::size_t _count;

public:
    shared_count() : _count(1) {}
    std::size_t add_count() {
        return ++_count;
    }
    std::size_t reduce_count() {
        return --_count;
    }
    std::size_t get_count() const {
        return _count;
    }
};

template <typename T>
class smart_ptr {
private:
    T* _ptr;
    shared_count*_count;

public:
    friend class smart_ptr;
    explicit smart_ptr(T* ptr = nullptr) : _ptr(ptr) {
        if (_ptr) _count = new shared_count;
    }

    smart_ptr(const smart_ptr& other) {
        _ptr = other.release();
        if (_ptr) {
            other._count->add_count();
            _count = other._count;
        }
    }

    template<typename U>
    explicit smart_ptr(smart_ptr<U>& other) {
        _ptr = other._ptr;
        if (_ptr) {
            other._count->add_count();
            _count = other._count;
        }
    }

    template<typename U>
    explicit smart_ptr(smart_ptr<U>&& other) {
        _ptr = other._ptr;
        if (_ptr) {
            _count = other._count;
            other._ptr = nullptr;
        }
    }

    // 强异常安全性 生成临时对象
    smart_ptr& operator=(smart_ptr rhs) {
        rhs.swap(*this);
        return *this;
    }

    ~smart_ptr() {
        if (_ptr && _count->reduce_count() <= 0) {
            delete _ptr;
            delete _count;
        }
    };

    std::size_t use_count() const {
        if (_ptr) {
            return _count->get_count();
        } else {
            return 0;
        }
    }

    void swap(smart_ptr & rhs) {
        using std::swap; swap(_ptr, rhs.ptr_);
        swap(this->_count, rhs._count);
    }

    T* get() const {
        return _ptr;
    }

    T& operator*() const noexcept {
        return *_ptr;
    }

    T* operator->() const noexcept {
        return _ptr;
    }

    explicit operator bool() const noexcept {
        return _ptr;
    }

    template<class U>
    smart_ptr(const smart_ptr<U>& other, T* ptr) {
        _ptr = ptr;
        if (_ptr) {
            other._count->add_count();
            _count = other._count;
        }
    }



};

template<typename T, typename U>
smart_ptr<T> dynamic_pointer_cast(const smart_ptr<U>& other) {
    T* ptr = dynamic_cast<T*>(other.get());
    return smart_ptr<T>(other, ptr);
}

class shape {
public:
    virtual ~shape() {
        std::cout << "~shape()" << std::endl;
    }
};

class circle : public shape {
public:
    ~circle() {
        std::cout << "~circle()" << std::endl;
    }
};


int main() {
    smart_ptr<circle> ptr1(new circle);
    std::cout << ptr1.use_count() << std::endl;
    smart_ptr<shape> ptr2(new shape);
    std::cout << ptr2.use_count() << std::endl;
    std::cout << ptr2.use_count() << std::endl;
}

