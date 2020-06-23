#include <string>

class Folder {
 friend class Message;
 public:
  Folder (/* args */);
  ~Folder ();
 private:
  void addMsg(Message* msg);
  void remMsg(Message* msg);
};

Folder ::Folder (/* args */)
{
}

Folder ::~Folder ()
{
}
