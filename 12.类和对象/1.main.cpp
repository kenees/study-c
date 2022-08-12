#include <iostream>
#define _USE_MATH_DEFINES // 使用math.h中的M_PI宏定义需要
#include <math.h>
using namespace std;

/*
    面向对象三大特性: 封装, 继承, 多态
*/

class Point {
public:
  int x;
  int y;

  Point(int p_x, int p_y) {
    x = p_x;
    y = p_y;
    cout << "point init" << endl;
  }
};

class Circle {

public:
  int c_r;
  Point center;

  Circle(int r, int x, int y): c_r(r), center(x, y) {
    cout << "circle. init" << endl;
  };

  int getArea() { return c_r * c_r * M_PI; }
};

int main() {
  Circle c1(10, 11, 11);
  cout << "面积:" << c1.getArea() << endl;

  return 0;
}