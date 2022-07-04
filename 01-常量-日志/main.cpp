/**
    1. 常量， 变量定义
        #define Days 20   (注意没有分号)
        const int num = 0;

    2. 输出日志
        cout << 'hello world' << endl;
        cout << 'age: ' << age << endl;
*/
#include <cstdio>
#include <iostream>
using namespace std;

// 宏常量 不可以修改， 后面不可以跟分号
// 常量通常用大写字母
#define DAYS 7


int main()
{
    cout << "hello c++" <<endl;       
    system("pause");

    // 变量
    int num = 0;
    num+=10;

    cout << num << endl;

    cout << "aa" << DAYS << "tian" << endl;

    // const 修饰的变量为常量
    const int MONTH = 12;

    cout << "a week have " << MONTH << " day" << endl;

    return 0;
}