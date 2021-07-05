/*
 * @Descripttion: 区别resize和reserve
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-07-05 23:04:04
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-07-05 23:17:03
 */
#include <iostream>
#include <string>

int main() {

	std::string s1 = "123";
	std::string s2 = "123";

	std::cout << s1.size() << " " << s1.capacity() << " " << std::endl;
	std::cout << s2.size() << " " << s2.capacity() << " " << std::endl;

	s1.reserve(s1.size() + 20);	
	s2.resize(s2.size() + 20);
	std::cout << s1.size() << " " << s1.capacity() << " " << std::endl;
	std::cout << s1[20] << std::endl;
	std::cout << s2.size() << " " << s2.capacity() << " " << std::endl;
	std::cout << s2[20] << std::endl;




	return 0;
}