/*************************************************************************
	> File Name: 349.intersection_of_two_arrays.cpp
	> Author: Mengbw
	> Mail: 1711900861@qq.com
	> Created Time: Wed 11 Nov 2020 08:44:27 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> rset; 
        unordered_set<int> uset(nums1.begin(), nums1.end());
        for(auto i : nums2) {
            if(uset.find(i) == uset.end()) continue;
            rset.insert(i);
        }
        return vector<int>(rset.begin(), rset.end());
    }
};

int main() {
    vector<int> nums1, nums2;
    srand(time(0));
    int size1 = rand()%15, size2 = rand()%15;
    cout << "nums1 : ";
    for(int i = 0; i < size1; i++) {
        nums1.push_back(rand()%10);
        cout << *(nums1.end()-1) << " ";
    } 
    cout << endl;
    
    cout << "nums2 : ";
    for(int i = 0; i < size2; i++) {
        nums2.push_back(rand()%10);
        cout << *(nums2.end()-1) << " ";
    } 
    cout << endl;
    Solution s;
    vector<int> ret;
    ret = s.intersection(nums1, nums2);
    for(auto i : ret) {
        cout << i << " " ;
    }
    cout << endl;

    return 0;
}
