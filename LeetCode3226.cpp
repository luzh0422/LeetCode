//
// Created by luzehui on 2024/11/2.
//

#include "LeetCode3226.h"

int LeetCode3226::minChanges(int n, int k) {
    int res = 0;
    while (n != 0 && k != 0) {
        int bit1 = n & 1;
        int bit2 = k & 1;
        if (bit1 == 1 && bit2 == 0) {
            res++;
        } else if (bit1 == 0 && bit2 == 1) {
            return -1;
        }
        n >>= 1;
        k >>= 1;
    }
    if (n == 0 && k != 0) {
        return -1;
    }
    while (n != 0) {
        if ((n & 1) == 1)
            res++;
        n >>= 1;
    }
    return res;
}
