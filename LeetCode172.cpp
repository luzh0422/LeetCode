//
// Created by luzh on 2022/3/25.
//

#include "LeetCode172.h"

int LeetCode172::trailingZeroes(int n) {
    int ret = 0;
    int basic = 5;
    while (n / basic != 0) {
        ret += n / basic;
        basic *= 5;
    }
    return ret;
}
