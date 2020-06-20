//Copyright
//License
//Author
//This is the header for the sort.It generate the data used to be sorted.

#ifndef SELECTIONSORT_SORTTESTHELPER_H_
#define SELECTIONSORT_SORTTESTHELPER_H_
// #define NDEBUG   //禁用assert，必须在其头文件之前定义
#include <assert.h>
#include <ctime>
#include <iostream>

using namespace std;

namespace SortTestHelper{

    //生成n个元素的随机数组，每个元素的随机范围为[rangeL,rangeR]
    int* generateRandomArray(int n, int rangeL, int rangeR) {
        int* arr = new int[n];
        srand(time(NULL));
        for (int i = 0; i < n; i++) {
            //rand()生成随机整数，取余之后右移到范围内
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }
    //生成近乎有序的随机数组,先生成有序的，再随机交换几个
    int* generateNearlyOrderedArray(int n, int swapTimes) {
        int* arr = new int[n];
        for(int i = 0; i < n; i++) {
            arr[i] = i;
        }
        srand(time(NULL));
        for (int i = 0; i < swapTimes; i++) {
            int posx = rand() % n;
            int posy = rand() % n;
            swap(arr[posx], arr[posy]);
        }
        return arr;
    }
    //用于打印排序的对象
    template<typename T>
    void printArray(T arr[], int n) {
        
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }
    //测试是否排序正确
    template<typename T>
    bool isSorted(T arr[], int n) {
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
        return true;
    }
    //用于测试排序性能
    template<typename T>
    void testSort(string sortName, void (*sort)(T [], int), T arr[], int n) {
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        
        assert(isSorted(arr, n));
        cout << sortName << ": " 
            <<double(endTime - startTime) / CLOCKS_PER_SEC <<" s"
            <<endl;
        return;
    }
    //用拷贝一份数组
    int* copyIntArray(int a[], int n) {
        int *arr = new int[n];
        copy(a, a+n, arr);
        return arr;
    }
}
#endif //SELECTIONSORT_SORTTESTHELPER_H_ 
