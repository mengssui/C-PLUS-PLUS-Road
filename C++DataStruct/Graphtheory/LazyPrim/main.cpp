#include "lazyprimMST.h"
#include "../graphwithweight/wsparsegraph.h"
#include "../graphwithweight/wreadgraph.h"
#include "lazyprimMSToptimized.h"
#include <iomanip>

using namespace std;

int main() {

  // string filename = "../graphwithweight/testG1.txt";
  string filename = "testG2.txt";
  int V = 250;
  SparseGraph<double> g(V, false);   //创建一个权值是double型的无向图
  ReadGraph<SparseGraph<double>, double>  read_graph(g, filename); //读取图并根据文件加入边

  
  //Test lazy prim MST
  cout << "Test Lazy Prim MST : " << endl;
  LazyPrimMST<SparseGraph<double>, double> lazyPrimMST(g);
  vector<Edge<double>> mst = lazyPrimMST.mstEdges();
  for (int i = 0; i < mst.size(); i++) {
    cout << fixed << setprecision(2);
    cout << mst[i] << endl;
  }
  cout << "The MST weight is : " << lazyPrimMST.result() << endl;
  cout << endl;


  //Test prim MST
  cout << "Test Prim MST : " << endl;
  PrimMST<SparseGraph<double>, double> primMST(g);
  mst = primMST.mstEdges();
  for (int i = 0; i < mst.size(); i++) {
    cout << mst[i] << endl;
  }
  cout << "The MST weight is : " <<primMST.result();
  cout << endl;
  return 0;

}