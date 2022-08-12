#include <iostream>
using namespace std;

/*
    引用做函数参数
    作用: 函数传参时, 可以利用引用的技术让形参修饰实参
    优点: 可以简化指针修改实参
*/


// 1. 值传递实现数据交换, 不会更改实参
void swap01(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

// 2. 指针地址实现数据交换
void swap02(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 3. 引用实现数据交换
void swap03(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int a =20;
    int b = 10;
    swap01(a, b);
    cout << "a: " << a << " b: " << b << endl;
    swap02(&a, &b);
    cout << "a: " << a << " b: " << b << endl;
    swap03(a, b);
    cout << "a: " << a << " b: " << b << endl;
    return 0;
}