/*************************************************************************
	> File Name: 27.remove_element.cpp
	> Author: Mengbw
	> Mail: 1711900861@qq.com
	> Created Time: Thu 29 Oct 2020 10:52:19 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length = nums.size();
        int flag = 0;
        if(length == 0) return 0;
        for (int i = 0; i < length; i++) {
            if (nums[i] != val) {
                nums[flag++] = nums[i];
            }
        }
        return flag;
    }
};

int main() {
    vector<int> nums{1,3,2,4,2,5,6};
    Solution s;
    for(auto i : nums) {
        cout << i << " " ;
    }
    cout << endl;
    int val;
    cin >> val;
    int res = s.removeElement(nums, val);
    cout << "length is :" << res << endl;
    cout << "elements are :";
    for(int i = 0; i < res; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
