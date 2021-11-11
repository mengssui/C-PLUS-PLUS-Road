/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-08-11 15:27:29
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-08-11 15:46:03
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

#define ENC_ID_SIZE 4

using namespace std;
struct node {
	uint32_t controller_id;
}paring_info{0x01020304};

uint8_t id[ENC_ID_SIZE * 2] = {
		paring_info.controller_id & 0xFF,
		(paring_info.controller_id >> 8U) & 0xFF,
		(paring_info.controller_id >> 16U) & 0xFF,
		(paring_info.controller_id >> 24U) & 0xFF,
		0x08,
		0x07,
		0x06,
		0x05,
	};

int main()
{




	uint32_t tmpfist = 0x01020304;
	uint32_t tmpsecd = 0x05060708;

	cout << static_cast<void*>(&id[0]) << endl;
	cout << static_cast<void*>(&id[1]) << endl;

	cout << hex << tmpfist << endl;
	cout << hex << *(uint32_t*)id << endl;

	cout << boolalpha << (tmpfist == *(uint32_t*)id) << endl;

	cout << hex << tmpsecd << endl;
	cout << hex << *(uint32_t*)&id[4] << endl;

	cout << boolalpha << (tmpsecd == *(uint32_t*)&id[ENC_ID_SIZE]) << endl;



   
   
	return 0;
}
