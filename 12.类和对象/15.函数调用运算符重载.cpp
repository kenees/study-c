#include <iostream>
using namespace std;

/**
 * @brief 函数调用运算符重载
 * 由于重载后使用的方式非常像函数的调用, 因此称为仿函数
 *  仿函数没有固定的写法, 非常灵活
 */

class MyPrint
{
public:
    void operator()(string text)
    {
        cout << text << endl;
    }
};

void MyPrint2(string text)
{
    cout << text << endl;
};

void test01()
{
    MyPrint mp;
    mp("hello world");
    MyPrint2("hello world");
};

// 仿函数非常灵活
// 加法类
class MyAdd
{
public:
    int operator()(int num1, int num2)
    {
        return num1 + num2;
    }
};

void test02()
{
    MyAdd myadd;
    int sum = myadd(10, 20);
    cout << "sum: " << sum << endl;
    cout << "匿名函数求和：" << MyAdd()(100, 100) << endl;
};

int main()
{
    test01();
    test02();
    return 0;
}