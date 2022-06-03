#include <iostream>
struct Foo {
    int n;
    Foo() {
        std::cout << "static constructor\n";
    }
    ~Foo() {
        std::cout << "static destructor\n";
    }
};
Foo f; // 静态对象

int main()
{
    std::cout << "main function\n";
}