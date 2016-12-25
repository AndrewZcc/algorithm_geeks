/*
 * Created by zhchuch.
 */

#ifndef ALGORITHM_MINLENGTH_SORT_H
#define ALGORITHM_MINLENGTH_SORT_H

#include <iostream>
#include "../quick_sort.h"

using namespace std;

/**
 * Find the Minimum length Unsorted Subarray, sorting which makes the complete array sorted
 */
void minLength_sort(int* arr, int len)
{
    int low = 0, high = len-1;

    while (arr[low+1] >= arr[low] && low <= len-1)
    {
        low++;
    }
    while (arr[high-1] <= arr[high] && high >= 0)
    {
        high--;
    }

    int min = arr[low+1], max = arr[high-1];
    for (int i=low+1; i<=high-1; i++)
    {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    while (arr[low] > min && low >= 0)
    {
        low--;
    }
    if (low != 0 || arr[low] > min)
        low++;
    while (arr[high] < max && high <= len-1)
    {
        high++;
    }
    if (high != len-1 || arr[high] < max)
        high--;

    cout << "Unsort-subarray: [" << low << ", " << high << "], Min-Lenght = " << high-low+1 << endl;

    quick_sort(arr, low, high);     // O(nlogn)
}

#endif //ALGORITHM_MINLENGTH_SORT_H
