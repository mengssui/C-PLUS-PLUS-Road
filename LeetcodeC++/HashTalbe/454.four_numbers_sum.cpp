/*************************************************************************
	> File Name: 454.four_numbers_sum.cpp
	> Author: Mengbw
	> Mail: 1711900861@qq.com
	> Created Time: Thu 12 Nov 2020 08:04:37 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int count = 0;
        unordered_map<int, int> umap;    //{和，数量}
        for(auto i : A) {
            for(auto j : B) {
                umap[i + j]++;
            }
        }
        
        for(int i : C) {
            for(int j : D){
                if(umap.find(-j-i) != umap.end())
                    count += umap.find(-i-j) -> second; 
            }
        }
        return count;
    }
};

int main() {
    srand(time(0));
    #define NUM rand()%1000
    vector<int> A, B, C, D;
    for(int i = 0; i < NUM; i++){
        A.push_back(rand()%1000 -500);
        B.push_back(rand()%1000 -500);
        C.push_back(rand()%1000 -500);
        D.push_back(rand()%1000 -500);
    }
    Solution s;
    cout << "all problems ways : " << s.fourSumCount(A,B,C,D) << endl;

    return 0;
}
