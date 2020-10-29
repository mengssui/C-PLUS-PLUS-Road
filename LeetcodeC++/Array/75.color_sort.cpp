/*************************************************************************
	> File Name: 75.color_sort.cpp
	> Author: Mengbw
	> Mail: 1711900861@qq.com
	> Created Time: Mon 12 Oct 2020 02:04:56 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <cstdlib>

void swap(int &a, int &b) {
    __typeof(a) tmp = a;
    a = b;
    b = tmp;
}

using namespace std;

class Solution {

public:
    //three ways quick sort
    void sortColors2(vector<int>& nums)  {
        int lt = 0;
        int gt = nums.size();
        int i = 1;
        swap(nums[rand()%(gt)] , nums[0]);
        while (i < gt) {
            if (nums[i] == nums[0]) {
                i++;
            } else if (nums[i] < nums[0]) {
                lt++;
                swap(nums[i], nums[lt]);
                i++;
            } else {
                gt--;
                swap(nums[i], nums[gt]);
            }
            swap(nums[0], nums[lt]);
        }
        return;
    }


    void sortColors(vector<int>& nums) {
        if(nums.size() <= 1) return;
        int idx = -1;
        int min_idx;
        int size = nums.size();

        while((++idx) < size) {
            min_idx = idx;
            int i = idx;
            for (++i; i < size; ++i) {
                if (nums[min_idx] > nums[i]) min_idx = i;
            }
            swap(nums[min_idx], nums[idx]);
            cout << nums[idx] << endl;
        }
        return ;
    }
};



int main() {
    
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(2);


    Solution s;
    s.sortColors(nums);
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << endl;
    }

    return 0;
}
