//author: Mengbw_
//date : 2020年7月22日

#include <string>
#include <iostream>

using namespace std;
const int* a = nullptr;
int const* b = nullptr;  // both is ok


class Test {
 public:
  enum { n = 4};  //use if not support to use static costant.
  static const int c = 2;  //const declaration
  int score[c];
}; 

int main() {
  const char* const author1 = "Mengbw";
  const string author("Mengbw");
  Test x;
  cout << x.score[1] << " - " << x.score[0] <<endl;
  cout << author << '\n' << author1 << endl;
  return 0;
}

