/*
 * @Descripttion: 三种递归的遍历方式
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-07-21 15:54:04
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-07-21 22:59:42
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int _val) : val(_val), left(nullptr), right(nullptr){}
};

void pre_order(TreeNode* root, vector<int> &ret);
void level_order(TreeNode* root);

int main()
{
	TreeNode *root;
	root = new TreeNode(1);
	root->left = new TreeNode(3);
	root->right = new TreeNode(2);

	vector<int> ret;
	pre_order(root, ret);

	for (auto i : ret) cout << i << " ";
	cout << endl;

	level_order(root);
   
	return 0;
}



void pre_order(TreeNode* root, vector<int> &ret) {
	if (root == nullptr) return;
	ret.push_back(root->val);
	pre_order(root->left, ret);
	pre_order(root->right, ret);
	return;	
}

void level_order(TreeNode* root) {
	queue<TreeNode*> que;
	vector<int> ret;
	if (root == nullptr) return;

	que.push(root);
	while (!que.empty()) {
		TreeNode* node = que.front();
		que.pop();
		ret.push_back(node->val);
		if (node->left) que.push(node->left);
		if (node->right) que.push(node->right);
	}

	for (auto i : ret) cout << i << " ";
	cout << endl;
	return;
}
