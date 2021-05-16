/*********************************************************************************
  *Copyright(C),BIT
  *FileName:  2.test.cpp
  *Author:    Mengbw
  *Date:      2021/4/18 21:13
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
int mytime[1005];
int val[1005];
int sum[1005];
int maxv[1005];

int main() {
  int T, n;
  cin >> T;
  for (int i = 0; i < T; i++) {
    long long minSum = 0;
    cin  >> n;
    for (int i = 1; i <= n; i++) sum[i] = 0, maxv[i] = 0;
    for (int i = 1; i <= n; i++) cin >> mytime[i];
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 1; i <= n; i++) {
      int ind = mytime[i];
      sum[ind] += val[i];
      maxv[ind] = max(maxv[ind], val[i]);
    }

    for (int i = 1; i <= n; i++) {
      minSum = minSum + (sum[i] - maxv[i]);
    }
    cout << minSum << endl;
  }
  return 0;
}