/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-08-04 20:46:13
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-08-04 21:29:12
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

using namespace std;

class SingleInstance {
public:
	static SingleInstance* getInstanec() {
		if (instance == nullptr) {
			unique_lock<mutex> lock(m_mutex);
			if (instance == nullptr) {
				instance = new SingleInstance();
			}
		}
		return instance;
	}
private:
	SingleInstance(){}
	SingleInstance(const SingleInstance& rhs) = delete;
	static SingleInstance *instance;
	static mutex m_mutex;
};

SingleInstance* SingleInstance::instance = nullptr;
mutex SingleInstance::m_mutex;

int main()
{
	SingleInstance* p = SingleInstance::getInstanec();
	SingleInstance* q = SingleInstance::getInstanec();
	cout << boolalpha << (p == q) << endl;
	return 0;
}
