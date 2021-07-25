/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-06-27 17:16:31
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-06-27 18:37:47
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//不够巧妙的方法 
class Solution {
public:
    //采用双指针的方式
    vector<int> sortedSquares2(vector<int>& nums) {
      int head = 0, tail = nums.size() - 1;
      int ind = nums.size() - 1;
      vector<int> ret(nums.size());
      while (head <= tail) {
        if (pow(nums[head], 2) >= pow(nums[tail], 2)) ret[ind--] = nums[head]*nums[head], head++;
        else  ret[ind--] = nums[tail] * nums[tail], tail--; 
      }
      return ret; 
    }

    vector<int> sortedSquares(vector<int>& nums) {
      if (nums.size() <= 0) return nums;
      //全正
      if (nums[0] >= 0) {
        for (int i = 0; i < nums.size(); i++) nums[i] *= nums[i];
        return nums;
      }
      //全负
      if (nums.back() <= 0) {
        for (int i = 0; i < nums.size(); i++) nums[i] *= nums[i];
        reverse(nums.begin(), nums.end());
        return nums;
      }
      //正负相间 
      int endofneg = 0;
      for (int i = 0; i < nums.size()-1; i++) {
        if (nums[i]*nums[i+1] <= 0) {
          endofneg = i+1;
          break; 
        }
      }
      vector<int> seg1(nums.begin(), nums.begin() + endofneg);
        for (int i = 0; i < seg1.size(); i++) seg1[i] *= seg1[i];
		reverse(seg1.begin(), seg1.end());
      vector<int> seg2(nums.begin()+endofneg, nums.end());
        for (int i = 0; i < seg2.size(); i++) seg2[i] *= seg2[i];
      vector<int> ret(nums.size());
      int s1 = 0, s2 = 0;
      for (int i = 0; i < nums.size(); i++) {
        if (s1 < seg1.size() && s2 < seg2.size() && seg1[s1] <= seg2[s2]
            ||s2 >= seg2.size()) ret[i] = seg1[s1++];
        else {
          ret[i] = seg2[s2++];
        }
      }
      return ret;
    }
};

int main() {
	vector<int> nums{-4, -1, 0, 3, 10};
	Solution s;
	//vector<int> ret = s.sortedSquares(nums);
	vector<int> ret1 = s.sortedSquares2(nums);
	for (auto i : ret1) cout << i << " ";
	return 0;
}