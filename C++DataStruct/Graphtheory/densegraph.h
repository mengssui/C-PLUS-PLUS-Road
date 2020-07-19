#ifndef DENSEGRAPH_H_ 
#define DENSEGRAPH_H_
//稠密图
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

//稠密图-邻接矩阵
class DenseGraph {

 private:
  int n, m;  // 存放点数和边数
  bool directed;  //无向图还是有向图
  vector<vector<bool>> g; //nxn矩阵,元素为bool型

 public:
  DenseGraph(int n, bool directed) {
    this -> n = n;
    this -> m = 0;
    this -> directed = directed;
    for (int i = 0; i < n; i++) {
      g.push_back(vector<bool>(n, false));
    }
  }
  ~DenseGraph(){}
  int vertex() { return n; } //返回点数
  int edge() { return m; }   //返回边数

  void addEdge(int v, int w) {
    assert(v >= 0 && v < n);
    assert(w >= 0 && w < n);
    if (hasEdge(v, w)) return; //如果有边
    g[v][w] = true;
    if( !directed ) g[w][v] = true;
    m ++;
  }
  bool hasEdge(int v, int w) {
    assert(v >= 0 && v < n);
    assert(w >= 0 && w < n);
    return g[v][w];
  }
  void show() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << g[i][j] << "\t";
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

    int begin() {
      index = -1;
      return next();
    }

    int next() {
      for (index += 1; index < G.vertex(); index ++) {
        if (G.g[v][index]) return index;
      }
      return -1;
    }

    bool end() {
      return index >= G.vertex();
    }
  };
};


#endif //GRAPH_DENSEGRAPH_H_