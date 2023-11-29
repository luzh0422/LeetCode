//
// Created by 陆泽辉 on 2023/10/1.
//

#include "LeetCode121.h"

int LeetCode121::maxProfit(vector<int> &prices) {
    int minPrice = INT_MAX, maxProfit = 0;
    for (int i = 0; i < prices.size(); i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else {
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
    }
    return maxProfit;
}
