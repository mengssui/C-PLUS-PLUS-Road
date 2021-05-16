/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-04-28 16:38:23
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-04-28 16:38:24
 */
// Copyright 2010, Shuo Chen.  All rights reserved.
// http://code.google.com/p/muduo/
//
// Use of this source code is governed by a BSD-style license
// that can be found in the License file.

// Author: Shuo Chen (chenshuo at chenshuo dot com)
//
// This is a public header file, it must only include public header files.

#ifndef MUDUO_NET_EVENTLOOP_H
#define MUDUO_NET_EVENTLOOP_H

#include <boost/noncopyable.hpp>

#include <muduo/base/CurrentThread.h>
#include <muduo/base/Thread.h>

namespace muduo
{
namespace net
{

///
/// Reactor, at most one per thread.
///
/// This is an interface class, so don't expose too much details.
//一个线程最多只能由一个EventLoop对象
class EventLoop : boost::noncopyable
{
 public:
  EventLoop();
  ~EventLoop();  // force out-line dtor, for scoped_ptr members.

  ///
  /// Loops forever.
  ///
  /// Must be called in the same thread as creation of the object.
  ///
  void loop();

  void assertInLoopThread()
  {
    if (!isInLoopThread())
    {
      abortNotInLoopThread();
    }
  }
  //是否运行在loop线程
  bool isInLoopThread() const { return threadId_ == CurrentThread::tid(); }

  static EventLoop* getEventLoopOfCurrentThread();

 private:
  void abortNotInLoopThread();
  
  bool looping_; /* atomic */
  const pid_t threadId_;		// 当前对象所属线程ID
};

}
}
#endif  // MUDUO_NET_EVENTLOOP_H
