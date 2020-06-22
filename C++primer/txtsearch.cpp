//Copyright
//License
//Author：Mengbw_
//2020年6月22日
//This is to search txt.
//在给定的文件中查询单词
//查询结果：单词在文件中出现的次数以及所在行的列表
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
  TextQuery(std::ifstream&);
  QueryResult query(const std::string&) const;
 private:
  std::shared_ptr<std::vector<std::string>> file;  //输入文件

  std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
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