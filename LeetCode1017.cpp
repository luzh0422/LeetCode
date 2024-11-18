//
// Created by luzehui on 2024/4/28.
//

#include "LeetCode1017.h"

string LeetCode1017::baseNeg2(int n) {
    if (n == 0)
        return "0";
    string res = "";
    while (n) {
        int a = n % -2;
        n /= -2;
        if (a < 0) {
            a += 2; // 余数相当于二进制的位数，同时二进制的位数不支持-1，因此遇到-1，要转换为1；
            n++; // 当余数从-1转换为1，相当于整体+2，则商要加1，相当于整体-2，抵消余数+1；
        }
        res = to_string(a) + res;
    }
    return res;
}
