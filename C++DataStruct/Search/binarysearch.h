#ifndef BINARYSEARCH_H_
#define BINARYSEARCH_H_

#include <assert.h>
#include <queue>

template <typename T>
int binarySearch(T arr[], int n, T target) {
  int l = 0, r = n - 1;  //在[l...r]中查找,注意开闭区间
  while (l <= r) {
    // int mid = (l + r) / 2; //可能溢出
    int mid = l + (r-l) / 2;
    if (arr[mid] == target) {
      return mid;
    }
    //在[l...mid-1]中查找
    if ( arr[mid] > target) {
      r = mid - 1;
    } else {  //在 [mid+1,r]
      l = mid + 1;
    }
  }
  return -1; //未找到
}

//binary serach tree
template <typename Key, typename Value>
class BST {
 private:
  struct Node {
    Key key;
    Value value;
    Node* left;
    Node* right;

    Node(Key key, Value value) {
      this->key = key;
      this->value = value;
      this->left = this->right = nullptr;
    }
    Node(Node* node) {
      this->key = node->key;
      this->value = node->value;
      this->left = node->left;
      this->right = node ->right;
    }
  } 
  Node* root; //根节点
  int count;
  //向node为根的节点插入节点，返回插入新节点后的二叉搜索树的根
  Node* insert(Node* node, Key key, Value value) {
    //递归到底的情况
    if (!node) {
      count++;
      return new Node(key,value);
    }
    if (key == node->key) {
      node->value = value;
    } else if (key < node->key) {
      node->left = insert(node->left, key, value);
    } else {
      node->right = insert(node->right, key ,value);
    }
    return node;
  }

  bool contain(Node* node, Key ,key) {
    if (!node) {
      return false;
    }
    if (key == node -> key) {
      return true;
    } else if (key < node -> key) {
      return contain (node->left, key);
    } else {
      return contain(node->right, key);
    }
  }

  Value* search(Node* node, Key key) {
    if (!node) {
      return nullptr;
    }

    if (key == node->key) {
      return &(node->value);
    } else if (key < node->key) {
      return search(node->left, key);
    } else {
      return search(node->right, key);
    }
  }
  void preOrder(Node* node) {
    if (!node) {
      std::cout << node -> key << std::endl;
      preOrder(node->left);
      preOrder(node->right);
    }
  }
  //中序遍历的是按照大小排列的
  void inOrder(Node* node) {
    if (!node) {
      inOrder(node->left);
      std::cout << node->key << std::endl;
      inOrder(node->right);
    }
  }
  void postOrder(Node* node) {
    if (!node) {
      postOrder(node->left);
      postOrder(node->right);
      std::cout << node->key << std::endl;
    }
  }
  void destroy(Node* node) {
    if (!node) {
      destroy(node->left);
      destroy(node->right);
      delete node;
      count--;
    }
  }
  Node* minimum(Node* node) {
    if (node->left == nullptr) {
      return node;
    }
    return minimum(node->left);
  }
  Node * maximum(Node* node) {
    if (node->right ==nullptr) {
      return node;
    }
    return maximum(node->right);
  } 
  Node* removeMin(Node* node) {
    if (node -> left == nullptr) {
      Node* rightNode = node->right;
      delete node;
      count--;
      return rightNode;
    }
    node->left = removeMin(node->left);
    return node;
  }
  //删除以node为根的二分搜索树的最大节点
  //返回删除节点后新的二分搜索书的根
  Node* removeMax(Node* node) {
    if (node->right == nullptr) {
      Node* leftNode = node->left;
      delete node;
      count--;
      return leftNode;
    }
    
    node->right = removeMax(node->right);
    return node;
  }
  
  
  //删除以node为根的节二分搜索树中键值为key的节点
  //返回删除节点后新的二分搜索树的根
  Node* remove (Node* node, Key key) {
    if (node == nullptr) {
      return nullptr;
    }
    if (key < node->key) {
      node->left = remove(node->left, key);
    } else if (key > node->key) {
      node->right = remove(node->right, key);
    } else { //  key == node->key 
      if (node->left == nullptr) {
        Node* rightNode = node->right;
        delete node;
        count--;
        return rightNode;
      }
      if (node->right == nullptr) {
        Node* leftNode = node->left;
        delete node;
        count--;
        return leftNode;
      }
      //左右孩子都不空

      Node* successor = new Node(minimum(node->right)); //使用Node复制一份要删除的节点
      count++; //增加了一个successor节点
      successor -> right = removeMin(node->right);
      successor -> left = node -> left;

      delete node;
      count --;

      return successor;
    }
  }
 public:
  BST () {
    root = nullptr;
    count = 0;
  }
  ~BST () {
    destroy(root);
  }
  int size() {
    return count;
  }
  bool isEmpty() {
    return count == 0;
  }
  void insert(Key key, Value value) {
    root = insert(root, key ,value);
  }
  bool contain(Key key) {
    return contain(root, key);
  }
  //查找成功就返回指向元素的指针，否则是空指针
  //返回类型可以考虑考虑，为了封装，别返回节点
  Value* search(Key key) {
    return search(root, key);
  }
//广度优先遍历  O(n)
  //前序遍历
  void preOrder() {
    preOreder(root);
  }
  //中序遍历
  void inOrder() {
    inOrder(root);
  }
  //后序遍历
  postOrder() {
    postOrder(root);
  }
  //层序遍历 广度优先 （一般广度优先都会使用到队列的先入先出的特性）
  void levelOrder() {
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
      Node* node = q.front();
      q.pop();
      std::cout << node->value << std::endl;
      if(!node->left) {
        q.push(node->left);
      }
      if (!node->right) {
        q.push(node->right);
      }
    }
  }
  Key minimum() {
    assert(count != 0);
    Node* min_node = minimum(root);
    return min_node->key;
  }
  Key maximum(){
    assert(count != 0);
    Node* max_mum = maximum(root);
    return max_mum ->key;
  }
  void removeMin() {
    if(root) {
      root = removeMin(root);
    }
  }
  void removeMax() {
    if(root) {
      root = removeMax(root);
    }
  }
  void remove( Key key) {
    root = remove(root, key);
  }
};


#endif BINARYSEARCH_H_