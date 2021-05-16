/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-04-21 16:36:31
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-04-21 20:58:45
 */
// Use of this source code is governed by a BSD-style license
// that can be found in the License file.
//
// Author: Shuo Chen (chenshuo at chenshuo dot com)

#ifndef MUDUO_BASE_MUTEX_H
#define MUDUO_BASE_MUTEX_H

#include <muduo/base/CurrentThread.h>
#include <boost/noncopyable.hpp>
#include <assert.h>
#include <pthread.h>

namespace muduo
{

class MutexLock : boost::noncopyable
{
 public:
  MutexLock()
    : holder_(0)
  {
    int ret = pthread_mutex_init(&mutex_, NULL);
    assert(ret == 0); (void) ret;
  }

  ~MutexLock()
  {
    assert(holder_ == 0);
    int ret = pthread_mutex_destroy(&mutex_);
    assert(ret == 0); (void) ret;
  }

  bool isLockedByThisThread()
  {
    return holder_ == CurrentThread::tid();
  }

  void assertLocked()
  {
    assert(isLockedByThisThread());
  }

  // internal usage

  void lock()
  {
    pthread_mutex_lock(&mutex_);
    holder_ = CurrentThread::tid();
  }

  void unlock()
  {
    holder_ = 0;
    pthread_mutex_unlock(&mutex_);
  }

  pthread_mutex_t* getPthreadMutex() /* non-const */
  {
    return &mutex_;
  }

 private:

  pthread_mutex_t mutex_;
  pid_t holder_;
};

//类对象，析构时候自动解锁，就不用再手动进行解锁了！妙！
class MutexLockGuard : boost::noncopyable
{
 public:
  explicit MutexLockGuard(MutexLock& mutex)
    : mutex_(mutex)
  {
    mutex_.lock();
  }

  ~MutexLockGuard()
  {
    mutex_.unlock();
  }

 private:

  MutexLock& mutex_; //关联,并不管理mutex 的生存期，只是一个引用
};

}

// Prevent misuse like:
// MutexLockGuard(mutex_);
// A tempory object doesn't hold the lock for long!
#define MutexLockGuard(x) error "Missing guard object name"

#endif  // MUDUO_BASE_MUTEX_H
