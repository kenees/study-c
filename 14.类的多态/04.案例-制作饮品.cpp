#include <iostream>
using namespace std;

/**
 * @brief 描述： 制作饮品的大致流程为： 煮水-冲泡-导入杯中-加入辅料
 *
 * 利用多态技术实现： 提供抽象制作饮品基类, 提供子类制作咖啡和茶叶
 *
 * @return int
 */

class AbstractDrinking
{
public:
    // 煮水
    virtual void Boil() = 0;

    // 冲泡
    virtual void Brew() = 0;

    // 导入杯中
    virtual void PourInCup() = 0;

    // 加入辅料
    virtual void PutSomething() = 0;

    // 制作
    void makeDring()
    {
        Boil();
        Brew();
        PourInCup();
        PutSomething();
    }
};

// 制作咖啡
class Coffee : public AbstractDrinking
{
public:
    // 煮水
    virtual void Boil()
    {
        cout << "煮山泉" << endl;
    };

    // 冲泡
    virtual void Brew()
    {
        cout << "冲咖啡" << endl;
    };

    // 倒入杯中
    virtual void PourInCup()
    {
        cout << "倒入杯中" << endl;
    };

    // 加入辅料
    virtual void PutSomething()
    {
        cout << "加入糖和牛奶" << endl;
    };
};

// 制作茶叶
class Tea : public AbstractDrinking
{
public:
    // 煮水
    virtual void Boil()
    {
        cout << "煮矿水" << endl;
    };

    // 冲泡
    virtual void Brew()
    {
        cout << "冲茶叶" << endl;
    };

    // 倒入杯中
    virtual void PourInCup()
    {
        cout << "倒入杯中" << endl;
    };

    // 加入辅料
    virtual void PutSomething()
    {
        cout << "加入枸杞" << endl;
    };
};

void doWork(AbstractDrinking *abs)
{
    abs->makeDring();
    delete abs;
}

void test01()
{
    doWork(new Coffee);
    doWork(new Tea);
}

int main()
{
    test01();
    return 0;
}