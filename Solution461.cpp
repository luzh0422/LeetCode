//
// Created by luzh on 2021/5/27.
//

#include "Solution461.h"

int Solution461::hammingDistance(int x, int y) {
    int num = x ^ y;
    int ans = getBits(num);
    return ans;
}

int Solution461::getBits(int num) {
    int ans = 0;
    while (num != 0) {
        num &= (num - 1);
        ans++;
    }
    return ans;
}
