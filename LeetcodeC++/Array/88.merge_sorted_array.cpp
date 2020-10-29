/*************************************************************************
	> File Name: 88.merge_sorted_array.cpp
	> Author: Mengbw
	> Mail: 1711900861@qq.com
	> Created Time: Fri 23 Oct 2020 08:36:09 PM CST
 ************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> tmp;
        if (m == 0) return;
        if (n == 0) {
            nums1 = nums2;
            return;
        }
        if (nums1[m-1] <= nums2[0]) {
            for (int i = 0; i < n; ++i) {
                nums1.push_back(nums2[i]);
            } 
            return;
        }

        if (nums2[n-1] <= nums1[0]) {
            for (int i = 0; i < m; ++i) {
                nums2.push_back(nums1[i]);
            }
            nums1 = nums2;
            return;
        }
        
        int i = 0, j = 0;
        while(i < m && j < n) {

            if (nums1[i] > nums2[j]) {
                tmp.push_back(nums2[j++]);
            } else {
                tmp.push_back(nums1[i++]);
            }

        }

        if (m == i) {
            for (j ; j < n; j++)  {
                tmp.push_back(nums2[j]);
            }
        } else if(n == j ) {
            for (i ; i < m; i++) {
                tmp.push_back(nums1[i]);
            }
        }
        nums1 = tmp;
    }
};

int main() {
    vector<int> nums1;
    vector<int> nums2;
    int m = 0, n = 0;
    for(int i = 0; i < 10; i += 2) {
        nums1.push_back(i);
        nums2.push_back(i+1);
        m++;
        n++;
    }

    for ( int i = 0; i < m; i++ ) {
        cout << nums1[i] << " ";
    }
    cout << endl;
    for ( int i = 0; i < n; i++ ) {
        cout << nums2[i] << " ";
    }
    cout << endl;

    Solution sol;
    sol.merge(nums1, m , nums2, n);

    for (int i = 0; i < m + n; ++i) {
        printf("%d ", nums1[i]);
    }

    return 0;
}
