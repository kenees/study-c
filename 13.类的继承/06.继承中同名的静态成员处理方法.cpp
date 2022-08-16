#include <iostream>
using namespace std;

/**
 * @brief 继承中同名的静态成员处理方法
 *  继承中同名的静态成员在子类对象上如何进行访问 ？
 *  静态成员和非静态成员出现同名， 处理方式一样
 * @return int
 */

class Base
{
public:
    static void func();

    static int m_a;

    static void func(int a)
    {
        cout << "base static func（int a）" << a << endl;
    }
};

int Base::m_a = 100;

void Base::func()
{
    cout << "base static func" << endl;
}

class Child : public Base
{
public:
    static void func();

    static int m_a;
};

void Child::func()
{
    cout << "child static func: " << endl;
}
int Child::m_a = 200;

void test()
{
    // 1. 通过对象访问
    cout << "-------------通过对象访问：------------ " << endl;
    Child c;
    cout << "Son 下的m_a=" << c.m_a << endl;
    cout << "Base 下的 m_a=" << c.Base::m_a << endl;
    cout << "--Son 下的func--" << endl;
    c.func();
    // c.func(12); // Error 子类同名函数会重载掉父类所有同名函数（包括父类的重载函数）
    cout << "--Base 下的func--" << endl;
    c.Base::func();
    c.Base::func(11);
    // 2. 通过类名访问
    cout << "------------通过类名访问--------------- " << endl;
    cout << "Son 下的m_a=" << Child::m_a << endl;
    cout << "Base 下的 m_a=" << Child::Base::m_a << " or " << Base::m_a << endl;
    cout << "--Son 下的func--" << endl;
    Child::func();
    // Child::func(12); // Error
    cout << "--Base 下的func--" << endl;
    Base::func();
    Child::Base::func();
    Child::Base::func(12);
};

int main()
{
    test();
    return 0;
}