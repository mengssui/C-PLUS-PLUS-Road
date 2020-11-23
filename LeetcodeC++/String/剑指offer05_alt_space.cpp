/*************************************************************************
	> File Name: 剑指offer05_alt_space.cpp
	> Author: Mengbw
	> Mail: 1711900861@qq.com
	> Created Time: Thu 19 Nov 2020 09:57:16 AM CST
 ************************************************************************/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int length = s.size();
        if(length <= 0) return s;
        int num_of_space = 0;
        for(char i : s) {
            if (i == ' ') num_of_space++; 
        }
        cout << num_of_space << endl;

        s.resize(length + 2 * num_of_space);

        cout << s.size() << endl;

        int olds = length-1, news = s.size()-1;
        while(olds < news) {
            if(s[olds] == ' ') 
                s[news--] = '0', s[news--] = '2', s[news--] = '%', olds--;
            else
                s[news--]  = s[olds--]; 
        }

        return s;
    }
};

int main() {

    string str("We are young!");

    cout << str << endl;

    Solution s;
    cout << s.replaceSpace(str);
    cout << endl;

    return 0;
}
