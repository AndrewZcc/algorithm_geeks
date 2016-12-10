/*
 * Created by zhchuch. 12.10
 */

#ifndef ALGORITHM_INSERTION_SORT_H
#define ALGORITHM_INSERTION_SORT_H

#include <iostream>
#include "../util/util.h"

using namespace std;

/*
 * Insertion Sort Algorithm: O(n^2) | Stable
 *
 * IDEA: pick element arr[i] and insert it into sorted sequence arr[0..i-1].
 */
void insertion_sort(int* arr, int len)
{
    int i, j, temp;

    for (i = 1; i < len; i++) {
        temp  = arr[i];
        for (j = i-1; j >= 0; j--) {
            if (arr[j] > temp)
                arr[j+1] = arr[j];  // 如果前面的值比我大,那么就向后移动
            else break;             // Note: prone-error
        }
        arr[j+1] = temp;            // insert in correct loc.
        cout << i << " iteration: "; print_array(arr, len);
    }
}

#endif //ALGORITHM_INSERTION_SORT_H
