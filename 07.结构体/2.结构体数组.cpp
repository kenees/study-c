#include <iostream>
using namespace std;

// 结构体数组
// 1. 定义结构体
struct Student {
  string name;
  int age;
  int score;
};

int main() {
  // 2. 创建结构体数组
  struct Student stdArray[3] = {
      {"张三", 11, 110},
      {"李四", 22, 220},
      {"王五", 33, 330},
  };
  // 3. 给结构体数组中的元素赋值
  stdArray[2].age = 1;
  stdArray[0].age = 1;
  stdArray[1].age = 1;
  // 4. 遍历结构体数组
  for (int i = 0; i < 3; i++) {
    cout << "name: " << stdArray[i].name << "age: " << stdArray[i].age
         << "分数: " << stdArray[i].score << endl;
  }
  return 0;
}