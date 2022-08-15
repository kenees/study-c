#include <iostream>
#include <fstream>
using namespace std;

/**
 * @brief 读文件与写文件步骤相似， 但是读取方式相对于比较多
 *
 *  步骤：
 *      1. 包含头文件    #include <fstream>
 *      2. 创建流对象    ifstream ifs;
 *      3. 打开文件并判断文件是否打开成功   ifs.open("文件路径", 打开方式)
 *      4. 读数据
 *          四种方式读取
 *
 *      5. 关闭文件     ifs.close();
 *
 *      打开方式
 *              _S_app 		= 1L << 0,
                _S_ate 		= 1L << 1,
                _S_bin 		= 1L << 2,
                _S_in 		= 1L << 3,
                _S_out 		= 1L << 4,
                _S_trunc 		= 1L << 5,
                _S_ios_openmode_end = 1L << 16,
                _S_ios_openmode_max = __INT_MAX__,
                _S_ios_openmode_min = ~__INT_MAX__
 */

void test()
{
    // 2. 创建流对象
    ifstream ifs;
    ifs.open("./text.txt", ios::in);

    // 判断是否打开成功
    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }

    // 读数据
    // 第一种：
    // char buf[1024] = {0};
    // while (ifs >> buf) {
    //     cout << buf << endl;
    // }

    // 第二种
    // char buf1[1024] = {0};
    // while (ifs.getline(buf1, sizeof(buf1))) {
    //     cout << ": " <<  buf1 << endl;
    // }

    // 第三种
    // string buf;
    // while (getline(ifs, buf))
    // {
    //     /* code */
    //     cout << buf << endl;
    // }

    // 第四种， 不推荐
    char c;
    while ((c = ifs.get()) != EOF)
    { // end of file
        cout << c << endl;
    }

    ifs.close();
};

int main()
{
    test();
    return 0;
}