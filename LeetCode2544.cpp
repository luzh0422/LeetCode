//
// Created by 陆泽辉 on 2023/7/12.
//

#include "LeetCode2544.h"

int LeetCode2544::alternateDigitSum(int n) {
    int tag = 0;
    int res = 0;
    while (n > 0) {
        int temp = n % 10;
        n /= 10;
        if (tag == 0) {
            res += temp;
        } else {
            res -= temp;
        }
        tag ^= 1;
    }
    if (tag == 0) {
        return 0 - res;
    }
    return res;
}
