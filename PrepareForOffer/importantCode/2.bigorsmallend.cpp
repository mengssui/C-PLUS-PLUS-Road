/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-08-05 16:04:50
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-08-05 16:09:52
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
	uint8_t id[4] = { 0x01, 0x02, 0x03, 0x04};
	uint32_t t =  *(uint32_t*)id;
	cout << hex << t << endl;
	cout << static_cast<void*>(id) << endl;
	cout << &t << endl;
   
	return 0;
}

