/*************************************************************************
	> File Name: 20.valid_parenthese.cpp
	> Author: Mengbw
	> Mail: 1711900861@qq.com
	> Created Time: Fri 11 Dec 2020 09:26:49 AM CST
 ************************************************************************/

#include <iostream>
#include <stack>

using namespace std;

class Solution {
    private:
    stack<int> sta;
    public:
    bool isValid(string s) {
        if (s.empty()) return true;
        for(int i = 0; i < s.size(); i++) {
            switch (s[i]) {
                case '(':
                case '[':
                case '{':
                    sta.push(s[i]);
                       cout << "push" << endl;
                    break;
                case ')':
                case ']':
                case '}':
                    if (sta.empty()) return false;
                    if (sta.top() == '('&& s[i]  == ')' ||
                        sta.top() == '['&& s[i]  == ']' ||
                        sta.top() == '{' && s[i] == '}'
                       ){
                           sta.pop();
                           cout << " pop"  << endl;
                       } 
                    else return false;
                    break;
                default:
                    break;
            }
        }
        if (sta.empty()) {
            return true;
        }
        return false;
    }

};

int main() {

    Solution s;

    while(1) {
        string str;
        cin >> str;
        cout << boolalpha << s.isValid(str) << endl;
    }

    return 0;
}
