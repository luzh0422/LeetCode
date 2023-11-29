//
// Created by 陆泽辉 on 2022/10/22.
//

#include "LeetCode901.h"

int StockSpanner::next(int price) {
    int curr = 1;
    int index = prices.size() - 1;
    while (index >= 0) {
        if (price >= prices[index].first) {
            int step = prices[index].second;
            curr += step;
            index -= step;
        } else {
            break;
        }
    }
    prices.emplace_back(price, curr);
    return curr;
}
