//Copyright
//License
//Autho : Mengbw_
//data : 2020/6/19
//This is the main.cpp to sort
//博客网站：https://blog.csdn.net/qq_42956667/article/details/106824989

#include <iostream>
#include <ctime>

struct ListNode {
	int val;
	ListNode* next; 	
	ListNode(int x) : val(x), next(NULL) {}
 };
ListNode* CreatList(int num);
void addTwoNumbers(ListNode* l1, ListNode* l2);
void addTwoNumbers2(ListNode* l1, ListNode* l2);


int main() {
    srand(time(NULL));  //随机种子要放在外面
    ListNode* l1 = CreatList(rand()%10+1);
    ListNode* l2 = CreatList(rand()%10+1);
    addTwoNumbers(l1,l2);

    ListNode* l3 = CreatList(rand()%10+1);
    ListNode* l4 = CreatList(rand()%10+1);
    addTwoNumbers2(l3,l4); 
       
    return 0; 
}

ListNode* CreatList(int num) {
    ListNode* front =new ListNode(0);
    ListNode* ret = front;
    //外面放的话，下面的while每次都是同样的序列
    while (num--)
    {  //里面放随机种子的话，每次都是一个相同的值
        ListNode* tmp = new ListNode(rand()%10);
        front -> next = tmp;
        front = front -> next;
        std::cout << tmp->val;
        if (num) std::cout<<" ->";
    }
    std::cout<<std::endl;
    return ret->next;

}

//自己的版本还是比较菜的
void addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* front = new ListNode(0);
	ListNode* ret = front;
	int carry = 0;
	//首先遍历两者同样的长度
	do {
		ListNode* tmp = new ListNode((l1->val + l2->val + carry) % 10 );
        carry = (l1->val + l2->val + carry) / 10;
        front -> next = tmp;
        l1 = l1 -> next;
        l2 = l2 -> next;
        front = front -> next;
	} while (l1 && l2 );
	//如果有没有遍历完的，则继续遍历
	if(l1 || l2) {
	//由于有进位，因此不能简单的连接，而是需要判断进位
	    if (carry) {
	        while (l1) {
	            int t = (l1 -> val + carry) / 10;
	            l1 -> val = (l1 -> val +=carry) % 10;
	            carry = t;
	            front->next = l1;
	            front = front -> next;
	            l1 = l1->next;
	         }
	         while (l2) {
	             int t = (l2-> val + carry) / 10;
	             l2 -> val = (l2 -> val +=carry) % 10;
	             carry = t;
	             front->next = l2;
	             front = front -> next;
	             l2 = l2->next;
	         }
            } else {
               if (l1) {
                  front -> next = l1;
               } else {
                  front -> next = l2;
               }
            }
        }
        //最终也要判断进位，以防出现示例二的情况
        if (carry) {
        	ListNode* tmp = new ListNode(carry);
        	front -> next = tmp;
        }
        while(ret->next) {
            std::cout << ret->next->val;
            ret = ret->next;
            if (ret->next) std::cout<<" ->";
        }
        std::cout << std::endl;
        return;
}

//官方版本
void addTwoNumbers2(ListNode* l1, ListNode* l2){
    ListNode* front = new ListNode(0);
    ListNode* ret = front;
    int carry = 0;
    //如果两者有一个不空
    while(l1 || l2) {
        //关键思路如果为空就把他当作0
    	int x = (l1) ? l1 -> val : 0;
    	int y = (l2) ? l2 -> val : 0;
    	int sum = x + y + carry;
    	ListNode* tmp = new ListNode(sum%10);
    	carry = sum / 10;
    	front -> next = tmp;
    	if (l1) l1 = l1 -> next;
    	if (l2) l2 = l2 -> next;
    	front = front -> next;
    }
    if (carry) {
    	ListNode* t = new ListNode(carry);
    	front -> next = t;
    }
    while(ret->next) {
        std::cout << ret->next->val;
        ret = ret->next;
        if (ret->next) std::cout<<" ->";
    }
    std::cout << std::endl;
    return;
 }
