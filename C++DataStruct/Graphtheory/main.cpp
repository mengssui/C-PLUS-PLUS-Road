#include <iostream>
#include "sparsegraph.h"
#include "densegraph.h"
#include <ctime>
#include <random>
#include "readgraph.h"
#include "component.h"
#include "path.h"
#include "shortestpath.h"
using namespace std;

int main() {

/*测试寻找路径*/
  string filename = "testG2.txt";
  SparseGraph g(6, false);
  ReadGraph<SparseGraph> readGraph(g, filename);
  g.show();
  cout << endl;

  Path<SparseGraph> dfs(g,0);
  cout << "DFS : ";
  dfs.showPath(5); 
  
/*最短路径*/
  ShortestPath<SparseGraph> bfs(g,0);
  cout << "BFS : ";
  bfs.showPath(5);
  return 0;


  // //只能用绝对路径
  // // string filename = "D:/MyStudyFile/Study_C_PLUS_PLUS/C-PLUS-PLUS-Road/C++DataStruct/Graphtheory/testG1.txt";
  // string filename1 = "testG1.txt";
  // SparseGraph g1 (13, false);
  // ReadGraph<SparseGraph> readGraph1(g1, filename1);
  // Component<SparseGraph> component1(g1);
  // cout << component1.count() << endl;

  // cout << "**********************************"<< endl;
  // string filename2 = "testG2.txt";
  // SparseGraph g2(6,false);
  // ReadGraph<SparseGraph> readGraph2(g2,filename2);
  // Component<SparseGraph> component2(g2);
  // cout << component2.count() <<endl;

  // return 0;


/* 随机生成边同时打印各个点的边
  int v = 20;
  int e = 100;
  uniform_int_distribution<unsigned> u(0,v-1);
  //设置随机数引擎,并且使用time0作为种子
  default_random_engine engine(time(0));
  
  //稀疏图
  SparseGraph g1(v, false);
  for (int i = 0; i < e; i++) {
    int a = u(engine);
    int b = u(engine);
    g1.addEdge(a,b); 
  }

  for (int i = 0; i < v; i++) {
    cout << i << " : ";
    SparseGraph::AdjIterator adj(g1, i);
    for (int w = adj.begin(); !adj.end(); w = adj.next()) {
      cout << w << " ";
    }
    cout << endl;
  }
  cout << endl;

  //稠密图
  DenseGraph g2(v, false);
  for (int i = 0; i < e; i++) {
    int a = u(engine);
    int b = u(engine);
    g2.addEdge(a,b); 
  }

  for (int i = 0; i < v; i++) {
    cout << i << " : ";
    DenseGraph::AdjIterator adj(g2, i);
    for (int w = adj.begin(); !adj.end(); w = adj.next()) {
      cout << w << " ";
    }
   
    cout << endl;
  }
  return 0;
*/  
}