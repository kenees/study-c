// #include <cstdlib>
#include <iostream>

using namespace std;


int main() {

    // 
    srand((unsigned int) time(NULL));
    int num = rand() % 100;

    int a = 0;
    while(1) {
        cout << "请输入：" << endl;
        cin >> a;
        if (a > num) {
            cout << "猜大了" << endl;
        } else if (a < num) {
            cout << "猜小了" << endl;
        } else {
            cout << "猜对了" << endl;
            break;
        }
    }
}