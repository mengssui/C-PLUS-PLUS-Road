/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-06-23 22:32:44
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-06-23 22:54:37
 */
#include <iostream>
#include <vector>
#include <cstdlib>

void bubbleSort(std::vector<int> &arr) {
	bool need = true;
	for (int i = 1; need && i < arr.size(); i++) {
		need = false;
		for (int j = 0; j < arr.size() - i; j++) {
			if (arr[j] < arr[j+1]) continue;
			std::swap(arr[j], arr[j+1]);
			need = true;
		}
	}
	return;
}

int main() {
	std::vector<int> arr;
	for (int i = 0; i < 10; i++) {
		int tmp = rand() % 20;
		std::cout << tmp << " ";
		arr.push_back(tmp);
	}
	std::cout << std::endl;

	bubbleSort(arr);

	for (auto i : arr) std::cout << i << " ";
	std::cout << std::endl;

	return 0;
}