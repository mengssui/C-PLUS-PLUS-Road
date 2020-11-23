#include <iostream>
#include <vector>
#include <unordered_set>
#include <ctime>
#include <algorithm>
using namespace std;

class Solution {
public:
    // a + b + c + d = target
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int length = nums.size();
        if(length < 4) return vector<vector<int>>();
        sort(nums.begin(), nums.end());   //排序
        //排序完排除几个特殊情况
        if(target > 4 * nums[length-1]) return vector<vector<int>>();
        if(target < 4 * nums[0]) return vector<vector<int>>();

        vector<vector<int>> ret;

        for (int i = 0; i < length-3; i++) {
            if( i > 0 && nums[i] == nums[i-1]) continue; //去重a
            if (nums[i] + nums[length-3] + nums[length-2] + nums[length-1] < target) continue;//如果nums[i]加上最大的三个数都比目标值小， 那么只能增加i了
            if (nums[i] + nums[i+1] + nums[i+2]+ nums[i+3] > target) break;  //如果最小的四个都比目标值大，那么之后更不会有了
            for (int j = i+1; j < length-2; j++) {
                if( j > i+1 && nums[j] == nums[j-1]) continue; //去重b
                if (nums[i] + nums[j] + nums[length-2] + nums[length-1] < target) continue;
                if (nums[i] + nums[j+1] + nums[j+2]+ nums[j] > target) break;
                int sum = target-(nums[i]+nums[j]);
                int l = j + 1, r = length-1;
                while(l < r) {
                    if(nums[l] + nums[r] > sum) r--;
                    else if (nums[l] + nums[r] < sum) l++;
                    else {
                        ret.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while(l < r && nums[l] == nums[l+1]) l++;
                        while(l < r && nums[r] == nums[r-1]) r--;
                        l++;
                        r--;
                    }
                }
            }
        }
        return ret;
    }
};

int main () {
    srand(time(0));
    vector<int> nums;
    int n = 100;
    for (int i = 0; i < n; i++) {
        nums.push_back(rand()%10-5);
    }
    cout << "nums: ";
    for (int i : nums) {
        cout << i << " " ;
    }
    cout << endl;
    cout << "target : ";
    int target = 4*(rand()%10-5);
    cout << target << endl;
    Solution s;
    vector<vector<int>> res = s.fourSum(nums,target);
    for(auto &i : res) {
        for(auto &j : i) {
            cout << j << " " ;
        }
        cout << endl;
    }
    system("pause");
    return 0;
}