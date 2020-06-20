#ifndef SELECTIONSORT_H_
#define SELECTIONSORT_H_

//选择排序，时间复杂度O(n²)
//第i元素与剩余的比较，找到最小的或最大的进行交换 不断循环递增i
template<typename T>//模板函数，方便通用
void selectionSort (T arr[], int n) {
    for (int i = 0; i < n; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr [minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]); //标准库中的函数
    }
    return;
}
#endif//SELECTIONSORT_H_