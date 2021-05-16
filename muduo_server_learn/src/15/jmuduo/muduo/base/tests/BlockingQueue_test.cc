/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-04-22 20:55:42
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-04-22 20:55:43
 */
#include <muduo/base/BlockingQueue.h>
#include <muduo/base/CountDownLatch.h>
#include <muduo/base/Thread.h>

#include <boost/bind.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include <string>
#include <stdio.h>

class Test
{
 public:
  Test(int numThreads)
    : latch_(numThreads),
      threads_(numThreads)
  {
    //创建numThreads个线程
    for (int i = 0; i < numThreads; ++i)
    {
      char name[32];
      snprintf(name, sizeof name, "work thread %d", i);
      //线程加入到线程队列，每个线程有对应的执行函数及其名字
      threads_.push_back(new muduo::Thread(
            boost::bind(&Test::threadFunc, this), muduo::string(name)));
    }
    //TODO:  了解for_each
    for_each(threads_.begin(), threads_.end(), boost::bind(&muduo::Thread::start, _1));
  }

  //加入times个产品
  void run(int times)
  {
    printf("waiting for count down latch\n");
    latch_.wait(); //count_ 大于0就阻塞 
    printf("all threads started\n");
    //加入times个产品
    for (int i = 0; i < times; ++i)
    {
      char buf[32];
      snprintf(buf, sizeof buf, "hello %d", i);
      queue_.put(buf);
      printf("tid=%d, put data = %s, size = %zd\n", muduo::CurrentThread::tid(), buf, queue_.size());
    }
  }

  void joinAll()
  {
    //加入线程个数个stop任务
    for (size_t i = 0; i < threads_.size(); ++i)
    {
      queue_.put("stop");
    }

    //相当于把this对象传入给join
    for_each(threads_.begin(), threads_.end(), boost::bind(&muduo::Thread::join, _1));
  }

 private:

  void threadFunc()
  {
    printf("tid=%d, %s started\n",
           muduo::CurrentThread::tid(),
           muduo::CurrentThread::name());

    latch_.countDown();
    bool running = true;
    while (running)
    {
      std::string d(queue_.take());
      printf("tid=%d, get data = %s, size = %zd\n", muduo::CurrentThread::tid(), d.c_str(), queue_.size());
      running = (d != "stop");
    }

    printf("tid=%d, %s stopped\n",
           muduo::CurrentThread::tid(),
           muduo::CurrentThread::name());
  }

  muduo::BlockingQueue<std::string> queue_;
  muduo::CountDownLatch latch_;
  boost::ptr_vector<muduo::Thread> threads_;
};

int main()
{
  printf("pid=%d, tid=%d\n", ::getpid(), muduo::CurrentThread::tid());
  Test t(5);
  t.run(100);
  t.joinAll();

  printf("number of created threads %d\n", muduo::Thread::numCreated());
}
