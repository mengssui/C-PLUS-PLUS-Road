/*************************************************************************
	> File Name: 215.Kth_largest_element.cpp
	> Author: Mengbw
	> Mail: 1711900861@qq.com
	> Created Time: Mon 12 Oct 2020 07:19:41 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <iterator>

using namespace std;

class Solution {

public:
    int findKthLargest(vector<int>& nums, int k) {
        quickSort(nums); 
        return nums[nums.size()-k];
    }

private:

    void quickSort(vector<int>& nums) {
        int l = 0, r = nums.size()-1;   
        __quickSort(nums, l, r);
        return;
    }

    void __quickSort(vector<int>& nums, int l , int r) {

        if(l >= r) return;

        int p = partition(nums,l,r);
        __quickSort(nums, l, p-1);
        __quickSort(nums, p+1, r);
    }

    int partition(vector<int>& nums, int l, int r) {
        
        int pivot = nums[l];
        int j = l;
        for(int i = j+1; i <= r; ++i) {
            if (nums[i] < pivot) {swap(nums[i], nums[j+1]), j++;
        }
        }
        swap(nums[l], nums[j]);
        return j;
    }

};


int main() {
    int numbers = 10;
    int k;

    vector<int> nums;

    while (numbers--) {
        nums.push_back(rand()%100);
    }
    cout << "nums.size = " << nums.size() <<  endl;

    for(vector<int>::iterator i = nums.begin(); i != nums.end() ; ++i) {
        cout << *i << " ";
    }
    cout << endl;

    cin >> k;

    Solution s;

    cout << "The " << k << "th largest elements is ";
    cout << s.findKthLargest(nums, k) << endl;


    for (vector<int>::iterator i = nums.begin(); i != nums.end() ; ++i) {
        cout << *i << " ";
    }
    cout << endl;
    
    return 0;
}
