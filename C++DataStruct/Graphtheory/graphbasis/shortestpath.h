#ifndef SHORTESTPATH_H_
#define SHORTESTPATH_H_

#include <cassert>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

template <typename Graph>

class ShortestPath {
 private:
  Graph &G;
  int s;
  bool *visited;
  int *from;
  int *ord;  //从s到每个节点的最短距离

 public:
  ShortestPath(Graph &graph, int s) : G(graph) {
    // 算法初始化
    assert(s >= 0 && s < graph.vertex());

    visited = new bool[graph.vertex()];
    from = new int[graph.vertex()];
    ord = new int[graph.vertex()];
    for (int i = 0; i < graph.vertex(); i++) {
      visited[i] = false;
      from[i] = -1;
      ord[i] = -1;
    }
    this->s = s;

    queue<int> q;  //队列

    // 无向图最短路径算法
    q.push(s);
    visited[s] = true;
    ord[s] = 0;
    while (!q.empty()) {
      int v = q.front();//如果不为空就去除第一个元素
      q.pop();

      typename Graph::AdjIterator adj(G, v); //遍历这个元素的所有相邻元素
      for (int i = adj.begin(); !adj.end(); i = adj.next())
        if (!visited[i]) {  //如果相邻元素没有访问过,将其加入队列。
          q.push(i);
          visited[i] = true;
          from[i] = v;
          ord[i] = ord[v] + 1;
        }
    }
  }

  ~ShortestPath() {
    delete[] visited;
    delete[] from;
    delete[] ord;
  }

  bool hasPath(int w) {
    assert(w >= 0 && w < G.vertex());
    return visited[w];
  }

  void path(int w, vector<int> &vec) {
    assert(w >= 0 && w < G.vertex());

    stack<int> s;

    int p = w;
    while (p != -1) {
      s.push(p);
      p = from[p];
    }

    vec.clear();
    while (!s.empty()) {
      vec.push_back(s.top());
      s.pop();
    }
  }

  void showPath(int w) {
    assert(w >= 0 && w < G.vertex());

    vector<int> vec;
    path(w, vec);
    for (int i = 0; i < vec.size(); i++) {
      cout << vec[i];
      if (i == vec.size() - 1)
        cout << endl;
      else
        cout << " -> ";
    }
  }

  int length(int w) {
    assert(w >= 0 && w < G.vertex());
    return ord[w];
  }
};

#endif //SHORTESTPATH_H_