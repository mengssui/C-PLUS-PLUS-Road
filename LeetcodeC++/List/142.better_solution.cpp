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
        ListNode* fast = head, *slow = head;
        while(fast != NULL && fast -> next != NULL){  //如果无环，肯定是快指针先到，同时判断了快指针下一个是否为空，方便两次next
            slow = slow -> next;
            fast = fast -> next -> next;

            if(slow == fast) {  //如果相遇，则说明有环，让slow=head， slow和fast同时一次一步地走，相遇处就是环的入口（数学方式证明）

                slow = head;  //节省多个指针

                while(slow != fast) {
                    slow = slow -> next;
                    fast = fast -> next;
                }
                return fast;
            }
        }
        return NULL;

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
    int index = 4;
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
