#include <cstdio>



int main() {
    const int vx = 10;
    const int vy = 10;
    int arr[vx] = {1, 2, 3};  // [错误1] 使用非常量表达式定义定长数组；
    switch(vy) {
        case vx: {  // [错误2] 非常量表达式应用于 case 语句；
            printf("Value matched!");
            break;
        }
    }
    return 0;
}