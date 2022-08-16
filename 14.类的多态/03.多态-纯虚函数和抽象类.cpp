#include <iostream>
using namespace std;

/**
 * 在多态中, 通常父类中的虚函数的实现是毫无意义的, 主要都是调用子类重写的内容
 * 所以: 可以将虚函数改为纯虚函数
 *
 * 语法： virtual 返回值类型 函数名 （参数列表） = 0；
 *
 * 当类中有了纯虚函数， 这个类就叫做抽象类
 *
 * 抽象类特点：1. 无法实例化对象
 *           2. 子类必须重写抽象类中的纯虚函数， 否则也属于抽象类
 *
 * 纯虚函数的目的： 强制子类重写纯虚函数
 *
 */

class Base
{
public:
    virtual void func() = 0;
};

class Son : public Base
{
};

class Son1 : public Base
{
public:
    void func()
    {
        cout << "func的调用" << endl;
    }
};

void test01()
{
    // 1. 抽象类无法实例化
    // Base base;
    // new Base;

    // 2. 子类未重写纯虚函数， 也是抽象类， 无法实例化
    // Son son;

    Son1 son;
    son.func();
};

int main()
{
    test01();
    return 0;
}