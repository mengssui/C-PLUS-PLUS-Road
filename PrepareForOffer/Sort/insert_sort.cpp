/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-06-23 22:32:44
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-06-23 23:27:36
 */
#include <iostream>
#include <vector>
#include <cstdlib>

void insertSort(std::vector<int> &arr) {
	for (int i = 1; i < arr.size(); i++) {
		int val = arr[i];
		int j;
		for (j = i - 1; j >= 0 && val < arr[j]; j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = val;
	}
	return;
}
//插入排序
//当前元素之前的为已排序好的，将该元素插入到合适位置
void insertSort2(std::vector<int> &arr) {
    for (int i = 1; i < arr.size(); i++) {
        int now = arr[i];
        int j;
        for (j = i; arr[j - 1] > now && j >= 0; j--) {
            arr[j] = arr[j - 1];  //用赋值代替交换操作💢
        }
        arr[j] = now;
    }
    return;
}

int main() {
	std::vector<int> arr;
	for (int i = 0; i < 10; i++) {
		int tmp = rand() % 20;
		//std::cout << tmp << " ";
		//arr.push_back(tmp);
		arr.push_back(10 - i);
		std::cout << 10 - i << " ";
	}
	std::cout << std::endl;


	//insertSort(arr);
	insertSort2(arr);

	for (auto i : arr) std::cout << i << " ";
	std::cout << std::endl;

	return 0;
}