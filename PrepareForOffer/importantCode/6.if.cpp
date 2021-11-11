/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-08-27 10:41:24
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-08-27 11:01:43
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstdint>

using namespace std;

int main()
{
	int d = 6;
	if (int c = 0 != 5) {
		cout << c << endl;
	} else {
		cout << c << endl;
		cout << "no" << endl;
	}
	//cout << c << endl;
	int arr[2][3];
	cout << arr << endl;
	cout << arr[0] << endl;
	cout << arr[1] << endl;
	cout << &arr[1][0] << endl;

	int a = 10;
	const int *pa = &a;

	int* c = const_cast<int*>(pa);
   
	return 0;
}
