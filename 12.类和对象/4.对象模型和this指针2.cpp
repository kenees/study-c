#include <iostream>
using namespace std;

// this作用
// 1.  解决名称冲突
// 2.  返回对象本身用 *this

class Person {

public:
//   Person(int age) { age = age; } // 无法区分形参和成员变量
  Person(int age) {
      // 指向被调用的成员函数所属的对象
      this->age = age;
  };

  Person& PersonAddPerson(Person &p) {
      this->age += p.age;
      return *this;
  }

  int age;
};

void test1() {
  Person p1(8);
  cout << "p1的年龄为：" << p1.age << endl;
};

void test2() {
    Person p1(10);
    Person p2(20);

    // 链式编程思想
    p2.PersonAddPerson(p1).PersonAddPerson(p1);
    cout << "p2 age:  " << p2.age << endl;
};

int main() {
  test1();
  test2();
  return 0;
}