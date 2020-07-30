// Demo2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <mutex>
#include <thread>

using namespace std;
//存钱
void Deposit(mutex& g_m, int& g_money) {
  for (int i = 0; i < 100; i++) {
		g_m.lock(); //锁的力度最小化
		g_money += 1;
		g_m.unlock();
  }
}

//取钱
void Withdraw(mutex& g_m, int& g_money) {
	for (int i = 0; i < 100; i++) {
		g_m.lock();
		g_money -= 2;
		g_m.unlock();
	}
}
int main()
{
	mutex g_m;
	int g_money = 2000;
	cout << "current money is " << g_money << endl;
	thread t1(Deposit, ref(g_m), ref(g_money));
	thread t2(Withdraw, ref(g_m), ref(g_money));

	t1.join();
	t2.join();

	cout << "Finally money is " << g_money << endl;
	return 0;
}

