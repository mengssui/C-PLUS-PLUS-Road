#ifndef EDGE_H_
#define EDGE_H_

#include <cassert>
#include <iostream>
//定义边的模板类
using namespace std;

template <typename Weight>
class Edge {
 private:  //顶点和权值
  int a, b;
  Weight weight;

 public:
  Edge(int a, int b, Weight weight)
    : a(a),b(b),weight(weight) { }
  Edge() { }
  ~Edge() { }
  int v() { return a; }
  int w() { return b; }
  Weight wt() { return weight; }
  int other(int x) { //知道一个定点，返回另一个定点
    assert(x == a || x == b);
    return x == a ? b : a;
  }
  //重载一些运算符
  friend ostream& operator<<(ostream &os, const Edge& e) {
    os << e.a << "—" << e.b << ": " << e.weight;
  }
  bool operator<(Edge<Weight>& e) {
    return weight < e.wt();
  }
  bool operator<=(Edge<Weight>& e) {
    return weight <= e.wt();
  }

  bool operator>(Edge<Weight>& e) {
    return weight > e.wt();
  }

  bool operator>=(Edge<Weight>& e) {
    return weight >= e.wt();
  }
  bool operator==(Edge<Weight>& e) {
    return weight == e.wt();
  }
};


#endif