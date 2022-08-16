#include <iostream>
using namespace std;

/**
 * 电脑主要组成部件为cpu， 显卡， 内存条
 * 将每个零件封装出抽象类, 并且提供不同的厂商生产不同的零件， 例如 inter厂商和lenovo厂商
 * 创建电脑类提供让电脑工作的函数， 并且调用每个零件工作的接口
 * 测试时组装三台不同的电脑进行工作
 *
 * @return int
 */

// cpu
class Cpu
{
public:
    // 计算
    virtual void calculate() = 0;
};

// 显卡
class Grap
{
public:
    // 显示
    virtual void display() = 0;
};

// 内存条
class Memory
{
public:
    // 存储
    virtual void storage() = 0;
};

// 电脑类
class Computer
{
public:
    Computer(Cpu *cpu, Grap *grap, Memory *memory)
    {
        this->cpu = cpu;
        this->grap = grap;
        this->memory = memory;
    };

    void work()
    {
        this->cpu->calculate();
        this->grap->display();
        this->memory->storage();
    };

    ~Computer()
    {
        if (this->cpu != NULL)
        {
            delete this->cpu;
            cout << "卸载cpu" << endl;
        }
        if (this->grap != NULL)
        {
            delete this->grap;
            cout << "卸载grap" << endl;
        }
        if (this->memory != NULL)
        {
            delete this->memory;
            cout << "卸载memory" << endl;
        }
    }

    Cpu *cpu;
    Grap *grap;
    Memory *memory;
};

// 厂商
// Inter
class InterCpu : public Cpu
{
public:
    void calculate()
    {
        cout << "Inter的cpu开始计算了" << endl;
    }
};
class InterGrap : public Grap
{
public:
    void display()
    {
        cout << "Inter的显卡开始显示了" << endl;
    }
};
class InterMemory : public Memory
{
public:
    void storage()
    {
        cout << "Inter的内存开始存储了" << endl;
    }
};
// lenovo
class LenovoCpu : public Cpu
{
public:
    void calculate()
    {
        cout << "lenovo的cpu开始计算了" << endl;
    }
};
class LenovoGrap : public Grap
{
public:
    void display()
    {
        cout << "Lenovo的显卡开始显示了" << endl;
    }
};
class LenovoMemory : public Memory
{
public:
    void storage()
    {
        cout << "Lenovo的内存开始存储了" << endl;
    }
};
// 测试阶段
// 组装三台不同的电脑
void test1()
{
    Cpu *cpu1 = new InterCpu;
    Grap *grap1 = new LenovoGrap;
    Memory *memory1 = new LenovoMemory;
    Computer *computer1 = new Computer(cpu1, grap1, memory1);
    computer1->work();
    delete computer1;

    // -----------

    Computer *computer2 = new Computer(new InterCpu(), new InterGrap(), new InterMemory());
    Computer computer3(new LenovoCpu(), new LenovoGrap(), new LenovoMemory());

    computer2->work();
    delete computer2;
    computer3.work();
}

int main()
{
    test1();
    return 0;
}