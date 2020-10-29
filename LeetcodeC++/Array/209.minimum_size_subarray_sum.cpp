/*************************************************************************
	> File Name: 209.minimum_size_subarray_sum.cpp
	> Author: Mengbw
	> Mail: 1711900861@qq.com
	> Created Time: Wed 28 Oct 2020 09:45:47 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int b = 0, sum = 0;
        int minlen = nums.size()+1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while(sum >= s) {
                minlen = minlen < (i-b+1) ? minlen : (i-b+1);
                sum -= nums[b++];
            }
        }
        return minlen == nums.size()+1 ? 0 : minlen;
    } 
};

int main() {
    vector<int> nums{2,3,1,2,4,3};
    Solution s;
    int size;
    cin >> size;
    cout << "minSubArrayLen = " <<  s.minSubArrayLen(size,nums);
    cout << endl;
    return 0;
}
