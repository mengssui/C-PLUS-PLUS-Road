//
// Created by Mengbw on 2021/4/4.
//
/*
#include <iostream>
#include <map>
using namespace std;

int main () {
    map<int, int> cut;
    int n;
    int ans = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t, angle;
        cin >> t >> angle;
        switch (t) {
            case 1: {
                if (cut.find(angle) == cut.end()) {
                    ans *= 2;
                    cut[angle] += 1;
                    cut[(angle+180)%360] += 1;
                }
            } break;
            case 0 :{
                ans *= 2;
            }break;
        }
    }
    cout << ans << endl;
    return 0;
}
 */