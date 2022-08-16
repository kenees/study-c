#include <iostream>
using namespace std;
/**
 * 总结：
 *      1. 虚析构或纯虚析构就是用来解决通过父类指针释放子类对象
 *      2. 如果子类中没有堆区数据, 可以不写为虚析构或纯虚析构
 *      3. 拥有纯虚析构函数的类属于抽象类, 无法实例化
 *
 */

/**
 * @brief 多态使用时, 如果子类中有属性开辟到堆区, 那么父类指针在释放时无法调用到子类的析构代码， 会造成内存泄漏
 *
 * 解决方式： 将父类中的析够函数改为虚析构或者纯虚析构
 *
 * 虚析构或者纯虚析构共性：
 *  1. 可以解决父类指针释放子类对象
 *  2. 都需要有具体的函数实现
 *
 * 虚析构或者纯虚析构区别：
 *   1. 纯虚析构， 该类属于抽象类, 无法实例化
 *
 */

class Animal
{
public:
    virtual void speak() = 0;

    Animal()
    {
        cout << "Animation构造函数调用" << endl;
    }

    // 解决子类析构不调用导致内存泄漏的问题
    // virtual ~Animal()
    // {
    //     cout << "Animation析构函数调用" << endl;
    // }

    // 纯虚析构
    // 虚析构必须要有实现类
    // 可在类外实现
    virtual ~Animal() = 0;
};

Animal::~Animal()
{
    cout << "Animation纯析构函数调用" << endl;
}

class Cat : public Animal
{
public:
    Cat(string name)
    {
        cout << "cat构造函数调用" << endl;
        m_name = new string(name);
    }

    void speak()
    {
        cout << *m_name << "小猫在说话" << endl;
    }

    ~Cat()
    {
        if (m_name != NULL)
        {
            cout << "cat析构函数调用" << endl;
            delete m_name;
            m_name = NULL;
        }
    }

    string *m_name;
};

void test1()
{
    Animal *animal = new Cat("tom");
    animal->speak();
    // 父类指针在析构的时候， 不会调用子类的析构函数， 导致子类如果有堆区属性， 出现内存泄漏
    // 将父类析构函数改成虚函数即可
    delete animal;
};

int main()
{
    test1();
    return 0;
}