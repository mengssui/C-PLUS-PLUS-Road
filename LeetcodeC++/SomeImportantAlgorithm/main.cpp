#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//冒泡排序
//n个序列，后边是已排序区，前边是未排序区
//每次要确定未排序区前一个元素
void bubbleSort(int *arr, int n) {
    int need = true;
    for (int i = 1; need && i < n; i++) {
        need = false;
        for (int j = 0;j < n - i; j++) {
            if (arr[j] <= arr[j + 1]) continue;
            swap(arr[j], arr[j + 1]);
            need = true;
        }
    }
    return;
}

void bubbleSort(vector<int> &arr) {
    bool need = true;
    for (int i = 1; need && i < arr.size(); i++) {
        need = false;
        for (int j = 0; j < arr.size() - i; j++) {
            if (arr[j] <= arr[j + 1]) continue;
            swap(arr[j], arr[j + 1]);
            need = true;
        }
    }
    return;
}

//插入排序
//当前元素之前的为已排序好的，将该元素插入到合适位置
void insertSort(vector<int> &arr) {
    for (int i = 1; i < arr.size(); i++) {
        int now = arr[i];
        int j;
        for (j = i; arr[j - 1] > now && j >= 0; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = now;
    }
    return;
}

//归并排序
void MergeSort(vector<int> &arr, int l ,int r) {
    if (l >= r) return;

    int mid = (l + r) >> 1;
    MergeSort(arr, l, mid);
    MergeSort(arr, mid + 1, r);

    vector<int> tmp;
    int le = mid, rb = mid + 1;
    int lb = l, re = r;
    while(lb <= le || rb <= re) {
        if (lb > le) {
            while (rb <= re) tmp.push_back(arr[rb++]);
            break;
        }
        if (rb > re) {
            while (lb <= le) tmp.push_back(arr[lb++]);
            break;
        }
        if (arr[lb] <= arr[rb]) tmp.push_back(arr[lb++]);
        else tmp.push_back(arr[rb++]);
    }

    for (int i = l; i <= r; i++) {
        arr[i] = tmp[i - l];
    }
    return;
}

//选择排序，每次从后边选择一个最大/小的与当前元素交换
//不稳定排序：5 3 5 2 1, 第一次将1和5交换，导致原来的两个5相对位置改变
void selectSort(vector<int> &arr) {
    for (int i = 0; i < arr.size()-1; i++) {
        int min = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] <= arr[j]) continue;
            min = j;
        }
        swap(arr[i], arr[min]);
    }
    return;
}

//快速排序
void quickSort(vector<int> &arr, int b ,int end) {
    if (b >= end) return;
    int pivot = arr[b];
    int l = b, r = end;
    //partation
    do {
        while(arr[l] < pivot) l++;
        while(pivot < arr[r]) r--;
        if (l <= r) {
            swap(arr[l], arr[r]);
            l++, r--;
        }
    } while(l <= r);

    quickSort(arr, b, r);
    quickSort(arr, l, end);
    return;
}

//希尔排序，有一个增量的插入排序
void shellSort(vector<int> &arr) {
    int n = arr.size();
    for (int increment = n / 3 + 1; increment > 0; increment = increment / 3 + 1) {
        for (int i = increment; i < n; i++) {
            int tmp = arr[increment];
            int j;
            for (j = i; j >= increment && arr[j - increment] > tmp; j -= increment) {
                arr[j] = arr[j-increment];
            }
            arr[j] = tmp;
        }
        if (increment == 1) break;
    }
    return;
}

//堆排序
//ind表示当前的index
void downUpdate(int*arr, int n, int ind) {
    while((ind << 1) <= n) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if(arr[l] > arr[temp]) temp = l;
        if(r <= n && arr[r] > arr[temp]) temp = r;
        if (temp == ind) break;
        swap(arr[temp], arr[ind]);
        ind = temp;
    }
    return;
}

void heap_sort(int* arr, int n) {
    arr -= 1; //给arr首地址减1，之后访问arr[0]就需要使用arr[1]
    //heapify操作，将数组转换为堆
    for(int i = n >> 1; i >= 1; i--) {
        downUpdate(arr, n , i);
    }
    //进行原地排序
    for(int i = n; i>1 ; i--) {
        swap(arr[i], arr[1]);
        downUpdate(arr, i-1, 1);
    }
    return;
}

int main() {
   // int arr[5] = {3, 4, 1, 2, 0};
   // bubbleSort(arr, 5);
   // for (int i = 0; i < 5; i++) cout << arr[i] << " ";
   // cout << endl;
   // vector<int> arr2{2, 3, 4, 5, 9,8,7,6};
   // bubbleSort(arr2);
   // for (auto i : arr2) cout << i << " ";
   // cout << endl;

   // vector<int> arr4{2, 3, 4, 5, 9,8,7,6};
   // insertSort(arr4);
   // for (auto i : arr4) cout << i << " ";
   // cout << endl;

    vector<int> arr5{6,8,4,5,1};
    quickSort(arr5, 0, 4);
    for (auto i : arr5) cout << i << " ";
    cout << endl;

   // vector<int> arr3{2, 3, 4, 5, 9,8,7,6};
   // selectSort(arr3);
   // for (auto i : arr3) cout << i << " ";
   // cout << endl;
    return 0;
}