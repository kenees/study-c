#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <type_traits>
using namespace std;

#define MAX 1000

// ============================================
/*
    1. 菜单功能
*/
void showMenu() {
  system("clear");
  cout << "*************************" << endl;
  cout << "***** 1. 添加联系人 *****" << endl;
  cout << "***** 2. 显示联系人 *****" << endl;
  cout << "***** 3. 删除联系人 *****" << endl;
  cout << "***** 4. 查找联系人 *****" << endl;
  cout << "***** 5. 修改联系人 *****" << endl;
  cout << "***** 6. 清空联系人 *****" << endl;
  cout << "***** 0. 退出该系统 *****" << endl;
  cout << "*************************" << endl;
}
// =============================================
/*
  2. 添加联系人
    1. 设计联系人结构体
    2. 设计通讯录结构体
*/
struct Person {
  string name;
  int sex; // 1: 男 0: 女
  int age;
  string tel;
  string address;
};

struct AddressBooks {
  Person persons[MAX]; // 列表
  int size;            // 个数
};

/*
  5. 按照姓名查询用户
  return 位置
*/
int findPersonByName(AddressBooks *adbs, string name) {
  for (int i = 0; i < adbs->size; i++) {
    if (adbs->persons[i].name == name) {
      return i;
    }
  }
  return -1;
}

void addPerson(AddressBooks *adbs) {
  system("clear");

  if (adbs->size >= MAX) {
    cout << "通讯录已满, 无法添加" << endl;
    return;
  }

  string name;
  int sex;
  int age;
  string tel;
  string address;

  cout << "请输入联系人姓名: ";
  cin >> name;
  adbs->persons[adbs->size].name = name;
  cout << "请输入联系人性别(1: 男, 0: 女): ";
  while (true) {
    cin >> sex;
    if (sex == 0 || sex == 1) {
      adbs->persons[adbs->size].sex = sex;
      break;
    } else {
      cout << "请重新输入联系人性别(1: 男, 0: 女): ";
    }
  }

  cout << "请输入联系人年龄: ";
  cin >> age;
  adbs->persons[adbs->size].age = age;

  cout << "请输入联系人电话: ";
  cin >> tel;
  adbs->persons[adbs->size].tel = tel;

  cout << "请输入联系人地址: ";
  cin >> address;
  adbs->persons[adbs->size].address = address;

  adbs->size = adbs->size + 1;
  cout << "添加成功" << endl;
};
// ============================================
/*
  3. 显示联系人
*/
void showPerson(AddressBooks *adbs) {
  system("clear");
  cout << "books size: " << adbs->size << endl;
  for (int i = 0; i < adbs->size; i++) {
    cout << i + 1 << ". name: " << adbs->persons[i].name
         << " sex: " << adbs->persons[i].sex << " age: " << adbs->persons[i].age
         << " tel: " << adbs->persons[i].tel
         << " address: " << adbs->persons[i].address << endl;
  }
}
// ============================================
/*
  4. 删除联系人
*/
void delPerson(AddressBooks *adbs) {
  system("clear");
  cout << "请输入要删除的联系人姓名: ";
  string name;
  cin >> name;
  int idx = findPersonByName(adbs, name);
  if (idx == -1) {
    cout << "查无此人" << endl;
  } else {
    cout << "查到了:" << idx << endl;
    for (int i = 0; i < adbs->size; i++) {
      if (i >= idx) {
        adbs->persons[i] = adbs->persons[i + 1];
      }
    }
    adbs->size = adbs->size - 1;
  }
};

/*
  查找联系人
*/
void findPersion(AddressBooks *adbs) {
  system("clear");
  cout << "请输入要查找的联系人姓名: ";
  string name;
  cin >> name;
  int idx = findPersonByName(adbs, name);
  if (idx == -1) {
    cout << "未找到联系人" << endl;
    return;
  }
  cout << to_string(idx + 1) << ". name: " << adbs->persons[idx].name
       << adbs->persons[idx].name << " sex: " << adbs->persons[idx].sex
       << " age: " << adbs->persons[idx].age
       << " tel: " << adbs->persons[idx].tel
       << " address: " << adbs->persons[idx].address << endl;
};

/*
  修改联系人
*/
void editPersion(AddressBooks *adbs) {
  system("clear");
  cout << "请输入要编辑的联系人姓名: ";
  string name;
  cin >> name;

  int idx = findPersonByName(adbs, name);
  if (idx == -1) {
    cout << "未找到联系人";
    return;
  }
  cout << "请编辑姓名: (-1 跳过): ";
  cin >> name;

  if (name != "-1") {
    adbs->persons[idx].name = name;
  }

  cout << "请编辑性别(1: 男, 0: 女): (-1 跳过): ";
  int sex;
  while (true) {
    cin >> sex;
    if (sex == -1) {
      break;
    }
    if (sex == 0 || sex == 1) {
      adbs->persons[idx].sex = sex;
      break;
    }
    cout << "请重新编辑性别(1: 男, 0: 女): (-1 跳过): ";
  }
  cout << "请编辑年龄: (-1 跳过): ";
  int age;
  cin >> age;
  if (age != -1) {
    adbs->persons[idx].age = age;
  }
  cout << "请编辑电话: (-1 跳过): ";
  string tel;
  cin >> tel;
  if (tel != "-1") {
    adbs->persons[idx].tel = tel;
  }
  cout << "请编辑地址: (-1 跳过): ";
  string address;
  cin >> address;
  if (address != "-1") {
    adbs->persons[idx].address = address;
  }
  cout << "编辑结束" << endl;
}

/*
  清空联系人
*/
void clearnBooks(AddressBooks *adbs) {
  adbs->size = 0;
}

int main() {
  int select = 0;

  AddressBooks adbs;
  adbs.size = 0;

  while (true) {
    showMenu();
    cout << "请选择操作: ";
    cin >> select;
    cout << select << endl;
    switch (select) {
    case 1:
      addPerson(&adbs);
      break;
    case 2:
      showPerson(&adbs);
      break;
    case 3:
      delPerson(&adbs);
      break;
    case 4:
      findPersion(&adbs);
      break;
    case 5:
      editPersion(&adbs);
      break;
    case 6:
      clearnBooks(&adbs);
      break;
    case 0:
      cout << "欢迎下次使用" << endl;
      system("read -p Press enter to continue \n");
      return 0;
    default:
      break;
    }

    system("read -p Press enter to continue \n");
  }
  // system("ls");
  return 0;
}