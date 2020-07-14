#ifndef UNIONFIND_H_
#define UNIONFIND_H_

//author:Mengbw
//date: 2020年7月12日

//并查集
//id 1 2 3 4 5 6 7 8
//   0 0 0 0 0 0 0 0
//以id为下标的值相同是相邻的.
#include <cassert>

using namespace std;

//id 1 2 3 4 5 6 7 8
//   0 0 0 0 0 0 0 0
//以id为下标的值相同是相邻的.
namespace UF1{   //quick find 查找很快

  class UnionFind {
  private:
    int* id;
    int count;
  public:
    UnionFind(int n) {
      id = new int[n];
      for (int i = 0; i < n; i++) {
        id[i] = i;
      }
      count = n;
    }
    ~UnionFind() {
      delete [] id;
    }
    int find(int p) {  //查找p所属集合
      assert(p >= 0 && p < count);
      return id[p];
    }
    bool isConnected( int p, int q) { //pq是否在一个集合中
      return find(p) == find (q);
    }
    void unionElements( int p, int q ) {//合并pq所在集合
      int pID = find(p);
      int qID = find(q);
      if (pID == qID ) {
        return;
      }

      for (int i = 0; i < count; i++) {  //时间复杂度o(n)
        if (id[i] == pID) {
          id[i] = qID;
        }
      }
    }
  };
}


//id       1 2 3 4 5 6 7 8
//parent   0 0 0 0 0 0 0 0
//parent 存储id 的根节点的位置.
namespace UF2 {   //quick union 合并很快

  class UnionFind {
   private:
    int* parent;
    int count;

   public:
    UnionFind(int n) {
      parent = new int[n];
      count = n;
      for (int i = 0; i < n; i++) {
        parent[i] = i;
      }
    }
    ~UnionFind() {
       delete [] parent;
     }
    //寻找对应的某个节点的根节点
    int find(int p) {
      assert(p >= 0 && p < count);
      while (parent[p] != p) {
        p = parent[p];
      }
     return p; 
    }
    //查看两个节点是否相连接
    bool isConnected(int p, int q) {
      return find(p) == find(q);
    }
    //并两个节点
    void unionElements(int p, int q) {
      //使两个节点的根节点一致即可
      int qroot = find(q);
      int proot = find(p);

      if (qroot = proot) {
        return;
      }
      parent[qroot] = proot;
    }
  };
  
} // namespace UF2

namespace UF3 {

  class UnionFind {
   private:
    int* parent;
    int* sz;   //sz[i]表示以i为根的结合中的元素的个数
    int count; 
   public:
    UnionFind(int n) {
      parent = new int[n];
      sz = new int[n];
      count = n;
      for (int i = 0; i < n; i++) {
        parent[i] = i;
        sz[i] = 1;
      }
    }
    ~UnionFind() {
      delete [] parent;
      delete [] sz;
    }
    int find(int p) {
      assert(p >= 0 && p < count);
      while( parent[p] != p) {
        p = parent[p];
      }
      return p;
    }
    bool isConnected(int p, int q) {
      return find(q) == find(p);
    }
    //优化
    void unionElements(int p, int q) {
      int qroot = find(q);
      int proot = find(p);

      if (qroot = proot) {
        return;
      }

      if (sz[qroot] > sz[proot]) {
        parent[proot] = qroot;
        sz[qroot] += sz[proot]; 
      } else {
        parent[qroot] = proot;
        sz[proot] = qroot;
      } 
    }
    
  };
} // namespace UF3

namespace UF4 {
  class UnionFind {
   private:
    int* parent;
    int count;
    int* rank;  //表示根节点为i 的树的高度
  public:
    UnionFind(int n) {
      parent = new int[n];
      rank = new int[n];
      for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 1;
      }
      count = n;
    }
    ~UnionFind() {
      delete [] parent;
      delete [] rank;
    }
    int find(int p) {
      assert( p >= 0 && p < count);
      while(p != parent[p]) {
        p = parent[p];
      }
      return p;
    } 
    bool isConnected(int p, int q) {
      return find(q) == find(p);
    }
    void unionElements(int p, int q) {
      int qroot = find(q);
      int proot = find(p);

      if (qroot == proot) {
        return;
      }
      if (rank[qroot] > rank[proot]) {
        parent[proot] = qroot;
      } else if(rank[qroot] < rank[proot]) {
        parent[qroot] = proot;
      } else { // rank[proot] = rank[qroot]
        parent[qroot] = proot;
        rank[proot] += 1;
      }
    }
  };
} // namespace UF4

namespace UF5 {

  class UnionFind {
   private:
    int* parent;
    int count;
    int* rank;
   public:
    UnionFind(int n) {
      parent = new int[n];
      rank = new int[n];
      for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 1;
      }
      count = n;
    }
    ~UnionFind() {
      delete [] parent;
      delete [] rank;
    }
    int find(int p) {     //路径压缩算法
      assert( p >= 0 && p < count);
      // while(p != parent[p]) {   //第一种路径压缩,层数减少
      //   parent[p] = parent[parent[p]];
      //   p = parent[p];
      // }
      // return p;
         
      if (p != parent[p]) {   //第二种路径压缩，层数为2
        parent[p] = find(parent[p]);
      }
      return parent[p];
    } 
    bool isConnected(int p, int q) {
      return find(q) == find(p);
    }
    void unionElements(int p, int q) {
      int qroot = find(q);
      int proot = find(p);

      if (qroot == proot) {
        return;
      }
      if (rank[qroot] > rank[proot]) {
        parent[proot] = qroot;
      } else if(rank[qroot] < rank[proot]) {
        parent[qroot] = proot;
      } else { // rank[proot] = rank[qroot]
        parent[qroot] = proot;
        rank[proot] += 1;
      }
    }
  };
} // namespace UF5


#endif //