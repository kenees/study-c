#include <iostream>
using namespace std;

// 常函数
class Person {
    public:
        // 没有更好的位置 添加const了
        // 类似于 const Person * const this;
        // 修饰的是this的指向，让指针的值也不可以修改
        // 这就是常函数
        // mutable修饰的变量可以修改
        void showPerson() const
        {
            // m_A= 100;
            this->m_B = 100;
        }

        void func() {

        }

        int m_A;
        mutable int m_B;
};


// 常对象
void test2() {
    // const Person p;  // 不知道为什么报错， 视频117集就可以
    // p.m_A = 100;
    // p.func2();  // 不可以调用普通函数， 因为普通函数可以修改成员变量， 而const 修饰的对象又不可以修改
};


int main() {
    test2();
    return 0;
}