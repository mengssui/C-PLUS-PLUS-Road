/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-08-04 21:47:43
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-08-04 21:54:50
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
#include <exception>

using namespace std;

int main()
{
	try
	{
		std::string s("ssss");
		throw s;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(std::string s) {
		std::cerr << s << endl;
	}
	
   
   
	return 0;
}
