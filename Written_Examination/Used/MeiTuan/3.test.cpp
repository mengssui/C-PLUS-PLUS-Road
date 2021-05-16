//
// Created by Mengbw on 2021/4/4.
/*
#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

string getNumStr(int num) {
    string s;
    int sqr = floor(sqrt(num));
    for (int i = sqr; i >= 1; i--) {
        if (num % i == 0) {
            s.insert(0,to_string(i));
            if (num / i != i) s.append(to_string(num/i));
        }
    }
    cout << s << endl;
    return s;
}

int main () {
    unsigned int n, k, a;
    scanf("%d%d", &n, &k);
    unsigned ans = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        string s = getNumStr(a);
        cout << "find : " << s.find(to_string(k)) << endl;
        //if (s.find() != string::npos), npos
        if (strstr(s.c_str(), to_string(k).c_str())) ans += 1;
    }
    printf("%d", ans);
    return 0;
}
 */