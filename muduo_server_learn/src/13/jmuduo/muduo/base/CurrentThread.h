// Use of this source code is governed by a BSD-style license
// that can be found in the License file.
//
// Author: Shuo Chen (chenshuo at chenshuo dot com)

#ifndef MUDUO_BASE_CURRENTTHREAD_H
#define MUDUO_BASE_CURRENTTHREAD_H

namespace muduo
{
namespace CurrentThread
{
  // internal
  extern __thread int t_cachedTid; //线程tid的缓存，防止每次都要去调用，提高效率
  extern __thread char t_tidString[32]; //线程tid字符串表示形式
  extern __thread const char* t_threadName;
  void cacheTid();

  inline int tid()
  {
    if (t_cachedTid == 0) //如果没有缓存过
    {
      cacheTid();
    }
    return t_cachedTid;
  }

  inline const char* tidString() // for logging
  {
    return t_tidString;
  }

  inline const char* name()
  {
    return t_threadName;
  }

  bool isMainThread();
}
}

#endif
