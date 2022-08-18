#include <stdio.h>
#include <iostream>
#include <fstream>

int getchar(void);

using namespace std;

class PersonBooks;
void saveData(PersonBooks &pb);
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
  Person books[100];
  int len = 0;

  void showPerson(Person &p)
  {
    cout << "序号: " << p.id << "\t\t"
         << "姓名: " << p.name << "\t\t"
         << "职位: " << p.post << "\t\t" << endl;
  }

  void showPersonList()
  {
    for (int i = 0; i < this->len; i++)
    {
      this->showPerson(this->books[i]);
    }
  }

  int getByName(string name)
  {
    int i = 0;
    while (i < len)
    {
      if (this->books[i].name == name)
      {
        return i;
      };
      i++;
    }
    return -1;
  };

  void saveToFile()
  {
    ofstream ofs("./sql.txt", ios::out | ios::binary);
    if (!ofs.is_open())
    {
      // 打开文件失败
      cout << "文件打开失败" << endl;
    }
    else
    {
      ofs.write((const char *)this, sizeof(PersonBooks));
      ofs.close();
    }
  };

  void appendPerson(Person &p)
  {
    if (len >= 100)
    {
      cout << "存储数据超过上限,请删除部分联系人后添加" << endl;
      return;
    }
    books[len] = p;
    len++;
    this->saveToFile();
  }

  void deletePerson(int n)
  {
    this->showPerson(this->books[n]);

    for (int i = n; i < len; i++)
    {
      this->books[i] = this->books[i + 1];
    }
    this->len--;
    this->saveToFile();
    cout << "删除成功" << endl;
  }

  void editPserson(Person &p, int n)
  {
    this->books[n] = p;
    this->saveToFile();
    cout << "编辑成功" << endl;
  };

  void sortById(int mode)
  {
    if (mode == 1) // 升
    {
      for (int i = 0; i < len; i++)
      {
        for (int j = i + 1; j < len; j++)
        {
          if (this->books[i].id > this->books[j].id)
          { // 依次比较, 找到最xiao的放到第i位
            Person max = this->books[i];
            this->books[i] = this->books[j];
            this->books[j] = max;
          }
        }
      }
    }
    else
    {
      for (int i = 0; i < len; i++)
      {
        for (int j = i + 1; j < len; j++)
        {
          if (this->books[i].id < this->books[j].id)
          { // 依次比较, 找到最小的放到第i位
            Person min = this->books[i];
            this->books[i] = this->books[j];
            this->books[j] = min;
          }
        }
      }
    }

    this->showPersonList();
  }
};

class Termina
{
public:
  Termina(PersonBooks &books)
  {
    ifstream ifs;
    ifs.open("./sql.txt", ios::in | ios::binary);

    if (!ifs.is_open())
    {
      // 打开文件失败
      cout << "文件打开失败" << endl;
      return;
    }
    ifs.read((char *)&books, sizeof(books));
  }

  void showMenu()
  {
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

  void addPerson(PersonBooks &books)
  {
    Person p;
    cout << "请输入ID： " << endl;
    cin >> p.id;
    cout << "请输入用户名： " << endl;
    cin >> p.name;
    cout << "请输入用户职位(1:普通员工 2:经理 3:老板): " << endl; // 1: 普通员工， 2： 经理 3：老板
    cin >> p.post;
    books.appendPerson(p);
  }

  void deletePerson(PersonBooks &books)
  {

    string name;
    cout << "请输入需要删除的用户名： " << endl;
    cin >> name;
    int i = books.getByName(name);
    if (i == -1)
    {
      cout << "未查询到该用户" << endl;
    }
    else
    {
      books.deletePerson(i);
    }
  }

  void editPerson(PersonBooks &books)
  {
    string name;
    cout << "请输入需要编辑的用户名： " << endl;
    cin >> name;

    int i = books.getByName(name);
    if (i == -1)
    {
      cout << "未查询到该用户" << endl;
    }
    else
    {
      books.showPerson(books.books[i]);
      Person np;
      cout << "请输入新序号: ";
      cin >> np.id;
      cout << "请输入新名称: ";
      cin >> np.name;
      cout << "请输入新用户职位(1:普通员工 2:经理 3:老板):";
      cin >> np.post;
      books.editPserson(np, i);
    }
  }

  void findByName(PersonBooks &books)
  {
    string name;
    cout << "请输入需要查询的用户名： " << endl;
    cin >> name;

    int i = books.getByName(name);
    if (i == -1)
    {
      cout << "未查询到该用户" << endl;
    }
    else
    {
      books.showPerson(books.books[i]);
    }
  }

  void sortById(PersonBooks &books)
  {
    int mode = 0;
    while (true)
    {
      cout << "请选择排序方式(0: 降序, 1: 升序): ";
      cin >> mode;
      if (mode == 0 || mode == 1)
      {
        books.sortById(mode);
        break;
      }
    }
  }
};

void start()
{
  int select = 0;
  PersonBooks books;
  Termina t(books);

  while (true)
  {
    t.showMenu();
    cout << "请选择操作： " << endl;
    cin >> select;
    system("clear");
    switch (select)
    {
    case 1:
      t.addPerson(books);
      break;
    case 2:
      books.showPersonList();
      break;
    case 3:
      t.deletePerson(books);
      break;
    case 4:
      t.editPerson(books);
      break;
    case 5:
      t.findByName(books);
      break;
    case 6:
      t.sortById(books);
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