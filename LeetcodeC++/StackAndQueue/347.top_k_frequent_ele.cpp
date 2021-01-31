/*************************************************************************
	> File Name: 347.top_k_frequent_ele.cpp
	> Author: Mengbw
	> Mail: 1711900861@qq.com
	> Created Time: Wed 16 Dec 2020 06:41:45 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;
class mycom {
    public:
    bool operator() (const pair<int, int>& lhs, const pair<int,int>&rhs) {
        return lhs.second > rhs.second;
    } 
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> fremap;
        for (int i : nums) {
            fremap[i]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int> > , mycom> pri_que;

        for (auto it = fremap.begin(); it != fremap.end(); it++) {
            pri_que.push(*it);
            if (pri_que.size() > k) pri_que.pop();
        }

        vector<int> ret;
        while(pri_que.size()) {
            ret.push_back(pri_que.top().first);
            pri_que.pop();
        }

        return ret;
    }
};


int main() {

    vector<int> vec{1,2,1,1,3,3,3,3,3,4,4};
    Solution s;
    vector<int> ret = s.topKFrequent(vec,2);

    for(auto i : ret) {
        cout << i <<" ";
    }

    cout << endl;
    return 0;
}

