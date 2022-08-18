#include <iostream>
#include <fstream>
using namespace std;

class Person
{
public:
    char m_name[64];
    int age;
};

class PersonList
{
public:
    Person list[100];
    int len;
};

void test()
{
    // 2. 创建流对象
    ofstream ofs("./person.txt", ios::out | ios::binary);

    // ofs.open("person.txt", ios::out | ios::binary);

    Person p = {"张三", 12};
    Person p2 = {"张三2", 121};
    Person p3 = {"张三3", 122};
    Person p4 = {"张三4", 123};
    Person p5 = {"张三5", 124};

    PersonList pl;
    pl.list[0] = p;
    pl.list[1] = p2;
    pl.list[2] = p3;
    pl.list[3] = p4;
    pl.list[4] = p5;

    pl.len = 5;

    ofs.write((const char *)&pl, sizeof(PersonList));

    ofs.close();
};

int main()
{
    test();
    return 0;
}