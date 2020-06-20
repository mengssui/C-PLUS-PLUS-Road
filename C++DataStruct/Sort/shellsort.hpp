#ifndef SHELLSORT_H_
#define SHELLSORT_H_

//希尔排序，时间复杂度（O^(3/2))  由插入排序改进 跳跃分割的策略  是不稳定的
//主要思路：将相距某个“增量”的记录组成子序列进行直接插入排序，得到的结果是基本有序
//increament的选取比较重要，但是最后一次increament必须为1
template<typename T>
void shellSort(T arr[], int n) {
    for (int increament = n/3+1; increament > 0; increament = increament/3+1) {
        for (int i = increament; i < n; i++) {
            T tmp = arr[i];
            int j;
            for (j = i; j >= increament && tmp < arr[j-increament] ;j -= increament) {
                arr[j] = arr [j-increament];
            }
            arr[j] = tmp;
        }
        if (increament == 1) break; //进行一次增量为一的即退出，否则increament一直为1 ，一直循环
    }
    return;
}
#endif//SHELLSORT_H_