/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-06-23 22:32:44
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-06-24 00:21:26
 */
#include <iostream>
#include <vector>
#include <cstdlib>

void __mergeSort(std::vector<int> &arr, int l ,int r) {
	if (r - l <= 1) return; //分成一个就返回
	int mid = ((r - l) >> 1) + l;
	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid, r);

	// merge two section
	std::vector<int> left(arr.begin()+l, arr.begin() + mid);
	std::vector<int> right(arr.begin() + mid, arr.begin() + r);
	for (auto i : left) std::cout << i << " "; std::cout << std::endl;
	for (auto i : right) std::cout << i << " "; std::cout << std::endl;
	int lp = 0, rp = 0;
	std::cout << "a : ";
	for (int i = l; i < r; i++) {
		if (lp < mid - l && rp < r - mid && left[lp] <= right[rp] || rp >= r - mid) arr[i] =  left[lp++];
		else arr[i] = right[rp++];
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	return;
}

void mergeSort(std::vector<int> &arr) {
	__mergeSort(arr, 0, arr.size());
	return;
}


int main() {
	std::vector<int> arr;
	for (int i = 0; i < 20; i++) {
		int tmp = rand() % 20;
		//std::cout << tmp << " ";
		//arr.push_back(tmp);
		arr.push_back(10 - i);
		std::cout << 10 - i << " ";
	}
	std::cout << std::endl;


	mergeSort(arr);

	for (auto i : arr) std::cout << i << " ";
	std::cout << std::endl;

	return 0;
}