#include <iostream>
using namespace std;

/**
 * 类模板成员函数类外实现
 *
 */

template <class T>
class Person
{
public:
    Person(T name);

    void say();

    T name;
};

template <class T>
Person<T>::Person(T name)
{
    this->name = name;
}

template <class T>
void Person<T>::say()
{
    cout << "hello " << this->name << endl;
}

void test01()
{
    Person<string> p("zhangsan");
    p.say();
}

int main()
{
    test01();
    return 0;
}