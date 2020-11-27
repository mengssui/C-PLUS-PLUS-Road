/*************************************************************************
	> File Name: 459.multiple_str.cpp
	> Author: Mengbw
	> Mail: 1711900861@qq.com
	> Created Time: Thu 26 Nov 2020 04:37:33 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Solution {
public:
    void getNext(int* next, const string& s) {
        int j = -1;
        next[0] = j;
        for(int i = 1; i < s.size(); i++) { // 注意i从1开始
            while (j >= 0 && s[i] != s[j + 1]) { // 前后缀不相同了
                j = next[j]; // 向前回溯
            }
            if (s[i] == s[j + 1]) { // 找到相同的前后缀
                j++;
            }
            next[i] = j; // 将j（前缀的长度）赋给next[i]
        }
    }
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle);
        int j = -1; // // 因为next数组里记录的起始位置为-1
        for (int i = 0; i < haystack.size(); i++) { // 注意i就从0开始
            while(j >= 0 && haystack[i] != needle[j + 1]) { // 不匹配
                j = next[j]; // j 寻找之前匹配的位置
            }
            if (haystack[i] == needle[j + 1]) { // 匹配，j和i同时向后移动
                j++;
            }
            if (j == (needle.size() - 1) ) { // 文本串s里出现了模式串t
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
    
    bool repeatedSubstringPattern(string s) {
        //奇数个，如果重复，只能全相同字符
        int length = s.size();
        if (length <= 1) return true;
        if (length % 2 == 1) { 
            for (int i = 1; i < length; i++) {
                if(s[i] != s[0]) return false;
            }
            return true;
        }
        //偶数个
        int end = length / 2;
        while(end-->0) {
            int i = end;
            for(i = end; i < length; i+=end) {
                //比较0~end-1 是否和后面的每一段相等
                //不等就break；
                if((s.substr(0,end) !=  s.substr(i,i+end))) break;

            }
            if(i  >= length) return true;
        }
        return false;
    }
};

int main() {

    string str;
    cin >> str;
    Solution s;
    cout << boolalpha << s.repeatedSubstringPattern(str);
    cout << endl;

    return 0;
}
