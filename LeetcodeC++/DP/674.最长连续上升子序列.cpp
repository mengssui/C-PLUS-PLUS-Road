/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-07-24 17:23:58
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-07-31 17:07:31
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
      if (nums.size() <= 1) return nums.size();
      int head = 0, maxsize = 1;
      for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > nums[i-1]) continue;
        maxsize = max(maxsize, i - head);
        head = i;
      }
      maxsize = max(maxsize, (int)nums.size() - head); //退出循环后要判断是否是一直到末尾的情况
      return maxsize;
    }
};
