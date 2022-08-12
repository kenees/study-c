#include <iostream>
using namespace std;

// 值传递, 只交换形参
void swap1(int num1, int num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void swap2(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

// 实现两个数字的交换(利用指针)
int main() {
    int a = 10;
    int b = 20;
    swap1(a, b); 
    swap2(&a, &b);
    cout << "a: " << a << "; b: " << b <<endl;
    return 0;
}