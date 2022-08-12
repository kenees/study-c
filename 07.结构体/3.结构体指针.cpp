#include <iostream>
using namespace std;

// 1. 结构体指针
// 结构体指针可以通过 -> 访问结构体变量中的数据
// 2. 定义结构体对象
struct Student {
    string name;
    int age;
    int score;
};

int main() {
    // 3. 创建学生结构体变量
    Student s1 = {"张三", 11, 100};
    // 4. 通过指针指向结构体变量
    Student *p = &s1;
    // 5. 通过指针访问机构体变量中的数据
    cout << "name: " << p->name << " age: " << p->age << " score: "<< p->score << endl; 
    return 0;
}