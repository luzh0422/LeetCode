//
// Created by 陆泽辉 on 2023/10/8.
//

#include "LeetCode2034.h"

void StockPrice::update(int timestamp, int price) {
    if (timestamp >= _timestamp) {
        _price = price;
        _timestamp = timestamp;
    }
    int prevPrice = cache.count(timestamp) ? cache[timestamp] : 0;
    cache[timestamp] = price;
    if (prevPrice > 0) {
        auto it = stocks.find(prevPrice);
        if (it != stocks.end()) {
            stocks.erase(it);
        }
    }
    stocks.emplace(price);
}

int StockPrice::current() {
    return _price;
}

int StockPrice::maximum() {
    return *stocks.rbegin();
}

int StockPrice::minimum() {
    return *stocks.begin();
}
