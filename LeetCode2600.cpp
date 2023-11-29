//
// Created by 陆泽辉 on 2023/7/5.
//

#include "LeetCode2600.h"
#include <algorithm>

int LeetCode2600::kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
    int res = std::min(numOnes, k);
    k -= numOnes;
    if (k < 0) {
        return res;
    }
    k -= numZeros;
    if (k < 0) {
        return res;
    }
    return res - k;
}
