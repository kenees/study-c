#include <iostream>
using namespace std;

// 1. 直接包含cpp文件(不推荐， 很少直接包含源文件)
// #include "person.cpp"
// 2. 写到一起改为.hpp (推荐， 主流方式)
#include "person.hpp"

/**
 * 问： 类模板中成员函数创建时机是在调用阶段， 导致分文件编写时链接不到
 *
 * 解决：
 *      1： 直接包含.cpp源文件, 不需要包含.h文件
 *      2： 将声明和实现写到同一个文件中, 并更改后缀名为.hpp， hpp是约定的名称， 不是强制的
 *
 */



void test01()
{
    Person<string, int> p1("老王", 20);
    p1.showPerson();
}

int main()
{
    test01();
    return 0;
}