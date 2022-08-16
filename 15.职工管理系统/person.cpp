#include <iostream>
#include <fstream>
#include "person.h"

using namespace std;

// class Person
// {
// public:
//     int id;
//     string name;
//     int post; // 1: 普通员工， 2： 经理 3：老板


// };

class PersonBook
{
public:
    void getPersonList()
    {
        ifstream ifs;
        ifs.open("./sql.text", ios::in);

        if (!ifs.is_open())
        {
            cout << "文件打开失败" << endl;
            return;
        }

        string buf;
        while (getline(ifs, buf))
        {
            /* code */
            cout << buf << endl;
        }
    }

    void appendPerson(Person &p)
    {
        fstream ofs;
        ofs.open("./sql.text", ios::out | ios::app);

        if (!ofs.is_open())
        {
            cout << "文件打开失败" << endl;
        }
        else
        {
            ofs.seekg(-sizeof(Person), ios::end);

            string s;

            getline(ofs, s);

            cout << s << endl;

            // ofs << "test" << endl;

            ofs.close();
        }
    }

    void deletePerson()
    {
    }
};