#include <iostream>
using namespace std;

// c++编译器至少给一个类添加4个函数
// 1. 默认构造函数（无参， 函数体为空）name
// 2. 默认析构函数（无参， 函数体为空）～name
// 3. 默认拷贝函数， 对属性值进行值拷贝， 如果在析构函数中进行释放, 会造成重复释放堆区内存 (浅拷贝)
// 4. 赋值运算符 operator=, 对属性进行值拷贝， 可以实现深拷贝

class Person
{
public:
    Person(int age)
    {
        m_age = new int(age);
    }

    ~Person()
    {
        // 堆区内存重复释放报错
        // 重写赋值运算
        if (m_age != NULL)
        {
            delete m_age;
            m_age = NULL;
        }
    }

    // 重载 赋值
    Person &operator=(Person &p)
    {
        if (m_age != NULL)
        {
            delete m_age;
            m_age = NULL;
        }

        m_age = new int(*p.m_age);
        return *this;
    }

    int *m_age;
};

void test01()
{
    Person p1(18);

    Person p2(20);

    Person p3(30);

    p2 = p1 = p3;

    cout << "p1年龄： " << *p1.m_age << endl;
    cout << "p2年龄： " << *p2.m_age << endl;
    cout << "p3年龄： " << *p3.m_age << endl;
};

int main()
{
    test01();

    // int a = 10;
    // int b = 20;
    // int c = 30;

    // c = b = a;

    // cout << "c: " << c << " b: " << b << " a: " << a << endl;

    return 0;
}