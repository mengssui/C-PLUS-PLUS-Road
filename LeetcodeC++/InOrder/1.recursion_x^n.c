/************************************************************************
	> File Name: 1.recursion_x^n.c
	> Author: Mengbw
	> Mail: 1711900861@qq.com
	> Created Time: Mon 28 Sep 2020 08:10:55 PM CST
 ************************************************************************/

/*
 * 计算x的n次方，几种不同复杂度。
 */

#include <stdio.h>

//1. for 循环 不写了
//2. recursion递归
//3. 第二种递归
//4. 第三种递归
//前三种方法时间复杂度都是O(n), 第4中方法时间复杂度是O(logn)

int function2(int x, int n) {
    if(n == 0) {
        return 1;
    }
    return function2(x, n-1) * x;
}

int function3(int x, int n) {
    if(n == 0) {
        return 1;
    }
    if(n & 1) {
        return function3(x,n/2) * function3(x,n/2) * x;
    }
    return function3(x,n/2) * function3(x,n/2);
}

int function4(int x, int n) {
    if (n == 0) {
        return 1;
    }
    int temp = function4(x,n/2);
    if(x & 1){
        return temp * temp * x;
    }
    return temp * temp;
}


int main() {
    int x,n;
    scanf("%d%d", &x, &n);
    printf("func2 = %d\n", function2(x,n));
    printf("func3 = %d\n", function3(x,n));
    printf("func4 = %d\n", function4(x,n));
    return 0;
}
