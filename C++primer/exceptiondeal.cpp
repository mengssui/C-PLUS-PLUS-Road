#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
  int i, j, c;
  cout << "Please input to unequal int : \n";
  cin.clear();
  cin.sync(); //清除缓冲区的内容
while(true) {
  while (cin.clear(), cin.sync(), cin >> i >> j) {
    try {
      if (i == j) {
        throw runtime_error("not euqal !!");
      }
      c = j + i;
      cout << "end ->" << c << endl;
    } catch (runtime_error e) {
      std::cerr << e.what() << '\n';
      cout << "\nwant try again? Y/n" << endl;
      char z;
      cin >> z;
      if(!cin || z == 'n')
        break;
      cout << "Please input to unequal int : \n";
    }
  }
  if (cin.fail()) {
    cout << "NOTE: input int!!!\n\n" << endl;
    cout << "Please input to unequal int : \n";
  }else{
    break;
  }
}
  return 0;
}