/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-07-23 19:13:28
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-07-23 19:14:18
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
      if (root == nullptr) return true;
      if (abs(height(root->left) - height(root->right)) > 1) return false;
      bool lb = isBalanced(root->left);
      bool rb = isBalanced(root->right);
      return lb && rb;
    }
private:
    int height(TreeNode* root) {
      if (root == nullptr) return 0;
      int lh = height(root->left);
      int rh = height(root->right);
      return max(lh, rh) + 1;
    }
};