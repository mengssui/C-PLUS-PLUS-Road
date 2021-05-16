/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-04-24 22:24:04
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-04-24 22:25:26
 */
#include <muduo/base/ThreadPool.h>
#include <muduo/base/CountDownLatch.h>
#include <muduo/base/CurrentThread.h>

#include <boost/bind.hpp>
#include <stdio.h>

void print()
{
  printf("tid=%d\n", muduo::CurrentThread::tid());
}

void printString(const std::string& str)
{
  printf("tid=%d tid=%lu, str=%s\n", muduo::CurrentThread::tid(), pthread_self(), str.c_str());
}

int main()
{
  muduo::ThreadPool pool("MainThreadPool");
  pool.start(5);

  pool.run(print);
  pool.run(print);
  for (int i = 0; i < 100; ++i)
  {
    char buf[32];
    snprintf(buf, sizeof buf, "task %d", i);
    pool.run(boost::bind(printString, std::string(buf)));
  }

  muduo::CountDownLatch latch(1);
  pool.run(boost::bind(&muduo::CountDownLatch::countDown, &latch));
  latch.wait();
  pool.stop();
}

