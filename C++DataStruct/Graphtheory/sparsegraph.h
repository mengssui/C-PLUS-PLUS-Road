# ifndef SPARSEGRAPH_H_
# define SPARSEGRAPH_H_

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

//稀疏图 - 邻接表
class SparseGraph {
 private:
  int n, m;
  bool directed;
  vector<vector<int>> g; //一个vecotr存与其相连的点，是int

 public:
  SparseGraph(int n, bool directed) {
    this -> n = n;
    this -> m = 0;
    this -> directed = directed;
    for (int i = 0; i < n; i++) {
      g.push_back(vector<int>()); //每个g[i]是空初始化为空的vector
    }
  }
  ~SparseGraph() { }
  
  int vertex() { return n; }
  int edge() { return m; }
  //如果增加判断平行边，则复杂度会成为O(n)
  //因此，通常做法是，加入边的时候不判断，所有边加入完成后再做一次统一的处理
  void addEdge(int v, int w) {
    assert(v >= 0 && v < n);
    assert(w >= 0 && w < n);
    // if (hasEdge(v ,w)) return ;// 通常不处理平行边
    g[v].push_back(w);
    if (v != w && !directed) g[w].push_back(v);  //防止自环边
    m++;
  }
  //处理平行边复杂度为O(n)
  bool hasEdge(int v, int w) {  //处理平行边
    assert(v >= 0 && v < n);
    assert(w >= 0 && w < n);

    for (int i = 0; i < g[v].size(); i++) {
      if (g[v][i] == w) return true; //存在边
    }
    return false;
  }
  void show() {
    for (int i = 0; i < n; i++) {
      cout << "vertex " << i << ":\t";
      for (int j = 0; j < g[i].size(); j++){
        cout << g[i][j] << "\t";
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
    int begin() {   // 要迭代的第一个元素
      index = 0;
      if (G.g[v].size()) {
        return G.g[v][index];
      }
      return -1;
    } 
    int next() {
      index ++;
      if(index < G.g[v].size()) {
        return G.g[v][index];
      }
      return -1;
    }
    bool end(){  //判断迭代是否结束
      return index >= G.g[v].size();
    }
  };
};

# endif // SPARSEGRAPH_H_