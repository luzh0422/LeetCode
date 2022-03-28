//
// Created by luzh on 2022/3/14.
//

#include "LeetCode121.h"

int LeetCode121::maxProfit(vector<int> &prices) {
    int n = prices.size();
    int currMin = prices[0];
    int ret = 0;
    for (int i = 1; i < n; i++) {
        if (prices[i] < currMin) {
            currMin = prices[i];
        } else {
            ret = max(ret, prices[i] - currMin);
        }
    }
    return ret;
}
