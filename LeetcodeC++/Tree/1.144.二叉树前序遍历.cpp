/*************************************************************************
	> File Name: 1.144.二叉树前序遍历.cpp
	> Author: Mengbw
	> Mail: 1711900861@qq.com
	> Created Time: Sat 06 Mar 2021 09:56:23 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x) , left(NULL), right(NULL) {}
};

class solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> ret;
        queue<int> q;
        if (root == nullptr) return ret;

        return ret;
    }
};






int main() {


    return 0;
}
