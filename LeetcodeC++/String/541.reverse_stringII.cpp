/*************************************************************************
	> File Name: 541.reverse_stringII.cpp
	> Author: Mengbw
	> Mail: 1711900861@qq.com
	> Created Time: Wed 18 Nov 2020 08:41:04 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

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
