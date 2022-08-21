#include <iostream>
using namespace std;

/**
 * @brief 模板的局限性
 *
 *  template<class T>
 *  void f(T a, T b) {
 *    a = ;
 *  }
 *
 *  在上诉代码中提供的赋值操作了如果传入的a,b是一个数组, 就无法实现了
 *
 *   template<class T>
 *   void f(T a, T b) {
 *      if (a > b) { ... }
 *   }
 *
 *   在上述代码中, 如果T的数据类型是Person这种自定义类型, 也无法正常运行
 *
 *   为了解决上述问题, 提供的模板的重载, 可以为这些特定的类型提供具体化的模板
 */

// 对比两个数据是否相等

class Person
{
public:
    Person(string name, int age)
    {
        this->age = age;
        this->name = name;
    }
    string name;
    int age;
};

template <class T>
bool myCompare(T &a, T &b)
{
    if (a == b)
    {
        return true;
    }
    else
    {
        return false;
    }
};

// 内置数据类型对比
void test01()
{
    int a = 10;
    int b = 20;

    bool ret = myCompare(a, b);
    if (ret)
    {
        cout << "a == b" << endl;
    }
    else
    {
        cout << "a != b" << endl;
    }
}

// 无法对比自定义类型
// 解决方案:
//  1. 自己实现运算符重载, 实现对比, 比较麻烦, 所有对比都要自己写
//  2. 利用具体化Person的模板来实现代码, 具体化优先调用

template <>
bool myCompare(Person &p1, Person &p2)
{
    if (p1.name == p2.name && p1.age == p2.age)
    {
        return true;
    }
    return false;
}

// 自定义数据类型对比
void test02()
{
    Person p1("tom", 10);
    Person p2("tom", 10);

    bool ret = myCompare(p1, p2);

    if (ret)
    {
        cout << "p1 == p2" << endl;
    }
    else
    {
        cout << "p1 != p2" << endl;
    }
};

int main()
{
    test01();
    test02();
    return 0;
}