//
// Created by 陆泽辉 on 2023/1/2.
//

#include "LeetCode1801.h"

#include <queue>

int LeetCode1801::getNumberOfBacklogOrders(vector<vector<int>> &orders) {
    auto buyCmp = [&](pair<int, int>& buy1, pair<int, int>& buy2) -> bool {
        return buy1.first < buy2.first;
    };
    auto sellCmp = [&](pair<int, int>& sell1, pair<int, int>& sell2) -> bool {
        return sell1.first > sell2.first;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(buyCmp)> buys(buyCmp);
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(sellCmp)> sells(sellCmp);
    for (auto order : orders) {
        int price = order[0];
        int amount = order[1];
        int orderType = order[2];
        if (orderType == 0) {
            int index = 0;
            while (index < amount && !sells.empty()) {
                int sellPrice = sells.top().first;
                if (sellPrice <= price) {
                    int sellCount = sells.top().second;
                    sells.pop();
                    if (index + sellCount < amount) {
                        index += sellCount;
                    } else {
                        sellCount -= amount - index;
                        index = amount;
                        sells.emplace(sellPrice, sellCount);
                        break;
                    }
                } else {
                    break;
                }
            }
            if (index < amount) {
                buys.emplace(price, amount - index);
            }
        } else {
            int index = 0;
            while (index < amount && !buys.empty()) {
                int buyPrice = buys.top().first;
                if (buyPrice >= price) {
                    int buyCount = buys.top().second;
                    buys.pop();
                    if (index + buyCount < amount) {
                        index += buyCount;
                    } else {
                        buyCount -= amount - index;
                        index = amount;
                        buys.emplace(buyPrice, buyCount);
                        break;
                    }
                } else {
                    break;
                }
            }
            if (index < amount) {
                sells.emplace(price, amount - index);
            }
        }
    }
    long res = 0;
    const int MOD = 1e9 + 7;
    while (!buys.empty()) {
        auto buy = buys.top();
        buys.pop();
        res += buy.second;
        res %= MOD;
    }
    while (!sells.empty()) {
        auto sell = sells.top();
        sells.pop();
        res += sell.second;
        res %= MOD;
    }
    return res;
}
