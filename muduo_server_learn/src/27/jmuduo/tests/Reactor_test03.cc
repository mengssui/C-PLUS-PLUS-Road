/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-04-28 22:38:47
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-04-28 22:38:47
 */
#include <muduo/net/Channel.h>
#include <muduo/net/EventLoop.h>

#include <boost/bind.hpp>

#include <stdio.h>
#include <sys/timerfd.h>

using namespace muduo;
using namespace muduo::net;

EventLoop* g_loop;
int timerfd;

void timeout(Timestamp receiveTime)
{
	printf("Timeout!\n");
	uint64_t howmany;
	::read(timerfd, &howmany, sizeof howmany); //必须读取走，否则会不断触发，LT方式
	g_loop->quit();
}

int main(void)
{
	EventLoop loop;
	g_loop = &loop;

	timerfd = ::timerfd_create(CLOCK_MONOTONIC, TFD_NONBLOCK | TFD_CLOEXEC); //像文件一样
	Channel channel(&loop, timerfd);
	channel.setReadCallback(boost::bind(timeout, _1));
	channel.enableReading(); //相当于监听其可读事件的发生

	struct itimerspec howlong;
	bzero(&howlong, sizeof howlong);
	howlong.it_value.tv_sec = 1;
	::timerfd_settime(timerfd, 0, &howlong, NULL);

	loop.loop();

	::close(timerfd);
}



