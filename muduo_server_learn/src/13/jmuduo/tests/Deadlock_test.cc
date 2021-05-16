/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-04-21 15:28:50
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-04-21 15:38:49
 */
// 一个在多线程程序里fork造成死锁的例子
// 一个输出示例：
/*

pid = 19445 Entering main ...
pid = 19445 begin doit ...
pid = 19447 begin doit ...
pid = 19445 end doit ...
pid = 19445 Exiting main ...

父进程在创建了一个线程，并对mutex加锁，
父进程创建一个子进程，在子进程中调用doit，由于子进程会复制父进程的内存，这时候mutex处于锁的状态，
父进程在复制子进程的时候，只会复制当前线程的执行状态，其它线程不会复制。因此子进程会处于死锁的状态。
*/
#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <syscall.h>


pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* doit(void* arg)
{
	//获取线程库分配的id,不同进程中由线程库分配的id可以相同
	printf("pid = %u begin doit ...\n",static_cast<int>(pthread_self()));
	pthread_mutex_lock(&mutex);
	struct timespec ts = {2, 0};
	nanosleep(&ts, NULL);
	pthread_mutex_unlock(&mutex);
	//通过系统调用获取真实的tid
	printf("pid = %ul end doit ...\n",static_cast<int>(syscall(SYS_gettid)));

	return NULL;
}

int main(void)
{
	printf("main = %u ...\n",static_cast<int>(syscall(SYS_gettid)));
	printf("pid = %d Entering main ...\n", static_cast<int>(getpid()));
	pthread_t tid;
	pthread_create(&tid, NULL, doit, NULL);
	struct timespec ts = {1, 0};
	nanosleep(&ts, NULL);
	if (fork() == 0)
	{
		//子进程复制了父进程的锁，并且是处于加锁状态的
		//子进程执行doit函数，无法获得锁，因为已经被加锁而且没有解锁的语句
		//子进程没有复制父进程的子线程，仅仅复制父进程的主线程
		//doit(NULL);
	}
	pthread_join(tid, NULL);
	printf("pid = %d Exiting main ...\n",static_cast<int>(getpid()));

	return 0;
}
