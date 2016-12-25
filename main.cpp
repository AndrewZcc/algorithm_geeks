/*
 * Created by zhchuch.
 */

#include <iostream>

#include "util/util.h"
#include "search/binary_search.h"
#include "sort/insertion_sort.h"
#include "sort/selection_sort.h"
#include "sort/bubble_sort.h"
#include "sort/merge_sort.h"
#include "sort/heap_sort.h"
#include "sort/quick_sort.h"
#include "sort/application/minLength_sort.h"

using namespace std;

int arr[] = {3, 7, 8, 12, 13, 16};
int unsorted_arr[] = {4, 9, 10, 4, 8, 3, 5};
int len = sizeof(unsorted_arr)/sizeof(unsorted_arr[0]);
int* temp_arr = new int[len];

int main() {
    bool flag = true;

    /* Swap two elements Test (implemented in util.h)
    int a = 3, b = 4;
    cout << "Swap before: " << a << " " << b << endl;
    swap_1(a, b); // swap_2(a, b); swap_3(&a, &b);
    cout << "Swap after: " << a << " " << b << endl;
    */

    while (flag) {
        int key, pos;

        /*
        // Binary Search Test (implemented in binary_search.h)
        cout << endl << "+++ Binary Search Test [O(log n)] +++" << endl;
        cout << "Please input the element you want to search: "; cin >> key;
        len = sizeof(arr)/sizeof(arr[0]);
        pos = binary_search(arr, len, key);
        pos == -1 ?
            cout << "Not Found" << endl :
            cout << "Found: loc = " << pos << endl;

        // Insertion Sort Test (implemented in insertion_sort.h)
        cout << endl << "+++ Insertion Sort Test [O(n^2) | Stable] +++" << endl;
        copy_array(temp_arr, unsorted_arr, len);
        cout << "Before: "; print_array(temp_arr, len);
        insertion_sort(temp_arr, len); // Stable
        cout << "After: "; print_array(temp_arr, len);
        //break;

        // Insertion Sort Test (implemented in insertion_sort.h)
        cout << endl << "+++ Selection Sort Test [O(n^2) | Unstable] +++" << endl;
        copy_array(temp_arr, unsorted_arr, len);
        cout << "Before: "; print_array(temp_arr, len);
        selection_sort(temp_arr, len);  // Unstable
        cout << "After: "; print_array(temp_arr, len);
        //break;

        // Bubble Sort Test (implemented in bubble_sort.h)
        cout << endl << "+++ Bubble Sort Test [O(n^2) | Stable] +++" << endl;
        copy_array(temp_arr, unsorted_arr, len);
        cout << "Before: "; print_array(temp_arr, len);
        bubble_sort(temp_arr, len);  // Stable
        cout << "After: "; print_array(temp_arr, len);

        // Merge Sort Test (implemented in merge_sort.h)
        cout << endl << "+++ Merge Sort Test [O(n log(n)) | Stable] +++" << endl;
        copy_array(temp_arr, unsorted_arr, len);
        cout << "Before: "; print_array(temp_arr, len);
        merge_sort(temp_arr, len);  // Stable
        cout << "After: "; print_array(temp_arr, len);
        int unsort_array2[] = {18, 35, 10, 4, 23, 12, 16};
        len = sizeof(unsort_array2)/ sizeof(unsort_array2[0]);
        cout << "Before: "; print_array(unsort_array2, len);
        merge_sort(unsort_array2, len);
        cout << "After: "; print_array(unsort_array2, len);

        cout << endl << "+++ Heap Sort Test [O(n log(n)) | Unstable/Stable] +++" << endl;
        copy_array(temp_arr, unsorted_arr, len);
        cout << "Before: "; print_array(temp_arr, len);
        heap_sort(temp_arr, len);  // Unstable/Stable
        cout << "After: "; print_array(temp_arr, len);

        cout << endl << "+++ Quick Sort Test [Θ(n log(n)) | Unstable] +++" << endl;
        copy_array(temp_arr, unsorted_arr, len);
        cout << "Before: "; print_array(temp_arr, len);
        quick_sort(temp_arr, len);  // Unstable
        cout << "After: "; print_array(temp_arr, len);
        */

        cout << endl << "+++ Application: Minimal-Length Quick Sort Test [Θ(n log(n))] +++" << endl;
        copy_array(temp_arr, unsorted_arr, len);
        cout << "Before: "; print_array(temp_arr, len);
        minLength_sort(temp_arr, len);
        cout << "After: "; print_array(temp_arr, len);

         int temp_arr_2[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
        len = sizeof(temp_arr_2)/ sizeof(temp_arr_2[0]);
        cout << "Before: "; print_array(temp_arr_2, len);
        minLength_sort(temp_arr_2, len);
        cout << "After: "; print_array(temp_arr_2, len);

        break;
    }

    cout << endl << "Hello, World!" << endl;
    return 0;
}