/*
 * @Descripttion: 内存对齐
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-08-01 00:12:01
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-08-01 00:18:49
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

struct Node
{
	uint16_t u16;
	uint8_t u8;
	uint8_t u88;
};
struct Node2
{
	uint8_t u8;
	uint16_t u16;
	uint8_t u88;
};

int main()
{
	//打印地址
	Node node;
	cout << &node << endl;
	cout << static_cast<void*>(&(node.u8)) << endl;
	cout << static_cast<void*>(&node.u88) << endl;
	cout << sizeof(node) << endl;
	cout << alignof(node) << endl;
   
   
	return 0;
}

