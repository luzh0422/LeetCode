//
// Created by 陆泽辉 on 2023/2/4.
//

#include "LeetCode1798.h"

int LeetCode1798::getMaximumConsecutive(vector<int> &coins) {
    std::sort(coins.begin(), coins.end());
    int curr = 0;
    for (int i = 0; i < coins.size(); i++) {
        if (coins[i] <= curr + 1) {
            curr += coins[i];
        } else {
            break;
        }
    }
    return curr;
}
