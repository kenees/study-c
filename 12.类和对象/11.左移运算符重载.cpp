#include <iostream>
using namespace std;

// 左移运算符重载
class Person
{
    friend ostream &operator<<(ostream &cout, Person &p);
    friend void test01();

private:
    int m_A;
    int m_B;

    // 成员函数无法实现
    // void operator<<(cout)
    // {
    // 最终结果： p << cout, p在左边不符合
    // }
};

ostream &operator<<(ostream &cout, Person &p)
{
    cout << "m_A: " << p.m_A << " m_B: " << p.m_B << endl;
    return cout;
}

void test01()
{
    Person p;
    p.m_A = 10;
    p.m_B = 10;

    // cout << p.m_A << p.m_B << endl;
    cout << p << endl;
}

int main()
{
    test01();
    return 0;
}