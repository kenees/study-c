#include <iostream>
using namespace std;

/**
 * 类模板中的成员函数创建时机 (调用时才去创建)
 *
 * @return int
 */

class Person1
{
public:
    void showPerson1()
    {
        cout << "person1 show" << endl;
    }
};

class Person2
{
public:
    void showPerson2()
    {
        cout << "person2 show" << endl;
    }
};

template <class T>
class MyClass
{
public:
    T obj;

    // 类模板中的成员函数
    // 因为不确定T的类型, 所以该成员函数不会创建, 可以编译成功
    void func1()
    {
        obj.showPerson1();
    }

    void func2()
    {
        obj.showPerson2();
    }
};

void test1()
{
    MyClass<Person1> m;
    m.func1();
    // m.func2();

    MyClass<Person2> m2;
    // m2.func1();
    m2.func2();
}

int main()
{
    test1();
    return 0;
}