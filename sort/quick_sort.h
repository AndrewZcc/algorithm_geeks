/*
 * Created by zhchuch. 12.11
 */

#ifndef ALGORITHM_QUICK_SORT_H
#define ALGORITHM_QUICK_SORT_H

#include <iostream>
#include "../util/util.h"

/*
 * Quick Sort Algorithm: Θ(n logn) average, O(n^2) worst |
 *
 * IDEA: [Divide and Conquer] pick an element as pivot, and partition the given array around the picked pivot.
 *       Target of partitions is: given an array and an element x of array as pivot, put x at its correct position
 *              in sorted array and put all smaller elements before x, put all greater elements after x.
 */

// 方法一: 使用向后平移的方式, 调整 pivot 位置
int partition(int* arr, int low, int high)
{
    int pivot = low;        // 选取一个 pivot 元素。

    for (int i=low+1; i<=high; i++)
    {
        if (arr[i] < arr[pivot])    // 与数组中的元素进行一个比较, 如果比它小,就把它交换到pivot前面去,否则就不用动。
        {
            int temp = arr[i];
            for (int j=i; j>pivot; j--)
                arr[j] = arr[j-1];
            arr[pivot] = temp;
            pivot++;
        }
    }

    return pivot;
}

// 方法二: 采用交换的方法, 调整 pivot 位置
int partition_2(int* arr, int low, int high)
{
    int pivot = low;
    int j = low;

    for (int i=low+1; i<=high; i++)
    {
        if (arr[i] < arr[pivot])
        {
            j++;                    // 找到 第一个 大于 arr[pivot] 的位置
            swap(arr[j], arr[i]);   // 将 小数 交换过去
        }
    }

    swap(arr[pivot], arr[j]);       // 最后 为 pivot 找到自己正确的位置, j

    return j;
}

void quick_sort(int* arr, int low, int high)
{
    if (low < high)
    {
        //int pivot_pos = partition(arr, low, high);
        int pivot_pos = partition_2(arr, low, high);
        cout << "Pivot-Pos: " << pivot_pos << " | "; print_array(arr, 7);

        quick_sort(arr, low, pivot_pos - 1);    // 递归的对左右两边都进行快排就可以完成整个问题了。
        quick_sort(arr, pivot_pos + 1, high);
    }
}

void quick_sort(int* arr, int len)
{
    quick_sort(arr, 0, len-1);
}

#endif //ALGORITHM_QUICK_SORT_H
