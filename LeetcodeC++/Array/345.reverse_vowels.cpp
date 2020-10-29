/*************************************************************************
	> File Name: 345.reverse_vowels.cpp
	> Author: Mengbw
	> Mail: 1711900861@qq.com
	> Created Time: Wed 28 Oct 2020 08:39:04 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int b = 0, e = s.size()-1;
        string vowels = "aeiouAEIOU";
        while(b < e) {
            if(vowels.find(s[b]) == string::npos) {
                b++;
                continue;
            }
            if(vowels.find(s[e]) == string::npos) {
                e--;
                continue;
            }
            swap(s[b++], s[e--]);
        }
        return s;
    }
};

int main() {
    string str;
    Solution s;

    while(getline(cin, str)) {
        cout << s.reverseVowels(str); 
    }

    return 0;
}
