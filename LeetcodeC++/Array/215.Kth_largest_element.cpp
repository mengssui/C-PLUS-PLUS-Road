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
class Solution2 {

public:
    int findKthLargest(vector<int>& nums, int k) {
        int ret = quickSort(nums, k); 
        return nums[ret];
    }

private:

    int quickSort(vector<int>& nums, int k) {
        int l = 0, r = nums.size()-1;   
        int ret;
        ret = __quickSort(nums, l, r, k);
        return ret;
    }

    int  __quickSort(vector<int>& nums, int l , int r, int k) {

        if(l >= r) return l;

        int p = partition(nums,l,r);
        if (p == k - 1) return p;
        if (k - 1 < p)
            return __quickSort(nums, l, p-1, k);
        else 
            return __quickSort(nums, p+1, r, k);
    }

    int partition(vector<int>& nums, int l, int r) {
        
        swap(nums[l], nums[rand()%(r-l+1)+l]);
        int j = l;
        for(int i = j+1; i <= r; ++i) {
            if (nums[i] > nums[l]) swap(nums[i], nums[j+1]), j++;
        }
        swap(nums[l], nums[j]);
        return j;
    }

};

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
        
        int pivot = nums[rand()%(r-l+1)+l]; //optimization 1
        swap(nums[l], pivot);
        int j = l;
        for(int i = j+1; i <= r; ++i) {
            if (nums[i] < pivot) swap(nums[i], nums[j+1]), j++;
        }
        swap(nums[l], nums[j]);
        return j;
    }

};

int main() {
    int numbers = 10;
    int k;

    vector<int> nums2;

    while (numbers--) {
        nums2.push_back(rand()%100);
    }

    for(vector<int>::iterator i = nums2.begin(); i != nums2.end() ; ++i) {
        cout << *i << " ";
    }
    cout << endl;


    while(cin >> k) {
        Solution2 s2;
        cout << "The " << k << "th largest elements is ";
        cout << s2.findKthLargest(nums2, k) << endl;
    }
    for (vector<int>::iterator i = nums2.begin(); i != nums2.end() ; ++i) {
        cout << *i << " ";
    }
    cout << endl;

    return 0;
}
