#include <string>
#include <algorithm>
#include <iostream>
using namespace std;;


int lengthOfLongestSubstring(string s)
{
    int maxstr = 0;
    if (!s.empty())
    {
        int c = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int j;
            for (j = i - 1; j >= c; j--)
            {
                if (s[i] == s[j])
                    break;
            }
            c = j + 1;
            if (j < 0)
                maxstr =max((i + 1) , maxstr);
            else
                maxstr =max((i - j), maxstr);
        }
    }
    return maxstr;

}

//leetcode最快的解法
int hashmap[130];  //假设是ASCLL码，有128个字符，数组够大，用数组模拟哈希表的功能
int lengthOfLongestSubstring2(string s) {
    int max = 0;
    int n = s.size();
    for(int i = 0,j=0;j<n;j++){
        hashmap[s[j]]++;            //应该是将字符转换为其ASCLL码对应的十进制的值，把其值加一
        while(hashmap[s[j]]>1){     //加一后如果它的值大于一，说明重复出现
            hashmap[s[i++]]--;      //将i指向的减一并且向右移动直到刚才加入的那个 hashmap[s[j]]不大于1
        }
        if(j-i+1 > max){
            max = j-i+1;
        }
    }
    return max;
    
}


int main() {
    string a= "sdfdxgd";
    int b = lengthOfLongestSubstring2(a);
    cout << b << endl;
    cout << hashmap[129] <<endl;

}