#include <iostream>
using namespace std;

//题目序号从0开始表示第一个节点，因此有的方法需要index++

class MyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(NULL) {}
    };
    Node* virhead;   //虚拟头节点，不是链表的第一个节点
    int n;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        virhead = new Node(-1);
        n = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        index++;
        if(index <= 0 || index > n) return -1;
        Node* cur = virhead;
        while(index--) {
            cur = cur -> next;
        }
        return cur->data;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* node = new Node(val);
        node -> next = virhead -> next;
        virhead -> next = node;
        n++;
        return;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* cur = virhead;
        while(cur -> next) {
            cur = cur -> next;
        }
        Node* node = new Node(val);
        cur -> next = node;
        n++;
        return;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index == n) {addAtTail(val); return;}
        if(index < 0 || index > n) return;
        index++;
        Node* cur = virhead;
        while(--index) {
            cur = cur -> next;
        }
        Node* node = new Node(val);
        node -> next = cur -> next;
        cur -> next = node;
        n++;
        return;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        index++;
        if(index <=0 || index > n) return; 
        Node* cur = virhead;
        while(--index) {
            cur = cur -> next;
        }
        if(index == 0) {
            Node*tmp = cur->next;
            cur->next = tmp->next;
            delete tmp;
            n--;
        }
        return;
    }

    void printList() {
        Node* cur = virhead->next;
        cout << "My linkedList :" << endl;
        while(cur) {
            cout << cur->data << " -> " ;
            cur = cur->next;
        }
        cout << "NULL" << endl;
    }
};


int main () {

    MyLinkedList* linkedlist = new MyLinkedList();
    linkedlist->addAtHead(1);
    linkedlist->addAtTail(2);
    linkedlist->addAtTail(3);
    linkedlist->addAtTail(4);
    linkedlist->addAtTail(5);
    linkedlist->addAtHead(0);
    linkedlist->addAtHead(-1);
    linkedlist->addAtHead(-3);
    linkedlist->addAtIndex(1,-2);
    linkedlist->addAtIndex(9,6);
    linkedlist->addAtIndex(11,7);
    linkedlist->printList();
    cout << "get(1) = " << linkedlist->get(1) << endl;
    linkedlist->deleteAtIndex(0);
    linkedlist->printList();
    cout << "get(1) = " << linkedlist->get(1) << endl;
    linkedlist->printList();
    system("pause");
    return  0;
}