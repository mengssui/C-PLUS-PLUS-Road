//堆排序，时间复杂度O(nlogn)

#include "heap.hpp"

template <typename T>
void heapSort1(T arr[], int n) {
  MaxHeap<T> maxHeap(n);
  for (int i = 0; i < n; i++) {
    maxHeap.insert(arr[i]);
  }
  for (int i = n - 1; i >= 0; i--) {
    arr[i] = maxHeap.extractMax();
  }
  return;
}

template <typename T>
void heapSort2(T arr[], int n) {
  MaxHeap<int> maxHeap(arr, n);
  for (int i = n - 1; i >= 0; i--) {
    arr[i] = maxHeap.extractMax();
  }
  return;
}

//原地排序,序号从零开始
//空间复杂度为O(1)
template <class T>
void __shiftdown(T arr[], int n, int i) {
  while (2 * i + 1 < n) {  // 0开始，不包括n,小于号
    int j = 2 * i + 1;
    if (j + 1 < n && arr[j] < arr[j + 1]) {
      j += 1;
    }
    if (arr[j] <= arr[i]) {
      break;
    }
    swap(arr[i], arr[j]);
    i = j;
  }
}

template <class T>
void heapSort3(T arr[], int n) {
  // heapify创建好最大堆
  for (int i = (n - 1) / 2; i >= 0; i--) {
    __shiftdown(arr, n, i);
  }
  for (int i = n - 1; i > 0; i--) {
    swap(arr[0], arr[i]);
    __shiftdown(arr, i, 0);
  }
}