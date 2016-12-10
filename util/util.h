/*
 * Created by zhchuch.
 */

#ifndef ALGORITHM_UTIL_H
#define ALGORITHM_UTIL_H

#include <iostream>

using namespace std;

void print_array(int* arr, int len)
{
    cout << "Print Array (size = "<< len << "): ";
    for (int i=0; i<len; i++) cout << arr[i] << " ";
    cout << endl;
}

void copy_array(int* arr_copy, int* arr_ori, int len)
{
    for (int i=0; i<len; i++)
        arr_copy[i] = arr_ori[i];
}

/**
 * template function for swap two elements.
 * Failed by value.
 */
template <class T>
void swap_1(T a, T b)
{
    T c(a);     // 运用 拷贝构造函数, 就可以少写一条语句
    a = b;
    b = c;
}
/**
 * Success by reference
 */
template <class T>
void swap_2(T& a, T& b)
{
    T c(a);
    a = b;
    b = c;
}
/**
 * Success by pointer
 */
template <class T>
void swap_3(T* a, T* b)
{
    T c(*a);
    *a = *b;
    *b = c;
}


#endif //ALGORITHM_UTIL_H
