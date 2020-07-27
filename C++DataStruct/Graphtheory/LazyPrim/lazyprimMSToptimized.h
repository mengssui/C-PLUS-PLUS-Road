// lazyprim优化

#ifndef PRIMMST_H_
#define PRIMMST_H_

#include <cassert>
#include <iostream>
#include <vector>

#include "../../Sort/IndexMinHeap.h"
#include "../graphwithweight/edge.h"

using namespace std;

template <typename Graph, typename Weight>
class PrimMST {
 private:
  Graph& G;
  IndexMinHeap<Weight> ipq;  //最小堆存储边的权值
  bool* marked;              //标记是否被切分
  vector<Edge<Weight>> mst;
  vector<Edge<Weight>*> edge_to;
  Weight mstWeight;  // mst总的权值
  void visit(int v) {
    assert(!marked[v]);
    marked[v] = true;

    typename Graph::AdjIterator adj(G, v);
    for (Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next()) {
      int w = e -> other(v);
      if (!marked[w]) {  //是否被标记
        if (!edge_to[w]) { //是否有边与w相连
          ipq.insert(w, e -> wt());
          edge_to[w] = e;
        } else if( e -> wt() < edge_to[w]->wt()) {
          edge_to[w] = e;
          ipq.change(w, e -> wt());
        }
      }
    }
  }

 public:
  PrimMST(Graph& graph) : G(graph), ipq(IndexMinHeap<double>(graph.edge())) {
    marked = new bool[G.vertex()];
    for (int i = 0; i < G.vertex(); i++) {
      marked[i] = false;
      edge_to.push_back(nullptr);
    }
    mst.clear();
    // prim 算法  时间复杂度O(ElogV )
    visit(0);                            // O(E)
    while (!ipq.isEmpty()) {              //这个复杂度O(E)
      int v = ipq.extractMinIndex();
      assert(edge_to[v]);
      mst.push_back(*edge_to[v]);
      visit(v);
    }
    mstWeight = mst[0].wt();  //因为最开始mstWeight不知道赋值为什么类型的，因此先给他赋值，方便之后相加
    for (int i = 1; i < mst.size(); i++) {
      mstWeight += mst[i].wt();
    }
  }
  ~PrimMST() { delete[] marked; }
  vector<Edge<Weight>> mstEdges() { return mst; }
  Weight result() { return mstWeight; }
};

#endif  // PRIMMST_H_