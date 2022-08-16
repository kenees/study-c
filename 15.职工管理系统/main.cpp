#include <iostream>
using namespace std;

class Termina {
public:
  void showMenu() {
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
};

void start() {
  int select = 0;
  Termina t;
  while (true) {
    t.showMenu();
    cout << "请选择操作： " << endl;
    cin >> select;
    switch (select) {
    case 1:
      cout << "11" << endl;
      break;
    case 2:
      cout << "1122" << endl;
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

int main() {
  start();
  return 0;
}