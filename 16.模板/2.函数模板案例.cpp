#include <iostream>
using namespace std;

/**
 * 利用函数模板封装一个排序的函数， 可以对不同数据类型数组进行排序
 * 排序规则从大到小， 排序算法为选择排序
 * 分别利用char数组， int数组进行测试
 * 
 * @return int 
 */

template<class T>
void sort(T arr[], int len) {
    for (int i = 0; i < len; i++)
      {
        for (int j = i + 1; j < len; j++)
        {
          if (arr[i] < arr[j])
          { // 依次比较, 找到最xiao的放到第i位
            T max = arr[i];
            arr[i] = arr[j];
            arr[j] = max;
          }
        }
      }
    
    for(int i = 0; i < len; i ++) {
        cout << arr[i] << ", ";
    }
}

int main() {
    int arr[] = { 1, 3, 4, 2, 8, 5, 9, 6, 7, 0};
    char arr1[] = { 'a', 'g', 'f', 'h', 'r', 'b', 'q', 'p', 'd', 'l'};
    sort(arr, 10);
    sort(arr1, 10);
    return 0;
}