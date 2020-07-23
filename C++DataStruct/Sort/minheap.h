#ifndef MINHEAP_H_
#define MINHEAP_H_

#include <cassert>
#include "../Graphtheory/graphwithweight/edge.h"

using namespace std;

template <typename Item>
class MinHeap {
 private:
  int capacity_;
  int count_;
  Item* data_;
  void shiftUp(int k) {
    while (k > 1 && data_[k / 2] > data_[k]) {
      swap(data_[k], data_[k / 2]);
      k /= 2;
    }
  }
  void shiftDown(int j) {
    while (2 * j <= count_) {
      int k = 2 * j;
      if (k + 1 <= count_ && data_[k] > data_[k + 1]) {
        k++;
      }
      if (data_[j] <= data_[k]) break;
      swap(data_[k], data_[j]);
      j = k;
    }
  }

 public:
  MinHeap(int capacity) {
    data_ = new Item[capacity + 1];  //从下标1开始存储因此，需要多开辟一个空间
    count_ = 0;
    capacity_ = capacity;
  }
  MinHeap(Item arr[], int n) {
    data_ = new Item[n + 1];
    capacity_ = n;
    for( int i = 0; i < n; i++) {
      data_[i+1] = arr[i];
    }
    count_ = n;
    for(int i = count_/2; i >= 1; i--) {
      shiftDown(i);
    }

  }
  ~MinHeap() { delete[] data_; }
  int size() { return count_; }
  int capacity() { return capacity_; }
  bool isEmpty() { return count_ == 0; }

  void insert(Item item) {
    assert(count_ + 1 <= capacity_);
    count_++;
    data_[count_] = item;
    shiftUp(count_);
  }

  Item extractMin() {
    assert(count_ > 0);
    Item ret = data_[1];
    swap(data_[1], data_[count_]);
    count_--;
    shiftDown(1);
    return ret;
  }
  Item getMin() {
    assert(count_ > 0);
    return data_[1];
  }
  void show() {
    cout << "|";
    for (int i = 1; i <= count_; i++) {
      cout << data_[i]->wt() /*<<","<<data_[i]*/ << "|";
    }
    cout << endl;
  }
};

#endif  // MINHEAP_H_