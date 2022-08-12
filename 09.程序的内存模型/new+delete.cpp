#include <iostream>
using namespace std;

int *func() {
  int *p = new int(10);
  return p;
}

// new
void test01() {
  int *p = func();
  cout << *p << " " << &p << endl;
  delete p;
  cout << *p << " " << &p << endl;

  int *arr = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  cout << arr << " " << &arr << endl;
  delete[] arr;
}

int main() {
  test01();
  return 0;
}