/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-07-23 16:20:09
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-07-23 16:20:47
 */

struct TreeNode
{
	int val;
	TreeNode *left, *right;
};



class Solution {
public:
    bool isSymmetric(TreeNode* root) {
      if (root == nullptr) return true;
      return isSame(root->left, root->right);
    }
private:
  bool isSame(TreeNode *l, TreeNode * r) {
    if (l == nullptr && r == nullptr) return true;
    if (l == nullptr || r == nullptr) return false;
    if (l->val != r->val) return false;
    return isSame(l->left, r->right) && isSame(l->right, r->left);
  }
};