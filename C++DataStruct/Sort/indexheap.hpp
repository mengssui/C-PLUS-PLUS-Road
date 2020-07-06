/*索引堆*/
//为了防止数据类型复杂进行交换操作时很复杂
//为每一个数据指定一个索引号
//构建最大堆的过程只是改变索引，而不改变内容
//寻找索引堆内容的时候用其索引号来寻找

//比较时候使用数据,而交换时候只交换索引
/*
如下所示索引堆
***************************************
    0  1  2  3  4  5  6  7  8  9  10
index  1  2  3  4  5  6  7  8  9  10
 data  13 32 43 56 23 70 30 56 87 33
  rev   
***************************************
  rev[i]表示表示索引i在indexes中的位置
  indexes[i] = j
  rev[i] = i
  indexes[rev[i]] = i
  rev[indexex[i]] = i


*/

#ifndef INDEXHEAP_H_
#define INDEXHEAP_H_

#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;

template <typename Item>
class IndexMaxHeap {
 public:
  IndexMaxHeap(int capacity) {
    data = new Item[capacity + 1];  //开辟内存空间
    indexes = new int[capacity + 1];
    reverse = new int[capacity + 1];
    for (int i = 0; i <= capacity; i++) {
      reverse[i] = 0; //为0表示不存在
    }
    count = 0;
    this->capacity = capacity;
  }
  IndexMaxHeap(Item arr[], int n) {
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
  ~IndexMaxHeap() { 
    delete[] data; 
    delete[] indexes;
    delete[] reverse;
    }
  int size() { return count; }
  int gcapacity() { return capacity; }
  bool isEmpty() { return count == 0; }

  //传入的i是面项用户的，通常是从0索引的
  void insert(int i, item item) {
    assert(count + 1 <= capacity);
    assert(i + 1 >= 1 &&; i + 1 <= capacity)

    i += 1;//变成从1开始索引
    data[i] = item;
    indexes[count + 1] = i;  //数组越界问题
    reverse[i] = count + 1;
    count++;
    shiftUp(count);
  }
  Item extractMaxIndex() {
    assert(count > 0);
    int ret = index[1] - 1;
    swap(indexes[1], indexes[count]);
    reverse[indexes[1]] = 1;
    reverse[indexes[count]] = 0;//删除了元素就置0
    count--;
    shiftDown(1);  //向下移动
    return ret;
  }
  bool contain(int i) {
    assert(i +1 >=1 && i + 1 <= capacity);
    return reverse[i+1] != 0;
  }


  //给定索引返回值
  Item getItem(int i) {
    assert(contain(i));
    return data[i + 1];
  }

  void change(int i, Item new_item) {
    assert(contain(i));
    i += 1;
    data[i] = new_item;

    //找到indexes[j] ==i j表示data[i]在堆中的位置
    //找到indexes中指向data[i]的 位置 比较耗时O(n)
    /*耗时O(n)
    for (int j = 1; j <= count; j++) {
      if (indexes[j] == i) {
        shiftUp(j);
        shiftDown(j);
      }
    }
    */
    int j = reverse[i];
    shiftUp(j);
    shiftDown(j);
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
  int* indexes;
  int* reverse;
  int count;
  int capacity;
  void shiftUp(int k) {
    while (k > 1 && data[indexes[k / 2]] < data[indexes[k]]) {
      swap(indexes[k / 2], indexes[k]);
      reverse[indexes[k / 2]] = k / 2;
      reverse[indexes[k]] = k;
      k /= 2;
    }
  }
  void shiftDown(int k) {
    while (2 * k <= count) {
      int j = 2 * k;    //j 和 k交换位置
      if (j + 1 <= count && data[indexes[j]] < data[indexes[j + 1]]) {
        j += 1;
      }
      if (data[indexes[k]] >= data[indexes[j]]) {
        break;
      }
      swap(indexes[k],indexes[j]);   //对于具有交换的可以想办法能否优化为先找位置在赋值
      reverse[indexes[k]] = k;
      reverse[indexes[j]] = j;
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

  #endif //INDEXHEAP_H_