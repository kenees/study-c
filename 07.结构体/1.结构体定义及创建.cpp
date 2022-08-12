#include <iostream>
using namespace std;

// 语法: struct 结构体名 {结构体成员列表};
// 通过结构体创建变量的方式有三种: (创建对象, 创建对象时 struct关键字可以省略)
    // 1 struct 结构体名 变量名;
    // 2 struct 结构体名 变量名 = {成员1值, 成员2值...};
    // 3 定义结构体时顺便创建变量

// 1. 创建学生数据类型
struct Student {
    string name;
    int age;
    string sex;
    int score;
} s3; // 定义结构体时顺便创建变量

// 2. 通过学生类型创建具体学生
int main () {
    // 2.1 struct 结构体名 变量名;
    Student s1; // struct Student s1; 
    s1.name = "wangcheng";
    s1.age = 28;
    s1.sex = "man";
    s1.score = 100;
    cout << "姓名: " << s1.name << "年龄: " << s1.age << "性别: " << s1.sex << "分数: " << s1.score << endl;

    // 2.2 struct 结构体名 变量名 = (成员1值, 成员2值...);
    Student s2 = {"wang", 11, "woman", 190}; // struct Student s2 = {"wang", 11, "woman", 190};
    cout << "姓名: " << s2.name << "年龄: " << s2.age << "性别: " << s2.sex << "分数: " << s2.score << endl;

    // 2.3 定义结构体时顺便创建变量
    s3.age = 16;
    s3.name = "cheng";
    // s3.sex = "unknown";
    // s3.score = 100;
    cout << "姓名: " << s3.name << "年龄: " << s3.age << "性别: " << s3.sex << "分数: " << s3.score << endl;

    return 0;
}