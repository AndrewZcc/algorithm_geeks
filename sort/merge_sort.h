/*
 * Created by zhchuch. 12.10
 */

#ifndef ALGORITHM_MERGE_SORT_H
#define ALGORITHM_MERGE_SORT_H

#include <iostream>
#include "../util/util.h"

/*
 * Merge Sort Algorithm: O(n * log n) | Stable
 *
 * IDEA: [Divide and Conquer] divide input array into two halves, calls itself for two halves
 * and then merges the two sorted halves into one sorted array!
 */
// 居然一遍成功了, Wonderful!!! It's so great!
void merge(int* arr, int l, int m, int r)
{
    int l_len = m - l + 1;  // 因为是整除, 所以 m = (0+1)/2 = 0 [0,0,1]
    int r_len = r - m;
    int i, j, k, t;

    // Copy left sub-array and right sub-array.
    int l_arr[l_len], r_arr[r_len];
    for (i=0; i<l_len; i++)
        l_arr[i] = arr[l+i];
    for (j=0; i<(l_len + r_len); i++, j++)
        r_arr[j] = arr[l+i];

    // Merge two ordered-sub-array into arr.
    i = 0, j = 0;
    for (k=l; k<=r; k++) {

        if (i >= l_len || j >= r_len) break;

        if (l_arr[i] <= r_arr[j]){
            arr[k] = l_arr[i];
            i++;
        } else {
            arr[k] = r_arr[j];
            j++;
        }
    }

    // Copy remained left/right sub-array elements to arr.
    for (t=0; i<l_len; i++, t++)
        arr[k+t] = l_arr[i];
    for (; j<r_len; j++, t++)
        arr[k+t] = r_arr[j];
}

void merge_sort(int* arr, int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;

        merge_sort(arr, l, mid);    // 为了递归能终止,这里不能使用 merge_sort(arr, l, mid-1)
        merge_sort(arr, mid+1, r);

        merge(arr, l, mid, r);
    }
}

void merge_sort(int* arr, int len)
{
    merge_sort(arr, 0, len-1);
}

#endif //ALGORITHM_MERGE_SORT_H
