#include <iostream>
using namespace std;

/**
 * @brief c++允许一个类继承多个类
 * 语法：  class 子类: 继承方式 父类1， 继承方式 父类2 ...
 *
 * 多继承可能会引发父类中有同名成员出现， 需要加作用域区分
 *
 * c++不建议实际开发中使用多继承
 *
 * @return int
 */

class Base1
{
public:
    int m_a;

    Base1()
    {
        m_a = 100;
    }
};

class Base2
{
public:
    int m_a;

    Base2()
    {
        m_a = 200;
    }
};

class Child : public Base1, public Base2
{
public:
    int m_c;
    int m_d;
    Child()
    {
        m_c = 300;
        m_d = 400;
    }
};

void test1()
{
    Child c;
    cout << "sizeof son: " << sizeof(c) << endl; // 16

    // 两个父类有同名变量出现， 需要添加作用域
    cout << "base1 m_a: " << c.Base1::m_a << endl;
    cout << "base2 m_a: " << c.Base2::m_a << endl;
};

int main()
{
    test1();
    return 0;
}