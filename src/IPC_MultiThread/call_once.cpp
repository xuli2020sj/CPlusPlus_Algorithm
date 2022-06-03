#include <thread>
#include <mutex>
#include "iostream"

using namespace std;

static std::once_flag flag;

auto f = []()                // 在线程里运行的lambda表达式
{
    std::call_once(flag,      // 仅一次调用，注意要传flag
                   [](){                // 匿名lambda，初始化函数，只会执行一次
                       cout << "only once" << endl;
                   }                  // 匿名lambda结束
    );                     // 在线程里运行的lambda表达式结束
};

int main() {
    thread t1(f);            // 启动两个线程，运行函数f
    thread t2(f);
    t1.join(); // 等待线程结束
    t2.join();
}
