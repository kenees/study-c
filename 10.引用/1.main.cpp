#include <iostream>
using namespace std;

/*
    1. 引用类型
        数据类型 &别名 = 原名
        相当于:  数据类型 const * p,   
*/
int main() {
    int a = 10;
    int &b = a;

    cout << " a: " << a << endl;
    cout << " b: " << b << endl;

    b = 100;
  
    cout << " a: " << a << endl;
    cout << " b: " << b << endl;

    int c = 20;
    b = c;

    cout << " a: " << a << endl;
    cout << " b: " << b << endl;
    cout << " c: " << c << endl;

    return 0;
}