#ifndef QUICKSORT_H_ 
#define QUICKSORT_H_
#include "insertionsort.hpp"
#include <iostream>
#include <ctime>
//快速排序O(nlogn)
//核心过程partition

/**
 方法一
 *
 * 
 */
//对arr[l...r]进行partition操作
//返回p，使得arr[l..p-1] < arr[p] < arr[p+1...r]
template<typename T>
int __partition(T arr[], int l, int r) {

    //优化二：随机选取中间值，以防待排序序列近乎有序导致其退化为O(n²)
    swap(arr[l], arr[rand()%(r-l+1)+l]);
    T v = arr[l];
    //arr[l..p-1] < arr[p] < arr[p+1...i)
    int j = l;
    for (int i = l + 1; i <= r; i++) {
        if (arr[i] < v) {
            swap(arr[j+1], arr[i]);
            j++;   //可以写成swap(arr[++j], arr[i]);
        }
    }
    
    swap(arr[l], arr[j]);

    return j;
}
//对arr[l...r]部分进行快速排序
template<typename T>
void __quickSort(T arr[], int l, int r) {
    // if (l >= r) return;
    //可优化一：可以采用插入排序，对于小数量数组其有优势
    if (r - l <= 15) {
        insertionSort(arr, l, r);
        return;
    }
    int p = __partition(arr, l, r);
    __quickSort(arr, l, p-1);
    __quickSort(arr, p+1, r);

}
template<typename T>
void quickSort(T arr[], int n) {
    srand(time(NULL));
    __quickSort(arr, 0, n-1);
}
/**************************************************************/


/*******************************方法二**************************/
//优化partition，为了解决大量重复序列导致退化为O(n²)
template<typename T>
int __partition2(T arr[], int l, int r) {
    swap(arr[l], arr[rand()%(r-l+1)+l]);
    T v = arr[l];
    // arr[l+1...i) <= v; arr(j...r] >=v
    int i = l+1, j = r;
    while (true) {
        while (i <= r && arr[i] < v) i++;
        while (j >= l+1 && arr[j] > v) j--;
        if (i > j) break;
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    swap(arr[l], arr[j]);
    return j;
}
//对arr[l...r]部分进行快速排序
template<typename T>
void __quickSort2(T arr[], int l, int r) {
    // if (l >= r) return;
    //可优化一：可以采用插入排序，对于小数量数组其有优势
    if (r - l <= 15) {
        insertionSort(arr, l, r);
        return;
    }
    int p = __partition2(arr, l, r);
    __quickSort2(arr, l, p-1);
    __quickSort2(arr, p+1, r);

}
template<typename T>
void quickSort2(T arr[], int n) {
    srand(time(NULL));
    __quickSort2(arr, 0, n-1);
}

/**
 * 三路排序
 * 分成大于，小于，等于 三部分
 * 
 */
template<typename T>
void __quickSort3Ways(T arr[], int l, int r) {
    // if (l >= r) return;
    //可优化一：可以采用插入排序，对于小数量数组其有优势
    if (r - l <= 15) {
        insertionSort(arr, l, r);
        return;
    }
    //patition部分
    swap(arr[l], arr[rand()%(r-l+1)+l]);
    T v = arr[l];
    int lt = l; //arr[l+1...lt] < v
    int gt = r + 1;//arr[gt...r] > v
    int i = l + 1;//arr[l+1...i) == v
    while (i < gt) {
        if (arr[i] < v) {
            swap(arr[i], arr[lt+1]);
            lt++;
            i++;
        } else if (arr[i] > v) {
            swap(arr[i], arr[gt-1]);
            gt--;
        } else { //arr[i] == v 
            i++;
        }
    }
    swap(arr[l], arr[lt]);

    __quickSort3Ways(arr, l, lt-1);
    __quickSort3Ways(arr, gt, r);

}
template<typename T>
void quickSort3Ways(T arr[], int n) {
    srand(time(NULL));
    __quickSort3Ways(arr, 0, n-1);
}


#endif //QUICKSORT_H_