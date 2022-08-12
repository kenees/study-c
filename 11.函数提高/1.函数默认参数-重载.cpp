#include <iostream>
using namespace std;


void func1(int a, int b) {

};

// 有默认参数时可以不传递
// 有默认参数后, 默认参数后面必须全部有默认值
void func2(int a, int b = 1, int c = 22) {
    cout << "fun1" << endl;
};

// 函数重载条件: 
// 1. 同一个作用域
// 2. 函数重载, 方法名一致, 参数不一致
void func2(int b, int a) {
    cout << "fun2" << endl;
}

int main() {
    func1(1, 2);
    // func1(1) ; // 必须传递两个参数
    func2(1); // 有默认参数时可以不传递, 

    return 0;
}