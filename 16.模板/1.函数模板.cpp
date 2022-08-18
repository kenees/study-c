#include <iostream>
using namespace std;

/**
 *  c++另一种编程思想称为泛型编程， 主要利用的技术就是模板
 *  c++提供两种模板机制： 函数模板和类模板
 *
 *
 *  1. 函数模板
 *      作用： 建立一个通用函数， 其函数返回值类型和形参类型可以不具体定制， 用一个虚拟的类型来代表
 *
 *       语法： template<typename T>
 *              函数声明或定义
 *
 *              template -- 声明创建模板
 *              typename -- 表明其后面的符号是一种数据类型， 可用class代替
 *              T -- 通用的数据类型， 名称可以替换， 通常为大写字母
 * 
 *     注意事项：
 *          1. 自动类型推导， 必须推导出一致的数据类型T才可以使用
 *          2. 模板必须要确定出T的数据类型才可以使用
 */

// 功能引入：
// 交换两个整型函数
void swapInt(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 交换两个浮点型函数
void swapDouble(double &a, double &b)
{
    double temp = a;
    a = b;
    b = temp;
}

// 升级版
template <typename T> // 声明一个模板， 告诉编译器后面的代码紧跟着T不要报错， T是一个通用数据类型
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
T add(T &a, T &b)
{
    return a + b;  
}

template <class T>
void func() {
    cout << "func调用" << endl;
}

void test1()
{
    int a = 1;
    int b = 2;

    swapInt(a, b);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    double c = 1.1;
    double d = 2.2;

    swapDouble(c, d);

    cout << "c = " << c << endl;
    cout << "d = " << d << endl;

    // 利用模板函数进行交换
    // 有两种使用方式
    // 1. 自动类型推导
    mySwap(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    // 2. 显示指定类型
    mySwap<double>(c, d);
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;

    // func();  error: 无法推导出T的数据类型
    func<int>();  // success: 明确指出类型后可调用
}

int main()
{
    test1();
    return 0;
}