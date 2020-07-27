#ifndef KRUSKAL_H_
#define KRUSKAL_H_

#include <cassert>
#include <iostream>
#include <vector>
#include "../../Unionfind/unionfind.h"
#include "../graphwithweight/edge.h"
#include "../../Sort/minheap.h"
using namespace std;

template<typename Graph, typename Weight>
class KruskalMST {
 private:
  vector<Edge<Weight>> mst;
  Weight mstWeight;
 public:
  KruskalMST(Graph &graph) {
    MinHeap<Edge<Weight>> pq( graph.edge());
    for (int i = 0; i < graph.vertex(); i++) {
      typename Graph::AdjIterator adj(graph, i);
      for (Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next()) {
        if (e -> v() < e -> w()) pq.insert(*e); //防止无向图重复入堆
      }
    }
    UF5::UnionFind uf(graph.vertex());
    while (!pq.isEmpty() && mst.size() < graph.vertex() - 1) {
      Edge<Weight> e = pq.extractMin();
      if(uf.isConnected(e.v(), e.w())) {
        continue;
      }
      mst.push_back(e);
      uf.unionElements(e.v(), e.w());
    }
    mstWeight = mst[0].wt();
    for (int i = 1; i < mst.size(); i++) {
      mstWeight += mst[i].wt();
    }
  }
  ~KruskalMST() {} //记得定义析构函数
  vector<Edge<Weight>> mstEdges() {
    return mst;
  }
  Weight result() {
    return mstWeight;
  }
};

#endif //KRUSKAL_H_