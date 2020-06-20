#ifndef MERGESORT_H_ 
#define MERGESORT_H_

//归并排序
//二分log(n),每次n，成为O(nlogn)
//O(n)空间复杂度

//对arr[l...mid]和arr[mid+1,r]的范围进行归并
template<typename T>
void __merge(T arr[], int l, int mid, int r) {
    // T aux[r-l+1]; //临时空间   这种使用方式不对，貌似原因是溢出
    auto aux = new T[r-l+1];
    for (long long i = l; i <= r; i++)  //拷贝一份副本
        aux[i-l] = arr[i];
    int i = l, j = mid + 1;
    for (long long k = l; k <= r; k++) {
        if (i > mid) {
            arr[k] = aux[j-l];
            j++;
        } else if (j > r) {
            arr[k] = aux[i-l];
            i++;
        } else if (aux[i-l] < aux[j-l]) {
            arr[k] = aux[i-l];
            i++;
        } else {
            arr[k] = aux[j-l];
            j++;
        }
    }
    delete[] aux;
}
//递归使用归并排序，对arr[l...r]的范围进行排序
template<typename T>
void __mergeSort(T arr[], int l, int r) {
    if (l >= r) return;
    // if (r - l <= 15) {   //数量较小时用插入排序
    //     insertionSort(arr, l, r);
    //     return;
    // }

    int mid = (l+r) / 2;
    __mergeSort(arr, l ,mid);
    __mergeSort(arr, mid+1, r);
    if (arr[mid] > arr [mid+1]){ //优化1：前后两段都有序了，并且前边最大小于后边最小，因此最后就不用归并了
    __merge(arr, l , mid ,r);
    }
}
//递归实现归并排序  
template<typename T>
void mergeSort(T arr[], int n) {
    __mergeSort(arr, 0, n-1);
}
//不用递归，自底向上
template<typename T>
void mergeSortBU(T arr[], int n) {
    for (int sz = 1; sz <= n; sz += sz) {
        for (int i = 0; i + sz < n; i += sz*2) {
            __merge(arr, i, i + sz -1, min(i + 2*sz - 1, n-1));   //有可能后一个不够sz长了
        }
    }
}

#endif//MERGESORT_H_