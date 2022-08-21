#include <iostream>
using namespace std;

/**
 * 普通函数与函数模板的区别
 * 
 * 1. 普通函数调用可以发生隐式类型转换
 * 2. 函数模板 用自动类型推导， 不可以发生隐式类型转换
 * 3. 函数模板 用显示指定类型， 可以发生隐式类型转换
 * 
 * @return int 
 */

int myAdd01(int a, int b) {
    return a + b;
}

template<class T>
T myAdd02(T a, T b) {
    return a + b;
}

void test01() {
    int a = 10;
    int b = 20;

    char c = 'a';

    cout << myAdd01(a, b) << endl;
    cout << myAdd01(a, c) << endl;  // 函数明确指定了int类型， 所以发生隐式类型转换 a -> 97

    cout << myAdd02(a, b) << endl;
    // cout << myAdd02(a, c) << endl;  // error 无法发生类型转换
    cout << myAdd02<int>(a, c) << endl;  // 函数明确指定了int类型， 所以发生隐式类型转换 a -> 97
    cout << myAdd02<char>(a, c) << endl;  // 函数明确指定了int类型， 所以发生隐式类型转换 a -> 97
}

int main() {
    test01();
    system("pause");
    return 0;
}