#include <iostream>
using namespace std;

int main() {

  // 选择结构 if
  int score = 0;
  cout << "请输入分数：。" << endl;
  cin >> score;
  if (score > 650) {
    cout << "一本 " << endl;
  } else if (score > 450) {
    cout << "er本 " << endl;
  } else {
    cout << "san ben " << endl;
  }

  // 三目运算符
  int a = 1;
  int b = 2;
  int c = 0;

  c = a > b ? a : b;
  cout << c << endl;

  // 三目 运算符 返回 变量可继续赋值
  (a > b ? a : b) = 100;
  cout << a << b << endl;
  // switch 判断时只能判断整型，字符型， 不可以是一个区间
  // 比if效率高
  // ======================
  // 循环结构
  //。while
  // do ... while
  // for
  int i = 0;
  while (i < 10) {
    cout << i << endl;
    i++;
  }

  do {
    cout << i << endl;
    i++;
  } while (i < 20);

  for(int i = 0; i < 10; i ++) {

  }

// 死循环
  //for(;;) {
  //    cout << 1 << endl;
  //}
  return 0;
}