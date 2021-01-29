/*************************************************************************
	> File Name: x^n.cpp
	> Author: Mengbw
	> Mail: 1711900861@qq.com
	> Created Time: Fri 08 Jan 2021 09:27:20 AM CST
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

//x的n次方，理解递归的时间复杂度

long long calculate(int num, int pol) {
    if (pol == 0) return 1;
    cout << pol << endl;
    return num * calculate(num, pol-1);
}

long long calculate1(int num, int pol) {
    //分奇偶
    if (pol == 0) return 1;
    cout << pol << endl;
    if (pol % 2 == 1) return calculate1(num, pol/2) * num * calculate1(num, pol/2);
    return calculate1(num, pol/2) * calculate1(num, pol/2);
}

//O(logn)时间复杂度
long long calculate2(int num, int pol) {
    if (pol == 0) return 1;
    cout << pol << endl;
    long long t = calculate2(num, pol/2);   //每次函数只进行一次递归，每次是除2
    if (pol % 2 == 1) return t*t * num;
    return t*t;
}

int main() {
    int number, pol;
    cin >> number >> pol;

    cout << "calculate时间复杂度为：" 
         << calculate(number, pol) << endl;
    cout << "calculate1时间复杂度为：" 
         << calculate1(number, pol) << endl;
    cout << "calculate2时间复杂度为：" 
         << calculate2(number, pol) << endl;

    return 0;
}
