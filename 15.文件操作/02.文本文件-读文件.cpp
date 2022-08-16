#include <iostream>
#include <fstream>
using namespace std;

/**
 * 1. 要包含头文件 <fstream>
 * 2. 文件类型分为：
 *      2.1 文本文件   文件以文本的ASCII码形式存储在计算机中
 *      2.2 二进制文件  文件以文本的二进制形式存储在计算机中, 用户一般不能直接读懂他们
 *
 *
 * 3. 文件的三大类：
 *      3.1 ofstream: 写操作
 *      3.2 ifstream: 读操作
 *      3.3 fstream: 读写操作
 */

/**
 *  写文件：
 *      1. 包含头文件  #include <fstream>
 *      2. 创建流对象  ofstream ofs;
 *      3. 打开文件    ofs.open("文件路径", 打开方式)
 *      4. 写数据      ofs << "data data";
 *      5. 关闭文件    ofs.close();
 *
 *  打开方式：
 *      1. ios::in    读文件
 *      2. ios::out   写文件
 *      3. ios::ate   初始位置： 文件尾
 *      4. ios::app   追加方式写文件
 *      5. ios::trunc 如果文件存在先删除， 再创建
 *      6. ios::binary 二进制方式
 *
 *      注意： 文件打开方式可以配合使用： 利用 | 操作符， egg: ios::binary | ios::out
 *
 */

// 文本文件  写文件
void test1()
{
    // 2. 创建流对象
    ofstream ofs;
    // 3. 打开文件
    ofs.open("./test.txt", ios::out | ios::app);
    // 4. 写数据
    ofs << "test" << endl;
    // 5. 关闭文件
    ofs.close();
}

int main()
{
    test1();
    return 0;
}