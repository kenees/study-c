#include <iostream>
using namespace std;

/**
 * @brief               Animal
 *                      /     \
 *                   Sheep     Tuo
 *                      \     /
 *                      SheepTuo
 *
 * @return int
 */

// class Animal
// {
// public:
//     int age;
// };

// class Sheep : public Animal
// {
// };

// class Tuo : public Animal
// {
// };

// class SheepTuo : public Sheep, public Tuo
// {
// };

class Animal
{
public:
    int age;
};

class Sheep : virtual public Animal
{
};

class Tuo : virtual public Animal
{
};

class SheepTuo : public Sheep, public Tuo
{
};

void test1()
{
    SheepTuo st;
    st.Sheep::age = 100;
    st.Tuo::age = 200;

    // 二异性， 菱形继承导致有两份数据, 造成浪费
    cout << "sheep::age = " << st.Sheep::age << endl;
    cout << "tuo::age = " << st.Tuo::age << endl;

    // 解决方法：
    // 1. 利用虚继承解决菱形继承的问题  添加 virtual 关键字 变为虚继承
    //      Animal: 虚基类
    //      只保留一份, 同时访问方式添加一种直接访问
    //      所有修改age的方式修改的都是同一个数据

    // 2. 底层原理：
    /**
     *      class SheepTuo
     *          +---
     *      0    |   +--- (base class Sheep)
     *      0    |   | （vbptr）   // 虚基类指针， 指向 vbtable     ------------
     *           |   +---                                                   |  0+8
     *      4    |   +--- (base class Tuo)                                  |
     *      4    |   |  (vbptr)    // 虚基类指针， 指向 vbtable   -------------|-----
     *           |   +---                                                   |     |
     *           +---                                                       |     |
     *           +--- (virtual base Animal)                                 |     |
     *      8    | m_age                                                    |     |
     *           +---                                                       |     |  4+4    两个指针根据偏移量指向同一个地址
     *                                                                      |     |
     *      SheepTuo::$vbtable Sheep@:    <----------------------------------     |
     *      0    | 0                                                              |
     *      1    | 8 (SheepTuod(Sheep+0)Animal)                                   |
     *      SheepTuo::$vbtable Tuo@:     <-----------------------------------------
     *      0    | 0
     *      1    | 4 (SheepTuod(Tuo+0)Animal)
     */
    cout << "st.age = " << st.age << endl;
};

int main()
{
    test1();
    return 0;
}