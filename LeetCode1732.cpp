//
// Created by 陆泽辉 on 2022/11/20.
//

#include "LeetCode1732.h"

int LeetCode1732::largestAltitude(vector<int> &gain) {
    int ret = 0;
    int curr = 0;
    for (auto& num : gain) {
        curr += num;
        ret = max(ret, curr);
    }
    return ret;
}
