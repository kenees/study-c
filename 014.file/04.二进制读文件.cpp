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
    ifstream ifs("./014.file/person.txt", ios::in | ios::binary);

    if (!ifs.is_open()) {
        cout << "打开失败" << endl;
        return;
    }

    Person p;
    ifs.read((char *)&p, sizeof(Person));
    
    cout << p.age << p.m_name << endl;
    
    ifs.close();
};

int main() {
    test();
    return 0;
}