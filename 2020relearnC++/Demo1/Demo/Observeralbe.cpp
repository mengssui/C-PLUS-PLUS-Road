#include "Observeralbe.h"

Observeralbe::Observeralbe() : _bChange(false) {}

Observeralbe::~Observeralbe() {}

int Observeralbe::GetObserverCnt()  { 
  return _Obs.size();
}
//注册观察者
void Observeralbe::Attach(Observer* pOb) {
  if (pOb == nullptr) {
    return;
  }
  auto it = _Obs.begin();
  for(; it != _Obs.end(); it++) {
    if(*it == pOb) {
    return;
    }
  }
  _Obs.push_back(pOb);
}

void Observeralbe::Detach(Observer* pOb) {
  if(pOb == nullptr || _Obs.empty()) {
    return;
  }
  _Obs.remove(pOb);
}

void Observeralbe::DetachAll() {
  _Obs.clear();
}

void Observeralbe::GetSomeNews(string str) {
  SetChange(str);
}

void Observeralbe::SetChange(string news) {
  _bChange = true;
  Notify((void*)(news.c_str()));
}

void Observeralbe::Notify(void* pArg) {
  if(_bChange == false) {
    return;
  }
  for(auto it = _Obs.begin(); it != _Obs.end(); it++) {
    (*it) -> Update(pArg);
  }
  _bChange = false;
}
