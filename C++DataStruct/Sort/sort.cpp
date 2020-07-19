//Copyright
//License
//Author：Mengbw_
//2020年6月19日
//This is the main.cpp to sort.

#include "sorttesthelper.hpp"
#include "mergesort.hpp"
#include "quicksort.hpp"
#include "shellsort.hpp"
#include "insertionsort.hpp"
#include "selectionsort.hpp"
#include "bubblesort.hpp"
#include "heapsort.hpp"


int main() {
    int n = 1000000;
    int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    // int* arr2 = SortTestHelper::copyIntArray(arr1, n);
    // int* arr3 = SortTestHelper::copyIntArray(arr1, n);
    // int* arr4 = SortTestHelper::copyIntArray(arr1, n);
    // int* arr5 = SortTestHelper::copyIntArray(arr1, n);
    // int* arr6 = SortTestHelper::copyIntArray(arr1, n);
    int* arr7 = SortTestHelper::copyIntArray(arr1, n);
    int* arr8 = SortTestHelper::copyIntArray(arr1, n);
    int* arr9 = SortTestHelper::copyIntArray(arr1, n);
    int* arr10 = SortTestHelper::copyIntArray(arr1,n);
    int* arr11 = SortTestHelper::copyIntArray(arr1,n);
    int* arr12 = SortTestHelper::copyIntArray(arr1,n);

    // SortTestHelper::testSort("Selection Sort", selectionSort, arr1, n);
    // SortTestHelper::testSort("Bubble Sort", bubbleSort, arr2, n);
    // SortTestHelper::testSort("Inseration Sort", insertionSort, arr3, n);
    // SortTestHelper::testSort("Shell Sort", shellSort, arr4, n);
    // SortTestHelper::testSort("MergeSort", mergeSort, arr5, n);
    // SortTestHelper::testSort("MergeSortBU", mergeSortBU, arr6, n);
    SortTestHelper::testSort("QuickSort", quickSort, arr7, n);
    SortTestHelper::testSort("QuickSort2", quickSort2, arr8, n);
    SortTestHelper::testSort("QuickSort3Ways", quickSort3Ways, arr9, n);
    SortTestHelper::testSort("HeapSort", heapSort1,arr10,n);
    SortTestHelper::testSort("HeapSort2", heapSort2, arr11 ,n);
    SortTestHelper::testSort("HeapSort3", heapSort3, arr12 ,n);

    delete [] arr1;
    // delete [] arr2;
    // delete [] arr3;
    // delete [] arr4;
    // delete [] arr5;
    // delete [] arr6;
    delete [] arr7;
    delete [] arr8;
    delete [] arr9;
    delete [] arr10;
    delete [] arr11;
    delete [] arr12;
    return 0;    
}