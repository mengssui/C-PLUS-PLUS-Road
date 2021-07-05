/*************************************************************************
	> File Name: 344.reverse_string.cpp
	> Author: Mengbw
	> Mail: 1711900861@qq.com
	> Created Time: Wed 18 Nov 2020 08:30:16 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.size() <= 0) return;
        int begin = 0, end = s.size()-1;
        while(begin < end) {
            swap(s[begin], s[end]);
            begin++;
            end--;
        }
        return;
    }
};


int main() {
    vector<char> s{'h','e','l','l','o'};

    for(char i : s) {
        cout << i << " ";
    }
    cout << endl;

    Solution sl;
    //sl.reverseString(s);
    reverse(s.begin(), s.end());

    for(char i : s) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
