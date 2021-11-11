/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-08-26 21:53:10
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-08-27 10:39:49
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

void f(int a){
	cout << __func__ << endl;
}
void f(const int a) {
	cout << __func__ << endl;
}

int main()
{
	const int a = 0;
	f(a); //error: 错误，重定义了

	int d = 6;
	auto f = [=]() mutable {
		d++;
		cout << d << endl;
	};
	f();
	cout << d << endl;
   
   
	return 0;
}
