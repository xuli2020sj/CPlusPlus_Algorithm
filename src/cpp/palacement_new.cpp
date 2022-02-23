//
// Created by x on 2022/2/23.
//

#include <iostream>
using namespace std;

class A
{
public:
    A()
    {
        cout << "A's constructor" << endl;
    }


    ~A()
    {
        cout << "A's destructor" << endl;
    }

    void show()
    {
        cout << "num:" << num << endl;
        cout << "num:" << num2 << endl;
    }

private:
    int num;
    int num2;
};

int main()
{
    char mem[100];
    mem[0] = 'A';
    mem[1] = 'B';
    mem[2] = '\0';
    mem[3] = '\0';
    cout << (void*)mem << endl;
    A* p = new (mem)A;  // 指定位置放置对象
    cout << p << endl;
    p->show();
//    p->~A(); //显示调用，否则内存不会释放
//    getchar();
}

/*
 * palacement new 定点放置
 * 1. 降低内存申请时间
 * 2. 防止内存碎片
 */