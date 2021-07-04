/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-07-02 19:34:25
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-07-03 16:55:45
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int id = 0;
	auto lamb = [id]() mutable {
		cout << &id << endl;
		id++;
	};


	id = 42;
	lamb();  //0 , lambda 捕获了id之后，所有的lamb 中使用的 id都是一个变量
	lamb();  //1
	lamb();  //2
	cout << id << endl;




	vector<int> s = {2, 3, 1, 5, 4};

	sort(s.begin(), s.end(), [](int a, int b) {return a < b;});

	auto f = [s] {
		std::cout << *s.begin() << std::endl;
	};

	f();


	for (auto i : s) cout << i  << " ";
	cout << endl;

	return 0;
}