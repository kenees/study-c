#include "iostream"

using namespace std;

void max1(int a, int b);

int main() {
    int a = 10;
    int b = 20;


    max1(a, b);

    return 0;
}

void max1(int a, int b) {
    cout << a+b << endl;
}