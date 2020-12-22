/*************************************************************************
	> File Name: 239.sliding_max_win.cpp
	> Author: Mengbw
	> Mail: 1711900861@qq.com
	> Created Time: Tue 15 Dec 2020 11:04:36 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <cstdio>
#include <deque>

using namespace std;

class MyQueue {
private:
    deque<int> que; //双端队列来实现这个单调队列
public:
    //入队，只有队列为空或者val小于back的值才入队，否则就是pop back处的值
    //维护一个非严格单调递减(可以 8 8 5 5 4)的队列
    void push(int val) {
        while(!que.empty() && val > que.back()) {
            que.pop_back();
        }
        que.push_back(val);
    }

    //出队,非空，并且出队是最大的那个才把其出队列
    void pop(int val) {
        if (!que.empty() && val == que.front()) que.pop_front();
    }
    int max() {
        return que.front(); 
    }
};

class Solution2 {
private:
    MyQueue que;
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        for(int i = 0; i < k; i++) {
            que.push(nums[i]);
        }
        ret.push_back(que.max());

        for (int i = k; i < nums.size(); i++) {
            que.push(nums[i]);
            que.pop(nums[i-k]);
            ret.push_back(que.max());
        }
        
        return ret;
}; 

//时间复杂度较高
class Solution {
    public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int in, out = nums[0], max = nums[0];
        vector<int> maxvec;
        for (int i = 0; i < k; i++) {
            if (nums[i] > max) {
                max = nums[i];
            }
        }
        maxvec.push_back(max);

        for (int i = k; i < nums.size(); i++) {
            in = nums[i];
            out = nums[i-k];
            if (in >= max) {
                max = in;
            } else if(out == max) {
                max = nums[i-k+1];
                for (int j = i-k+1; j < k; j++) {
                    if (nums[j] > max) {
                        max = nums[j];
                    }
                }
            }
            maxvec.push_back(max);
        }
        return maxvec;
    }

};

int main() {

    vector<int> vec;
    int k ;
    int i;
    while(cin >> i) {
        vec.push_back(i);
        if (getchar() == '\n') break;
    }

    cout << "input k" << endl;

    cin >> k;

    Solution s;
    vector<int> ret = s.maxSlidingWindow(vec, k);

    cout << "result  " << endl;
    for (auto i : ret) {
        cout << i << endl;
    }

    return 0;
}
