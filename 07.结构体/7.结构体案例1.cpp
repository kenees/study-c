#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;


/*
    案例描述:
        学校正在做必设项目, 每名老师带领5个学生, 总共有3个老师, 需求如下:
        设计学生和老师的结构体, 其中在老师的结构体中, 有老师姓名和一个存放5名学生的数组作为成员
        学生的成员有姓名, 考试分数, 创建数组存放3名老师, 通过函数给每个老师及所带的学生赋值
        最终打印出老师数据及老师所带学生数据
*/ 

struct Student {
    string name;
    int score;
};

struct Teacher {
    string name;
    Student stus[5];
};

void allocateSpace(Teacher teachers[], int len) {
    for(int i = 0; i < 3; i ++) {

        teachers[i].name = "teach_"+to_string(i);
        for(int j = 0; j < 5; j ++) {
            teachers[i].stus[j].name = "stud_"+to_string(j);
            teachers[i].stus[j].score = random() % 101;
        }
    }
    return;
}

int main() {

    // 随机数种子
    srand((unsigned int)time(NULL));

    Teacher teachers[3];
    allocateSpace(teachers, 3);

    for(int i = 0; i < 3; i ++) {
        cout << "teach: " << teachers[i].name << endl;
        for(int j = 0; j < 5; j ++) {
            cout << "\tstudent: " << teachers[i].stus[j].name << " score: " << teachers[i].stus[j].score << endl;
        }
    }


    return 0;
}