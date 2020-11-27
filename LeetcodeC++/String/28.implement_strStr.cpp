/*************************************************************************
	> File Name: 28.implement_strStr.cpp
	> Author: Mengbw
	> Mail: 1711900861@qq.com
	> Created Time: Thu 26 Nov 2020 10:36:06 AM CST
 ************************************************************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution1 {
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
};


class Solution {
public:
    int strStr(string haystack, string needle) {
        int length = needle.size();
        if (length <=0 ) return 0;
        vector<int> next(length);
        getnext(next, needle);
        
        int j = 0;
        int i = 0;
        for(int i = 0; i < haystack.size(); i++) {
            //如果不相等,回退到相等的地方
            while(j > 0 && haystack[i] != needle[j]) {
                j = next[j-1]; 
            }
            if (j == 0 && haystack[i] != needle[j]) continue; //回退到0且不等,continue

           //如果相等,找到不相等的位置
            while(j < needle.size() && haystack[i] == needle[j]) {
                i++, j++; 
            }
            if (j == needle.size()) return i-j; //全都相等
            i = i - 1;
        }
        return -1;
    }
private:
    void getnext(vector<int>& next, string str) {
        int pre = 0;
        next[0] = 0;
        for (int tail = 1; tail < str.size(); tail++) {
            //处理不等
            while(pre > 0 && str[tail] != str[pre]) {
                pre = next[pre-1];
            }
            //处理相等
            if(str[tail] == str[pre]) pre++;
            next[tail] = pre;
        }
    }
};

int main() {

    string txt, patten;
    cin >> txt;
    cin >> patten;
    Solution s;
    cout << s.strStr(txt, patten);
    cout << endl;

    return 0;
}
