#include <iostream>
using namespace std;

/**
 * @brief 继承中构造和析构顺序
 *  先调用父类构造， 再调用子类构造
 *  先调用子类析构， 再调用父类析构
 *
 * @return int
 */

class Base
{
public:
    Base()
    {
        cout << "base ..." << endl;
    }

    ~Base()
    {
        cout << "base 西沟..." << endl;
    }
};

class Child : public Base
{
public:
    Child()
    {
        cout << "child ..." << endl;
    }

    ~Child()
    {
        cout << "child 西沟..." << endl;
    }
};

void test()
{
    Child child;
}

int main()
{
    test();
    return 0;
}