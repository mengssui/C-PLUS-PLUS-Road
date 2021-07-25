/*************************************************************************
	> File Name: 202.happy_number.cpp
	> Author: Mengbw
	> Mail: 1711900861@qq.com
	> Created Time: Wed 11 Nov 2020 09:17:30 PM CST
 ************************************************************************/

#include <iostream>
#include <unordered_set>
#include <iomanip>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> uset;
        int sum = getSum(n);
        while(sum != 1) {
            if(uset.find(sum) != uset.end()) return false;
            uset.insert(sum);
            sum = getSum(sum);
        }
        return true;
    }
    int getSum(int n) {   //按位平方和
        int sum = 0; //记得初始化为0
        while(n) {
            sum += (n%10) * (n%10);  
            n = n/10;
        }
        return sum;
    }

    bool isHappy2(int n) {     //快慢指针的方法
        //判断循环用快慢指针
        int slow = n, fast = n;
        do{
            slow = getSum(slow);
            fast = getSum(fast);
            fast = getSum(fast);
        }while(slow != fast);  //若最终为1，快慢指针会相遇，若最终进入循环，快慢指针也会相遇

        return slow == 1;
    }
};

int main() {
    int n;
    cin >> n;
    Solution s;
    cout << boolalpha <<  s.isHappy(n) << endl;
    cout << boolalpha <<  s.isHappy2(n) << endl;
    return 0;
}
