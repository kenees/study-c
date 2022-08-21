#include <iostream>
using namespace std;

/**
 * 类模板实例化出的对象, 向函数传参的方式
 *
 * 一共三种传入方式:
 *      1. 指定传入的类型  --- 直接显示对象的数据类型
 *      2. 参数模板化     --- 将对象中的参数变为模板进行传递
 *      3. 整个类模板化   ---将这个对象类型模板化进行传递
 *
 */

template <class NameType, class AgeType>
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

// 1. 指定传入的类型, 比较常用
void printPerson(Person<string, int> &p)
{
    cout << "name: " << p.name << endl;
    p.showPerson();
};

void test01()
{
    Person<string, int> p1("张三", 20);
    printPerson(p1);
};

// 2. 参数模板化
template <class T1, class T2>
void printPerson2(Person<T1, T2> &p)
{
    cout << "name: " << p.name << endl;
    p.showPerson();
    cout << "T1的类型为: " << typeid(T1).name() << endl;
    cout << "T2的类型为: " << typeid(T2).name() << endl;
};

void test02()
{
    Person<string, int> p1("老王", 18);
    printPerson2(p1);
};

// 3. 整个类模板化
template <class T>
void printPerson3(T &p)
{
    cout << "name: " << p.name << endl;
    p.showPerson();
    cout << "T的类型为: " << typeid(T).name() << endl;
};

void test03()
{
    Person<string, int> p1("老油条", 18);
    printPerson3(p1);
};

int main()
{
    test01();
    test02();
    test03();
    return 0;
}