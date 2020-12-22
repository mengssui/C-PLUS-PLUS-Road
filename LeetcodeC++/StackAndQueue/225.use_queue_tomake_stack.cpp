/*************************************************************************
	> File Name: 225.use_queue_tomake_stack.cpp
	> Author: Mengbw
	> Mail: 1711900861@qq.com
	> Created Time: Thu 10 Dec 2020 02:42:34 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> que,que_back;   //备份的一个队列, 也可以是用一个队列
public:
        /** Initialize your data structure here. */
    MyStack() {
        que = queue<int>();
        que_back = queue<int>();
    }
        
        /** Push element x onto stack. */
    void push(int x) {
        que.push(x);    
    }
        
        /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(que.empty()) {
            return -1;
        }
        while(que.size()>1) {
            int c = que.front();
            que_back.push(c);
            que.pop();
        }
        int ret = que.front();
        que.pop();
        while(!que_back.empty()) {
            int c = que_back.front();
            que.push(c);
            que_back.pop();
        }
        return ret;
    }
        
        /** Get the top element. */
    int top() {
        if (que.empty()) return -1;
        int ret = this->pop();
        que.push(ret);
        return ret; 
        //或者直接使用que.back()
    }
        
        /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty(); 
    }

};

/**
* Your MyStack object will be instantiated and called as such:
* MyStack* obj = new MyStack();
* obj->push(x);
* int param_2 = obj->pop();
* int param_3 = obj->top();
* bool param_4 = obj->empty();
*/

int main() {


    return 0;
}
