#include <iostream>

using namespace std;

int main() {

    int a = 10;
    // 定义指针
    int * p;
    p = &a;  // a的内存地址
    cout << "a  的地址：" << p << endl;
    // 使用指针
    *p = 100;
    cout << "a  的值：" << *p << endl;


    return 0;
}