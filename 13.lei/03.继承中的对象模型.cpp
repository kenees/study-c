#include <iostream>
using namespace std;

/**
 * @brief 从父类继承过来的成员， 那些属于子类对象中?
 * 父类中所有的非静态的成员属性都会被子类继承下去
 * // 父类中私有成员属性是被编译器隐藏了, 因此访问不到, 但是确实继承下去了
 *
 */

class Base
{
public:
    int m_a;

protected:
    int m_b;

private:
    int m_c;
};

class Child : public Base
{
public:
    int m_d;
};

void test()
{
    Child c;
    c.m_a = 10;
    cout << "child sizeof: " << sizeof(Child) << endl;
};

int main()
{
    test();
    int legs = 100;
    return 0;
}