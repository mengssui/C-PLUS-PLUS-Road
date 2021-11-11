/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-08-16 10:42:39
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-08-16 10:58:52
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
	//cd53956d1af01f431667d2eb0853d835
	string s;
	cin >> s;
	if (s.size() != 32) cerr << "ERROR: SIZE MUST BE 16 bytes" << endl;
	vector<string> out;
	for (int i = 0; i < s.size(); i+=2) {
		out.push_back("0x" + s.substr(i, 2));
	}

cout << out .size() << endl;
	for (auto i : out) {
		cout << i << ",";
	}
	cout << endl;
   
	return 0;
}