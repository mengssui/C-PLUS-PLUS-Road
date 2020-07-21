//author: Mengbw_
//date: 2020年7月17日
//计算连通分量
#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <iostream>
#include <cassert>

using namespace std;

template <typename Graph>
class Component {
 private:
  Graph &G;
  bool *visited;  //记录是否访问过
  int* id;
  int ccount;     //记录有多少个连通分量
  void dfs(int v) {
    visited[v] = true;
    id[v] = ccount;
    typename Graph::AdjIterator adj(G, v);
    for (int i = adj.begin(); !adj.end(); i = adj.next()) {
      if (!visited[i]){
        dfs(i);
      }
    } 
  }
 public:
  Component(Graph &graph) 
    : G(graph) {
    visited = new bool[G.vertex()];
    id = new int[G.vertex()];
    ccount = 0;
    for (int i = 0; i < G.vertex(); i++) {
      visited[i] = false;
      id[i] = -1;
    }
    for (int i = 0; i < G.vertex(); i++) {
      if (!visited[i]) {
        dfs(i);
        ccount++;
      }
    }
  }
  ~Component() {
    delete [] visited;
    delete [] id;
  }
  int count() {  //返回连通分量数目
    return ccount;
  }
  bool isConnected(int v, int w) {
    assert( v >= 0 && v < G.vertex());
    assert( w >= 0 && w < G.vertex());
    return id[w] == id[v];
  }
};

#endif //COMPONENT_H_