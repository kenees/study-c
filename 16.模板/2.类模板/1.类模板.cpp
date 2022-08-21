#include <iostream>
using namespace std;

// 类模板
template <class NameType, class AgeType>
class Person
{
public:
    Person(NameType name, AgeType age)
    {
        this->age = age;
        this->name = name;
    }

    void showPerson()
    {
        cout << "name: " << this->name << " age: " << this->age << endl;
    }

    NameType name;
    AgeType age;
};

void test01()
{
    Person<string, int> p1("张三", 12);
    Person<string, int> p2("李四", 12);

    cout << "p1.name: " << p1.name << endl;
    p1.showPerson();
    p2.showPerson();
};

int main()
{
    test01();
    return 0;
}