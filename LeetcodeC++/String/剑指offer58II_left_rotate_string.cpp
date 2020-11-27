#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        int length = s.size();
        while(n-- > 0) {
            char c = s[0];
            for(int i = 0; i < length-1; i++) {
                s[i]= s[i+1];
            }
            s[length-1] = s[0];
        }
        return s;
    }
};
class Solution2 {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};
int main () {
    string str;
    int n;
    cin >> str;
    cin >> n;
    Solution s;

    cout << s.reverseLeftWords(str, n);
    cout << endl;

    system("pause");

    return 0;
}