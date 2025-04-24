//
// Created by luzehui on 25-2-20.
//

#include "LeetCode2595.h"

vector<int> LeetCode2595::evenOddBit(int n) {
    int tag = 0;
    vector<int> res(2, 0);
    while (n != 0) {
        if (n % 2 == 1) {
            res[tag]++;
        }
        n >>= 1;
        tag ^= 1;
    }
    return res;
}
