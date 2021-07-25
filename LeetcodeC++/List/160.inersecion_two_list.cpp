/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-06-30 12:59:34
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-06-30 13:05:15
 */

#include <iostream>
using namespace std;
//使用哈希表是需要额外空间

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x, ListNode* n) : val(x), next(n) {}
};
//我的方法
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int la=0,lb=0;
        ListNode * cur = headA;
        while (cur) {
            la++;
            cur = cur->next;
        }
        
        cur = headB;
        while(cur) {
            lb++;
            cur = cur->next;
        }
        if (la > lb) {
            int delta = la - lb;
            while (delta--) headA = headA->next;
        } else if (la < lb) {
            int delta = lb - la;
            while (delta--) headB = headB->next;
        }

        while(headA && headB) {
            if (headA == headB) return headA;
            headB = headB->next;
            headA = headA->next;
        }

        return nullptr;

    }
};


int main() {
	ListNode head(1, nullptr);
	ListNode* cur = &head;
	for (int i = 2; i <= 4; i++) {
		cur->next = new ListNode(i, nullptr);
		cur = cur->next; 
	}
	ListNode same(100, nullptr);
	cur->next = &same;
	ListNode head2(5, nullptr);
	cur = &head2;
	for (int i = 2; i <= 4; i++) {
		cur->next = new ListNode(i, nullptr);
		cur = cur->next; 
	}
	cur->next = &same;

	Solution s;
	cur = s.getIntersectionNode(&head, &head2);
	std::cout << cur->val << std::endl;
	return 0;

}