//
// Created by x on 2022/6/18.
//
#include <bits/stdc++.h>

using namespace std;
struct A{
    int n;
    char c;
};

struct B{
    A a;
    char c;
    int i;
};

int main() {
    A a{1, 'a'};
    B b{a, 'a', 2};
    cout << "size of int:" << sizeof(int) << endl;
    cout << "size of char:" << sizeof(char) << endl;
    cout << "size of float:" << sizeof(float ) << endl;

    cout << "size of A:" << sizeof(A) << endl;
    cout << "size of B:" << sizeof(B) << endl;
    cout << "address of B:" << &b.a << endl;
    cout << "address of B:" << &b.c << endl; // cout 输出会认为 这是一个字符串。。。
    printf("%p", &b.c); // 内存对齐会跳过char后面剩余的内存
    cout << endl;
    cout << "address of B:" << &b.i << endl;


    cout<<sizeof(int*) * 8 << "位编译器 "<<endl; //查看编译器位数

}