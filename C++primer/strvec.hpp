#include <string>
#include <memory>

using namespace std;

class StrVec {
 public:
  StrVec()   //默认初始化
    : elements(nullptr), first_free(nullptr), cap(nullptr) { } 
  StrVec(const StrVec&);            //拷贝构造函数
  StrVec &operator=(const StrVec&); //拷贝赋值运算符
  ~StrVec();                        //析构函数
  void push_back(const string&);     //拷贝元素
  size_t size() const { return first_free - elements; }  //返回元素数量
  size_t capacity() const { return cap - elements; }     //返回空间大小
  string *begin() const { return elements; }
  string *end() const { return first_free; }
 private:
  static allocator<string> alloc; //分配元素
  void chk_n_alloc() { if (size() == capacity() ) reallocate();}
  pair<string*, string*> alloc_n_copy(const string*, const string*);
  void free();
  void reallocate();
  string* elements;
  string* first_free;
  string* cap;
};

void StrVec::push_back(const string& s) {
    chk_n_alloc();
    alloc.construct(first_free++,s);    
}

 pair<string*, string*> 
 StrVec::alloc_n_copy(const string* b, const string* e) {
     auto data = alloc.allocate(e - b);
     return {data, uninitialized_copy(b, e, data)};  //返回的是指向分配内存开始的位置和尾后位置
 }

void StrVec::free() {
    if (elements) {
        for (auto p = first_free; p != elements;) {
            alloc.destroy(--p);
        } //逆序销毁元素
        alloc.deallocate(elements, cap - elements);  //释放空间
    }
}

/**
 * 拷贝构造函数
 * */
StrVec::StrVec(const StrVec& s) {
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;  //构造空间恰好，因此两者位置相同
}

/**
 * 析构函数
 * */
StrVec::~StrVec() {
    free();
}

/**
 * 拷贝赋值运算符
 * */
StrVec &StrVec::operator=(const StrVec &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = data.second;
    return *this;
}

/**
 * rellocate成员
 * 重新分配内存过程中移动而不是拷贝元素
*/
void StrVec::reallocate() {
    auto newcapacity = size() ? 2 * size() : 1;  //分配两倍空间
    auto newdata = alloc.allocate(newcapacity);  //分配新内存
    auto dest = newdata;  //指向数组中下一个空闲位置
    auto elem = elements; //指向旧数组中下一个元素
    for (size_t i = 0; i != size(); ++i) {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}