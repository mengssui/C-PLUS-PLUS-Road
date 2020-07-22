#ifndef PATH_H_
#define PATH_H_

#include <cassert>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

template <typename Graph>
class Path {

 private:
  Graph &G;
  int s;    //开始的节点，从s节点开始
  bool* visited;
  int* from;   //节点的从哪个节点来

  void dfs(int v) {
    visited[v] = true;
    typename Graph::AdjIterator adj(G, v);
    for (int i = adj.begin(); !adj.end(); i = adj.next()) {
      if (!visited[i]){
        from[i] = v;
        dfs(i);
      }
    } 
  }

 public:
  Path(Graph& graph, int s) 
      : G(graph) {
    assert(s >= 0 && s < G.vertex());

    visited = new bool[G.vertex()];
    from = new int[G.vertex()];
    for (int i = 0; i < G.vertex(); i++) {
      visited[i] = false;
      from[i] = -1;
    }
    this->s = s;
    //寻路算法
    dfs(s);
  }
  ~Path() {
    delete [] visited;
    delete [] from;
  }
  bool hasPath(int w) {  //从s到w是否有路径
    assert(w >= 0 && w < G.vertex());
    return visited[w];
  }
  void path(int w, vector<int> &vec) {
    stack<int> s;   //创建一个堆栈
    int p = w;
    while (p != -1) {
      s.push(p);
      p = from[p];
    }
    vec.clear();
    while (!s.empty() ) {
      vec.push_back(s.top());
      s.pop();
    }
  }    
  void showPath(int w) {
    assert(w >= 0 && w < G.vertex());
    vector<int> vec;
    path(w,vec);
    for (auto i : vec) {
      cout << i << "-> ";
    }
    cout << endl;
  }
};

#endif //PAHT_H_