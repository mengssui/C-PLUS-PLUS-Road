/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-04-25 17:45:51
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-04-25 17:55:53
 */
#include <muduo/base/Logging.h>
#include <errno.h>
#include <stdio.h>

using namespace muduo;

//全局file
FILE* g_file;

void dummyOutput(const char* msg, int len)
{
	if (g_file)
	{
		fwrite(msg, 1, len, g_file);
	}
}

void dummyFlush()
{
	fflush(g_file);
}

int main()
{
	//日志输出至文件，根目录下的tmp文件夹中的muduo_log文件
	g_file = ::fopen("/tmp/muduo_log", "ae"); //e表示exec函数时候不继承 
	Logger::setOutput(dummyOutput);
	Logger::setFlush(dummyFlush);

	LOG_TRACE<<"trace ...";
	LOG_DEBUG<<"debug ...";
	LOG_INFO<<"info ...";
	LOG_WARN<<"warn ...";
	LOG_ERROR<<"error ...";
	//LOG_FATAL<<"fatal ...";
	errno = 13;
	LOG_SYSERR<<"syserr ...";
	//LOG_SYSFATAL<<"sysfatal ...";

	::fclose(g_file);

	return 0;
}
