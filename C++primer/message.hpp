#include <set>
#include <string>
#include "folders.hpp"

class Message { 
  friend class Folder;
 public:
  explicit Message(const std::string &str = "")
    : contents(str) { }
  //拷贝控制成员，用来管理指向本message的指针
  Message(const Message&);  //拷贝构造函数
  Message& operator=(const Message&);  //拷贝赋值运算符
  ~Message();   //析构函数
  void swap(Message &, Message &);
  void save(Folder&);//将本message添加到给定的Folder
  void remove(Folder&);//从给定的集合中删除本message
 private:
  std::string contents; //实际消息文本
  std::set<Folder*> folders;  //包含本message的folder
  void addToFolders(const Message&);
  void removeFromFolders();
};

void Message::save(Folder &f) {
    folders.insert(&f);  //将f添加到Folders列表
    f.addMsg(this);//将这个message添加到f的message集合中
}

void Message::remove(Folder &f) {
    folders.erase(&f);
    f.remMsg(this);
}
/**
 * 类的拷贝控制成员
*/

//将message拷贝到每个指向message的folders中
void Message::addToFolders(const Message &m) {  
  for (auto f : m.folders) {
    f->addMsg(this);
  }
}
Message::Message(const Message &m) 
    : contents(m.contents), folders(m.folders) {
      addToFolders(m);
}

/**
 * 析构函数
*/

//从对应的folder中删除本message
void Message::removeFromFolders() {
  for (auto f : folders) {
    f->remMsg(this);
  }
}
Message::~Message() {
  removeFromFolders();
}

//拷贝赋值运算符
Message& Message::operator=(const Message &rhs) {
  removeFromFolders();//左侧先删除
  contents = rhs.contents;
  folders = rhs.folders;
  addToFolders(rhs); //在右侧消息的folders中添加本消息，由于是赋值，消息一样
  return *this;
}

// Message的swap函数
void Message::swap(Message &lhs, Message &rhs) {
  using std::swap;
  //删除消息所在的folder中的指针
  for (auto f: lhs.folders) f-> remMsg(&lhs);
  for (auto f: rhs.folders) f-> remMsg(&rhs);
  //交换 contents set
  swap(lhs.folders, rhs.folders);
  swap(lhs.contents, rhs.contents);
  //将每个message添加到folder中
  for (auto f : lhs.folders) f->addMsg(&lhs);
  for (auto f : rhs.folders) f->addMsg(&rhs);
}
