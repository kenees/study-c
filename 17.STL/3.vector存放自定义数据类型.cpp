#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Person
{
public:
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    string name;
    int age;
};

void test01()
{
    vector<Person> v;
    Person p1("张三1", 10);
    Person p2("张三2", 20);
    Person p3("张三3", 30);
    Person p4("张三4", 40);
    Person p5("张三5", 50);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << (*it).name << " " << (*it).age << endl;
    }
}

// 存放自定义数据的指针
void test02()
{
    vector<Person *> v;
    Person p1("张三1", 10);
    Person p2("张三2", 20);
    Person p3("张三3", 30);
    Person p4("张三4", 40);
    Person p5("张三5", 50);

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    for (vector<Person *>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << (*(*it)).name << " " << (*(*it)).age << endl;
        cout << (*it)->name << " " << (*it)->age << endl;
    }
}

int main()
{
    // test01();
    test02();
    return 0;
}