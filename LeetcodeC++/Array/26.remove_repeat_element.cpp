/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-06-27 16:38:51
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-06-27 16:51:22
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		int size = nums.size();
		if (size <= 1) return size;
		int ind = 0;
		for (int i = 1; i < size; i++) {
			if (nums[i] <= nums[ind]) continue;
			nums[++ind] = nums[i];
		}
		return ind + 1;
	}
};

int main() {
    vector<int> nums{1,1,2,2,2,5,6};
    Solution s;
    for(auto i : nums) {
        cout << i << " " ;
    }
    cout << endl;
    int res = s.removeDuplicates(nums);
    cout << "length is :" << res << endl;
    cout << "elements are :";
    for(int i = 0; i < res; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
