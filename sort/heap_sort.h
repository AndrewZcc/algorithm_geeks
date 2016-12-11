/*
 * Created by zhchuch. 12.10
 */

#ifndef ALGORITHM_HEAP_SORT_H
#define ALGORITHM_HEAP_SORT_H

#include <iostream>
#include "../util/util.h"

/*
 * Heap Sort Algorithm: O(n logn) | Unstable, but can be modified to Stable
 *
 * IDEA: similar to selection sort but using Binary Heap data-structure.
 * repeatedly find the maximum element and place the maximum element at the end.
 *
 * Background: Binary Heap is a (complete binary tree) where items are stored in a special order.
 *            [ max-heap / min-heap ]
 * Binary Heap can be represented by binary tree or array!
 */

void heapify(int* arr, int len, int pos)    // 默认 pos 处的两侧左右子树已经是一个堆结构了
{
    int max = pos;
    int left = 2*pos + 1;
    int right = 2*pos + 2;

    if (left < len && arr[left] > arr[max])
        max = left;
    if (right < len && arr[right] > arr[max])
        max = right;

    if (max != pos) {
        swap(arr[max], arr[pos]);
        heapify(arr, len, max);     // 递归的向下建堆
    }
}

void heap_sort(int* arr, int len)   // O(n logn)
{
    // 自下而上建堆 (记住只有左右子树都是堆时进行递归向下的建堆过程才能得到正确的结果)
    for (int i=len/2+1; i >= 0; i--)    // O(n/2)
        heapify(arr, len, i);           // O(log n)

    for (int i=len-1, j=1; i>=0; i--, j++)  // O(n)
    {
        cout << "After heapify: "; print_array(arr, len);
        swap(arr[i], arr[0]);
        cout << j << " iteration: "; print_array(arr, len);
        heapify(arr, i, 0);                 // O(log n)
    }
}

#endif //ALGORITHM_HEAP_SORT_H
