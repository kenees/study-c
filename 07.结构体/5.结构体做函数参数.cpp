#include <iostream>
using namespace std;

// 结构体做函数参数传递
// 1. 值传递
// 2. 地址传递

struct Student {
  string name;
  int age;
  int score;
};

// 值传递时改变形参不会改变原始值
void fun1(Student s) {
  s.age = 40;
  cout << "name: " << s.name << " age: " << s.age << " score: " << s.score
       << endl;
};

void fun2(Student *s) {
  s->age = 100;
  cout << "name: " << s->name << " age: " << s->age << " score: " << s->score
       << endl;
};

int main() {

  Student s = {"张三", 11, 100};

  Student *s1 = &s;
  fun1(s);
  cout << "name: " << s.name << " age: " << s.age << " score: " << s.score
       << endl;
  fun2(s1);
  cout << "name: " << s.name << " age: " << s.age << " score: " << s.score
       << endl;
  return 0;
}