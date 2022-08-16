#include <iostream>
using namespace std;

class Person
{
public:
  static int m_A;
  int m_B;

  static void func()
  {
    cout << "static void func: " << m_A << endl;
    // 3. 静态方法只能访问静态成员变量，无法区分是那个对象的成员变量
    // cout << "static void func: " << m_B << endl;
  }

  // 3.外部无法访问私有成员变量和函数
protected:
  static void func2()
  {
    cout << "static void func2:" << endl;
  }
};
// 1. 静态成员变量必须在类外初始化
// 原因： 避免重复定义， 比如两个线程都创建了该类的对象， 如果初始化时就定义了, 就会产生竞争， 造成死锁

int Person::m_A = 10;

int main()
{
  Person p;
  // p.m_A = 300;
  cout << p.m_A << endl;

  Person p2;
  // 2. 静态成员变量所有成员共享
  p2.m_A = 300;
  cout << p.m_A << Person::m_A << endl;

  return 0;
}