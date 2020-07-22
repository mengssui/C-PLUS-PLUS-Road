#ifndef LAZYPRIMMST_H_
#define LAZYPRIMMST_H_

#include "../../Sort/minheap.h"
#include <vector>
#include <iostream>
#include <cassert>
#include "../graphwithweight/edge.h"

using namespace std;

template<typename Graph, typename Weight>
class LazyPrimMST {
 private:
  Graph& G;
  MinHeap<Edge<Weight>> pq; //最小堆存储边
  bool* marked; //标记是否被切分
  vector<Edge<Weight>> mst;
  Weight mstWeight; //mst总的权值
  void visit(int v) {
    assert(!marked[v]);
    marked[v] = true;

    typename Graph::AdjIterator adj(G, v);
    for( Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next()) {
      if(!marked[e->other(v)]) {
        pq.insert(*e);
      }
    }
  }
 public:
  LazyPrimMST(Graph& graph)
    : G(graph), pq(MinHeap<Edge<Weight>>(graph.edge())) {
      marked = new bool[G.vertex()];
      for(int i = 0; i < G.vertex(); i++) {
        marked[i] = false;
      }
      mst.clear();
      //Lazy prim 算法
      visit(0);
      while (!pq.isEmpty()) {
        Edge<Weight> e = pq.extractMin();
        if (marked[e.v()] == marked[e.w()]) continue;
        mst.push_back(e);
        if(!marked[e.v()]) {
          visit(e.v());
        } else {
          visit(e.w());
        }
      }
      mstWeight = mst[0].wt();   //因为最开始mstWeight不知道赋值为什么类型的，因此先给他赋值，方便之后相加
      for(int i = 1; i< mst.size(); i++) {
        mstWeight += mst[i].wt();
      }


    }
  ~LazyPrimMST() {
    delete [] marked;
  }
  vector<Edge<Weight>> mstEdges() {
    return mst;
  }
  Weight result() {
    return mstWeight;
  }
};



#endif  //LAZYPRIMMST_H_