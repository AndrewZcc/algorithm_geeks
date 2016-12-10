/*
 * Created by zhchuch. 12.09
 */

#ifndef ALGORITHM_BINARY_SEARCH_H
#define ALGORITHM_BINARY_SEARCH_H

#include <iostream>
using namespace std;

/*
 * Binary Search Algorithm: O(log n) | using recursion
 */
int binary_search(int* arr, int len, int key, int low, int high)
{
    if (low > high) return -1;

    int mid = (low + high) / 2;     // log n

    if (arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
        return binary_search(arr, len, key, mid+1, high);
    else
        return binary_search(arr, len, key, low, mid-1);
}

/*
 * Binary Search Algorithm: O(log n) | using loop
 */
int binary_search(int* arr, int len, int key)
{
    //return binary_search(arr, len, key, 0, len-1);

    int low = 0, high = len-1, mid, pos = -1;

    while (low <= high)
    {
        mid = (low + high) / 2;     // log n

        if (arr[mid] == key) return mid;
        else if (arr[mid] > key)
            high = mid-1;
        else
            low = mid+1;
    }

    return pos;
}

#endif //ALGORITHM_BINARY_SEARCH_H
