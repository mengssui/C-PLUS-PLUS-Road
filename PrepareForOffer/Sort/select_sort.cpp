/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-06-24 23:40:20
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-06-24 23:49:00
 */
#include <iostream>
#include <vector>
#include <cstdlib>

void selectSort(std::vector<int>& arr) {
	for (int i = 0; i < arr.size() - 1; i++) {
		int tmp = i;
		for (int j = i + 1; j < arr.size(); j++) {
			if (arr[tmp] > arr[j]) tmp = j;
		}
		std::swap(arr[tmp], arr[i]);
	}
}

int main() {
	std::vector<int> arr;
	for (int i = 0; i < 10; i++) {
		int tmp = rand() % 20;
		arr.push_back(tmp);
		std::cout << tmp << " ";
	}
	std::cout << std::endl;
	selectSort(arr);

	for (auto i : arr) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	return 0;
}