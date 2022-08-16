#include <iostream>
#include <fstream>
using namespace std;

class Person {
    public:
        char m_name[64];
        int age;
};

void test() {
    // 2. 创建流对象
    ofstream ofs("./014.file/person.txt", ios::out | ios::binary);

    //ofs.open("person.txt", ios::out | ios::binary);

    Person p = {"张三", 12};
    ofs.write((const char *)&p, sizeof(Person));

    ofs.close();
};

int main() {
    test();
    return 0;
}