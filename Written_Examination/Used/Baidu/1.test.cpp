/*********************************************************************************
  *Copyright(C),BIT
  *FileName:  1.test.cpp
  *Author:    Mengbw
  *Date:      2021/4/11 19:53
  *Description: none 
**********************************************************************************/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>    //
#include <vector>    //向量
#include <queue>    //队列
#include <string>
#include <cstring>
#include <map>      //
#include <stack>    //栈
#include <set>      //

using namespace std;
#define MAX_N 1000
int hope[MAX_N + 1000];
int pro[MAX_N + 1000];
int times, n, m;

void readHope() {
  for (int i = 0; i < n; i++) {
    cin >> hope[i];
  }
  return;
}

void readPro() {
  for (int i = 0; i < m; i++) {
    cin >> pro[i];
  }
  sort(pro, pro + m);
  //debug
 // for (int i = 0; i < m; i++) cout << pro[i] << " ";
 // cout << endl;
  //end of debug

}

void findOne(int target) {
  if (target > pro[m-1]) {cout << 0; return;}
  int head = 0, tail = m - 1, mid;
  while (head < tail) {
    mid = head + ((tail - head) >> 1);
    if (pro[mid] < target) {
      head = mid + 1;
    } else {
      tail = mid;
    }
  }
  cout << m - head << " ";
}


int main() {
  cin >> times;
  for (int i = 0; i < times; i++) {
    cin >> n >> m;
    readHope();
    readPro();
    for (int i = 0; i < n; i++) findOne(hope[i]);
    cout << endl;
  }
  return 0;
}