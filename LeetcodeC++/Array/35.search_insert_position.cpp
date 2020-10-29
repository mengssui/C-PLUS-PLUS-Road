/*************************************************************************
	> File Name: 35.search_insert_position.cpp
	> Author: Mengbw
	> Mail: 1711900861@qq.com
	> Created Time: Tue 27 Oct 2020 06:27:53 PM CST
 ************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        if (nums.size() == 0) return 0;
        if (target < nums[0]) return 0;
        if (target > nums[nums.size()-1]) return nums.size();

        int l = 0, r = nums.size()-1, m = 0;
        //区间[l, m-1, m , m+1 ,r]
        while (l <= r) {
            m = l + ((r-l)>>1);  
            cout << "l = " << l << " r = " << r << " m = " << m << endl;
            if (nums[m] == target) return m;
            else if (nums[m] < target) l = m + 1;
            else r = m - 1;
        }
        return r + 1;
    }
};


int main() {
    vector<int> nums;

    for (int i = 0; i < 10; i++) {
        nums.push_back(i*2);
    }
    cout << "**********nums**********" << endl;
    for (int i = 0; i < 10; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    Solution s;
    int target;
    while(cin >> target) {
        cout << s.searchInsert(nums, target) << endl;
    }
    return 0;
}
