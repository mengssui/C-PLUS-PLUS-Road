# ifndef WEIGHTSPARSEGRAPH_H_
# define WEIGHTSPARSEGRAPH_H_

#include <iostream>
#include <vector>
#include <cassert>
#include "edge.h"
using namespace std;

//稀疏图 - 邻接表
template<typename Weight>
class SparseGraph {
 private:
  int n, m;
  bool directed;
  vector<vector<Edge<Weight>* >> g; //一个vecotr存与其相连的点，是int

 public:
  SparseGraph(int n, bool directed) {
    this -> n = n;
    this -> m = 0;
    this -> directed = directed;
    for (int i = 0; i < n; i++) {
      g.push_back(vector<Edge<Weight> *>()); //每个g[i]是初始化为空的vector
    }
  }
  ~SparseGraph() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < g[i].size(); j++) {
        delete g[i][j];
      }
    }
  }
  
  int vertex() { return n; }
  int edge() { return m; }
  //如果增加判断平行边，则复杂度会成为O(n)
  //因此，通常做法是，加入边的时候不判断，所有边加入完成后再做一次统一的处理
  void addEdge(int v, int w, Weight weight) {
    assert(v >= 0 && v < n);
    assert(w >= 0 && w < n);
    // if (hasEdge(v ,w)) return ;// 通常不处理平行边
    g[v].push_back(new Edge<Weight>(v, w, weight));
    if (v != w && !directed) g[w].push_back(new Edge<Weight>(w, v, weight));  //防止自环边
    m++;
  }
  //处理平行边复杂度为O(n)
  bool hasEdge(int v, int w) {  //处理平行边
    assert(v >= 0 && v < n);
    assert(w >= 0 && w < n);

    for (int i = 0; i < g[v].size(); i++) {
      if (g[v][i] -> other(v) == w) return true; //存在边
    }
    return false;
  }
  void show() {
    for (int i = 0; i < n; i++) {
      cout << "vertex " << i << ":\t";
      for (int j = 0; j < g[i].size(); j++){
        cout << "( to:" <<g[i][j]->w()<<",wt:"<<g[i][j]->wt()<<")\t";
      }
      cout << endl;
    }
  }
  class AdjIterator {
   private:
    SparseGraph &G;
    int v;  //邻接的节点
    int index; //迭代到的节点
   public:
    AdjIterator(SparseGraph &graph, int v)
        : G(graph), v(v), index(0) { }
    Edge<Weight>* begin() {   // 要迭代的第一个元素
      index = 0;
      if (G.g[v].size()) {
        return G.g[v][index];
      }
      return nullptr;
    } 
    Edge<Weight>* next() {
      index += 1;
      if(index < G.g[v].size()) {
        return G.g[v][index];
      }
      return nullptr;
    }
    bool end(){  //判断迭代是否结束
      return index >= G.g[v].size();
    }
  };
};

# endif // WEIGHTSPARSEGRAPH_H_