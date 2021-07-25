/*************************************************************************
	> File Name: 541.reverse_stringII.cpp
	> Author: Mengbw
	> Mail: 1711900861@qq.com
	> Created Time: Wed 18 Nov 2020 08:41:04 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
class Solution {
public:
    string reverseStr(string s, int k) {
      bool rev = true;
      int i;
      for (i = 0; i < s.size(); i += k) {
        if (s.size() - 1 - i < k) break;
        if (i + k - 1 < s.size() && rev) {
          reverse(s.begin() + i, s.begin() + i + k);
        }
        rev = !rev;
      }
      if (i < s.size() && rev) reverse(s.begin() + i, s.end());
      
      return s;
    }
};
*/

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
            // 1. 每隔 2k 个字符的前 k 个字符进行反转
            // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k );
                continue;
            }
            // 3. 剩余字符少于 k 个，则将剩余字符全部反转。
            reverse(s.begin() + i, s.begin() + s.size());
        }
        return s;
    }
};


class Solution {
public:
    string reverseStr(string s1, int k) {
        string s = s1;
        int num = s.size() / (2*k);
        int ext = s.size() % (2*k);
        int begin, end;
        
        for(int i = 0; i < num; i++) {
            begin = 2*k*i;
            end = begin+k-1;
            while(begin < end) {
                swap(s[begin], s[end]);
                begin++, end--;
            }
        }

        if(ext >= k) {
            begin = num*2*k;
            end = begin + k-1;
            while(begin < end) {
                swap(s[begin++],s[end--]);
            }
        } else {
            begin = num*2*k;
            end = begin + ext-1;
            while(begin < end) {
                swap(s[begin++],s[end--]);
            }
        }
        return s;
    }
};

int main() {
    string s("abcdefghijklmn");
    cout << s << endl;
    Solution sol;
    int k = 2;
    cout << sol.reverseStr(s,k) << endl;
    return 0;
}
