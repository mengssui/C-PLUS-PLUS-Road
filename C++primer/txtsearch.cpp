//Copyright
//License
//Author：Mengbw_
//2020年6月22日
//This is to search txt.
//在给定的文件中查询单词
//查询结果：单词在文件中出现的次数以及所在行的列表
//12.3 文本查询程序

//补充2020年6月28日
//增加逻辑与或非操作
// 15.9 文本查询程序再探


#include <map>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <set>
#include <fstream>
#include <iostream>
#include <sstream>
#include <new>


class QueryResult;

class TextQuery {
 public:
  using line_no = std::vector<std::string>::size_type;
  TextQuery(std::ifstream&); //构造函数
  QueryResult query(const std::string&) const;
 private:
  std::shared_ptr<std::vector<std::string>> file;  //输入文件

  std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;   //单词映射到所在行号的集合
};


TextQuery::TextQuery(std::ifstream &is) : file(new std::vector<std::string>) {
    std::string text;
    while (std::getline(is, text)) {
        file->push_back(text);
        int n = file->size() - 1;
        std::istringstream line(text);
        std::string word;
        while (line >> word) {
            auto &lines = wm[word];
            if  (!lines) {
                lines.reset(new std::set<line_no>);
            }
            lines->insert(n);
        }
    }
}

class QueryResult {
  friend std::ostream& print(std::ostream&, const QueryResult&);
 public:
  using line_no = std::vector<std::string>::size_type; 
  QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p, std::shared_ptr<std::vector<std::string>> f)
    : sought(s), lines(p), file(f) {}
 private:
  std::string sought;
  std::shared_ptr<std::set<line_no>> lines;
  
  std::shared_ptr<std::vector<std::string>> file;
};

QueryResult TextQuery::query(const std::string& sought) const {
    //如果没找到，返回一个指向此set的指针
    static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
    auto loc = wm.find(sought);
    if (loc == wm.end()) {
        return QueryResult(sought,nodata,file);
    } else {
        return QueryResult(sought,loc->second,file);
    }
}

std::string make_plural(size_t ctr, const std::string& word, const std::string &ending) {
    return (ctr > 1) ? word + ending :word;
}

std::ostream& print(std::ostream& os, const QueryResult &qr) {
    os <<  qr.sought << " occurs " << qr.lines->size() << " "
       << make_plural(qr.lines->size(), "time", "s") << std::endl;
    for (auto num : *qr.lines) {
        os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << std::endl;
    }
    return os;
}

void runQueries(std::ifstream& infile) {
    TextQuery tq(infile);
    while (true) {
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;
        if (!(std::cin>>s) || s == "q") break;
        print(std::cout, tq.query(s)) <<std::endl;
    }
}






//补充2020年6月28日
//增加逻辑与或非操作

/**
 * 抽象基类
 * */

using namespace std;
class QueryBase {
  friend class Query;  //Query 需要调用虚函数
 protected:
  using line_no = TextQuery::line_no;
  virtual ~QueryBase() = default;
 private:
  virtual QueryResult eval(const TextQuery&) const = 0;
  virtual std::string rep() const = 0;
};



class Query {
  friend Query operator~(const Query&);
  friend Query operator|(const Query&, const Query&);
  friend Query operator&(const Query&, const Query&);
 public:
  Query(const string&);
  QueryResult eval(const TextQuery &t) const { return q->eval(t); }
  string rep() const { return q->rep(); }
 private:
  Query(shared_ptr<QueryBase> query) : q(query) { }
  shared_ptr<QueryBase> q;
};

//输出运算符
ostream& operator <<(ostream& os, const Query& query) {
    return os << query.rep();
}


class WordQuery : public QueryBase {
  friend class Query;   //Query使用WordQuery的构造函数
  WordQuery (const string& s) : query_word_(s) { }
  QueryResult eval(const TextQuery& t) const { return t.query(query_word_); }
  string rep() const { return query_word_; }
  string query_word_;
};



inline Query::Query(const string& s) : q(new WordQuery(s)) { }
 
class NotQuery : public QueryBase {
  friend Query operator~(const Query&);
  NotQuery(const Query& q) : query(q) { }
  string rep() const { return "~(" + query.rep() + ")";}
  QueryResult eval(const TextQuery&) const;
  Query query;
};

inline Query operator~(const Query& operand) {
    return shared_ptr<QueryBase>(new NotQuery(operand));
}