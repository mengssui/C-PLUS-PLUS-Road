/*************************************************************************
	> File Name: 1.two_sum.cpp
	> Author: Mengbw
	> Mail: 1711900861@qq.com
	> Created Time: Wed 28 Oct 2020 07:12:21 PM CST
 ************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret;
        int b = 0, e = numbers.size()-1;
        while(b < e) {
            if(numbers[b] + numbers[e] > target) e--;
            else if (numbers[b] + numbers[e] < target) b++;
            else break;
        }
        ret.push_back(b+1);
        ret.push_back(e+1);
        return ret;
    }
};

int main() {
    vector<int> num{2, 7, 11, 15};
    int target;
    for(auto i : num) {
        cout << i << " ";
    }
    cout << endl;
    
    Solution s;
    while(cin >> target) {
        for(auto i : s.twoSum(num, target)) {
            cout << i <<  " ";
        }
        cout << endl;
    }
    
    return 0;
}
