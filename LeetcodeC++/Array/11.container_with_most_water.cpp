/*************************************************************************
	> File Name: 11.container_with_most_water.cpp
	> Author: Mengbw
	> Mail: 1711900861@qq.com
	> Created Time: Wed 28 Oct 2020 09:07:16 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea = 0;
        int b = 0, e = height.size()-1;
        int width;
        int tmp = 0;
        while(b < e) {
            maxarea = max(maxarea, min(height[b], height[e]) * (e - b));

            if(height[b] > height[e]) e--;
            else b++;
        }
        return maxarea;
    }
};

int main() {
    vector<int> vec{1, 8, 6, 2, 5, 4, 8, 3, 7};
    int height;

    //while (cin >> height) {
    //    vec.push_back(height);
    //}
    
    Solution s;
    cout << "MaxArea = " << s.maxArea(vec) << endl;
    return 0;
}
