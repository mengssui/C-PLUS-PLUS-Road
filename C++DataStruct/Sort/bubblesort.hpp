#ifndef BUBBLESORT_H_
#define BUBBLESORT_H_
//冒泡排序，时间复杂度(O(n²))
//加入needcontinue判断是否需要继续，如果为交换说明已经排好了，不用再继续了
template<typename T> 
void bubbleSort(T arr[], int n) {
    bool needcontinue = true;
    for (int i = 0;i < n && needcontinue; i++) {
        needcontinue = false;
        for (int j = n -1; j > i; j--) {
            if (arr[j] < arr[j-1] ) {
                swap(arr[j], arr[j-1]);
                needcontinue = true;
            }
        }
    }
    return;
}

#endif