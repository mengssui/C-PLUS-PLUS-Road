/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-05-10 15:52:52
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-05-10 15:52:53
 */
#include "echo.h"

#include <muduo/base/Logging.h>
#include <muduo/net/EventLoop.h>

using namespace muduo;
using namespace muduo::net;

int main(int argc, char* argv[])
{
  LOG_INFO << "pid = " << getpid();
  EventLoop loop;
  InetAddress listenAddr(2007);
  int maxConnections = 3;
  if (argc > 1)
  {
    maxConnections = atoi(argv[1]);
  }
  LOG_INFO << "maxConnections = " << maxConnections;
  EchoServer server(&loop, listenAddr, maxConnections);
  server.start();
  loop.loop();
}

