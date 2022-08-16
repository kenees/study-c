#include <iostream>
using namespace std;

/**
 * @brief 分别利用普通写法和多态技术， 实现两个操作数进行运算的计算器类
 *
 * @return int
 */

// 普通写法
class Calculator
{
public:
    int num1;
    int num2;

    int getResult(string oper)
    {
        if (oper == "+")
        {
            return num1 + num2;
        }
        else if (oper == "-")
        {
            return num1 - num2;
        }
        else if (oper == "*")
        {
            return num1 * num2;
        }
        // 如果想扩展新的功能， 需要修改原码
        // 在真实的开发中， 提倡开闭原则 ： 对扩展进行开放, 对修改进行关闭
        //
    };
};

void test1()
{
    Calculator cal;
    cal.num1 = 100;
    cal.num2 = 3;
    cout << "+: " << cal.getResult("+") << endl;
    cout << "-: " << cal.getResult("-") << endl;
    cout << "*: " << cal.getResult("*") << endl;
    // cout << "/: " << cal.getResult("/") << endl;
};

// 2. 利用多态实现计算器
// 实现计算器抽象类
// 好处： 1. 组织结构清晰
//       2. 可读性强
//       3. 对于前期和后期扩展及维护性高
class AbstractCalculator
{
public:
    virtual int getResult()
    {
        return 0;
    }

    int num1;
    int num2;
};

// 加法类
class AddCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return num1 + num2;
    }
};

// 减法类
class SubCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return num1 - num2;
    }
};

// 乘法类
class MulCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return num1 * num2;
    }
};

// 除法类
class DivCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return num1 / num2;
    }
};

void test2()
{

    AbstractCalculator *abs = new AddCalculator;
    abs->num1 = 10;
    abs->num2 = 20;
    cout << "num1 + num2 = " << abs->getResult() << endl;

    // 用完后记得销毁
    delete abs;

    // 减法
    abs = new SubCalculator;
    abs->num1 = 10;
    abs->num2 = 20;
    cout << "num1 - num2 = " << abs->getResult() << endl;

    // 用完后记得销毁
    delete abs;

    // 乘法
    abs = new MulCalculator;
    abs->num1 = 10;
    abs->num2 = 20;
    cout << "num1 * num2 = " << abs->getResult() << endl;

    // 用完后记得销毁
    delete abs;

    // 除法
    abs = new DivCalculator;
    abs->num1 = 10;
    abs->num2 = 20;
    cout << "num1 / num2 = " << abs->getResult() << endl;
};

int main()
{
    test1();
    test2();
    return 0;
}