/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-07-24 17:00:40
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-07-24 17:01:04
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
    int dp[2506] = {0};
    int lengthOfLIS(vector<int>& nums) {
      if (nums.size() <= 1) return nums.size();
      int maxsize = 0;
      for (int i = 0; i < nums.size(); i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
          if (nums[j] >= nums[i]) continue;
          dp[i] = max(dp[i], dp[j] + 1);
        }
        maxsize = max(maxsize, dp[i]);
      }
      //for (int i = 0; i < nums.size(); i++) cout << dp[i] << " ";
      //cout << endl;
      return maxsize;
    }
};
