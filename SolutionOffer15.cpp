//
// Created by luzh on 2021/6/23.
//

#include "SolutionOffer15.h"

int SolutionOffer15::hammingWeight(uint32_t n) {
    int ans = 0;
    while (n != 0) {
        ans++;
        n &= n - 1;
    }
    return ans;
}
