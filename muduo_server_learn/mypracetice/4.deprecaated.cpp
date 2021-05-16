/*
 * @Descripttion: 警告一个函数是过期的
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-05-06 09:42:27
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-05-06 10:06:41
 */

#include <iostream>

//__attribute__ ((deprecated)) 表示该函数是过时的，被淘汰的
//调用该属性的函数，在编译时候会发出警告 
__attribute__ ((deprecated))
void donotcallthisfunc() 
{
  std::cout << "not me" << std::endl;
  return;
}

int main () {
  // donotcallthisfunc(); 调用该函数时候编译出错
  std::cout << "main()" << std::endl;
  return 0;
}
