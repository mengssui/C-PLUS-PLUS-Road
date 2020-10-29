/*************************************************************************
	> File Name: 125.valid_palindrome.cpp
	> Author: Mengbw
	> Mail: 1711900861@qq.com
	> Created Time: Wed 28 Oct 2020 07:45:41 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int length = s.size() - 1;
        if(length == 0) return true;

        int b = 0, e = length; 

        while(b < e) {
            if(!isalnum(s[b])) {b++; continue;}
            if(!isalnum(s[e])) {e--; continue;}
            if(tolower(s[b++]) != tolower(s[e--]))  return false;
        }
        return true;
    }
};

int main() {
    string str;
    Solution s;
    while(getline(cin , str)) {
        cout << boolalpha << s.isPalindrome(str) << endl;
    }
    return 0;
}
