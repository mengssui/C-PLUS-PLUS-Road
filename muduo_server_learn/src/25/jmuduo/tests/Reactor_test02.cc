/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-04-28 16:55:20
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-04-28 16:55:21
 */
#include <muduo/net/EventLoop.h>

#include <stdio.h>

using namespace muduo;
using namespace muduo::net;

EventLoop* g_loop;

void threadFunc()
{
	//终止，因为event是每个线程拥有一份的
	g_loop->loop();
}

int main(void)
{
	EventLoop loop;
	g_loop = &loop;
	Thread t(threadFunc);
	t.start();
	t.join();
	return 0;
}

