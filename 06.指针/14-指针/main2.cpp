#include <iostream>
// #include <stdexcept>

using namespace std;

int main() {
  int a = 10;

  int *p = &a;

  // 32位操作系统，所有数据类型的指针占4个字节，
  // 64位操作系统，所有数据类型的指针占8个字节

  cout << "sizeof(int *)" << sizeof(int *) << endl;

  cout << "sizeof(int *)" << sizeof(float *) << endl;
  cout << "sizeof(int *)" << sizeof(double *) << endl;
  cout << "sizeof(int *)" << sizeof(char *) << endl;


    // 空指针
    // 1. 指针变量p指向内存地址编号为0的空间
    // 2. 空指针 用于给指针变量 进行初始化
    // 3. 空指针是不可以进行访问的
    int * p1 = NULL;

    // 访问空指针报错
    // 内存编号为0 ～255 为系统占用内存，不允许用户访问
    // cout << *p1 << endl;

    // 野指针
    // 指针 变量直接 指向一块非法的内存空间
    int * pp = (int *)0x1100;
    // cout << *pp << endl;

    // const修饰指针
    // 1. const修饰指针 --- 常量指针
    // const int * p = &a;
    // p = &b;    //ok     const 修饰后指向可以修改， 
    // *p = 200;  //error. 但是指向的内存中的值不可以修改
    // 2. const修饰指针 --- 指针常量
    // int * const p = &a;
    // p = &b;    // error,  指针指向不可以修改
    // *p = 200; => a = 200;  //ok. ,指针指向的值可以修改
    // 3. 
    // const int * const p = &a; // 都不可以修改

    // 利用指针 访问 数组
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    cout << "第一个 元素： " << arr[0] << endl;

    int *pa = arr;
    cout << "指针访问第一个元素： " << *pa << endl;
    pa ++; // int类型的指针， ++ 自动加4个字节
    cout << "指针访问第二个元素： " << *pa << endl;

    int *pb = arr;
    for(int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i ++) {
        cout << "循环 访问" << i << "元素： " << *pb << endl;
        pb++;
    }
}