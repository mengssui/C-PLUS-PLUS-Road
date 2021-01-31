/*************************************************************************
	> File Name: 1047.remove_near_same_elements.cpp
	> Author: Mengbw
	> Mail: 1711900861@qq.com
	> Created Time: Fri 11 Dec 2020 10:15:51 AM CST
 ************************************************************************/

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    stack<char> sta;
public:
    string removeDuplicates2(string S) {
        string ret;
        for (char i : S) {
            if (ret.empty() || ret.back() != i) ret.push_back(i);
            else ret.pop_back();
        }
        return ret;
    }
    string removeDuplicates(string S) {
        if (S.empty()) return S;
        for(char i:S) {
            if(sta.empty() || sta.top() != i) sta.push(i);
            else sta.pop();
        }
        string ret;
        while(!sta.empty()) {
            ret.push_back(sta.top());
            sta.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main() {
    string str;
    Solution s;

    while(cin >> str) {
        cout << s.removeDuplicates(str);
        cout << endl;
        cout << s.removeDuplicates2(str);
        cout << endl;
    }

    return 0;
}
