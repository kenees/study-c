#include <iostream>
using namespace std;

// 递增运算符重载
// 通过重载递增运算符，实现自己的整型数据

class MyInteger
{
    friend ostream &operator<<(ostream &cout, MyInteger &a);
    // friend void operator++(MyInteger &num);
    friend void test2();

public:
    MyInteger(int num)
    {
        a = num;
    };

    // 重载前置++
    MyInteger &operator++()
    {
        a++;
        return *this;
    }

    // 重载后置++
    MyInteger operator++(int)
    {
        MyInteger temp = *this;
        a++;
        return temp;
    }

private:
    int a;
};

ostream &operator<<(ostream &cout, MyInteger &a)
{
    cout << a.a << endl;
    return cout;
};

void test1()
{
    MyInteger num = 100;
    cout << ++num << endl;
};

void test2()
{
    MyInteger ab = 10;
    MyInteger tt = ab++;
    cout << "操作返回值： " << tt << endl;
    cout << "操作后原值： " << ab << endl;
};

int main()
{
    test1();
    test2();
    return 0;
}