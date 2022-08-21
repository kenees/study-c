#include <iostream>
using namespace std;
#include "MyArray.hpp"

/**
 * 实现一个通用的数组类， 要求如下：
 *
 * 1. 可以对内置数据类型及自定义数据类型的数据进行存储
 * 2. 将数组中的数据存储到堆区
 * 3. 构造函数中可以传入数组的容量
 * 4. 提供对应的拷贝函数及operator=防止浅拷贝问题
 * 5. 提供尾插法和尾删除法对数组中的数据进行增加和删除
 * 6. 可以通过下标的方式访问数组中的元素
 * 7. 可以获取数组中当前元素个数和数组的容量
 *
 */

void test01()
{
    // 有参构造
    MyArray<int> arr(5);
    // 尾插
    arr.push(1);
    arr.push(2);
    cout << "arr[0]: " << arr[0] << endl;
    cout << "arr.lenght: " << arr.getlength() << endl;
    cout << "arr.getcapacity: " << arr.getcapacity() << endl;

    // 拷贝构造
    MyArray<int> arr2(arr);
    // operator=
    MyArray<int> arr3(100);
    arr3 = arr;

    cout << "arr2[0]: " << arr2[0] << endl;
    cout << "arr2.lenght: " << arr2.getlength() << endl;
    cout << "arr2.getcapacity: " << arr2.getcapacity() << endl;

    arr2.pop();
    cout << "arr2 pop: " << endl;
    cout << "arr2[0]: " << arr2[0] << endl;
    cout << "arr2.lenght: " << arr2.getlength() << endl;
    cout << "arr2.getcapacity: " << arr2.getcapacity() << endl;
}

// 自定义类型 测试
class Person
{
public:
    Person(){};
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    int age;
    string name;

    void p_print()
    {
        cout << "name: " << this->name << " age: " << this->age << endl;
    }
};

void test02()
{
    Person p1("王1", 1);
    Person p2("王2", 11);
    Person p3("王3", 111);
    Person p4("王4", 1111);
    // 有参构造
    MyArray<Person> arr(5);
    // 尾插
    arr.push(p1);
    arr.push(p2);
    arr.push(p3);
    arr.push(p4);
    arr[0].p_print();
    cout << "arr.lenght: " << arr.getlength() << endl;
    cout << "arr.getcapacity: " << arr.getcapacity() << endl;

    // // 拷贝构造
    MyArray<Person> arr2(arr);
    // // operator=
    MyArray<Person> arr3(100);
    arr3 = arr;
    arr2[0].p_print();
    cout << "arr2.lenght: " << arr2.getlength() << endl;
    cout << "arr2.getcapacity: " << arr2.getcapacity() << endl;

    arr2.pop();
    cout << "arr2 pop: " << endl;
    arr2[0].p_print();
    cout << "arr2.lenght: " << arr2.getlength() << endl;
    cout << "arr2.getcapacity: " << arr2.getcapacity() << endl;
}

int main()
{
    // test01();
    test02();
    return 0;
}