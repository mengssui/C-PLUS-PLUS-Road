/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-07-23 17:02:00
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-07-23 17:03:44
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

struct TreeNode
{
	int val;
	TreeNode *left, *right;
};

class Solution {
public:
    int getDepth(TreeNode* node) {
        if (node == NULL) return 0;
        int leftDepth = getDepth(node->left);       // 左
        int rightDepth = getDepth(node->right);     // 右
        int depth = 1 + max(leftDepth, rightDepth); // 中
        return depth;
    }
    int maxDepth(TreeNode* root) {
        return getDepth(root);
    }
};


class Solution2 {
public:
    int getDepth(TreeNode* node) {
        if (node == NULL) return 0;
        int leftDepth = getDepth(node->left);           // 左
        int rightDepth = getDepth(node->right);         // 右
                                                        // 中
        // 当一个左子树为空，右不为空，这时并不是最低点
        if (node->left == NULL && node->right != NULL) { 
            return 1 + rightDepth;
        }   
        // 当一个右子树为空，左不为空，这时并不是最低点
        if (node->left != NULL && node->right == NULL) { 
            return 1 + leftDepth;
        }
        int result = 1 + min(leftDepth, rightDepth);
        return result;
    }

    int minDepth(TreeNode* root) {
        return getDepth(root);
    }
};
