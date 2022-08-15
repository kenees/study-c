#include <iostream>
using namespace std;
/**
 * @brief 继承中同名的静态成员在子类对象上如何进行访问
 * 
 * 1. 访问子类同名成员  直接访问
 * 2. 访问父类同名成员， 需要加作用域
 * 
 * @return int 
 */

class Base {
    public:
        static void func() {
            cout << "base - static void func" << endl;
        }

        static void func(int a) {
            cout << "base -static vodi func(int a)" << a << endl;
        }
};

class Child: Base {
    public:
        static void func() {
            cout << "base - static void func" << endl;
        }

        static void func(int a) {
            cout << "base -static vodi func(int a)" << a << endl;
        }
};

int main() {
    cout << "testasdas" << endl;
    return 0;
}