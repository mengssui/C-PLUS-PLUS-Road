/*************************************************************************
	> File Name: 88.merge_sorted_array2.cpp
	> Author: Mengbw
	> Mail: 1711900861@qq.com
	> Created Time: Tue 27 Oct 2020 04:09:38 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        if(m == 0) {
            nums1 = nums2;
            return;
        }
        if (n == 0) return;

        int i = m - 1 , j = n - 1, k = nums1.size() - 1;

        //尾插法
        //对于有序数组的合并这种情况， 一般是从后往前看，开辟nums1足够nums1和nums2的大小。

        while (j>=0) {
            if (i < 0) { //如果nums1一直比较大，那么i可能先减为0，之后讲所有的nums2加到nums1[k--]
                swap(nums1[k], nums2[j--]);
            }
            else if (nums1[i] < nums2[j]) { 
                swap(nums1[k], nums2[j]);
                j--;
            }else if (nums1[i] >= nums2[j]) {
                swap(nums1[i], nums1[k]);
                i--;
            }
            k--;
        }
    }
};

int main() {
    vector<int> nums1(10,0);
    vector<int> nums2(5,0);
    int m = 5, n = 5;
    for(int i = 0; i < 5; i += 1) {
        nums1[i] = (i);
        nums2[i] = 2*i;
    }

    cout << "nums1.size = " << nums1.size() << endl;
    for ( int i = 0; i < m+n; i++ ) {
        cout << nums1[i] << " ";
    }
    cout << endl;

    cout << "nums2.size = " << nums2.size() << endl;
    for ( int i = 0; i < n; i++ ) {
        cout << nums2[i] << " ";
    }
    cout << endl;

    Solution sol;
    sol.merge(nums1, m , nums2, n);

    for (int i = 0; i < m+n; ++i) {
        printf("%d ", nums1[i]);
    }

    return 0;
}
