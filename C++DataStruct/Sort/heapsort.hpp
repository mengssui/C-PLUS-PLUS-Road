#include "heap.hpp"

template<typename T>
void heapSort1(T arr[], int n) {
  MaxHeap<T> maxHeap(n);
  for (int i = 0; i < n; i++) {
    maxHeap.insert(arr[i]);
  }
  for (int i = n-1; i >= 0; i--) {
    arr[i] = maxHeap.extractMax();
  }
  return;
}

template<typename T>
void heapSort2(T arr[], int n) {
  MaxHeap<int> maxHeap(arr, n);
  for (int i = n - 1; i >= 0; i--) {
    arr[i] = maxHeap.extractMax();
  }
  return;
}