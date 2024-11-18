//
// Created by luzehui on 2024/8/22.
//

#include "LeetCode3133.h"

long long LeetCode3133::minEnd(int n, int x) {
    long long res = x, bit = 1ll;
    n -= 1;
    while (n > 0) {
        while ((res & bit) != 0) {
            bit <<= 1;
        }
        if ((n & 1) == 1)
            res ^= bit;
        n >>= 1;
        bit <<= 1;
    }
    return res;
}
