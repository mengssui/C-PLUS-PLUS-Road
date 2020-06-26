//Copyright
//License
//Author：Mengbw_
//2020年6月19日
//This is an exercise in the book  No.12.1.1
//创建用来管理string的类StrBlob
//不能再Blob对象内直接保存vector，因为对象成员再对象被销毁的时也会被销毁，例如，假定
//b1和b2时两个Blob对象指向相同的vector，如果vector保存在其中一个Blob中的b2，当b2离
//开作用域的时候，vector也被销毁，为了保证vector继续存在，我们将vector保存在动态内存中

#ifndef STRBLOB_H_
#define STRBLOB_H_
#include <vector>
#include <memory>
#include <string>
#include <cassert>
#include <stdexcept>

using namespace std;
class StrBlob {
 public:
  typedef vector<string>::size_type size_type;
  StrBlob(); //默认构造函数
  StrBlob(initializer_list<string> ili); //接收初始化器的花括号列表
  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }
  //添加和删除元素
  void push_back(const string &t) { data->push_back(t); }
  void pop_back();
  //元素访问
  string &front();
  string &back();
 private:
  shared_ptr<vector<string>> data;
  //检查，如果data[i]不合法，则抛出异常
  void check(size_type i, const string &msg) const;
};
//构造函数
StrBlob::StrBlob() 
    : data(make_shared<vector<string>>()) { }
StrBlob::StrBlob(initializer_list<string> il)
    : data(make_shared<vector<string>>(il)) { }
//元素访问成员函数
//操作前检查元素是否存在
void StrBlob::check(size_type i, const string &msg) const {
    if (i  >= data->size()) {
        throw out_of_range(msg);
    }
}

#endif //STRBLOB_H_