#pragma once
//单例模式
#include <iostream>

using namespace std;
class Singleton {
 public:
  static const Singleton* getInstance();
  static void DoSomething() {
    cout << "Do Something!" << endl;
    return;
  }
	//私有化析构和构造函数
 private:
  Singleton();
  ~Singleton();
  static Singleton* This; //使用静态变量帮助解决资源分配和释放
};
