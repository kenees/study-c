#include <cstddef>
#include <iostream>
using namespace std;
// 空指针调用成员函数

class Person {

    public:
        void showClassName() {
            cout << "this is Person class" << endl;
        }

        void showPersonAge() {
            cout << "this person age: " << this->m_age << endl;
        }

        int m_age;
};

void test1() {
    Person *p = NULL;
    p->showClassName();
    p->showPersonAge(); // 空指针调用具体属性会访问 不到
    // NULL -> age
};

int main() {
    test1();
    return 0;
}