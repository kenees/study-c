#include <iostream>
using namespace std;

int main() {

  
  cout << "11" << endl;
  cout << "22" << endl;
  goto ABC;
  cout << "33" << endl;
  ABC:
  cout << "44" << endl;
  cout << "55" << endl;
  goto D;
  cout << "66" << endl;
  cout << "77" << endl;
  D:
  return 0;
}