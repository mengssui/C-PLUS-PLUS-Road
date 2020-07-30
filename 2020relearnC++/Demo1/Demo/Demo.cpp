#include "Singleton.h"
#include "Observeralbe.h"
#include "Adaptertest.h"
using namespace std;
class News : public Observeralbe{
 public: 
  virtual void GetSomeNews(string str) {
    SetChange("NEWS: " + str);   
  }
};
int main() {
  //单例模式
  //Singleton::getInstance()->DoSomething();
  
  ////观察者模式
  //User1 u1;
  //User2 u2;

  //News n1;
  //n1.GetSomeNews("T0");
  //cout << n1.GetObserverCnt() << endl;//0

  //n1.Attach(&u1);
  //n1.Attach(&u2);
  //n1.GetSomeNews("T1");
  //cout << n1.GetObserverCnt() << endl;//0

  //n1.Detach(&u2);
  //n1.GetSomeNews("T2");
  //cout << n1.GetObserverCnt() << endl;//1

  //n1.DetachAll();
  //n1.GetSomeNews("T3");
  //cout << n1.GetObserverCnt() << endl;

  //cout << "exit main function"<< endl;

  //适配器模式
  double x = 20.0, y = 50.0, w = 300.0, h =200.0;
  RectangleAdapter ra(x,y,w,h);
  Rectangle* pR = &ra;
  pR->Draw("Testing Adapter");

  
  RectangleAdapter2 ra2(x,y,w,h);
  Rectangle* pR2 = &ra2;
  pR2->Draw("Testing2 Adapter");
  return 0;
}