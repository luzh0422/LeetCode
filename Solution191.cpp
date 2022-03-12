//
// Created by luzh on 2021/3/22.
//

#include "Solution191.h"

int Solution191::hammingWeight(uint32_t n) {
    int ans = 0;
    while (n != 0) {
        n &= (n - 1);
        ans++;
    }
    return ans;
}
