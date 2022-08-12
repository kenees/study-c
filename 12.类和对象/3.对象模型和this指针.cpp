#include <iostream>
using namespace std;

// 成员变量和成员函数是分开存储的
// 只有非静态成员变量属于类的对象上， 其他都不属于sizeof统计不到大小
// 空对象也占用一个字节空间，为了区分对象占用内存 的 位置 

class Person {

};

class Person2 {
    int m_A;  // 属于类的 对象 ， 占用四个字节

    bool m_B; // 属于类的对象， 单独占用1个字节， 组合会因为四字节对其， 总共占用8个字节

    static int m_C; // 静态成员变量， 不属于类上， 不占用类的内存

    void  func() {}; // 非静态成员函数， 不属于类对象上， 同上
    static void func2() {}; // 不属于 类 的 对象 上
};

int Person2::m_C = 10;

void test01() {
    Person p;
    cout << "size of p=:" << sizeof(p) << endl;
}

void test2() {
    Person2 p;
    cout << "size of p: " << sizeof(p) << endl;
}

int main() {
    test01();
    test2();
    return 0;
}