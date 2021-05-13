/*
 * @Descripttion: 我的智能指针
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-05-01 18:24:27
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-05-01 20:15:48
 */
#include <iostream>
#include <memory>

namespace mengbw {

class Use_count {
public:
  Use_count() : cnt_(1) {}
  void add_cnt_() { cnt_++; }
  int sub_cnt_() { --cnt_; }
  int get_cnt_() { return cnt_; }
  ~Use_count() {}
private:
  int cnt_;
};

template<typename T>
class smart_ptr {
public:
  smart_ptr(T *ptr);
  ~smart_ptr();
  smart_ptr(smart_ptr &rhs);
  smart_ptr(smart_ptr &&rhs);
  smart_ptr& operator=(smart_ptr rhs);

  T* get() const { return ptr_; }
  T& operator*() const { return *ptr_; }
  T* operator->() const { return ptr_; }
  void swap(smart_ptr &rhs);
  int use_count() const { return ptr_ ? count_->get_cnt_() : 0; }


private:

  T *ptr_;
  Use_count* count_;
};

//ctor
template<typename T>
smart_ptr<T>::smart_ptr(T *ptr = nullptr) : ptr_(ptr) {
  if (ptr_ != nullptr) {
    count_ = new Use_count();
  }
}

//copy ctor
template<typename T>
smart_ptr<T>::smart_ptr(smart_ptr &rhs) {
  ptr_ = rhs.ptr_;
  if (ptr_) {
    rhs.count_->add_cnt_();
    count_ = rhs.count_;
  }
}

//move ctor
template<typename T>
smart_ptr<T>::smart_ptr(smart_ptr &&rhs) {
  rhs.swap(*this);
  rhs.ptr_ = nullptr;
}


template<typename T>
smart_ptr<T>& smart_ptr<T>::operator=(smart_ptr rhs) {
  rhs.swap(*this);
  return *this;
}

template<typename T>
void smart_ptr<T>::swap(smart_ptr &rhs) {
  using std::swap;
  swap(ptr_, rhs.ptr_);
  swap(count_, rhs.count_);
  return;
}

//dtor
template<typename T>
smart_ptr<T>::~smart_ptr() {
  if (ptr_ && count_->sub_cnt_() == 0) {
    delete ptr_;
    delete count_;
  }
}

} //end of mengbw


int main () {
  int *a = new int(23);
  std::shared_ptr<int> p1(a);
  std::shared_ptr<int> p2(std::move(p1));
  std::cout <<*p2 << std::endl;
  std::cout << p2.use_count() << std::endl;

  mengbw::smart_ptr<int> m1(new int(3));
  mengbw::smart_ptr<int> m2(std::move(m1));
  std::cout << *m2 << std::endl;
  std::cout << m2.use_count() << std::endl;

  return 0;
}

