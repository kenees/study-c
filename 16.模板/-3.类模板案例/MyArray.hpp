#pragma once
#include <iostream>
using namespace std;

template <class T>
class MyArray
{

public:
    // 参数： 容量
    MyArray(int capacity)
    {
        cout << "My array 有参构造" << endl;
        this->m_capacity = capacity;
        this->m_size = 0;
        this->pAddress = new T[this->m_capacity];
    }

    // 拷贝构造
    MyArray(const MyArray &arr)
    {
        cout << "My array 拷贝构造" << endl;

        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        // this->pAddress = arr.pAddress;
        // 深拷贝
        this->pAddress = new T[this->m_capacity];
        // 拷贝数据
        for (int i = 0; i < this->m_size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    // 防止浅拷贝
    MyArray &operator=(const MyArray &arr)
    {
        cout << "My array operator=" << endl;

        // 先判断原来堆区是否有数据， 如果有先释放
        if (this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->m_capacity = 0;
            this->m_size = 0;
        }

        // 深拷贝
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        // this->pAddress = arr.pAddress;
        // 深拷贝
        this->pAddress = new T[this->m_capacity];
        // 拷贝数据
        for (int i = 0; i < this->m_size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }

        return *this;
    }

    ~MyArray()
    {
        cout << "My array 析构函数" << endl;

        if (this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
        }
    }

    void push(const T v) {
        // 1. 判断容量是否满了
        if (this->m_capacity == this->m_size) {
            return;
        }
        this->pAddress[this->m_size] = v;
        this->m_size++;
    }

    void pop() {
        // 让用户访问不到最后一个元素
        if (this->m_size == 0) {
            return;
        }
        this->m_size --;
    }

    // 通过下标访问
    T operator[](int index) {
        return this->pAddress[index];
    }

    int getlength() {
        return this->m_size;
    }

    int getcapacity() {
        return this->m_capacity;
    }


private:
    T *pAddress;    // 指向堆区开辟的真实数组
    int m_capacity; // 数组容量
    int m_size;     // 数组大小
};