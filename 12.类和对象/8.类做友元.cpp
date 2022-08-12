#include <iostream>
#include <string>
using namespace std;

class Building {
  // GoodDay是该类的好朋友，可以 访问私有成员
  friend class GoodDay;

public:
  string m_sittingRoom;

  Building();

private:
  string m_badRoom;
};

Building::Building() {
  m_badRoom = "woshi";
  m_sittingRoom = "keting";
};

class GoodDay {
public:
  Building *building;

  GoodDay();

  void visit();
};

GoodDay::GoodDay() { building = new Building(); };

void GoodDay::visit() {
  cout << "好基友正在访问 ：" << building->m_sittingRoom << endl;
  cout << "好基友正在访问 ：" << building->m_badRoom << endl;
};

void test1() {
  GoodDay gd;
  gd.visit();
};

int main() {
  test1();
  return 0;
}