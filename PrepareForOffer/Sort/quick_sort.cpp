/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-06-26 15:57:10
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-08-16 18:56:39
 */
#include <iostream>
#include <vector>
#include <cstdlib>

//[l, r) 区间
int partation(std::vector<int>& arr, int l ,int r) {
	int pivot = rand() % (r - l) + l;
	std::swap(arr[l], arr[pivot]);
	int head = l;
	for (int i = l + 1; i < r; i++) {
		if (arr[i] > arr[l]) continue;
		else {
			std::swap(arr[i], arr[++head]);
		} 
	}
	std::swap(arr[l], arr[head]);
	return head;
}

void __quickSort(std::vector<int>&arr, int l, int r) {
	if (r - l <= 1) return;
	int pivot = partation(arr, l , r);
	__quickSort(arr, l, pivot);
	__quickSort(arr, pivot, r);
	return;
}

void quickSort(std::vector<int>& arr) {
	__quickSort(arr, 0, arr.size());
	return;
}


//[l, r)
void __quickSort2(std::vector<int>& arr, int l, int r) {
	if (r - l <= 1) return;
	
	int pivot = arr[l];
	int head = l+1, tail = r-1;

	while (true) {
		while(head < r && arr[head] <= pivot) head++;
		while(tail > l && arr[tail] >= pivot) tail--;

		if (head > tail) break;
		std::swap(arr[head++], arr[tail--]);
	}
	std::swap(arr[l], arr[tail]);

	__quickSort2(arr, l, tail); //head和tail之间很可能有值，是等于piovt
	__quickSort2(arr, head, r);
	return;
}

void quickSort2(std::vector<int>& arr) {
	__quickSort2(arr, 0, arr.size());
	return;
}

int main() {
	std::vector<int> arr;
	for (int i = 0; i < 60; i++) {
		int tmp = rand() % 20;
		arr.push_back(tmp);
		std::cout << tmp << " ";
	}
	std::cout << std::endl;


	quickSort(arr);

	for (auto i : arr) std::cout << i << " ";
	std::cout << std::endl;

	return 0;
}