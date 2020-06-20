#ifndef INSERTIONSORT_H_
#define INSERTIONSORT_H_

//插入排序，时间复杂度O(n²)  
//处理近乎有序的数据非常有优势，甚至比一些nlog(n)性能还要好
//处理近乎有序以及数据量较少的时候较为有优势
template<typename T>
void insertionSort(T arr[], int n) {
    for (int i = 1; i < n; i++) {   //第一个元素不用管，因为每次都与要与之前的比较
        T e = arr[i];
        int j;  //由于下面for循环之后还要用到j，因此需要在外部初始化j
        for (j = i; j > 0 && arr[j-1] > e; j--) {
                arr[j] = arr[j-1]; //用赋值而不是交换提高效率
        }   
        arr[j] = e;
    }
    return;
}
//对于arr[l..r]区间内数据进行插入排序，应用于递归排序的一部分
template<typename T>
void insertionSort(T arr[], int l, int r) {
    for (int i = l+1; i <= r; i++) {
        int j;
        T tmp = arr[i];
        for (j = i; j > l && arr[j-1] > tmp ; j--) {
            arr[j] = arr[j-1];
        }
        arr[j] = tmp;
    }
    return;
}

#endif//INSERTIONSORT_H_