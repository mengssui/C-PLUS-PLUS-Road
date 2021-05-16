// Use of this source code is governed by a BSD-style license
// that can be found in the License file.
//
// Author: Shuo Chen (chenshuo at chenshuo dot com)
#include <muduo/base/ThreadPool.h>
#include <muduo/base/Exception.h>
#include <boost/bind.hpp>
#include <assert.h>
#include <stdio.h>
using namespace muduo;

ThreadPool::ThreadPool(const string& name)
  : mutex_(),
    cond_(mutex_),
    name_(name),
    running_(false)
{
}

ThreadPool::~ThreadPool()
{
  if (running_)
  {
    stop();
  }
}

//开启n个线程，对于每个线程开始执行
void ThreadPool::start(int numThreads)
{
  assert(threads_.empty());
  running_ = true;
  threads_.reserve(numThreads);
  for (int i = 0; i < numThreads; ++i)
  {
    char id[32];
    snprintf(id, sizeof id, "%d", i);
    threads_.push_back(new muduo::Thread(
          boost::bind(&ThreadPool::runInThread, this), name_+id));
    threads_[i].start();
  }
}

void ThreadPool::stop()
{
  {
  MutexLockGuard lock(mutex_);
  running_ = false;
  cond_.notifyAll();
  }
  for_each(threads_.begin(),
           threads_.end(),
           boost::bind(&muduo::Thread::join, _1)); //传入了this指针
}

//添加一个任务加入到队列中并且唤醒一个线程来执行，或者直接在本线程执行
void ThreadPool::run(const Task& task)
{
  if (threads_.empty())
  {
    task();
  }
  else
  {
    MutexLockGuard lock(mutex_);
    queue_.push_back(task);
    cond_.notify();
  }
}

ThreadPool::Task ThreadPool::take()
{
  MutexLockGuard lock(mutex_);
  // always use a while-loop, due to spurious wakeup
  //如果任务队列空，并且在运行中，则阻塞
  while (queue_.empty() && running_)
  {
    cond_.wait();
  }
  Task task;
  //如果队列有任务, 就取任务执行
  if(!queue_.empty())
  {
    task = queue_.front();
    queue_.pop_front();
  }
  return task;
}

//每个线程一个loop，不断的获取队列任务然后执行
void ThreadPool::runInThread()
{
  try
  {
    while (running_)
    {
      //取任务,函数调用对象初始化，类似int(1)这种
      Task task(take());
      //如果有任务就执行
      if (task)
      {
        task();
      }
    }
  }
  catch (const Exception& ex)
  {
    fprintf(stderr, "exception caught in ThreadPool %s\n", name_.c_str());
    fprintf(stderr, "reason: %s\n", ex.what());
    fprintf(stderr, "stack trace: %s\n", ex.stackTrace());
    abort();
  }
  catch (const std::exception& ex)
  {
    fprintf(stderr, "exception caught in ThreadPool %s\n", name_.c_str());
    fprintf(stderr, "reason: %s\n", ex.what());
    abort();
  }
  catch (...)
  {
    fprintf(stderr, "unknown exception caught in ThreadPool %s\n", name_.c_str());
    throw; // rethrow
  }
}

