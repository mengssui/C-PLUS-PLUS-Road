/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-04-21 15:57:57
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-04-21 15:57:58
 */
#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* doit(void* arg)
{
	printf("pid = %d begin doit ...\n",static_cast<int>(getpid()));
	pthread_mutex_lock(&mutex);
	struct timespec ts = {2, 0};
	nanosleep(&ts, NULL);
	pthread_mutex_unlock(&mutex);
	printf("pid = %d end doit ...\n",static_cast<int>(getpid()));

	return NULL;
}

void prepare(void)
{
	pthread_mutex_unlock(&mutex);
}

void parent(void)
{
	pthread_mutex_lock(&mutex);
}

int main(void)
{
	//设置调用fork前后开锁和加锁使得子进程不产生死锁
	pthread_atfork(prepare, parent, NULL);
	printf("pid = %d Entering main ...\n", static_cast<int>(getpid()));
	pthread_t tid;
	pthread_create(&tid, NULL, doit, NULL);
	struct timespec ts = {1, 0};
	nanosleep(&ts, NULL);
	//调用fork之前解锁，这样拷贝的子进程锁是打开的
	//fork后主进程再加锁，从而使doit中的加锁后的解锁操作仍旧有效
	if (fork() == 0)
	{
		doit(NULL);
	}
	pthread_join(tid, NULL);
	printf("pid = %d Exiting main ...\n",static_cast<int>(getpid()));

	return 0;
}
