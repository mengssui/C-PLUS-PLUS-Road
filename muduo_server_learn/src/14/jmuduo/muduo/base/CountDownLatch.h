/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-04-21 21:13:40
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-04-21 21:13:41
 */
// Use of this source code is governed by a BSD-style license
// that can be found in the License file.
//
// Author: Shuo Chen (chenshuo at chenshuo dot com)

#ifndef MUDUO_BASE_COUNTDOWNLATCH_H
#define MUDUO_BASE_COUNTDOWNLATCH_H

#include <muduo/base/Condition.h>
#include <muduo/base/Mutex.h>

#include <boost/noncopyable.hpp>

namespace muduo
{

class CountDownLatch : boost::noncopyable
{
 public:

  explicit CountDownLatch(int count);

  void wait();

  void countDown();

  int getCount() const;

 private:
  mutable MutexLock mutex_; //可以被const函数修改
  Condition condition_;
  int count_;
};

}
#endif  // MUDUO_BASE_COUNTDOWNLATCH_H
