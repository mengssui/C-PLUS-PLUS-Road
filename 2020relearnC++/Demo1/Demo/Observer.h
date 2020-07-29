#pragma once

#ifndef OBSERVER_H_
#define OBSERVER_H_

#include <iostream>

using namespace std;

class Observer {
 public:
  Observer() { }
	virtual ~Observer(){ }
	//当被观察者对象发生变化时候，通知被观察者调用这个函数
	virtual void Update(void* pArg) = 0; //纯虚函数
};

class User1 : public Observer{
	virtual void Update(void* pArg) {
		cout << "user 1 got news" << static_cast<char*>(pArg) << endl;
	}
};

class User2 : public Observer{
	virtual void Update(void* pArg) {
		cout << "user 2 got news" << static_cast<char*>(pArg) << endl;
	}
};

#endif  // !OBSERVER_H_