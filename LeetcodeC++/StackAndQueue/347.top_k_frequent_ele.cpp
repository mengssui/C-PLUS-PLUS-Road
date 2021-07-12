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

    vector<int> topKFrequent2(vector<int>& nums, int k) {
        typedef int val;
        typedef int times;
        unordered_map<val, times> valToTime;
        for(int i : nums) {
            valToTime[i]++;
        } 

        pair<int,int> s1(1,5), s2(2,4);

        auto lam = [&](pair<val, times> &lhs, const pair<val, times> &rhs) {
            return lhs.second > rhs.second;
        };
        
        cout << boolalpha << lam(s1, s2);

        typedef  decltype([](const pair<val, times> lhs, const pair<val, times> &rhs) -> bool{
             return lhs.second > rhs.second;
        }) ComType;

        auto comp = [](const pair<val, times> lhs, const pair<val, times> &rhs) -> bool{
             return lhs.second > rhs.second;
        };
        //auto prio_que = priority_queue<pair<val, times>, vector<pair<val, times>>, decltype(comp)> (comp);
        priority_queue<pair<val, times>, vector<pair<val, times>>, decltype(comp)> prio_que(comp); //指定类型
        //priority_queue<pair<val, times>, vector<pair<val, times>>, mycom> prio_que;

        for (auto i : valToTime) {
            prio_que.push(i);
            if (prio_que.size() > k) prio_que.pop();
        }

        vector<int> ret(k);
        for (int i = k-1; i >= 0; i--) {
            ret[i] = prio_que.top().first;
            prio_que.pop();
        }
        return ret;
    }

};

//2021年7月11日的方法,利用multimap


int main() {

    vector<int> vec{1,2,1,1,3,3,3,3,3,4,4};
    Solution s;
    vector<int> ret = s.topKFrequent2(vec,2);

    for(auto i : ret) {
        cout << i <<" ";
    }

    cout << endl;
    return 0;
}

