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
public:
    bool isValid(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(')'); //把另一半入栈
            else if (s[i] == '{') st.push('}');
            else if (s[i] == '[') st.push(']');
            // 第三种情况：遍历字符串匹配的过程中，栈已经为空了，没有匹配的字符了，说明右括号没有找到对应的左括号 return false
            // 第二种情况：遍历字符串匹配的过程中，发现栈里没有我们要匹配的字符。所以return false
            else if (st.empty() || st.top() != s[i]) return false;
            else st.pop(); // st.top() 与 s[i]相等，栈弹出元素
        }
        // 第一种情况：此时我们已经遍历完了字符串，但是栈不为空，说明有相应的左括号没有右括号来匹配，所以return false，否则就return true
        return st.empty();
    }
};



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
