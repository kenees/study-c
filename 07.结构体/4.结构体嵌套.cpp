#include <iostream>
using namespace std;

struct Student {
  string name;
  int age;
  int score;
};

struct Teacher {
  int id;
  string name;
  int age;
  Student stu; // 或: struct Student stu;
};

int main() {
  // 结构体嵌套结构体
  Teacher t = {1001, "王老师", 28, {"小学生", 11, 100}};
  cout << "name: " << t.name << " age: " << t.age << "编号: " << t.id
       << " std.name: " << t.stu.name << " std.age: " << t.stu.age
       << " std.score: " << t.stu.score << endl;
  return 0;
}