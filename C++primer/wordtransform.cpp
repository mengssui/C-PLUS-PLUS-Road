#ifndef WRODTRANSFORM_H_
#define WRODTRANSFORM_H_

#define OUTPUT
#include <iostream>
#include <map>
#include <string>
#include <vector> 
#include <cassert>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

class WordTransform {

 public:
  WordTransform() = default;
  WordTransform(ifstream& regularfile, ifstream& tansformedfile);
  ~WordTransform();

  void Test(ifstream& regularfile) { buildMap(regularfile); }
  void showResult() {
  #ifdef OUTPUT
    cout << "************展示转换结果*************" << endl;
    cout <<endl;
  #endif
    for (auto i : output) {
      cout << i;
    }
    cout << endl;
  }
  void print() {
    cout << "**Output the regular of the transform**" << endl;
    cout << "---------------------------------------" << endl;
    for(auto i = regular_map_.begin(); i != regular_map_.end(); i++ ) {
      cout << setw(3) <<right;
      cout << (*i).first << "   ==>   ";
      cout << left;
      cout << (*i).second << endl;
    }
    cout << "---------------------------------------" << endl;
    cout << endl;
  }
  void printInitialtxt(ifstream& transformfile) { outputTransformedFile(transformfile);}
 private:
  void buildMap(ifstream& regularfile);
  map<string, string> regular_map_;
  void outputTransformedFile(ifstream& transformfile);
  vector<string> output;
  void printout();
};

WordTransform::WordTransform(ifstream& regularfile, ifstream& tansformedfile) {
  buildMap(regularfile);
  outputTransformedFile(tansformedfile);
}

WordTransform::~WordTransform() {}

void WordTransform::outputTransformedFile(ifstream& transformfile) {    
  if(!transformfile.is_open()) {
      cout << "打开文件失败" << endl;
      assert(0);
   }
  int linenum = 0;
  int count = 1;  
  string line;
  #ifdef OUTPUT
  cout << "*************原文************" << endl;

  while(getline(transformfile, line)) {
    cout << line << endl;
    ++linenum;
  }
  #endif
  ++linenum;
  #ifdef OUTPUT
  cout << "*****************************" <<endl;
  cout << endl;
  #endif
  transformfile.clear();
  transformfile.seekg(0,ios::beg);
  #ifdef OUTPUT
  cout << "*************转换开始************" << endl;
  #endif
  while (getline(transformfile,line)) {
    #ifdef OUTPUT
    string printx(count*8,'*');
    cout << setw(24) << left << setprecision(3);
    cout << printx << static_cast<double>(count)/linenum*100 << "%" << endl;
    #endif
    istringstream ss(line);
    string tmp;
    while(ss >> tmp) {
      if ( regular_map_.find(tmp) != regular_map_.end() ) {
        output.push_back(regular_map_.at(tmp));
      } else {
        output.push_back(tmp);
      }
      output.push_back(" ");
    }
    output.push_back("\n");
    ++count;
  }
  transformfile.close();
  #ifdef OUTPUT
  cout << "*************转换完成************" << endl;
  cout << endl;
  #endif
}


void WordTransform::buildMap(ifstream& regularfile) {

  if(!regularfile.is_open()) {  //open the file.
    cout << "文件打开失败" << endl;
    assert(0);
  }

  int linenum = 0;
  int count = 1; 
  char c;
  while (regularfile.get(c)) {
    if (c == '\n') {
      ++linenum;
    }
  }  
  ++linenum; //because the last line have no \n

  regularfile.clear();   //由于前一次遍历文件的指针已经改变，流状态也已经改变，因此要重置
  regularfile.seekg(0,ios::beg);
  #ifdef OUTPUT
  clog << "********共有 (" << linenum << ") 组转换********" << endl;
  clog << endl;
  clog << "******开始建立MAP转换映射******" << endl;
  clog << "----------------------------------" << endl;
  #endif
  string key;
  string value;

  while (regularfile >> key &&  getline(regularfile, value)) {  //the first word is key, the rest is value
    if (value.size() > 1) {
      #ifdef OUTPUT
      string px(3*count,'*');
      clog <<"- " <<setw(25)<< left << px << setprecision(3) << showpoint
           << static_cast<double>(count)/linenum*100.0 <<"% -" << endl;
      #endif
      ++count;
      regular_map_[key] = value.substr(1);  //skip the left whitespace
    } else {
      cout << key << "==> 没有转换规则 " << endl;
    }
  }
  #ifdef OUTPUT
  clog << "----------------------------------" << endl;
  clog << "******建立MAP转换映射完成******" << endl;
  clog << endl;
  #endif
  regularfile.close();
}


/**
 * 主程序
 * */

int main() {
  string regularfile = "rugularfile.txt";
  string transform = "transform.txt";
  ifstream reg(regularfile);
  ifstream tran(transform);
  
  WordTransform mytransform(reg, tran);
  mytransform.showResult();

  reg.close();
  tran.close();
  
  return 0;
}

#endif  // WRODTRANSFORM_H_ 