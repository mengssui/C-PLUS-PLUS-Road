#include "../../Sort/IndexMinHeap.h"
#include "../graphwithweight/edge.h"
#include "../graphwithweight/wreadgraph.h"
#include "../graphwithweight/wsparsegraph.h"
#include <stack>

using namespace std;

template <typename Graph, typename Weight>
class Dijkstra {
 private:
  Graph& G;  // 图的引用
  int s;     // 源点

  Weight* distTo;              // 距离某个点的距离
  bool* marked;                // 是否访问过
  vector<Edge<Weight>*> from;  // 到达的顶点从哪里来

 public:
  Dijkstra(Graph& graph, int s) : G(graph), s(s) {
    distTo = new Weight[G.vertex()];
    marked = new bool[G.vertex()];
    for (int i = 0; i < G.vertex(); i++) {
      distTo[i] = Weight();  //由于不知道类型，因此赋值其默认构造函数的初始值
      marked[i] = false;
      from.push_back(nullptr);
    }
    IndexMinHeap<Weight> ipq(G.vertex());

    // dijkstra算法的实现
    distTo[s] = Weight();
    marked[s] = true;
    ipq.insert(s, distTo[s]);
    while (!ipq.isEmpty()) {
      int v = ipq.extractMinIndex();
      marked[v] = true; // distTo[v] 是 s 到 v 的最短距离
      //松弛操作
      typename Graph::AdjIterator adj(G, v);
      for (Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next()) {
        int w = e -> other(v);
        if( !marked[w]) {
          if (from[w] == nullptr || distTo[v] + e->wt() < distTo[w]) {
            distTo[w] = distTo[v] + e->wt();
            from[w] = e;
            if(ipq.contain(w)) {
              ipq.change(w, distTo[w]);
            } else {
              ipq.insert(w, distTo[w]);
            }
          }
        }
      }
    }
  }
  ~Dijkstra() {
    delete[] distTo;
    delete[] marked;
  }
  //返回到w的最短路径的值
  Weight shortestPathTo(int w) { return distTo[w]; }
  //是否有路径到达
  bool hasPathTo(int w) { return marked[w]; }
  //最短路径的边
  void shortestPath(int w, vector<Edge<Weight>>& vec) {
    stack<Edge<Weight>*> s;
    Edge<Weight> *e = from[w];
    while (!e) {  //直至其不为 空 
      s.push(e);
      e = from[e -> v()];
    }
    while (!s.empty()) {
      e = s.top();
      vec.push_back(*e);
      s.pop();
    }
  }
  //显示最短路径
  void showPath(int w) {
    assert( w >= 0 && w < G.vertex());
    vector<Edge<Weight>> vec;
    shortestPath(w, vec);
    for (int i = 0; i < vec.size(); i++) {
      cout << vec[i].v() << " -> ";
      if (i == vec.size() - 1) {
        cout << vec[i].w() << endl;
      }
    }
  }
};
