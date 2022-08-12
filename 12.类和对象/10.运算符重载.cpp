#include <iostream>
using namespace std;

// 运算符重载概念： 对已有的运算符重新定义， 赋予 其另一种功能，
// 以适应不同的数据类型
// 注意： 内置的数据类型不可以进行运算符重载
// 注意： 不要滥用， 避免阅读和理解困难（案例就是在滥用🤔）

// 加号重载, 减号
class Person {
public:
  Person() {}

  int m_a;
  int m_b;

  // NO 1
//   Person operator+ (Person &p){
//       Person temp;
//       temp.m_a = m_a - p.m_a;
//       temp.m_b = m_b - p.m_b;

//      return temp;
//   };
};

// ＮＯ 2 ， 全局 函数实现
Person operator+(Person &p1, Person &p2) {
       Person temp;
       temp.m_a = p1.m_a - p2.m_a;
       temp.m_b = p2.m_b - p1.m_b;
       return temp;
};

//. NO 2.1 函数重载
Person operator+(Person &p, int a) {
    Person temp;
    temp.m_a = p.m_a + a;
    temp.m_b = p.m_b;

    return temp;
}

void test() {
  Person p1;
  p1.m_a = 10;
  p1.m_b = 11;

  Person p2;
  p2.m_a = 20;
  p2.m_b = 21;

  Person p3 = p1 + p2;
  Person p4 = p1 + 100;

  cout << "p3: m_a: " << p3.m_a << " " << p3.m_b << endl;
   cout << "p4: m_a: " << p4.m_a << " " << p4.m_b << endl;
}

int main() {
  test();

    cout << 1+1 << endl;

  return 0;
}