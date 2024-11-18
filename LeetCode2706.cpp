//
// Created by luzehui on 2023/12/29.
//

#include "LeetCode2706.h"
#include <map>

int LeetCode2706::buyChoco(vector<int> &prices, int money) {
    std::sort(prices.begin(), prices.end());
    if (prices[0] + prices[1] > money) {
        return money;
    }
    return money - prices[0] - prices[1];
}
