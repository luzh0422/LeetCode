//
// Created by 陆泽辉 on 2022/10/27.
//

#include "LeetCode1822.h"

int LeetCode1822::arraySign(vector<int> &nums) {
    int ret = 1;
    for (auto& num : nums) {
        if (num < 0) {
            ret *= -1;
        } else if (num == 0) {
            return 0;
        }
    }
    return ret;
}
