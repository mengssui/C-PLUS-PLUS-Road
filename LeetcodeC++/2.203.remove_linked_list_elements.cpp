/*************************************************************************
	> File Name: 2.203.remove_linked_list_elements.cpp
	> Author: Mengbw
	> Mail: 1711900861@qq.com
	> Created Time: Tue 29 Sep 2020 02:22:08 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* removeElements(ListNode* head, int val) {

    if(!head) return head;  //处理空链表
    while(head && (head -> val == val)) { //处理头节点一直是要删除的值的情况
        ListNode* tmp = head;
        head = tmp -> next;
        delete tmp;
    }
    ListNode* cur = head;
    if(cur == NULL) return head;
    while(cur -> next) {
        if(cur -> next -> val == val) {   //如果是要删除的元素就删除
            ListNode* tmp = cur -> next;
            cur -> next = tmp -> next;
            delete tmp;
        }else{ 
            cur = cur -> next;
        }
    }
    return head;
}


ListNode* removeElementsWithVHead(ListNode* head, int val) {
    ListNode* virtualhead = new ListNode(-1);
    virtualhead -> next = head;
    ListNode* cur = virtualhead;

    while(cur -> next) {
        if(cur -> next -> val == val){
            ListNode* tmp = cur -> next;
            cur -> next = tmp -> next;
            delete tmp;
        }else{
            cur = cur -> next;
        }
    }
    delete virtualhead;
    return virtualhead -> next;
}

int main() {
    
    ListNode* head = new ListNode(1);
    head -> next = new ListNode(2);
    head -> next -> next = new ListNode(6);
    head -> next -> next -> next = new ListNode(2);

//    ListNode* tmp = removeElements(head, 2);
    ListNode* tmp = removeElementsWithVHead(head,2);

    while(tmp) {
        cout << tmp -> val;
        tmp = tmp -> next;
        if(tmp) cout << "->";
    }
    return 0;
}
