#pragma once

#include <list>
#include <string>
#include <cstdlib>
#include "Observer.h"

using std::list;
using std::string;


//被观察者
class Observeralbe {
 public:
  Observeralbe();
  virtual ~Observeralbe();

  //返回当前观察者对象数量
  int GetObserverCnt();
  //注册观察者
  void Attach(Observer* pOb);
  //取消注册观察者
  void Detach(Observer* pOb);
  //取消所有
  void DetachAll();
  //更改状态
  virtual void GetSomeNews(string str);
 protected:
   //设置状态改变
  void SetChange(string news); 
 private:
   //通知观察者
  void Notify(void* pArg);

 private:
  list<Observer*> _Obs;
  bool _bChange;
};
