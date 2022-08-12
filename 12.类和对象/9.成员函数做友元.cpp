#include <iostream>
#include <string>
using namespace std;

// 1. 注意两个对象构建 的顺序
// 2.  提前声明 ， 如果 对应成员函数没有 实现也会报错

class Building;

class GoodDay {
public:
  GoodDay();

  void visit();
  void visit2() {
    // 不可以访问
  }

  Building *building;
};

class Building {

  friend void GoodDay::visit();

public:
  string m_sittingRoom;

  Building();

  void say() { cout << "hh: " << this->m_badRoom << endl; }

private:
  string m_badRoom;
};

Building::Building() {
  m_badRoom = "卧室";
  m_sittingRoom = "客厅";
}

GoodDay::GoodDay() { building = new Building(); };

void GoodDay::visit() {
  // 可以访问
  cout << "好基友：" << building->m_sittingRoom << endl;
  cout << "好基友：" << building->m_badRoom << endl;
}

void test() {
  GoodDay gd;
  gd.visit();
  gd.visit2();
  cout << "xx: " << endl;
};

int main() {
  test();
  return 0;
}