// Copyright
// License
// Autho : Mengbw_
// data : 2020/7/10
// This is the main.cpp to sort
//博客网站：https://blog.csdn.net/qq_42956667/article/details/107227883

//暴力解法，找到所有的字符子串，依次判断
//中心扩散解法 ，分为单个字符中心和两个字符中心

#include <iostream>
#include <string>
#include <vector>

using namespace std;
//动态规划
//输入是一个字符串
//输出是一个最大回文子串
string longPalinDrome(string s) {
  if (s.size() < 2) {
    return s;
  }
  // string retstr = s.substr(0,1); //返回的子串至少为s的第一个值
  int len = s.size();
  int begin = 0;
  int length = 1;
  vector<vector<int>> dp(len, vector<int>(len));  //创建len个vecotr的vector，其中的vetctor又初始化为len个int

  for (int i = len - 2; i >= 0; i--) {
    for (int j = i; j < len; j++) {
      //若ij相等是回文; 两个元素相邻，若值一样则他们是回文的;
      //两值一样，前一组是回文
      dp[i][j] = (i == j) || ((i + 1 == j || dp[i+1][j-1]) && s[i] == s[j]);
      if (dp[i][j] && length < j - i + 1) {
        begin = i;
        length = j - i + 1;
      }
    }
  }
  return s.substr(begin, length);
}

int main() {
  string s =
      "dsfsdhadhfkdsdsfsdhadhdsfsdhadhfkddsfsdhadhfkdsahfk\
  sadhdsfsdhadhfkdsahfksadhfksddsfsdhadhfkdsahfksadhfksdhfusdihfk\
  sjadfhksadjkdsahfdsjkhfksdhffhiawoeuruihweiyrtiuoncsdbfzmbfkhfi\
  oaewncfhskdsfsdhadhfkdsahfksadhfksdhfusdihfksjadfhksadjkdsahfds\
  jkhfksdhffhiawoeuruihweiyrtiuoncsdbfzmbfkhfioaewncfhskhfusdihfk\
  sjadfhksadjkdsahfdsjkhfksdhffhiawoeuruihweiyrtiuoncsdbfzmbfkhf\
  oaewncfhskdsfsdhadhfkdsahfksadhfksdhfusdihfksjadfhksadjkdsahfd\
  jkhfksdhffhiawoeuruihweiyrtiuoncsdbfzmbfkhfioaewncfhskdsfsdhad\
  fkdsahfksadhfksdhfusdihfksjadfhksadjkdsahfdsjkhfksdhffhiawoeur\
  ihweiyrtiuoncsdbfzmbfkhfioaewncfhskdsfsdhadhfkdsahfksadhfksdhf\
  sdihfksjadsfsdhadhfkdsahfksadhfksdhfusdihfksjadfhksadjkdsahfd\
  jkhfksdhffhiawoeuruihweiyrtiuoncsdbfzmbfkhfioaewncfhskdsfsdha\
  hfkdsahfksadhfksdhfusdihfksjadfhksadjkdsahfdsjkhfksdhffhiawoe\
  ruihweiyrtiuoncsdbfzmbfkhfioaewncfhskdfhksadjkdsahfdsjkhfksdh\
  fhiawoeuruihweiyrtiuoncsdbfzmbfkhfioaewncfhskfdsfsdhadhfkdsah\
  ksadhfksdhfusdihfksjadfhksadjkdsahfdsjkhfksdhffhiawoeuruihwei\
  rtiuoncsdbfzmbfkhfioaewncfhskksdhfusdihfksjadfhksadjkdsahfdsj\
  hfksdhffhiawoeuruihweiyrtiuoncsdbfzmbfkhfioaewncfhsksahfksad\
  ksdhfusdihfksjadfhksadjkdsahfdsjkhfksdhffhiawoeuruihweiyrtiuon\
  csdbfzmbfkhfioaewncfhskfkdsahfksadhfksdhfusdihfksjadfhksadjkd\
  ahfdsjkhfksdhffhiawoeuruihweiyrtiuoncsdbfzmbfkhfioaewncfhskah\
  ksadhfksdhfusdihfksjadfhksadjkdsahfdsjkhfksdhffhiawoeuruihwei\
  rtiuoncsdbfzmbfkhfioaewncfhsk";

  cout << longPalinDrome(s) << endl;
  return 0;
}