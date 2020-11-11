/*************************************************************************
	> File Name: 142.cycle_list.cpp
	> Author: Mengbw
	> Mail: 1711900861@qq.com
	> Created Time: Wed 04 Nov 2020 07:28:51 PM CST
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
    ListNode *detectCycle(ListNode *head) {
        if(!hascycle(head)) return NULL;
        ListNode* pre = head, *rear = pre -> next;
        //断开这个和下一个的链 pre 和 rear
        while(pre) {
            pre -> next = NULL;
            if(!hascycle(rear)) break; 
            pre -> next = rear;
            pre = pre -> next;
            rear = rear -> next;
        }
        pre->next = rear;  //break出来，但是也要恢复这个链表
        return pre;
    }

    bool hascycle(ListNode* head) {
        if(!head || !head -> next) return false;
        ListNode* cur = head, *pre = head -> next;
        while(cur != pre && pre) {   //判断是否有环
            cur = cur -> next;
            pre = pre -> next;
            if(!pre) break;
            pre = pre -> next;
        }

        if(!pre) return false;
        return true;
    }

};

int main() {
    Solution s;
    ListNode* head = new ListNode(-1), *cur = head, *tmp;
    for(int i = 1; i <= 5; i++) {
        ListNode* tmp = new ListNode(i);
        cur -> next = tmp;    
        cur = cur -> next;
    }
    cout << s.hascycle(head->next) << endl;

    int index = 3;
    tmp = head;
    while(index--) {
        tmp = tmp->next;
    }
    cout << "begin at " << tmp->val << endl;
    cur -> next = tmp;
    
    cur = head -> next;
    index = 10;
    while(index--) {
        cout << cur -> val << " -> ";
        cur = cur -> next;
    }
    cout << "NULL" <<  endl;
    cout << s.hascycle(head->next) << endl;

    cout << s.detectCycle(head->next)->val << endl;

    cur = head -> next;
    index = 10;
    while(index--) {
        cout << cur -> val << " -> ";
        cur = cur -> next;
    }
    cout << "NULL" <<  endl;
    return 0;
}
