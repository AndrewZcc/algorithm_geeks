### 一、二分查找 (Binary Search) 中可能需要注意的问题：

```
// A iterative binary search function. It returns location of x in
// given array arr[l..r] if present, otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        // find index of middle element
        int m = (l+r)/2;
 
        // Check if x is present at mid
        if (arr[m] == x) return m;
 
        // If x greater, ignore left half
        if (arr[m] < x) l = m + 1;
 
        // If x is smaller, ignore right half
        else r = m - 1;
    }
 
    // if we reach here, then element was not present
    return -1;
}
```

#### Note:

- the statement `m = (l+r)/2` will fail for large values of l and r.
- Specifically, it fails if the sum of low and high is greater than the maximum positive int value (2^31 – 1). 
- The sum overflows to a negative value, and the value stays negative when divided by two. 
- In C this causes an array index `out of bounds` with unpredictable results.

#### 可选的改进的方法

1. `int mid = low + ((high - low) / 2); `
2. `int mid = (low + high) >>> 1; ` (In Java)
3. `int mid = ((unsigned int)low + (unsigned int)high)) >> 1; ` (In C/C++)

## 
### 二、二分查找应用：[Search in an almost sorted array](http://www.geeksforgeeks.org/search-almost-sorted-array/)

给定一个极其接近已排序的数列 (Basically the element arr[i] can only be swapped with either arr[i+1] or arr[i-1])，让你在其中更快地查找到期待数字的位置。

Solution:   
The idea is to **compare the key with middle 3 elements**, if present then return the index. If not present, then compare the key with middle element to decide whether to go in left half or right half. Comparing with middle element is enough as all the elements after **mid+2** must be greater than element mid and all elements before **mid-2** must be smaller than mid element.

分析：  
该题就是把原来 BinarySearch 中的 mid (`一个中间位置`) 变成了 [mid-1, mid+1] 这`一个中间区间`。
