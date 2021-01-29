/*************************************************************************
	> File Name: 106.contruct_tree_from_post_inorder.cpp
	> Author: Mengbw
	> Mail: 1711900861@qq.com
	> Created Time: Tue 29 Dec 2020 07:07:51 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    void output(TreeNode *root) {
        if (root == NULL) return;
        cout << root->val << endl;
        output(root->left);
        output(root->right);
        return;
    }
	vector<int> inorder, postorder;
    size_t size;

    int findNum(int val) {
        for (int i = 0; i < size; i++) {
            if (inorder[i] == val) {
                cout << "find in location " << i << endl;
                return i;
            }
        }
        return -1;
    }


    TreeNode* build(int l, int r, int rigl, int rigr) { //l，r指代中间的中序遍历的数组的切分 loc指代后序遍历的下标
        int rootval = postorder[rigr];
        TreeNode* root = new TreeNode(rootval);
        if (l == r) return root;
        int newr = findNum(rootval); 

        root->left = build(l, newr - 1, rigl, rigl + newr - l - 1); 
        root->right = build(newr + 1, r, rigl + newr - l, rigr - 1);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		this->inorder = inorder;
		this->postorder = postorder; 
        this->size = inorder.size();
        if (size == 0) return NULL;
        TreeNode *root = build(0, size - 1, 0, size -1); 		
        output(root);
        return root;
    }
};

int main() {
    vector<int> in{9, 3, 15, 20, 7}, post{9, 15, 7, 20, 3};

    Solution s;
    s.buildTree(in, post);
    return 0;
}
