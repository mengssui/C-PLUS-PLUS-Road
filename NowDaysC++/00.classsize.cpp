/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-08-04 09:33:14
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-08-04 09:39:23
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
#include <cstddef>

using namespace std;

class A
{
public:
	/* data */
	char c1;
	int  i2;
	char c3;
	double d4;
public:
	A(/* args */);
	~A();
};

A::A(/* args */)
{
}

A::~A()
{
}


int main()
{
	A a;
	cout << sizeof(A) << endl;
	cout << sizeof a << endl;
	cout << &a << endl;
	cout << static_cast<void*>(&a.c1) << endl;
	cout << &a.i2 << endl;
	cout << static_cast<void*>(&a.c3) << endl;
	cout << &a.d4 << endl;
	cout << offsetof(A, c1) << endl;
	cout << offsetof(A, i2) << endl;
	cout << offsetof(A, c3) << endl;
	cout << offsetof(A, d4) << endl;
   
   
	return 0;
}
