#include <iostream>
using namespace std;

// 子类继承父类的成员, 后访问同名成员默认访问子类的
// 访问父类同名成员添加作用域： child.Base::func();

// 访问不同名的, 优先从子类找, 没有找父类

class Base
{
public:
    Base()
    {
        cout << "base ..." << endl;
        m_a = 100;
    }

    ~Base()
    {
        cout << "base 西沟..." << endl;
    }

    void func()
    {
        cout << "父类func" << endl;
    }

    void func(int a)
    {
        cout << "父类func2" << a << endl;
    }

    int m_a;
};

class Child : public Base
{
public:
    Child()
    {
        cout << "child ..." << endl;
        m_a = 200;
    }

    ~Child()
    {
        cout << "child 西沟..." << endl;
    }

    void func()
    {
        cout << "子类func" << endl;
    }

    int m_a;
};

// 同名成员变量
void test1()
{
    Child child;
    cout << "m_a: " << child.m_a << endl; // 200
    cout << "Base m_a: " << child.Base::m_a << endl;
    cout << "===================" << endl;
};

// 同名成员函数
void test2()
{
    Child child;
    // child.func(100); // 子类重写同名函数后, 编译器会隐藏所有父类的同名函数
    child.Base::func(100);
}

int main()
{
    test1();
    test2();
    return 0;
}