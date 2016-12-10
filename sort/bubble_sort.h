/*
 * Created by zhchuch. 12.10
 */

#ifndef ALGORITHM_BUBBLE_SORT_H
#define ALGORITHM_BUBBLE_SORT_H

#include <iostream>
#include "../util/util.h"

using namespace std;

/*
 * Bubble Sort Algorithm: O(n^2) | Stable
 *
 * IDEA: repeatedly swapping the adjacent elements if they are in wrong order.
 * Due to its simplicity, bubble sort is often used to introduce the concept of a sorting algorithm.
 */

void bubble_sort(int* arr, int len)
{
    int i, j, k = 1;

    for (i = len-1; i >= 0; i--, k++)   // arr[i] 存储当前 unsort-array 中的最大数, 当 i=0 时排序完成
    {
        for (j = 0; j < i; j++){
            if (arr[j] > arr[j+1])          // 大数 向数组后面移动(冒泡)
                swap(arr[j], arr[j+1]);
        }

        cout << k << " iteration: "; print_array(arr, len);
    }
}

#endif //ALGORITHM_BUBBLE_SORT_H
