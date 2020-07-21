#ifndef WEIGHT_DENSEGRAPH_H_ 
#define WEIGHT_DENSEGRAPH_H_

//稠密图
#include <iostream>
#include <vector>
#include <cassert>
#include "edge.h"

using namespace std;

//稠密图-邻接矩阵
template<typename Weight>
class DenseGraph {

 private:
  int n, m;  // 存放点数和边数
  bool directed;  //无向图还是有向图
  vector<vector<Edge<Weight>* >> g; //nxn矩阵,元素为bool型

 public:
  DenseGraph(int n, bool directed) {
    this -> n = n;
    this -> m = 0;
    this -> directed = directed;
    for (int i = 0; i < n; i++) {
      g.push_back(vector<Edge<Weight>* >(n, nullptr));
    }
  }
  ~DenseGraph(){
    for(int i= 0; i < n; i++) {
      for (int j = 0; j < n; j++){
        delete g[i][j];
      }
    }
  }
  int vertex() { return n; } //返回点数
  int edge() { return m; }   //返回边数

  void addEdge(int v, int w, Weight weight) {//需要知道边的定点和权值
    assert(v >= 0 && v < n);
    assert(w >= 0 && w < n);
    if (hasEdge(v, w)) {  //如果已经有边，就删除之前的，在重建，因为有可能权值不一样
      delete g[v][w];
      if (!directed) {
        delete g[w][v];
      }
      m --;
    } 
    g[v][w] = new Edge<Weight>(v, w, weight);
    if( !directed ) g[w][v] = new Edge<Weight>(w, v, weight); //无向图需要对应的边也设置
    m ++;
  }
  bool hasEdge(int v, int w) {
    assert(v >= 0 && v < n);
    assert(w >= 0 && w < n);
    return g[v][w] != nullptr;
  }
  void show() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if(g[i][j]) {
          cout << g[i][j] -> wt() << "\t";
        } else {
          cout << "NULL\t";
        }
      }
      cout << endl;
    }
  }
  class AdjIterator {
   private:
    DenseGraph &G;
    int v;
    int index;
   public:
    AdjIterator(DenseGraph &graph, int v)
      : G(graph), v(v), index(-1) { }
    ~AdjIterator() { }

    Edge<Weight>* begin() {
      index = -1;
      return next();
    }

    Edge<Weight>* next() {
      for (index += 1; index < G.vertex(); index ++) {
        if (G.g[v][index]) return G.g[v][index];
      }
      return nullptr;
    }

    bool end() {
      return index >= G.vertex();
    }
  };
};


#endif //WEIGHT_DENSEGRAPH_H_