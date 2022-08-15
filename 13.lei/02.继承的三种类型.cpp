
/**
 * @brief
 *  class B {
 *      public:
 *          int a;
 *      protected:
 *          int b;
 *      private: (子类不可访问)
 *          int c;
 *  }
 *  class Child: public Parent;
 *         class A : public B {
 *              public:
 *                  int a;
 *              protected:
 *                  int b;
 *              （private:）不可访问
 *                  int c;
 *          }
 *  class Child: private Parent;
 *          class A : private B {
 *                private:
 *                  int a;
 *                  int b;
 *              （private:）不可访问
 *                //  int c;
 *          }
 *  class Child: protected Parent; // 保护权限
 *          class A : protected B {
 *              protected:
 *                  int a;
 *                  int b;
 *              （private:）不可访问
 *               //   int c;
 *          }
 *
 *   private: 私有属性, 不管那种方式都无法继承
 *
 */
#include <iostream>
using namespace std;

//=====公共继承===========
class Base
{
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C;
};

class Son1 : public Base
{
public:
    void func()
    {
        m_A = 10;
        m_B = 20;
        // m_C = 30; // 无法访问
    }
};
void test01()
{
    Son1 son1;
    son1.func();
    cout << "public: m_A: " << son1.m_A << endl;
    // 无法访问  m_B, m_C
};

// =====保护继承==========
class Son2 : protected Base
{
public:
    void func()
    {
        m_A = 10;
        m_B = 30;
        // m_C = 40;
    }
};

void test02()
{
    Son2 son2;
    son2.func();
    // cout << "public: m_A: " << son2.m_A << endl;
    // 无法访问 m_A m_B, m_C, public变成 protected属性
};

// =====私有继承====
class Son3 : private Base
{
public:
    void func()
    {
        m_A = 100;
        m_B = 100;
        // m_C = 100;
    }
};

void test03()
{
    Son3 son3;
    son3.func();
    // cout << "public: m_A: " << son3.m_A << endl;
    // 无法访问 m_A m_B, m_C, public, protected都变成 private属性
};

int main()
{
    test01();
    test02();
    test03();
    return 0;
}