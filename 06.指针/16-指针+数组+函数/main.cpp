#include <iostream>
using namespace std;

// 函数中无法计算数组大小, 传递的数组回退化成指针
// 冒泡排序
void sort(int *arr, int len) {
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] > arr[j]) {  // 依次比较, 找到最小的放到第i位
        int max = arr[i];
        arr[i] = arr[j];
        arr[j] = max;
      }
    }
  }
}

// 封装一个函数, 利用冒泡排序,实现对整型数组的升序排序
// 例如数组 int arr[10] = {4,3,6,9,1,2,10,8,7,5};
int main() {
  int arr[10] = {4, 3, 6, 9, 1, 2, 10, 8, 7, 5};
  cout << sizeof(arr) << " " << arr << endl;
  int len = sizeof(arr) / sizeof(arr[0]);
  sort(arr, len);
  // cout << sizeof(arr) << " " << &arr << endl;
  for (int i = 0; i < len; i++) {
    cout << arr[i] << endl;
  }
  return 0;
}