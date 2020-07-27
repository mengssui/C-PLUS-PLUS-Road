#include "kruskal.h"
#include "../graphwithweight/wreadgraph.h"
#include "../graphwithweight/wsparsegraph.h"
#include <iomanip>

using namespace std;

int main() {
  string filename = "testG1.txt";
  int V = 8;
  SparseGraph<double> g(V, false);
  ReadGraph<SparseGraph<double>, double> readgraph(g, filename);
  
  //Test kruskal MST
  KruskalMST<SparseGraph<double>, double> kruskalMST(g);
  cout << "Test KruskalMST : " << endl;
  vector<Edge<double>> mst = kruskalMST.mstEdges();
  for (int i = 0; i < mst.size(); i++) {
    cout << fixed << setprecision(2);
    cout << mst[i] << endl;
  }
  cout << "The MST weight is : " << kruskalMST.result() << endl;
  cout << endl;
}