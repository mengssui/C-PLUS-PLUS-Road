/*********************************************************************************
  *Copyright(C),BIT
  *FileName:  1.test.cpp
  *Author:    Mengbw
  *Date:      2021/4/17 14:42
  *Description: none 
**********************************************************************************/

#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

long long getMintimes(string &str);

int main () {
  int a = 13e+4;
  cout << a << endl;
  cout << (1e7+6) << endl;
  string str;
  cin >> str;
  cout << getMintimes(str) << endl;
  return 0;
}
long long getMintimes(string &str) {
  if (str.size() <= 1) return 0;
  long long sum = 0;
  int head = 0;

  while (head < str.size()) {
    string::iterator fa = find(str.begin()+head, str.end(),'a');
    if (fa == str.end()) break;
    if (find(fa, str.end(), 'b') == str.end()) break;
    if (str[fa-str.begin()+1] == 'b') {
      sum++;
      str[fa-str.begin()+1] = 'a';
      head = fa-str.begin()+1;
    } else head++;
  }

  return sum % (1000000007);
}