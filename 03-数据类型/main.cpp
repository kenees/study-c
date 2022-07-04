#include <iostream>

using namespace std;

int main() {

  short num1 = 10;
  int num2 = 20;
  long num3 = 30;
  long long num4 = 40;

  cout << "short占用内存空间大小:" << sizeof(short) << endl;
  cout << "int占用内存空间大小:" << sizeof(int) << endl;
  cout << "long占用内存空间大小:" << sizeof(long) << endl;
  cout << "long long占用内存空间大小:" << sizeof(long long) << endl;

  //. 浮点型
  // 1. 单精度 float
  // 2. 双精度 double
  // 默认情况下输出一个小数，辉县市 6位有效数字

  float f1 = 3.1415926f;
  double f2 = 3.1415926;

  cout << "float:" << f1 << "内存 空间 ：" << sizeof(f1) << endl;
  cout << "double:" << f2 << "内存空间: " << sizeof(f2) << endl;

  // 3. 科学计数法
  float f3 = 3e2;  // 3*10 ^ 2
  float f4 = 3e-2; // 3*0.1^2

  cout << "f3: " << f3 << " f4: " << f4 << endl;

  // 4. 字符型
  // 单字符，单引号 1字节
  char ch = 'a';

  cout << "ch ascll 码:" << int(ch) << endl;

  //. 5.  字符串
  // 多字符，
  //。5.1 c风格字符串。char ch1[] = "abcdef"
  //. 5.2 c++风格 字符串 string ch2 = "abcdefg"

  char str1[] = "wangcheng";
  cout << "c类型字符串:" << str1 << endl;
  string str2 = "chengcheng";
  cout << "c++类型字符串:" << str2 << endl;


// 布尔类型. 1个字节
bool flag = true;
cout << flag << endl;


  return 0;
}