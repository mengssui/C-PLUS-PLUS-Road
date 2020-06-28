#include <string>

using namespace std;



//基类
class Quote {
 public:
  Quote() = default; //定义默认构造函数,因为既需要默认的,也需要自定义的
  Quote(const string& book, double sales_price)
    : book_no_(book), price_(sales_price) { }
  string isbn() const { return book_no_; }
  virtual double net_price(size_t num) const { return num * price_; }
  virtual ~Quote () = default; //对析构函数动态绑定
 private:
  string book_no_;
 protected:
  double price_ = 0.0;
};


class BulkQuote : public Quote {
 public:
  BulkQuote() = default;
  BulkQuote(const string&, double, size_t, double);
  //覆盖基类
  double net_price(size_t) const override;
 private:
  size_t min_qty_ = 0;
  double discount = 0.0;
};
