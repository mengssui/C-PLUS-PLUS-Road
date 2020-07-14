#include <iostream>
#include "UnionFindTestHelper.h"

using namespace std;

int main() {

    int n = 1000000;

    // Quick Find  查找很快
    // UnionFindTestHelper::testUF1(n);

    // Quick Union   合并很快
    // UnionFindTestHelper::testUF2(n);

    // Quick Union + sz

    // UnionFindTestHelper::testUF3(n);

    // Quick Union + rank
    UnionFindTestHelper::testUF4(n);

    // Quick Union + rank + path compression
    UnionFindTestHelper::testUF5(n);

    return 0;
}