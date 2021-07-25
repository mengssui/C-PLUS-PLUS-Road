/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-06-30 12:28:56
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-06-30 12:36:20
 */
#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode virNode(0, head);
        ListNode *virhead = &virNode, *pre = virhead, *tail = virhead;

        while (n--) {
            pre = pre->next;
        }
        while (pre->next) {
            pre = pre->next;
            tail = tail->next;
        }

        ListNode *del = tail->next;
        tail->next = del->next;
        delete del;
        return virhead->next;
    }
};

int main() {

	ListNode head(1, nullptr);
	ListNode* cur = &head;
	for (int i = 2; i <= 4; i++) {
		cur->next = new ListNode(i, nullptr);
		cur = cur->next; 
	}

	cur = &head;
	while(cur) {
		std::cout << cur->val;
		if (cur->next) std::cout << "->";
		cur = cur->next;
	}
	std::cout << std::endl;

	Solution s;
	ListNode *ret = s.removeNthFromEnd(&head, 3);

	cur = ret;
	while(cur) {
		std::cout << cur->val;
		if (cur->next) std::cout << "->";
		cur = cur->next;
	}
	std::cout << std::endl;

	return 0;
}