#include <iostream>
using namespace std;

/**
 * @brief 多态是c++面向对象的三大特性之一
 *     多态分两类：
 *          静态多态： 函数重载 和运算符重载属于静态多态， 复用函数名   // 函数地址早绑定--编译阶段确定函数地址
 *          动态多态： 派生类和虚函数实现运行时多态                  //  函数地址晚绑定--运行阶段确定函数地址
 *                   动态多态满足条件： 1.有继承关系， 2. 子类重写父类虚函数（重写： 函数名，返回类型， 参数都一致）
 *                   动态多态使用：  1. 父类的指针或引用, 执行子类对象
 */

class Animal
{
public:
    // 虚函数， 可以编程地址晚绑定, 实现动态多态
    virtual void speak()
    {
        cout << "动物在说话" << endl;
    }
};

class Cat : public Animal
{
public:
    void speak()
    {
        cout << "小猫在说话" << endl;
    }
};

class Dog : public Animal
{
public:
    void speak()
    {
        cout << "小狗在说话" << endl;
    }
};

// 执行说话函数
// 地址早绑定, 编译阶段就确定函数地址了, 不管传入什么都执行父类函数
void doSpeak(Animal &animal) // 父类引用接受子类对象
{
    animal.speak();
};

void test1()
{
    Cat cat;
    doSpeak(cat);
    Dog dog;
    doSpeak(dog);
};

int main()
{
    test1();
    return 0;
};