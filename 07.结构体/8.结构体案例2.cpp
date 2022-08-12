#include <iostream>
using namespace std;

/*
    设计一个英雄的结构体, 包含成员姓名, 年龄, 性别;
    创建结构体数组, 数组中存放5名英雄
    通过冒泡排序算法, 将数组中的英雄按照年龄升序排序, 最终打印排序后的结果
*/

struct Hero {
    string name;
    int age;
    string sex;
};


void sortHero(Hero array[], int size) {
    for(int i = 0; i < size; i ++) {
        for(int j = i+1; j < size; j++) {
            Hero temp = array[i];
            if (array[j].age < temp.age) {
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void printHero(Hero array[], int size) {
    for(int i = 0; i < size; i ++) {
        cout << "name: " << array[i].name << "age: " << array[i].age << "set: " << array[i].sex << endl;
    }
}

int main() {

    Hero heroArray[5] = {
        {"刘备", 23, "男"},
        {"关羽", 24, "男"},
        {"张飞", 20, "男"},
        {"赵云", 21, "男"},
        {"貂蝉", 18, "女"},
    };

    sortHero(heroArray, 5);

    printHero(heroArray, 5);

    return 0;
}