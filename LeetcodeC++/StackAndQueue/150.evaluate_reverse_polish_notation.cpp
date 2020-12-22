/*************************************************************************
	> File Name: 150.evaluate_reverse_polish_notation.cpp
	> Author: Mengbw
	> Mail: 1711900861@qq.com
	> Created Time: Tue 15 Dec 2020 09:46:53 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
private:
    stack<int> sta;

public:
    int evalRPN(vector<string>& tokens) {
        int ret;
        for (string i : tokens) {
            //if (i == "+" || i == "-" || i == "*" || i == "/") {
            if (i.length() == 1  && !isdigit(i[0])) {
                int expre_right = (sta.top());
                sta.pop();
                int expre_left = (sta.top());
                sta.pop();
                int tmp;
                switch (i[0]) {
                    case '+':
                         tmp = (expre_left + expre_right );
                        sta.push(tmp);
                        break;
                    case '-':
                         tmp = (expre_left - expre_right );
                        sta.push(tmp);
                        break;
                    case '*':
                         tmp = (expre_left * expre_right );
                        sta.push(tmp);
                        break;
                    case '/':
                         tmp = (expre_left / expre_right );
                        sta.push(tmp);
                        break;
                }

            } else {
                sta.push(stoi(i));
            }
        }

        ret = (sta.top());
        return ret;
    }
};

int main() {
    
    vector<string> vec;
    Solution sol;
    string str;

    
    cout << endl;
    while(cin>>str) {
        vec.push_back(str);
    }

    cout << sol.evalRPN(vec) << endl;
    

    return 0;
}
