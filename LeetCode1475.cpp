//
// Created by 陆泽辉 on 2022/9/1.
//

#include "LeetCode1475.h"

vector<int> LeetCode1475::finalPrices(vector<int> &prices) {
    int n = prices.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (prices[j] <= prices[i]) {
                prices[i] = prices[i] - prices[j];
                break;
            }
        }
    }
    return prices;
}
