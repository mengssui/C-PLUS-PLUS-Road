/*
 * @Descripttion: 只有shared_ptr给另一个share_ptr才会引用计数加一
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-05-06 20:56:27
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-05-06 21:09:42
 */

#include <iostream>
#include <memory>

int main() {

  int * a = new int(121);
  std::shared_ptr<int> ptr1(new int(333));
  std::shared_ptr<int> ptr2(ptr1);
  std::shared_ptr<int> ptr3(a); //相当于又新建了一个智能指针
  // ptr1.reset(new int());
  ptr2.reset(new int());
  std::cout << ptr1.use_count() << std::endl;
  std::cout << ptr2.use_count() << std::endl;
  std::cout << ptr3.use_count() << std::endl;
  std::cout << *ptr1 << std::endl;
  std::cout << *ptr2 << std::endl;
  std::cout << *ptr3 << std::endl;

  return 0;
}