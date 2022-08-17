#include <cstddef>
#include <iostream>
#include <fstream>
using namespace std;

class Person
{
public:
  int id;
  string name;
  int post; // 1: 普通员工， 2： 经理 3：老板
};

class PersonBooks
{
public:
  // Person books[100];
  int len = 0;
};

class FileOperation
{
public:
  FileOperation()
  {
    cout << "begin read sql " << sizeof(PersonBooks) << endl;
    ifstream ifs;
    ifs.open("./sql.txt", ios::in | ios::binary);

    if (!ifs.is_open())
    {
      // 打开文件失败
      cout << "文件打开失败" << endl;
      return;
    }

    PersonBooks pbs;
    ifs.read((char *)&pbs, sizeof(PersonBooks));

    cout << pbs.len << endl;
  }

  void showPersonList()
  {
    ifstream ifs;
    ifs.open("./sql.txt", ios::in);

    if (!ifs.is_open())
    {
      cout << "文件打开失败" << endl;
      return;
    }

    cout << "序号 \t"
         << "ID \t"
         << "姓名 \t"
         << "职位 \t" << endl;

    PersonBooks pbs;
    ifs.seekg(0, ios::beg);
    ifs.read((char *)&pbs, sizeof(PersonBooks));

    cout << "pbs" << pbs.len << endl;
    ifs.close();
  }

  void appendPerson(Person &p)
  {
    fstream ofs;
    ofs.open("./sql.txt", ios::out | ios::in | ios::binary | ios::app);

    if (!ofs.is_open())
    {
      cout << "文件打开失败" << endl;
      system("pause");
    }
    else
    {
      PersonBooks pbs2;
      ofs.read((char *)&pbs2, sizeof(PersonBooks));

      cout << "pbs" << pbs2.len << endl;


      // 手动添加
      PersonBooks pbs1 = {
        pbs2.len+1,
      };

      // pbs.books[pbs.len] = p;
      ofs.seekp(0, ios::beg);
      ofs.write((const char *)&pbs1, sizeof(PersonBooks));
      ofs.close();
    }
  }

  void deletePerson()
  {
  }
};

class Termina
{
public:
  void showMenu()
  {
    // system("clear");
    cout << "***********************" << endl;
    cout << "*** 1. 增加职工信息 ***" << endl;
    cout << "*** 2. 显示职工信息 ***" << endl;
    cout << "*** 3. 删除离职职工 ***" << endl;
    cout << "*** 4. 修改职工信息 ***" << endl;
    cout << "*** 5. 查找职工信息 ***" << endl;
    cout << "*** 6. 按照编号排序 ***" << endl;
    cout << "*** 7. 清空所有文档 ***" << endl;
    cout << "*** 0. 退出 ***********" << endl;
  }

  void quit() { cout << "欢迎下次继续使用" << endl; }

  void addPerson(FileOperation &fo)
  {
    system("clear");
    Person p;
    cout << "请输入ID： " << endl;
    cin >> p.id;
    cout << "请输入用户名： " << endl;
    cin >> p.name;
    cout << "请输入用户职位(1:普通员工 2:经理 3:老板): " << endl; // 1: 普通员工， 2： 经理 3：老板
    cin >> p.post;

    fo.appendPerson(p);
  }
};

void start()
{
  int select = 0;
  Termina t;
  FileOperation fo;

  while (true)
  {
    t.showMenu();
    cout << "请选择操作： " << endl;
    cin >> select;
    switch (select)
    {
    case 1:
      t.addPerson(fo);
      break;
    case 2:
      fo.showPersonList();
      break;
    case 3:
      cout << "113" << endl;
      break;
    case 4:
      cout << "114" << endl;
      break;
    case 5:
      cout << "115" << endl;
      break;
    case 6:
      cout << "116" << endl;
      break;
    case 7:
      cout << "117" << endl;
      break;
    case 0:
      t.quit();
      return;
    default:
      break;
    }
  }
}

int main()
{
  start();
  return 0;
}