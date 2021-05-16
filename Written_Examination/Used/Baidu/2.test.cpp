/*********************************************************************************
  *Copyright(C),BIT
  *FileName:  2.test.cpp
  *Author:    Mengbw
  *Date:      2021/4/11 20:25
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

#define MAX_N 100000
using namespace std;

int n, m;
char op;
int a, b;

vector<vector<int>> vec(MAX_N + 5, vector<int>());
int mark[MAX_N + 5]; //i人在i区域

void init() {
  for (int i = 1; i <= n; i++) {
    vec[i].push_back(i);
    mark[i] = i;
  }
  return;
}

void unionTwo(int a, int b) {
  for (auto i : vec[a]) vec[b].push_back(i), mark[i] = b;
  vec[a].clear();
  return;
}
long long  query(int a, int b) {
  if (mark[a] != mark[b]) return -1;
  else {
    int tmp = mark[b];
    int head = 0, tail = 0, time = 0;
    for (int i = 0; i < vec[tmp].size(); i++) {
      if (vec[tmp][i] == a) {head = i, time++;}
      if (vec[tmp][i] == b) {tail = i; time++;}
      if (time == 2) break;
    }
    return tail > head ? tail - head - 1 : head - tail - 1;
  }
}

int main() {
  cin >> n >> m;
  init();
  for (int i = 0; i < m; i++) {
    cin >> op >> a >> b;
    switch (op) {
      case 'C' : unionTwo(a, b); break;
      case 'Q' : cout << query(a, b) << endl; break;
    }
  }
  return 0;
}