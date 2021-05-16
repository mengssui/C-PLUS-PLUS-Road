/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-04-25 15:56:00
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-04-25 15:56:00
 */
// Use of this source code is governed by a BSD-style license
// that can be found in the License file.
//
// Author: Shuo Chen (chenshuo at chenshuo dot com)

#ifndef MUDUO_BASE_THREADLOCALSINGLETON_H
#define MUDUO_BASE_THREADLOCALSINGLETON_H

#include <boost/noncopyable.hpp>
#include <assert.h>
#include <pthread.h>

namespace muduo
{

template<typename T>
class ThreadLocalSingleton : boost::noncopyable
{
 public:

  static T& instance()
  {
    //不用双重检查锁，因为每个线程都有一份t_value
    if (!t_value_)
    {
      t_value_ = new T();
      deleter_.set(t_value_);
    }
    return *t_value_;
  }

  static T* pointer()
  {
    return t_value_;
  }

 private:

  static void destructor(void* obj)
  {
    assert(obj == t_value_);
    typedef char T_must_be_complete_type[sizeof(T) == 0 ? -1 : 1];
    delete t_value_;
    t_value_ = 0;
  }

  //主要是用于回调destructor函数，使得自动销毁
  class Deleter
  {
   public:
    Deleter()
    {
      pthread_key_create(&pkey_, &ThreadLocalSingleton::destructor);
    }

    ~Deleter()
    {
      pthread_key_delete(pkey_);
    }

    void set(T* newObj)
    {
      assert(pthread_getspecific(pkey_) == NULL);
      pthread_setspecific(pkey_, newObj);
    }

    pthread_key_t pkey_;
  };

  //每个线程都有一份的T类对象的指针
  static __thread T* t_value_;
  static Deleter deleter_; //用于销毁t_value_指向的对象
};

template<typename T>
__thread T* ThreadLocalSingleton<T>::t_value_ = 0;

template<typename T>
typename ThreadLocalSingleton<T>::Deleter ThreadLocalSingleton<T>::deleter_;

}
#endif
