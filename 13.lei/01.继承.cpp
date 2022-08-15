#include <iostream>
using namespace std;

/**
 * @brief 类的继承
 *  class 子类 ： 继承方式 父类
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
 *
 */

class Animal
{
public:
    Animal(string _name, string _food)
    {
        name = _name;
        food = _food;
    }

    void eat()
    {
        cout << this->name << "在吃" << this->food << endl;
    }

    string name;
    int legs;
    int age;
    string food;
};

class Cat : public Animal
{
public:
    Cat(string _name, string _food) : Animal(_name, _food){};
};

void test01()
{
    Animal animal("小东", "猫粮");
    animal.eat();
    Cat cat("小猫", "粮");
    cat.eat();
}

int main()
{
    test01();
    return 0;
}