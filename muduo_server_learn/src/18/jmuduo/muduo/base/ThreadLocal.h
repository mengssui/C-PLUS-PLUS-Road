/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-04-25 14:57:42
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-04-25 15:06:18
 */
/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-04-25 14:57:41
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-04-25 14:57:42
 */
// Use of this source code is governed by a BSD-style license
// that can be found in the License file.
//
// Author: Shuo Chen (chenshuo at chenshuo dot com)

#ifndef MUDUO_BASE_THREADLOCAL_H
#define MUDUO_BASE_THREADLOCAL_H

#include <boost/noncopyable.hpp>
#include <pthread.h>

namespace muduo
{

template<typename T>
class ThreadLocal : boost::noncopyable
{
 public:
  ThreadLocal()
  {
    //创建key和以及指定销毁数据的函数
    pthread_key_create(&pkey_, &ThreadLocal::destructor);
  }

  ~ThreadLocal()
  {
    //仅销毁key
    pthread_key_delete(pkey_);
  }

//获取数据或创建数据
  T& value()
  {
    T* perThreadValue = static_cast<T*>(pthread_getspecific(pkey_));
    if (!perThreadValue) {
      T* newObj = new T();
      pthread_setspecific(pkey_, newObj);
      perThreadValue = newObj;
    }
    return *perThreadValue;
  }

 private:

  static void destructor(void *x)
  {
    T* obj = static_cast<T*>(x);
    //必须是完整类型，否则在编译时候出错
    typedef char T_must_be_complete_type[sizeof(T) == 0 ? -1 : 1];
    delete obj;
  }

 private:
  pthread_key_t pkey_;
};

}
#endif
