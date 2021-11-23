/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-06-26 11:02:07
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-08-27 20:29:44
 */
#include <iostream>
#include <cstdlib>
#include <vector>

void shellSort(std::vector<int> &arr) {
	//不断更改increment的值，保证最后increment为1, 保证最后是1
	for (int increment = arr.size()/3+1; increment > 0; increment = increment/3+1) {
		//进行插入排序
		for (int i = increment; i < arr.size(); i++) {
			int tmp = arr[i];
			int j;
			for (j = i; j >= increment && arr[j-increment] > tmp; j -= increment) {
				arr[j] = arr[j-increment];
			}
			arr[j] = tmp;
		}
		if (increment == 1) break; //防止在此处死循环,因为最终会一直是1 increment / 3 + 1
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
	shellSort(arr);

	for (auto i : arr) {
		std::cout << i << " ";
	}

	std::cout << std::endl;
	system("pause");
	return 0;
}