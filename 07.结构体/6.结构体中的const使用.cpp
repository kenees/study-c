#include <iostream>
using namespace std;

struct Student {
  string name;
  int age;
  int score;
};

// 会拷贝整个对象, 对象属性过多时会占用过多内存
void printStudent(Student s) {
  cout << "姓名: " << s.name << "年龄: " << s.age << "分数:" << s.score << endl;
}

// 将形参改成指针可以节省内存空间, 但是函数中修改值会影响外部数据
// 添加 const 防止误操作
void printStudent2(const Student *s) {
    // s->age = 200;
    cout << "姓名: " << s->name << "年龄: " << s->age << "分数:" << s->score << endl;
}

int main() {
  Student s1 = {"张三", 11, 100};
  printStudent(s1);
  printStudent2(&s1);
  return 0;
}