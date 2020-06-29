// Author：Mengbw_
// 2020年6月29日

//二叉堆需要是完全二叉树
//使用数组存储二叉堆，左孩子序号是它的二倍，右孩子二倍加1
//序号从1开始不是0
//有索引就要考虑索引越界的问题
//堆排序中需要用到的堆的定义
//二叉堆综述除以二就是最大的非叶子节点



#ifndef HEAP_H_
#define HEAP_H_

#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;

template <typename Item>
class MaxHeap {
 public:
  MaxHeap(int capacity) {
    data = new Item[capacity + 1];  //开辟内存空间
    count = 0;
    this->capacity = capacity;
  }
  MaxHeap(Item arr[], int n) {
    data = new Item[n + 1];
    capacity = n;
    for (int i = 0; i < n; i++) {
      data[i+1] = arr[i];
    }
    count = n; 
    for( int i = count / 2; i >= 1; i--) { //找到最大下标的非叶子节点然后进行shiftdown来获得最大堆 
      shiftDown(i);
    }
  }
  ~MaxHeap() { delete[] data; }
  int size() { return count; }
  int gcapacity() { return capacity; }
  bool isEmpty() { return count == 0; }
  void insert(Item item) {
    assert(count + 1 <= capacity);
    data[count + 1] = item;  //数组越界问题
    count++;
    shiftUp(count);
  }
  Item extractMax() {
    assert(count > 0);
    Item ret = data[1];
    swap(data[1], data[count]);
    count--;
    shiftDown(1);  //向下移动
    return ret;
  }

  /**
   * 打印成树状信息
   * 以树状打印整个堆结构
   * https://github.com/liuyubobobo/Play-with-Algorithms/blob/master/04-Heap/Course%20Code%20(C%2B%2B)/03-Shift-Up/main.cpp
   * */
  void testPrint() {
    // 我们的testPrint只能打印100个元素以内的堆的树状信息
    if (size() >= 100) {
      cout << "This print function can only work for less than 100 int";
      return;
    }
    // 我们的testPrint只能处理整数信息
    if (typeid(Item) != typeid(int)) {
      cout << "This print function can only work for int item";
      return;
    }

    cout << "The max heap size is: " << size() << endl;
    cout << "Data in the max heap: ";
    for (int i = 1; i <= size(); i++) {
      // 我们的testPrint要求堆中的所有整数在[0, 100)的范围内
      assert(data[i] >= 0 && data[i] < 100);
      cout << data[i] << " ";
    }
    cout << endl;
    cout << endl;

    int n = size();
    int max_level = 0;
    int number_per_level = 1;
    while (n > 0) {
      max_level += 1;
      n -= number_per_level;
      number_per_level *= 2;
    }

    int max_level_number = int(pow(2, max_level - 1));
    int cur_tree_max_level_number = max_level_number;
    int index = 1;
    for (int level = 0; level < max_level; level++) {
      string line1 = string(max_level_number * 3 - 1, ' ');

      int cur_level_number =
          min(count - int(pow(2, level)) + 1, int(pow(2, level)));
      bool isLeft = true;
      for (int index_cur_level = 0; index_cur_level < cur_level_number;
           index++, index_cur_level++) {
        putNumberInLine(data[index], line1, index_cur_level,
                        cur_tree_max_level_number * 3 - 1, isLeft);
        isLeft = !isLeft;
      }
      cout << line1 << endl;

      if (level == max_level - 1) break;

      string line2 = string(max_level_number * 3 - 1, ' ');
      for (int index_cur_level = 0; index_cur_level < cur_level_number;
           index_cur_level++)
        putBranchInLine(line2, index_cur_level,
                        cur_tree_max_level_number * 3 - 1);
      cout << line2 << endl;

      cur_tree_max_level_number /= 2;
    }
  }
  void putBranchInLine(string& line, int index_cur_level, int cur_tree_width) {
    int sub_tree_width = (cur_tree_width - 1) / 2;
    int sub_sub_tree_width = (sub_tree_width - 1) / 2;
    int offset_left =
        index_cur_level * (cur_tree_width + 1) + sub_sub_tree_width;
    assert(offset_left + 1 < line.size());
    int offset_right = index_cur_level * (cur_tree_width + 1) + sub_tree_width +
                       1 + sub_sub_tree_width;
    assert(offset_right < line.size());

    line[offset_left + 1] = '/';
    line[offset_right + 0] = '\\';
  }
  void putNumberInLine(int num, string& line, int index_cur_level,
                       int cur_tree_width, bool isLeft) {
    int sub_tree_width = (cur_tree_width - 1) / 2;
    int offset = index_cur_level * (cur_tree_width + 1) + sub_tree_width;
    assert(offset + 1 < line.size());
    if (num >= 10) {
      line[offset + 0] = '0' + num / 10;
      line[offset + 1] = '0' + num % 10;
    } else {
      if (isLeft) {
        line[offset + 0] = '0' + num;
      } else {
        line[offset + 1] = '0' + num;
      }
    }
  }

 private:
  Item* data;
  int count;
  int capacity;
  void shiftUp(int k) {
    while (k > 1 && data[k / 2] < data[k]) {
      swap(data[k / 2], data[k]);
      k /= 2;
    }
  }
  void shiftDown(int k) {
    while (2 * k <= count) {
      int j = 2 * k;    //j 和 k交换位置
      if (j + 1 <= count && data[j] < data[j + 1]) {
        j += 1;
      }
      if (data[k] >= data[j]) {
        break;
      }
      swap(data[k],data[j]);   //对于具有交换的可以想办法能否优化为先找位置在赋值
      k = j;
    }
  }
};

  // int main() {
  //   Maxheap<int> maxHeap(100);
  //   cout << maxHeap.size() << endl;
  //   cout << maxHeap.gcapacity() << endl;
  //   srand(time(NULL));
  //   for (int i = 0; i < 25; i++) {
  //     maxHeap.insert(rand() % 100);
  //   }
  //   for (int i = 0; i < 10; i++) {
  //     cout << maxHeap.extractMax() << " ";
  //   }
  //   cout << endl;
  //   maxHeap.testPrint();
  //   return 0;
  // }

  #endif //HEAP_H_