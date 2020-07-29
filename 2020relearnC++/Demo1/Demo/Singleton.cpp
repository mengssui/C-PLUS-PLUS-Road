#include "Singleton.h"

Singleton* Singleton::This = nullptr;  //声明指针
const Singleton* Singleton::getInstance() {
  if(!This) {
    This = new Singleton();
  }
  return This;
}
Singleton::Singleton() {}
Singleton::~Singleton() {}
