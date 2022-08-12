#include <cstdio>
#include <iostream>
using namespace std;

int main() {

  // 1. 统计数组占用 内存大小。 sizeof(arr)
  // 2. 查看 数组首地址 &arr 
  // 3. 查看元素地址。 &arr[1]  &arr[2]
  //   每个元素地址 相差4字节， 地址是 连续的

  // 4. 二维数组
  // int [行][列]； 
  // int [行][列] = {{1,2,3}, {1,2,3} ...}；
  // int [行][列] = {1,2,3,4,5,6,7,8}
  // int [][列] = {1,2,3,4,5,6,7,8,9,0} 
  int jj[2][3] = {
    {1,2,3},
    {1,2,3}
  };

  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  cout << "数组占用 内存空间为： " << sizeof(arr) << endl;
  cout << "每个元素占用 内存空间为： " << sizeof(arr[0]) << endl;

  cout << "数组 首地址：" << arr << endl;
  cout << "第一个元素 地址：" << &arr[0] << endl;
  cout << "第二个元素 地址：" << &arr[1] << endl;
  cout << "第三 个元素 地址：" << &arr[2] << endl;
  return 0;
}