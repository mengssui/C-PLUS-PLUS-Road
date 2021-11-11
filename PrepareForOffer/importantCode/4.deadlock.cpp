/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-08-08 15:41:56
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-08-08 15:48:22
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
#include <mutex>
#include <thread>
#include <chrono>

using namespace std;

unique_lock<mutex> m1, m2;

void task1() {
	m1.lock();
	cout << "m1 lock" << endl;
	this_thread::sleep_for(chrono::seconds(2));
	m2.lock();
	cout << "m2 lock" << endl;

	m2.unlock();
	m1.unlock();
	
}
void task2() {
	m2.lock();
	cout << "m2 lock" << endl;
	this_thread::sleep_for(chrono::seconds(1));
	m1.lock();
	cout << "m1 lock" << endl;

	m1.unlock();
	m2.unlock();
	
}
int main()
{
	thread t1(task1);
	thread t2(task2);

	t1.join();
	t2.join();
	return 0;
}
