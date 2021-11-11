/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-08-04 20:07:13
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-08-04 20:13:53
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
#include <memory>

using namespace std;

int main()
{
	shared_ptr<int> p(new int(3));
	cout << p.use_count() << endl;
	cout << *p << endl;
	shared_ptr<double> pd = make_shared<double>(5);
	cout << pd.use_count() << endl;
	cout << *pd << endl;
	shared_ptr<double> s = pd;
	cout << s.use_count() << endl;
	cout << s.get() << endl;
	
   
	return 0;
}

