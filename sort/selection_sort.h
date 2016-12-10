/*
 * Created by zhchuch. 12.10
 */

#ifndef ALGORITHM_SELECTION_SORT_H
#define ALGORITHM_SELECTION_SORT_H

#include <iostream>
#include "../util/util.h"

using namespace std;

/*
 * Selection Sort Algorithm: O(n^2) | Unstable
 *
 * IDEA: repeatedly finding the minimum element from unsorted part and putting it at the beginning.
 */
void selection_sort(int* arr, int len)
{
    int i, j, pos_min;

    for (i=0; i < len; i++)
    {
        pos_min = i;
        for (j = i+1; j < len; j++) {
            if (arr[j] < arr[pos_min])
                pos_min = j;            // 每次循环都找出 unsort-array 中的最小值
        }

        // Note: swap operation cannot guarantee the relative position! -> Unstable
        swap(arr[i], arr[pos_min]);     // 将其与 unsort_arr[0] 位置处的数值交换位置

        cout << i+1 << " iteration: "; print_array(arr, len);
    }
}

#endif //ALGORITHM_SELECTION_SORT_H
