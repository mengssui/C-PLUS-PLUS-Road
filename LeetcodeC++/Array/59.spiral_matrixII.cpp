/*************************************************************************
	> File Name: 59.spiral_matrixII.cpp
	> Author: Mengbw
	> Mail: 1711900861@qq.com
	> Created Time: Fri 30 Oct 2020 04:37:29 PM CST
 ************************************************************************/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> vec(n, vector<int>(n,0));
        int loop = n / 2;  //统计一共会有几个圈
        int xstar = 0,  ystar = 0;
        int offset = 1;
        int count = 1;
        int i,j;
        int mid = n / 2;

        while(loop--) {
            i = xstar;   //每次圈都要改变一下开始的参考点
            j = ystar;
            //明确循环不变量，左闭右开区间，每次缩小一个圈，offset就要加2
            for(j = ystar; j < ystar+n-offset; j++) { 
                vec[i][j] = count++;
            }
            for(i = xstar; i < xstar+n-offset; i++) {
                vec[i][j] = count++; 
            }
            for(; j > ystar; j--) {
                vec[i][j] = count++;
            }
            for(; i > xstar; i--) {
                vec[i][j] = count++;
            }
            offset += 2;
            xstar ++;
            ystar ++;
        }

        if(n%2) vec[mid][mid] = count;
        return vec;
    }
};
int main() {
    int n;
    cout << "Input the n : "  << endl;
    cin >> n;
    Solution s;
    int num = n*n;
    int size = 0;

    do {
        size++;
        num /= 10;
    } while(num);

    cout  << "It will have most " << size << "digits!" << endl;
    for(auto &i : s.generateMatrix(n)) {  //防止i被自动转化为指针
        for(auto &j : i) {
            cout << setw(size) << j << " ";
        }
        cout << endl;
    }
    return 0;
}
