#include <iostream>
using namespace std;

/**
 * 类模板与继承
 *
 */
template <class T>
class Base
{
    T m;
};

class Son : public Base<int>
{
};

void test01()
{
    Son s1;
}

// 2. 想灵活的指定父类中的T类型, 子类也需要变为类模板
template <class T1, class T2>
class Son2 : public Base<T2>
{
public:
    Son2()
    {
        cout << "T1: " << typeid(T1).name() << endl;
        cout << "T2: " << typeid(T2).name() << endl;
    }
    T1 obj;
};

void test02()
{
    Son2<string, int> s2;
}

int main()
{
    test01();
    test02();
    return 0;
}