## 排序算法 对比分析 与 总结

### 一、复杂度 · 详细参考网站：[Big-O cheat sheet](http://bigocheatsheet.com/)

No. | Algo Name	| Average Complexity | Worst Complexity| Stable
:---: | :----------	| :------------: | :----------: | :---------:
1 | ✅ bubble sort| `Θ(n^2)` |`O(n^2)`	| **Yes**
2 | ✅ **selection sort**| `Θ(n^2)` | `O(n^2)`	| **No**
3 | ✅ **insertion sort**| `Θ(n^2)` | `O(n^2)`	| **Yes**
4 | ✅ **merge sort**| `Θ(n·log(n))` | `O(n·log(n))` | **Yes**
5 | timsort 		| **improved** Merge Sort | `O(n·log(n))` | ❓
6 | ✅ **heap sort**| `Θ(n·log(n))` | `O(n·log(n))` | **No**
7 | ✅ **quick sort**| `Θ(n·log(n))` | `O(n^2)` | **No**
8 | tree sort		| `Θ(n·log(n))`(balanced) | `O(n^2)`(unbalanced) | BST-based
9 | radix sort		| `Θ(n*k)`	| `O(n*k)` | log2(n) bits for every digit
10| counting sort	| `Θ(n+k)`	| `O(n+k)` | 数字的范围不能远超待排数字的个数
11| bucket sort		| `Θ(n+k)`	| `O(n^2)` | 每个桶内部仍然采用基于比较的排序
12| shell sort		| `Θ(n·[log(n)]^2))` | `O(n·[log(n)]^2)` | **No**
13| cube sort		| `Θ(n·log(n))` | `O(n·log(n))` | ❌
14| comb sort		| **improved** Bubble Sort | `O(n^2)` | ❌
15| pigeonhole sort	| **similar to** counting sort | 但不灵活性，几乎不使用 | ❌ 

备注：✅ 代表已实现 (6/15)，❌ 代表不考虑(3/15)，❓代表不清楚(6/15)。

## 
### 二、算法对比与分析

#### 1. QuickSort vs. MergeSort

- `QuickSort` is preferred over `MergeSort` for sorting **Arrays**;
- `MergeSort` is preferred over `QuickSort` for sorting **Linked-lists**.

- QuickSort is faster than MergeSort in practice, because QuickSort needs lesser extra-space [O(log n)], ranther than MergeSort needs [O(n)] extra-space.  

- Allocating and de-allocating the extra-space increases the actual running time of the MergeSort.

- MergeSort is prefered for sorting linked-list because of the **slow random-access performance** of the linked-list.

#### 2. Stability in sorting algorithms

定义：A sorting algorithm is said to be `stable` if two objects with equal keys appear *in the same order in sorted output as* they appear in the input unsorted array. 

特点：Any given sorting algo which is not stable can be modified to be stable.  Modified to be stable by *changing the key comparison operation*.

#### 3. When does the worst-case of Quicksort occur?

The answer depends on strategy for choosing pivot. In early versions of Quick Sort where leftmost (or rightmost) element is chosen as pivot, the worst occurs in following cases.

1) Array is already sorted in same order.  
2) Array is already sorted in reverse order.  
3) All elements are same (special case of case 1 and 2)  

总结：The Worst Case can occur if **the input array** is such that the **maximum (or minimum) element is always chosen as pivot**.  
也即：每次选了 pivot 之后，所有其他数组元素都被分到了同一边，从而失去了用 pivot 划分 unsort-array 的作用。

#### 4. The lower-bound for comparison-based sorting algorithms

分析：comparison-based → decision trees! `n! ≤ 2^x → x ≥ log(n!)=Θ(n·logn)`，  
结论：the lower-bound is `Ω(n·log(n))`

#### 5. 什么时候适合使用 基数排序？(Radix sorting)

* `Every digit takes log2(n) bits`, we get the time complexity as O(n).[Linear time]
* If we have **log2(n) bits** for every digit, the running time of Radix appears to be better than Quick Sort for a **wide range** of input numbers. 
* 应用场景：[Sort n numbers in range from 0 to n^2 – 1 in linear time](http://www.geeksforgeeks.org/sort-n-numbers-range-0-n2-1-linear-time/)！

#### 6. 什么时候适合使用 基数排序？(Counting sorting)
- **Time Complexity**: O(n+k) where n is the number of elements in input array and k is the range of input.
- **Auxiliary Space**: O(n+k)

* Counting sort is efficient if `the range of input data` is **not** significantly greater than `the number of objects` to be sorted.
* It is **not** a comparison based sorting. It running time complexity is O(n) with space proportional to the range of data.

#### 7. 为什么要有 shell sorting 的存在？

* 首先一点：shell-sorting 是 insertion-sorting 的一个`更高效`变种，又称“缩小增量排序”！
* 思考： In insertion sort, we move elements only one position ahead. When an element has to be moved far ahead, many movements are involved. 这就是插入排序可改进的地方！
* The idea of shellSort is to allow exchange of far items.

