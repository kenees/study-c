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
    ifstream ifs("./person.txt", ios::in | ios::binary);

    if (!ifs.is_open())
    {
        cout << "打开失败" << endl;
        return;
    }

    PersonList pl;

    ifs.read((char *)&pl, sizeof(PersonList));

    cout << pl.len << endl;

    for (int i = 0; i < pl.len; i++)
    {
        cout << pl.list[i].m_name << " " << pl.list[i].age << endl;
    }

    ifs.close();
};

int main()
{
    test();
    return 0;
}