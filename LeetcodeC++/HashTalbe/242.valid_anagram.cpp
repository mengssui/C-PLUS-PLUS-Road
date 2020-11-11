/*************************************************************************
	> File Name: 242.valid_anagram.cpp
	> Author: Mengbw
	> Mail: 1711900861@qq.com
	> Created Time: Fri 06 Nov 2020 09:49:58 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        initarr();
        for(auto i : s) {
            addone(i);
        } 
        for(auto i : t) {
            subone(i);
        }
        return zero();
    }
private:
    void initarr(){
        for(char i = 'a',j = 1; i <= 'z'; i++,j++) {
            arr[j] = {i,0};
        }
    }

    void addone(char c) {
        int l = 1, r = 26,m;
        while(l <= r) {
            m = (l +r) /2;
            if(arr[m].c == c) {
                arr[m].time++;
                break;
            }
            else if(arr[m].c < c) l = m+1;
            else r = m -1;
        }
    }

    void subone(char c) {
        int l = 1, r = 26,m;
        while(l <= r) {
            m = (l +r) / 2;
            if(arr[m].c == c){
                arr[m].time--;
                break;
            } 
            else if(arr[m].c < c) l = m+1;
            else r = m -1;
        }
    }
private:
    struct alphatime {
        char c;
        int time;
    };
    alphatime arr[27];

    bool zero() {
        for(int i = 1; i<=26; i++) {
            if(arr[i].time != 0) return false;
        }
        return true;
    }
};

//将26个字母映射到数组上
//arr[i-'a'],将a-z依次映射到0-25

class Solution2{
public:
    bool isAnagram(string s, string t) {
        int arr[26] = {0};
        if(s.size()!=t.size()) return false;
        for(auto i : s) {
            arr[i-'a']++;
        }
        for(auto i : t) {
            arr[i-'a']--;
        }

        for(auto i : arr) {
            if(i !=0) return false;
        }
        return true;
    }

};

int main() {
    string s,t; 
    Solution2 sl;
    while(cin>>s>>t) {
        cout << boolalpha << sl.isAnagram(s,t) << endl;
    }
    return 0;
}

