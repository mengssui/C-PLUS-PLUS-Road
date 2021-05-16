/*
 * @Descripttion: 内存泄漏的代码，使用工具查看
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-04-23 11:01:23
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-04-23 11:54:21
 */

#include <iostream>
#include <algorithm>

using namespace std;

int main () {
  int *p = new int[3];
  delete[] p;
  return 0;
}
