#include <iostream>
using namespace std;

/**
 * 类模板和函数模板的区别
 *
 * 1. 类模板没有自动类型推导的使用方式
 * 2. 类模板在模板参数列表中可以有默认参数
 *
 */

template <class NameType, class AgeType = int>
class Person
{
public:
    Person(NameType name, AgeType age)
    {
        this->age = age;
        this->name = name;
    }

    void showPerson()
    {
        cout << "name: " << this->name << " age: " << this->age << endl;
    }

    NameType name;
    AgeType age;
};

void test01()
{
    // 1. 无法自动类型推导
    // Person p1("张三", 100);
    // p1.showPerson();

    Person<string, int> p1("张三", 100);
    p1.showPerson();
};

void test02()
{
    // 2. 类模板在模板参数列表中可以有默认参数
    Person<string> p2("猪八戒", 300);
    p2.showPerson();
}

int main()
{
    test01();
    test02();
    return 0;
}