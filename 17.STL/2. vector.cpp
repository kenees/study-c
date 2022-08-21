#include <iostream>
using namespace std;

#include <vector>
#include <algorithm> // 标准算法头文件
/**
 *  容器算法迭代器
 *
 *  vector春风内置数据类型
 *
 *  容器： vector
 *  算法： for_each
 *  迭代器：vector<int>:interator
 *
 *
 */

void myPrint(int val)
{
    cout << val << endl;
}

void test01()
{
    vector<int> v;
    v.push_back(10); // 尾插
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    // 1. 通过迭代器访问
    vector<int>::iterator itBegin = v.begin(); // 起始迭代器， 指向容器中第一个元素
    vector<int>::iterator itEnd = v.end();     // 结束迭代器， 指向容器中最后一个元素的下一个位置

    while (itBegin != itEnd)
    {
        cout << *itBegin << endl;
        itBegin++;
    }

    // 2. 常用方式
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }

    // 3. 利用STL中提供的遍历算法
    for_each(v.begin(), v.end(), myPrint);
}

int main()
{
    test01();
    return 0;
}