#include "iostream"

using namespace std;

class Person
{
public:
    int id;
    string name;
    int post; // 1: 普通员工， 2： 经理 3：老板
};

class PersonBook
{
public:
    void getPersonList();

    void appendPerson(Person &p);

    void deletePerson();
};