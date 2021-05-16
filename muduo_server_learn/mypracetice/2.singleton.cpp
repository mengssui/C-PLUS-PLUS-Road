/*
 * @Descripttion:  学习使用单例模式
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-04-23 16:38:27
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-04-24 19:29:04
*/

#include <iostream>
#include <pthread.h>

class Singleton {
public:
  static Singleton* getInstance();
  void say() {
    std::cout << this << std::endl;
  }
  ~Singleton() { delete instance; }
private:
  Singleton() {}
  Singleton(const Singleton &rhs);
  Singleton operator=(const Singleton &rhs) {}
  static pthread_mutex_t mutex;
  static Singleton* instance;
};

pthread_mutex_t Singleton::mutex = PTHREAD_MUTEX_INITIALIZER;
Singleton* Singleton::instance = NULL;

Singleton* Singleton::getInstance() {
  if (instance == NULL) {
    pthread_mutex_lock(&mutex);
    if (instance == NULL) {
      instance = new Singleton();
    }
    pthread_mutex_unlock(&mutex);
  }
  return instance;
}

int main() {
  Singleton* t = Singleton::getInstance();
  Singleton* t2 = Singleton::getInstance();
  Singleton* t3 = Singleton::getInstance();
  Singleton* t4 = Singleton::getInstance();
  t->say();
  t2->say();
  t3->say();
  t4->say();
  return 0;
}