/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-06-26 20:24:25
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-06-26 21:20:05
 */
#include <iostream>
#include <vector>
#include <cstdlib>


void shiftDown(std::vector<int> &arr, int ind, int size) {
	while (ind*2 <= size) {
		int tmp = ind*2;
		if ((ind*2 + 1) <= size && arr[ind*2+1] > arr[tmp]) {
			tmp = ind*2+1;
		}
		if (arr[ind] >= arr[tmp]) break; //比较三者最大，而不是两者！！！
		std::swap(arr[ind], arr[tmp]);
		ind = tmp;
	}
	return;	
}
void headpify(std::vector<int> &arr) {
	for (int i = (arr.size()-1)/2; i >= 1; i--) {
		shiftDown(arr, i, arr.size()-1);
	}
}
void heapSort(std::vector<int>& arr) {
	//建堆，线性建堆法
	arr.insert(arr.begin(), 0); //方便从1开始
	// for (auto i : arr) std::cout << i << " ";
	// std::cout << std::endl;
	headpify(arr);
	std::cout << "max : " << arr[1] << std::endl;
	//不断循环
	for (int i = 1; i <= arr.size()-1; i++) {
		std::swap(arr[1], arr[arr.size()-i]);
		shiftDown(arr, 1, arr.size()-1-i);
	}
	return;
}

int main() {
	std::vector<int> arr;
	for (int i = 0; i < 10; i++) {
		int tmp = rand() % 20;
		arr.push_back(tmp);
		std::cout << tmp << " ";
	}
	std::cout << std::endl;
	heapSort(arr);

	arr.erase(arr.begin());
	for (auto i : arr) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	return 0;
}
