/*************************************************************************
	> File Name: 206.reverse_list.cpp
	> Author: Mengbw
	> Mail: 1711900861@qq.com
	> Created Time: Wed 04 Nov 2020 04:27:45 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head->next == NULL) return head;
        ListNode* pre = head->next, *rear = NULL, *tmp = NULL;
        while (pre) {
            rear = pre -> next;
            pre -> next = tmp;
            tmp = pre;
            pre = rear;
        }
        head -> next = tmp;
        return head;
    }
    void output(ListNode* head) {
        ListNode* cur = head -> next;
        while(cur) {
            cout << cur -> val << " -> " ;
            cur = cur -> next;
        }
        cout << "NULL" <<  endl;
    }

private:
    ListNode* head;
};

int main() {
    Solution s;
    ListNode* head = new ListNode(-1), *cur = head;
    for(int i = 1; i <= 5; i++) {
        ListNode* tmp = new ListNode(i); 
        cur -> next = tmp;
        cur = cur -> next;
    }
    s.output(head);
    cur = s.reverseList(head);
    s.output(cur);
    return 0;
}
