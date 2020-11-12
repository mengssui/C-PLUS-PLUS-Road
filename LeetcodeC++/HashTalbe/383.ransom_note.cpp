/*************************************************************************
	> File Name: 383.ransom_note.cpp
	> Author: Mengbw
	> Mail: 1711900861@qq.com
	> Created Time: Thu 12 Nov 2020 08:27:01 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <iomanip>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(!ransomNote.size() || !magazine.size()) return false;
        unordered_map<char, int> ramap, mamap;
        for(auto i : ransomNote) {
            ramap[i]++;
        }
        for(auto i : magazine) {
            mamap[i]++;
        }
        for(auto i : ramap) {
            char ch = i.first;
            auto iter = mamap.find(ch);
            if (iter == mamap.end() || iter->second < i.second) return false;
        }
        return true;
    }

    bool canConstruct2(string ransomNote, string magazine) { //因为题目表明只有小写字符因此使用数组作为哈希表
        int record[26] = {0};  //初始化全部为0
        for (int i = 0; i < magazine.length(); i++) {
            // 通过recode数据记录 magazine里各个字符出现次数
            record[magazine[i]-'a'] ++; 
        }
        for (int j = 0; j < ransomNote.length(); j++) {
            // 遍历ransomNote，在record里对应的字符个数做--操作
            record[ransomNote[j]-'a']--; 
            // 如果小于零说明 magazine里出现的字符，ransomNote没有
            if(record[ransomNote[j]-'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    string ransomNote, magazine;
    cin >> ransomNote >> magazine;
    Solution s;
    cout << boolalpha << s.canConstruct(ransomNote, magazine) << endl;
    return 0;
}
