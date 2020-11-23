/*************************************************************************
	> File Name: 151.reverse_word_in_string.cpp
	> Author: Mengbw
	> Mail: 1711900861@qq.com
	> Created Time: Thu 19 Nov 2020 10:50:01 AM CST
 ************************************************************************/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string str;
        for(int i = s.size()-1; i >=0; i--) {
            if(i == s.size()-1 && s[i] == ' ') {//去除结尾多余空格
                while(s[i] == ' ') i--; 
            }
            if(i <s.size()-1 && s[i] == ' ' && s[i+1] == ' ') continue;

            str.push_back(s[i]);
        }
        if(str[str.size()-1] == ' ') str.pop_back();   //去除头部空格

        //反转每一个单词
        //"we are fun"
        int start = 0, end;
        for(int i = 0; i < str.size(); i++) {
            if(str[i] != ' ') continue;
            end = i - 1;
            while(start < end) {
                swap(str[start++], str[end--]);
            }
            start = i+1;
        }
        end = str.size()-1;
        while(start < end) {
            swap(str[start++], str[end--]);
        }
        return str;
    }
};

int main() {

    string str;
    getline(cin , str);

    Solution s;
    cout << s.reverseWords(str) << endl;

    return 0;
}

