#include <iostream>
using namespace std;

/**
 * @brief 重载关系运算符
 */

class Person
{
public:
    Person(string name, int age)
    {
        m_name = name;
        m_age = age;
    }

    string m_name;
    int m_age;

    bool operator==(Person &p)
    {
        return (p.m_age == this->m_age && p.m_name == this->m_name);
    }

    bool operator!=(Person &p)
    {
        return !(p.m_age == this->m_age && p.m_name == this->m_name);
    }
};

void test01()
{
    Person p1("tom", 18);
    Person p2("tom", 18);

    if (p1 == p2)
    {
        cout << "p1 和 p2是相等的" << endl;
    }
    else
    {
        cout << "p1 和 p2是不相等的" << endl;
    }

    if (p1 != p2)
    {
        cout << "p1 和 p2是不相等的" << endl;
    }
    else
    {
        cout << "p1 和 p2是相等的" << endl;
    }
};

/**
 * @brief
 *
 * @return int
 */

int main()
{
    test01();
    return 0;
}