#include <iostream>
using namespace std;

/**
 * 掌握类模板配合友元函数的类内和类外实现
 *
 * 全局函数类内实现 - 直接在类内声明友元即可
 * 全局函数类外实现-需要提前让编译器知道全局函数的存在
 *
 */
template <class T1, class T2>
class Person;

template<class T1, class T2>
void printPerson2(Person<T1, T2> p) {
      cout << "姓名：" << p.name << "年龄：" << p.age << endl;
}

// 1. 类内实现
template <class T1, class T2>
class Person
{
    // 全局函数类内实现  （建议类内实现， 用法简单， 编译器可以直接识别）
    friend void printPerson(Person<T1, T2> p) {
        cout << "姓名：" << p.name << "年龄：" << p.age << endl;
    }

    // 全局函数类外实现
    // 1. 需要添加一个空的参数列表， 告诉编译器这是模板函数， 不是普通函数
    // 2. 需要提前让编译器知道这模板函数， 将该函数提前
    //    又： 因为该模板函数有一个person参数， 所以需要将person提前声明  (操作复杂)
    friend void printPerson2<>(Person<T1, T2> p);

public:
    Person(T1 name, T2 age)
    {
        this->name = name;
        this->age = age;
    }

private:
    T1 name;
    T2 age;
};



void test() {
    Person<string, int> p("张三", 11);
    printPerson(p);
    printPerson2(p);
}

int main()
{
    test();
    return 0;
}