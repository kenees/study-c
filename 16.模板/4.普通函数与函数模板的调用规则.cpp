

/**
 * @brief 普通函数与函数模板的调用规则
 * 
 *  1. 如果函数模板和普通函数都可以实现， 优先调用普通函数
 *  2. 可以通过空模板参数列表来强制调用函数模板
 *  3. 函数模板也可以发生重载
 *  4. 如果函数模板可以产生更好的匹配优先调用函数模板
 */

#include <iostream>
using namespace std;


void myPrint(int a, int b) {
    cout << "调用普通函数" << endl;
}

template<class T>
void myPrint(T a, T b) {
    cout << "调用模板" << endl;
};

template<class T>
void myPrint(T a, T b, T c) {
    cout << "调用重载模板" << endl;
};

void test01() {
    int a = 10;
    int b = 20;
    // 1. 优先调用普通函数, 普通函数如果未实现， 直接报错
    myPrint(a, b);
    
    //2 通过空模板参数列表来强制调用函数模板
    myPrint<>(a, b);

    // 3. 函数模板也可以发生重载
    myPrint(a, b, 100);

    // 4. 如果函数模板可以产生更好的匹配优先调用函数模板
    char c1 = 'a';
    char c2 = 'b';
    myPrint(c1, c2);  // 普通函数可以发生隐式类型转换从而调用， 但是有模板更好的匹配。所以调用模板
}

int main() {
    test01();
    return 0;
}