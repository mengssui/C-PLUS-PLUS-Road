/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-06-29 23:08:45
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-06-30 00:04:23
 */
#include <iostream>
#include <vector>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int v, ListNode* n) : val(v), next(n) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return head;
		ListNode * ret = head->next;
		head->next = swapPairs(ret->next);
		ret->next = head;
		return ret;
    }
	void printList(ListNode *head) {
		ListNode* cur = head;
		while (cur)
		{
			std::cout << cur->val ;
			if (cur->next) std::cout << "->";
			cur = cur->next;
		}
		std::cout << std::endl;
		return;
	}
};

int main() {

	ListNode head(1, nullptr);
	ListNode* cur = &head;
	for (int i = 2; i <= 4; i++) {
		cur->next = new ListNode(i, nullptr);
		cur = cur->next; 
	}
	
	Solution s;
	s.printList(&head);
	cur = s.swapPairs(&head);
	s.printList(cur);
	return 0;
}