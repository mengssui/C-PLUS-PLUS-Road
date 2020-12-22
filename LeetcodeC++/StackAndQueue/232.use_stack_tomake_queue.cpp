/*************************************************************************
	> File Name: 232.use_stack_tomake_queue.cpp
	> Author: Mengbw
	> Mail: 1711900861@qq.com
	> Created Time: Thu 10 Dec 2020 10:28:00 AM CST
 ************************************************************************/

#include <iostream>
#include <stack>
#include <cstdlib>

using namespace std;
class MyQueue {
    public:
        /** Initialize your data structure here. */
    MyQueue() {
        sta_in = stack<int>();
        sta_out = stack<int>();
    }
        
        /** Push element x to the back of queue. */
    void push(int x) {
        sta_in.push(x);
    }
        
        /** Removes the element from in front of queue and returns that element. */
    //「但在pop的时候，操作就复杂一些，输出栈如果为空，就把进栈数据全部导入进来（注意是全部导入）」
    int pop() {
        if(empty()) {
            return -1;
        }
        if(sta_out.empty()) {
            while(!sta_in.empty()) {
                sta_out.push(sta_in.top());
                sta_in.pop();
            }
        }
        int ret = sta_out.top();
        sta_out.pop();
        return ret;
    }
        
        /** Get the front element. */
    int peek() {
        
        int res = this->pop(); // 代码复用
        sta_out.push(res);  //pop弹出了，因此加回去
        return res;
    }
        
        /** Returns whether the queue is empty. */
    bool empty() {
        return sta_in.empty() && sta_out.empty();
    }
    private:
        stack<int> sta_in, sta_out;

};

/**
*  * Your MyQueue object will be instantiated and called as such:
    *   * MyQueue* obj = new MyQueue();
    *    * obj->push(x);
    *     * int param_2 = obj->pop();
    *      * int param_3 = obj->peek();
    *       * bool param_4 = obj->empty();
    *        */

int main() {
    srand(time(0));
    MyQueue* myqueue = new MyQueue();
    for(int i = 0; i < 20; i++) {
        int c = rand()%4;
        int in = rand()%1000;
        cout << "opt " << c << " num : " << in << "   ";
        switch (c) {
            case 0:
            case 1:
                myqueue->push(in);
                cout << "push in " << myqueue->peek() << endl;
                break;
            case 2:
            case 3:
                cout << "pop out " << myqueue->peek() << endl;
                myqueue->pop();
                break;
        }
    }

    cout << boolalpha << "the queue is " << (myqueue->empty() ? "empty" : "not empty") << endl;

    return 0;
}
