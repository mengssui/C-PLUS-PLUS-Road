#include <pthread.h>

class Thread {
public:
  Thread();
  virtual ~Thread();
  virtual void Run() = 0;
  void Start();
  void Join();
private:
  pthread_t thread_id_;
  static void *StartRoute(void *arg);
};

Thread::Thread() {}
Thread::~Thread() {}
void Thread::Start() {
  //这里面调用的普通的函数，因此StartRoute不能是成员函数，因为成员函数具有一个this指针，
  //会有一个寄存器存储这个this指针,可以把StartRoute作为全局函数，也可以使用类方法
  pthread_create(&thread_id_, NULL, &StartRoute, this);
}

