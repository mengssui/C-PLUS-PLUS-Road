#include <iostream>
#include <string>

using namespace std;

class LegacyRectangle {
  
 public:
  LegacyRectangle(double x1, double y1, double x2, double y2)
    : _x1(x1),_y1(y1),_x2(x2),_y2(y2) {}
  ~LegacyRectangle(){}

  void LegacyDraw() {
    cout << " LegacyRectangle::LegacyDrwa()";
    cout << _x1 << " ";
    cout << _y1 << " ";
    cout << _x2 << " ";
    cout << _y2 << " " << endl;
  }
 private:
  double _x1;
  double _y1;
  double _x2;
  double _y2;
};


//定义一个抽象类
//适配原来的上边的class

class Rectangle { 
 public:
  virtual void Draw(string str) = 0; //虚继承- 接口继承

};

//第一种适配的方式：使用多重继承
class RectangleAdapter : public Rectangle, public LegacyRectangle {
 public:
  RectangleAdapter(double x, double y, double w, double h) 
    : LegacyRectangle(x,y,x+w,y+h) {
    cout << "RectangleAdapter(int x, int y, int w, int h)" << endl;
  }
  ~RectangleAdapter(){}
  void Draw(string str) {
    cout << "RectangleAdapter::Draw()" << endl;
    LegacyDraw();
  }
 };

//int main1() {
//  double x = 20.0, y = 50.0, w = 300.0, h =200.0;
//  RectangleAdapter ra(x,y,w,h);
//  Rectangle* pR = &ra;
//  pR->Draw("Testing Adapter");
//  return 0;
//}

//组合方式的Adapter
 class RectangleAdapter2 : public Rectangle {
  public:
   RectangleAdapter2(double x, double y, double w, double h)
       : _IRect(x, y, x + w, y + h) {
     cout << "RectangleAdapter2(int x, int y, int w, int h)" << endl;
   }
   ~RectangleAdapter2() {}
   void Draw(string str) {
     cout << "RectangleAdapter2::Draw()" << endl;
     _IRect.LegacyDraw();
   }
  private:
   LegacyRectangle _IRect;
 };

